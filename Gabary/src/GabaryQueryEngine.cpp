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

    return navigationEngine.getDate(dayId);
}

} // namespace Gabary
