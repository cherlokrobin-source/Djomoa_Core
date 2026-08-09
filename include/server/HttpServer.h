#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "TemporalServer.h"
#include <string>

class HttpServer
{
public:

    HttpServer(int port);

    void run();

private:

    int port;
    TemporalServer temporalServer;

    void handleClient(
        int clientSocket
    );

    std::string parsePath(
        const std::string& request
    );

    std::string buildResponse(
        const std::string& body
    );

    std::string serveStaticFile(
        const std::string& path
    );

    std::string getContentType(
        const std::string& path
    );
};

#endif
