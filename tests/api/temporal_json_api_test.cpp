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


    if(json.find("\"globalSolarDay\":739823")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: globalSolarDay missing\n";
        return 1;
    }


    if(json.find("\"solarDate\"")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: solarDate missing\n";
        return 1;
    }


    if(json.find("\"calendarMetadata\"")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: calendarMetadata missing\n";
        return 1;
    }


    if(json.find("\"architecture\"")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: architecture missing\n";
        return 1;
    }


    if(json.find("\"name\":\"Gabary V2\"")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: Gabary V2 missing\n";
        return 1;
    }


    if(json.find("\"validation\":\"PASSED\"")
       == std::string::npos)
    {
        std::cerr
            << "FAIL: validation missing\n";
        return 1;
    }


    std::cout
        << "JSON API TEST PASSED\n";


    return 0;
}
