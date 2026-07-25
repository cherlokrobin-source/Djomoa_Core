#include "server/TemporalServer.h"

#include <iostream>

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Golden Calendar Temporal Server v1\n";
    std::cout << " 50000 Year Chronology Engine\n";
    std::cout << "=====================================\n";

    TemporalServer server;

    std::cout << "\n[STATUS]\n";
    std::cout << server.handleStatusRequest() << std::endl;

    std::cout << "\n[DAY QUERY]\n";
    std::cout << server.handleDayRequest(1) << std::endl;

    std::cout << "\n[SOLAR QUERY]\n";
    std::cout << server.handleSolarRequest(1, 1, 1) << std::endl;

    std::cout << "\n[LUNAR QUERY]\n";
    std::cout << server.handleLunarRequest(1, 1, 1) << std::endl;

    return 0;
}
