#ifndef GABARY_GLOBAL_SOLAR_DAY_H
#define GABARY_GLOBAL_SOLAR_DAY_H

#include <cstdint>

namespace Gabary
{

struct GlobalSolarDay
{
    // Primary global coordinate
    int64_t dayId = 0;

    // Solar chronology
    int32_t solarYear = 1;
    int32_t dayOfYear = 1;

    // Leap year flag
    bool leapYear = false;
};

}

#endif
