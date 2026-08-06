#ifndef GABARY_GLOBAL_SOLAR_DAY_H
#define GABARY_GLOBAL_SOLAR_DAY_H

#include <cstdint>
#include <string>

namespace Gabary
{

struct GlobalSolarDay
{
    // Global coordinate
    int64_t dayId = 0;

    // Solar chronology
    int32_t solarYear = 1;
    int32_t solarMonth = 1;
    int32_t solarDay = 1;
    int32_t dayOfYear = 1;

    // Week cycle
    int32_t weekIndex = 0;
    std::string monthName = "January";
    std::string weekName = "Friday";

    // Leap information
    bool leapYear = false;
};

}

#endif
