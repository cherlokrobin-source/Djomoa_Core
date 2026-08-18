#include "GabaryNavigationEngine.h"

namespace Gabary
{

GabaryNavigationEngine::GabaryNavigationEngine()
{
}

DualCalendarDate
GabaryNavigationEngine::getDate(int64_t dayId)
{
    return dualCalendarEngine.getDate(dayId);
}

DualCalendarDate
GabaryNavigationEngine::nextDay(int64_t dayId)
{
    return dualCalendarEngine.getDate(dayId + 1);
}

DualCalendarDate
GabaryNavigationEngine::previousDay(int64_t dayId)
{
    if (dayId <= 1)
    {
        return dualCalendarEngine.getDate(1);
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

} // namespace Gabary
