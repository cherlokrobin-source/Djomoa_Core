#ifndef GABARY_SOLAR_ENGINE_V2_H
#define GABARY_SOLAR_ENGINE_V2_H

#include "SolarDate.h"
#include <cstdint>
#include "GlobalSolarDay.h"
#include "WeekCycleEngine.h"
namespace Gabary
{

class SolarEngineV2
{

public:
    GlobalSolarDay buildDay(int64_t dayId);
    SolarDate fromDayId(int64_t dayId);

    int64_t toDayId(
        int year,
        int month,
        int day
    );

    int daysInYear(int year);

    int daysInMonth(
        int year,
        int month
    );

};

}

#endif
