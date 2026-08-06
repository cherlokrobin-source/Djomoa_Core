#include "TemporalServer.h"

#include <iostream>
#include <string>


int main()
{
    std::cout << "Temporal JSON API Test\n";
    std::cout << "=====================\n";


    TemporalServer server;


    std::string json =
        server.handleDayJSONRequest(739823);


    std::cout << json << std::endl;


    if(json.find("\"dayId\":739823") == std::string::npos)
    {
        std::cerr << "FAIL: dayId missing\n";
        return 1;
    }


    if(json.find("\"architecture\":\"Gabary V2\"") == std::string::npos)
    {
        std::cerr << "FAIL: architecture missing\n";
        return 1;
    }


    if(json.find("\"validation\":\"PASSED\"") == std::string::npos)
    {
        std::cerr << "FAIL: validation missing\n";
        return 1;
    }


    std::cout << "JSON API TEST PASSED\n";

    return 0;
}
