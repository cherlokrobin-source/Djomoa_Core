#include "GabaryQueryEngine.h"

namespace Gabary
{

GabaryQueryEngine::GabaryQueryEngine()
{
}

DualCalendarDate
GabaryQueryEngine::queryDay(int64_t dayId)
{
    return navigationEngine.getDate(dayId);
}

DualCalendarDate
GabaryQueryEngine::querySolar(
    int year,
    int month,
    int day
)
{
    int64_t dayId =
        navigationEngine.jumpToSolarDate(
            year,
            month,
            day
        );

    if (dayId < GabaryNavigationEngine::MIN_GLOBAL_DAY ||
        dayId > GabaryNavigationEngine::MAX_GLOBAL_DAY)
    {
        return DualCalendarDate{};
    }

    return navigationEngine.getDate(dayId);
}

DualCalendarDate
GabaryQueryEngine::queryLunar(
    int year,
    int month,
    int day
)
{
    int64_t dayId =
        navigationEngine.jumpToLunarDate(
            year,
            month,
            day
        );

    if (dayId < GabaryNavigationEngine::MIN_GLOBAL_DAY ||
        dayId > GabaryNavigationEngine::MAX_GLOBAL_DAY)
    {
        return DualCalendarDate{};
    }

    return navigationEngine.getDate(dayId);
}

} // namespace Gabary
