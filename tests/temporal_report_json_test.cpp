#include <iostream>

#include "report/TemporalReportEngine.h"
#include "report/TemporalReportJSON.h"


int main()
{
    TemporalReportEngine engine;


    long long dayId = 739823;


    TemporalReport report =
        engine.generate(dayId);


    std::string json =
        TemporalReportJSON::toJSON(report);


    std::cout
        << json
        << std::endl;


    if(json.find("\"dayId\"") == std::string::npos)
    {
        return 1;
    }


    if(json.find("\"solar\"") == std::string::npos)
    {
        return 1;
    }


    if(json.find("\"lunar\"") == std::string::npos)
    {
        return 1;
    }


    return 0;
}
