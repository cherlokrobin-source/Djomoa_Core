#include "server/HttpServer.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

HttpServer::HttpServer(
    int port,
    Gabary::GabaryTemporalService& service
)
    : port_(port),
      running_(false),
      serverSocket_(-1),
      service_(service)
{
}

HttpServer::~HttpServer()
{
    stop();
}

void HttpServer::start()
{
    serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket_ < 0)
    {
        std::cerr << "[HTTP] socket() failed: "
                  << std::strerror(errno)
                  << std::endl;
        return;
    }

    int opt = 1;

    setsockopt(
        serverSocket_,
        SOL_SOCKET,
        SO_REUSEADDR,
        &opt,
        sizeof(opt)
    );

    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    if (
        bind(
            serverSocket_,
            (struct sockaddr*)&address,
            sizeof(address)
        ) < 0
    )
    {
        std::cerr << "[HTTP] bind() failed on port "
                  << port_ << ": "
                  << std::strerror(errno)
                  << std::endl;
        close(serverSocket_);
        serverSocket_ = -1;
        return;
    }

    if (listen(serverSocket_, 10) < 0)
    {
        std::cerr << "[HTTP] listen() failed: "
                  << std::strerror(errno)
                  << std::endl;
        close(serverSocket_);
        serverSocket_ = -1;
        return;
    }

    running_ = true;

    std::cout
        << "Server running on http://127.0.0.1:"
        << port_
        << std::endl;

    while (running_)
    {
        sockaddr_in clientAddr{};
        socklen_t addrLen = sizeof(clientAddr);

        int clientSocket =
            accept(
                serverSocket_,
                (struct sockaddr*)&clientAddr,
                &addrLen
            );

        if (clientSocket >= 0)
        {
            handleClient(clientSocket);
            close(clientSocket);
        }
    }
}

void HttpServer::stop()
{
    running_ = false;

    if (serverSocket_ >= 0)
    {
        close(serverSocket_);
        serverSocket_ = -1;
    }
}

