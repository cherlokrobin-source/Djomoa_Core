#include "server/HttpServer.h"

#include <iostream>

int main()
{
    std::cout
        << "Starting Golden Calendar HTTP Layer..."
        << std::endl;

    HttpServer server(8080);

    server.run();

    return 0;
}
