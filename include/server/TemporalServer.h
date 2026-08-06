#ifndef TEMPORAL_SERVER_H
#define TEMPORAL_SERVER_H

#include <string>
#include "../../Gabary/include/SolarEngineV2.h"

class TemporalServer
{
public:

    TemporalServer();


    // =====================================
    // Text Report API
    // =====================================

    std::string handleDayRequest(
        long long dayId
    );


    // =====================================
    // JSON API v2
    // =====================================

    std::string handleDayJSONRequest(
        long long dayId
    );


    // =====================================
    // Solar Query
    // =====================================

    std::string handleSolarRequest(
        int year,
        int month,
        int day
    );


    // =====================================
    // Lunar Query
    // =====================================

    std::string handleLunarRequest(
        int year,
        int month,
        int day
    );


    // =====================================
    // Engine Status
    // =====================================

    std::string handleStatusRequest();


private:

    Gabary::SolarEngineV2 solarEngine;

};


#endif