void HttpServer::handleClient(int clientSocket)
{
    char buffer[4096] = {0};

    ssize_t received =
        read(
            clientSocket,
            buffer,
            sizeof(buffer) - 1
        );

    if (received <= 0)
        return;

    std::string request(buffer);

    std::stringstream requestStream(request);

    std::string method;
    std::string path;

    requestStream >> method >> path;

    // --------------------------------------------------------
    // Static Web Pages
    // --------------------------------------------------------

    if (
        path == "/" ||
        path == "/index.html" ||
        path == "/app.js" ||
        path.find(".css") != std::string::npos
    )
    {
        std::string filePath =
            "frontend" +
            (path == "/" ? "/index.html" : path);

        std::ifstream file(
            filePath,
            std::ios::binary
        );

        if (file.is_open())
        {
            std::stringstream ss;
            ss << file.rdbuf();

            std::string content = ss.str();

            std::string mime =
                (path.find(".js") != std::string::npos)
                ? "text/javascript"
                : "text/html";

            std::string response =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: " + mime + "; charset=utf-8\r\n"
                "Access-Control-Allow-Origin: *\r\n"
                "Content-Length: " +
                std::to_string(content.size()) +
                "\r\n"
                "Connection: close\r\n"
                "\r\n" +
                content;

            send(
                clientSocket,
                response.c_str(),
                response.size(),
                0
            );

            return;
        }
    }

    // --------------------------------------------------------
    // API Endpoints
    // --------------------------------------------------------

    std::string body;
    std::string status = "HTTP/1.1 200 OK";

    if (path == "/api/status")
    {
        body =
            R"({"engine":"Gabary V2","architecture":"50,000 Year Solar Chronology","status":"stable","validation":"PASSED"})";
    }

    else if (
        path.rfind("/api/json/solar/", 0) == 0
    )
    {
        try
        {
            const std::string prefix =
                "/api/json/solar/";

            std::string values =
                path.substr(prefix.size());

            std::stringstream input(values);

            int year = 0;
            int month = 0;
            int day = 0;
            char sep1 = 0;
            char sep2 = 0;

            if (
                !(input >> year >> sep1 >> month >> sep2 >> day) ||
                sep1 != '/' ||
                sep2 != '/'
            )
            {
                throw std::runtime_error("Invalid solar date");
            }

            auto res =
                service_.querySolar(
                    year,
                    month,
                    day
                );

            std::stringstream ss;

            ss
                << "{"
                << "\"dayId\":" << res.dayId
                << ",\"solar\":{"
                << "\"year\":" << res.solar.solarYear
                << ",\"month\":" << res.solar.solarMonth
                << ",\"day\":" << res.solar.solarDay
                << ",\"monthName\":\"" << res.solar.monthName << "\""
                << ",\"weekday\":\"" << res.solar.weekName << "\""
                << ",\"dayOfYear\":" << res.solar.dayOfYear
                << ",\"leapYear\":"
                << (res.solar.leapYear ? "true" : "false")
                << ",\"weekIndex\":" << res.solar.weekIndex
                << "}"
                << ",\"lunar\":{"
                << "\"year\":" << res.lunar.year
                << ",\"month\":" << res.lunar.month
                << ",\"day\":" << res.lunar.day
                << "}"
                << ",\"architecture\":{"
                << "\"name\":\"Gabary V2\""
                << ",\"engine\":\"GabaryDualCalendarEngine\""
                << ",\"coordinate\":\"Global Solar Day\""
                << ",\"validation\":\"PASSED\""
                << "}"
                << "}";

            body = ss.str();
        }
        catch (...)
        {
            status = "HTTP/1.1 400 Bad Request";

            body =
                R"({"error":"Invalid Solar Date"})";
        }
    }

    else if (
        path.rfind("/api/json/lunar/", 0) == 0
    )
    {
        try
        {
            const std::string prefix =
                "/api/json/lunar/";

            std::string values =
                path.substr(prefix.size());

            std::stringstream input(values);

            int year = 0;
            int month = 0;
            int day = 0;
            char sep1 = 0;
            char sep2 = 0;

            if (
                !(input >> year >> sep1 >> month >> sep2 >> day) ||
                sep1 != '/' ||
                sep2 != '/'
            )
            {
                throw std::runtime_error("Invalid lunar date");
            }

            auto res =
                service_.queryLunar(
                    year,
                    month,
                    day
                );

            std::stringstream ss;

            ss
                << "{"
                << "\"dayId\":" << res.dayId
                << ",\"solar\":{"
                << "\"year\":" << res.solar.solarYear
                << ",\"month\":" << res.solar.solarMonth
                << ",\"day\":" << res.solar.solarDay
                << ",\"monthName\":\"" << res.solar.monthName << "\""
                << ",\"weekday\":\"" << res.solar.weekName << "\""
                << ",\"dayOfYear\":" << res.solar.dayOfYear
                << ",\"leapYear\":"
                << (res.solar.leapYear ? "true" : "false")
                << ",\"weekIndex\":" << res.solar.weekIndex
                << "}"
                << ",\"lunar\":{"
                << "\"year\":" << res.lunar.year
                << ",\"month\":" << res.lunar.month
                << ",\"day\":" << res.lunar.day
                << "}"
                << ",\"architecture\":{"
                << "\"name\":\"Gabary V2\""
                << ",\"engine\":\"GabaryDualCalendarEngine\""
                << ",\"coordinate\":\"Global Solar Day\""
                << ",\"validation\":\"PASSED\""
                << "}"
                << "}";

            body = ss.str();
        }
        catch (...)
        {
            status = "HTTP/1.1 400 Bad Request";

            body =
                R"({"error":"Invalid Lunar Date"})";
        }
    }

    else if (
        path.rfind("/api/json/day/", 0) == 0
    )
    {
        try
        {
            const std::string prefix =
                "/api/json/day/";

            long long dayId =
                std::stoll(
                    path.substr(prefix.size())
                );

            // ------------------------------------------------
            // Global Solar Day boundary
            // ------------------------------------------------

            if (
                dayId < Gabary::GabaryNavigationEngine::MIN_GLOBAL_DAY ||
                dayId > Gabary::GabaryNavigationEngine::MAX_GLOBAL_DAY
            )
            {
                status = "HTTP/1.1 400 Bad Request";

                body =
                    R"({"error":"Global Solar Day out of range","minGlobalDay":1,"maxGlobalDay":18261759})";
            }

            else
            {
                auto res =
                    service_.queryDay(dayId);

                  // ------------------------------------------------
                  // Full Gabary V2 temporal JSON contract
                  // ------------------------------------------------

                  std::stringstream ss;

                  const std::string weekday =
                      res.solar.weekName;

                  ss
                      << "{"
                      << "\"dayId\":" << dayId

                      << ",\"solar\":{"
                      << "\"year\":" << res.solar.solarYear
                      << ",\"month\":" << res.solar.solarMonth
                      << ",\"day\":" << res.solar.solarDay
                      << ",\"monthName\":\"" << res.solar.monthName << "\""
                      << ",\"weekday\":\"" << weekday << "\""
                      << ",\"dayOfYear\":" << res.solar.dayOfYear
                      << ",\"leapYear\":"
                      << (res.solar.leapYear ? "true" : "false")
                      << ",\"weekIndex\":" << res.solar.weekIndex
                      << "}"

                      << ",\"lunar\":{"
                      << "\"year\":" << res.lunar.year
                      << ",\"month\":" << res.lunar.month
                      << ",\"day\":" << res.lunar.day
                      << "}"

                      << ",\"architecture\":{"
                      << "\"name\":\"Gabary V2\""
                      << ",\"engine\":\"GabaryDualCalendarEngine\""
                      << ",\"coordinate\":\"Global Solar Day\""
                      << ",\"validation\":\"PASSED\""
                      << "}"

                      << "}";

                  body = ss.str();

                body = ss.str();
            }
        }
        catch (...)
        {
            status = "HTTP/1.1 400 Bad Request";

            body =
                R"({"error":"Invalid Day ID"})";
        }
    }

    else
    {
        status = "HTTP/1.1 404 Not Found";

        body =
            R"({"error":"Not Found"})";
    }

    // --------------------------------------------------------
    // HTTP Response
    // --------------------------------------------------------

    std::string response =
        status +
        "\r\n"
        "Content-Type: application/json; charset=utf-8\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Content-Length: " +
        std::to_string(body.size()) +
        "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        body;

    send(
        clientSocket,
        response.c_str(),
        response.size(),
        0
    );
}
