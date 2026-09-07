#include "server/HttpServer.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

HttpServer::HttpServer(int port, Gabary::GabaryTemporalService& service)
    : port_(port), running_(false), serverSocket_(-1), service_(service) {}

HttpServer::~HttpServer() { stop(); }

void HttpServer::start() {
    serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket_ < 0) return;

    int opt = 1;
    setsockopt(serverSocket_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    if (bind(serverSocket_, (struct sockaddr*)&address, sizeof(address)) < 0) {
        close(serverSocket_);
        return;
    }

    if (listen(serverSocket_, 10) < 0) {
        close(serverSocket_);
        return;
    }

    running_ = true;
    std::cout << "Server running on http://127.0.0.1:" << port_ << std::endl;

    while (running_) {
        sockaddr_in clientAddr{};
        socklen_t addrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket_, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket >= 0) {
            handleClient(clientSocket);
            close(clientSocket);
        }
    }
}

void HttpServer::stop() {
    running_ = false;
    if (serverSocket_ >= 0) {
        close(serverSocket_);
        serverSocket_ = -1;
    }
}

void HttpServer::handleClient(int clientSocket) {
    char buffer[4096] = {0};
    read(clientSocket, buffer, sizeof(buffer) - 1);
    
    std::string request(buffer);
    std::stringstream requestStream(request);
    std::string method, path;
    requestStream >> method >> path;

    // Static Web Pages
    if (path == "/" || path == "/index.html" || path == "/app.js" || path.find(".css") != std::string::npos) {
        std::string filePath = "frontend" + (path == "/" ? "/index.html" : path);
        std::ifstream file(filePath, std::ios::binary);
        if (file.is_open()) {
            std::stringstream ss;
            ss << file.rdbuf();
            std::string content = ss.str();
            std::string mime = (path.find(".js") != std::string::npos) ? "text/javascript" : "text/html";
            std::string response = "HTTP/1.1 200 OK\r\nContent-Type: " + mime + "; charset=utf-8\r\nAccess-Control-Allow-Origin: *\r\nContent-Length: " 
                                 + std::to_string(content.size()) + "\r\nConnection: close\r\n\r\n" + content;
            send(clientSocket, response.c_str(), response.size(), 0);
            return;
        }
    }

    // API Endpoints
    std::string body;
    if (path == "/api/status") {
        body = R"({"engine":"Gabary V2","architecture":"50,000 Year Solar Chronology","status":"stable","validation":"PASSED"})";
    } 
    else if (path.rfind("/api/json/day/", 0) == 0) {
        try {
            long long dayId = std::stoll(path.substr(14));
            auto res = service_.queryDay(dayId);
            std::stringstream ss;
            ss << "{\"dayId\":" << dayId 
               << ",\"solar\":{\"year\":" << res.solar.solarYear << ",\"month\":" << res.solar.solarMonth << ",\"day\":" << res.solar.solarDay << "}"
               << ",\"lunar\":{\"year\":" << res.lunar.year << ",\"month\":" << res.lunar.month << ",\"day\":" << res.lunar.day << "}}";
            body = ss.str();
        } catch(...) {
            body = R"({"error":"Invalid Day ID"})";
        }
    }
    else {
        body = R"({"status":"ok","engine":"Gabary V2"})";
    }

    std::string response = "HTTP/1.1 200 OK\r\nContent-Type: application/json; charset=utf-8\r\nAccess-Control-Allow-Origin: *\r\nContent-Length: " 
                         + std::to_string(body.size()) + "\r\nConnection: close\r\n\r\n" + body;
    send(clientSocket, response.c_str(), response.size(), 0);
}
