#ifndef GABARY_SOLAR_CYCLE_H
#define GABARY_SOLAR_CYCLE_H

#include <cstdint>

namespace Gabary
{

struct SolarCycle
{
    int32_t cycleId = 0;

    int32_t startYear = 1;

    int32_t endYear = 63;

    int64_t startDayId = 1;

    int64_t totalDays = 0;
};

}

#endif
