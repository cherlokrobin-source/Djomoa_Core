#ifndef GABARY_SOLAR_DATE_H
#define GABARY_SOLAR_DATE_H

#include <cstdint>

namespace Gabary
{

struct SolarDate
{
    int32_t year = 1;
    int32_t month = 1;
    int32_t day = 1;

    int32_t dayOfYear = 1;

    bool leapYear = false;
};

}

#endif
