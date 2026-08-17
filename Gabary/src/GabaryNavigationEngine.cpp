#include "../include/GabaryNavigationEngine.h"

namespace Gabary
{

GabaryNavigationEngine::GabaryNavigationEngine()
{
}

DualCalendarDate
GabaryNavigationEngine::getDate(int64_t dayId)
{
    if (dayId < MIN_GLOBAL_DAY)
    {
        return dualCalendarEngine.getDate(MIN_GLOBAL_DAY);
    }

    if (dayId > MAX_GLOBAL_DAY)
    {
        return dualCalendarEngine.getDate(MAX_GLOBAL_DAY);
    }

    return dualCalendarEngine.getDate(dayId);
}

DualCalendarDate
GabaryNavigationEngine::nextDay(int64_t dayId)
{
    if (dayId >= MAX_GLOBAL_DAY)
    {
        return dualCalendarEngine.getDate(MAX_GLOBAL_DAY);
    }

    return dualCalendarEngine.getDate(dayId + 1);
}

DualCalendarDate
GabaryNavigationEngine::previousDay(int64_t dayId)
{
    if (dayId <= MIN_GLOBAL_DAY)
    {
        return dualCalendarEngine.getDate(MIN_GLOBAL_DAY);
    }

    return dualCalendarEngine.getDate(dayId - 1);
}

int64_t
GabaryNavigationEngine::jumpToSolarDate(
    int year,
    int month,
    int day
)
{
    return dualCalendarEngine.solarToDayId(
        year,
        month,
        day
    );
}



} // Closing bracket for block at line 4
