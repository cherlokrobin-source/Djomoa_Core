#ifndef TEMPORAL_SERVER_H
#define TEMPORAL_SERVER_H

#include <string>

#include "TemporalQueryEngine.h"
#include "../../Gabary/include/SolarEngineV2.h"


class TemporalServer
{
public:

    TemporalServer();


    std::string handleDayRequest(
        long long dayId
    );


    std::string handleDayJSONRequest(
        long long dayId
    );


    std::string handleSolarRequest(
        int year,
        int month,
        int day
    );


    std::string handleLunarRequest(
        int year,
        int month,
        int day
    );


    std::string handleStatusRequest();


private:

    Gabary::SolarEngineV2 solarEngine;

    TemporalQueryEngine queryEngine;

};


#endif
