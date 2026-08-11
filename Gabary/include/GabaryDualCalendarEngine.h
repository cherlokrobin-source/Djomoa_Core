#ifndef GABARY_DUAL_CALENDAR_ENGINE_H
#define GABARY_DUAL_CALENDAR_ENGINE_H

#include <cstdint>

#include "SolarEngineV2.h"
#include "LunarEngineV2.h"
#include "GlobalSolarDay.h"
#include "Calendar.h"

namespace Gabary
{

struct DualCalendarDate
{
    int64_t dayId = 0;

    GlobalSolarDay solar;
    Date lunar;
};

class GabaryDualCalendarEngine
{
public:

    GabaryDualCalendarEngine();

    // Global Day -> complete dual-calendar date
    DualCalendarDate getDate(int64_t dayId);

    // Solar Date -> Global Day
    int64_t solarToDayId(
        int year,
        int month,
        int day
    );

    // Lunar Date -> Global Day
    int64_t lunarToDayId(
        int year,
        int month,
        int day
    );

private:

    SolarEngineV2 solarEngine;
    LunarEngineV2 lunarEngine;
};

}

#endif
