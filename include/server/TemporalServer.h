#ifndef TEMPORAL_SERVER_H
#define TEMPORAL_SERVER_H

#include <string>

#include "../api/TemporalAPI.h"


class TemporalServer
{

public:

    TemporalServer();


    // استقبال طلب يوم بواسطة Day ID
    std::string handleDayRequest(
        long long dayId
    );


    // استقبال طلب التاريخ الشمسي
    std::string handleSolarRequest(
        int year,
        int month,
        int day
    );


    // استقبال طلب التاريخ القمري
    std::string handleLunarRequest(
        int year,
        int month,
        int day
    );


private:

    TemporalAPI api;

};


#endif
