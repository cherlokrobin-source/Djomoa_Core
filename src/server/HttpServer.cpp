#include "server/HttpServer.h"

#include <iostream>
#include <sstream>
#include <exception>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


HttpServer::HttpServer(int port)
    : port(port)
{
}



// ======================================
// تشغيل الخادم
// ======================================

void HttpServer::run()
{
    int serverSocket = socket(
        AF_INET,
        SOCK_STREAM,
        0
    );


    if(serverSocket < 0)
    {
        std::cerr << "Socket creation failed\n";
        return;
    }


    int opt = 1;

    setsockopt(
        serverSocket,
        SOL_SOCKET,
        SO_REUSEADDR,
        &opt,
        sizeof(opt)
    );


    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);



    if(bind(
        serverSocket,
        (sockaddr*)&address,
        sizeof(address)
    ) < 0)
    {
        std::cerr << "Bind failed\n";
        close(serverSocket);
        return;
    }



    if(listen(serverSocket,10) < 0)
    {
        std::cerr << "Listen failed\n";
        close(serverSocket);
        return;
    }



    std::cout
        << "=====================================\n"
        << " Golden Calendar HTTP Server\n"
        << " Port: "
        << port
        << "\n Status: Running\n"
        << "=====================================\n";



    while(true)
    {
        int clientSocket =
            accept(
                serverSocket,
                nullptr,
                nullptr
            );


        if(clientSocket >= 0)
        {
            try
            {
                handleClient(clientSocket);
            }
            catch(const std::exception& e)
            {
                std::cerr
                    << "Exception: "
                    << e.what()
                    << std::endl;
            }
            catch(...)
            {
                std::cerr
                    << "Unknown exception"
                    << std::endl;
            }


            close(clientSocket);
        }
    }
}





// ======================================
// معالجة الطلب
// ======================================

void HttpServer::handleClient(
    int clientSocket
)
{
    char buffer[4096]{};


    read(
        clientSocket,
        buffer,
        sizeof(buffer)
    );


    std::string request(buffer);


    std::string path =
        parsePath(request);



    std::cout
        << "REQUEST PATH: "
        << path
        << std::endl;



    std::string body;



    // =========================
    // STATUS
    // =========================

    if(path == "/api/status")
    {
        body =
            temporalServer.handleStatusRequest();
    }



    // =========================
    // DAY
    // =========================

    else if(path.find("/api/day/") == 0)
    {
        long long dayId =
            std::stoll(
                path.substr(9)
            );


        body =
            temporalServer.handleDayRequest(
                dayId
            );
    }



    // =========================
    // SOLAR
    // =========================

    else if(path.find("/api/solar/") == 0)
    {
        std::string data =
            path.substr(11);


        std::stringstream ss(data);


        std::string year;
        std::string month;
        std::string day;


        getline(ss, year, '/');
        getline(ss, month, '/');
        getline(ss, day, '/');


        body =
            temporalServer.handleSolarRequest(
                std::stoi(year),
                std::stoi(month),
                std::stoi(day)
            );
    }



    // =========================
    // LUNAR
    // =========================

    else if(path.find("/api/lunar/") == 0)
    {
        std::cout
            << "LUNAR ENDPOINT HIT"
            << std::endl;


        // الصحيح: /api/lunar/ = 11 محرف
        std::string data =
            path.substr(11);



        std::stringstream ss(data);


        std::string year;
        std::string month;
        std::string day;


        getline(ss, year, '/');
        getline(ss, month, '/');
        getline(ss, day, '/');



        body =
            temporalServer.handleLunarRequest(
                std::stoi(year),
                std::stoi(month),
                std::stoi(day)
            );
    }



    else
    {
        body =
            R"({"error":"Endpoint not found"})";
    }



    std::string response =
        buildResponse(body);



    send(
        clientSocket,
        response.c_str(),
        response.size(),
        0
    );
}





// ======================================
// استخراج المسار
// ======================================

std::string HttpServer::parsePath(
    const std::string& request
)
{
    std::stringstream ss(request);


    std::string method;
    std::string path;


    ss >> method >> path;


    return path;
}





// ======================================
// بناء رد HTTP
// ======================================

std::string HttpServer::buildResponse(
    const std::string& body
)
{
    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Content-Length: "
        + std::to_string(body.size())
        + "\r\n\r\n"
        + body;


    return response;
}
