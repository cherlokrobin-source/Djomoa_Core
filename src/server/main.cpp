#include "server/HttpServer.h"
#include "GabaryTemporalService.h"
#include <iostream>

int main() {
    Gabary::GabaryTemporalService service;
    HttpServer server(8080, service);
    server.start();
    return 0;
}
