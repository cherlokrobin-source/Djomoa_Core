#include "../include/GabaryDualCalendarEngine.h"

namespace Gabary
{

GabaryDualCalendarEngine::GabaryDualCalendarEngine()
{
}

DualCalendarDate
GabaryDualCalendarEngine::getDate(int64_t dayId)
{
    DualCalendarDate result;

    result.dayId = dayId;

    result.solar =
        solarEngine.buildDay(dayId);

    result.lunar =
        lunarEngine.getDate(dayId);

    
    if (dayId > 17716312) {
        result.lunar.dayId = 0;
        result.lunar.year = 0;
        result.lunar.month = 0;
        result.lunar.day = 0;
    }
    return result;

}

int64_t
GabaryDualCalendarEngine::solarToDayId(
    int year,
    int month,
    int day
)
{
    return solarEngine.toDayId(
        year,
        month,
        day
    );
}

int64_t
GabaryDualCalendarEngine::lunarToDayId(
    int year,
    int month,
    int day
)
{
    return lunarEngine.getDayId(
        year,
        month,
        day
    );
}

}
