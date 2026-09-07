#include "GabaryNavigationEngine.h"

namespace Gabary {

GabaryNavigationEngine::GabaryNavigationEngine()
    : defaultEngine(), dualCalendarEngine(defaultEngine) {}

GabaryNavigationEngine::GabaryNavigationEngine(
    GabaryDualCalendarEngine& dualEngine
)
    : defaultEngine(), dualCalendarEngine(dualEngine) {}

DualCalendarDate GabaryNavigationEngine::getDate(int64_t dayId)
{
    // --------------------------------------------------------
    // Global Solar Day boundary protection
    // --------------------------------------------------------

    if (dayId < MIN_GLOBAL_DAY)
    {
        dayId = MIN_GLOBAL_DAY;
    }

    if (dayId > MAX_GLOBAL_DAY)
    {
        dayId = MAX_GLOBAL_DAY;
    }

    return dualCalendarEngine.getDate(dayId);
}

DualCalendarDate GabaryNavigationEngine::nextDay(
    int64_t currentDayId
)
{
    if (currentDayId >= MAX_GLOBAL_DAY)
    {
        return getDate(MAX_GLOBAL_DAY);
    }

    return getDate(currentDayId + 1);
}

DualCalendarDate GabaryNavigationEngine::previousDay(
    int64_t currentDayId
)
{
    if (currentDayId <= MIN_GLOBAL_DAY)
    {
        return getDate(MIN_GLOBAL_DAY);
    }

    return getDate(currentDayId - 1);
}

DualCalendarDate GabaryNavigationEngine::jumpToDay(
    int64_t dayId
)
{
    return getDate(dayId);
}

int64_t GabaryNavigationEngine::jumpToSolarDate(
    int year,
    int month,
    int day
)
{
    const int64_t dayId =
        dualCalendarEngine.solarToDayId(
            year,
            month,
            day
        );

    if (dayId < MIN_GLOBAL_DAY ||
        dayId > MAX_GLOBAL_DAY)
    {
        return -1;
    }

    return dayId;
}

int64_t GabaryNavigationEngine::jumpToLunarDate(
    int year,
    int month,
    int day
)
{
    const int64_t dayId =
        dualCalendarEngine.lunarToDayId(
            year,
            month,
            day
        );

    if (dayId < MIN_GLOBAL_DAY ||
        dayId > MAX_GLOBAL_DAY)
    {
        return -1;
    }

    return dayId;
}

} // namespace Gabary
