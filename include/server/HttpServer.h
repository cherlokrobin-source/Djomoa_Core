#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "GabaryTemporalService.h"
#include <string>

class HttpServer {
public:
    HttpServer(int port, Gabary::GabaryTemporalService& service);
    ~HttpServer();

    void start();
    void stop();

private:
    void handleClient(int clientSocket);

    int port_;
    bool running_;
    int serverSocket_;
    Gabary::GabaryTemporalService& service_;
};

#endif // HTTP_SERVER_H
