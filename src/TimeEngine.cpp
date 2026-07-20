#include "TimeEngine.h"


TimeEngine::TimeEngine()
{
}


Chronology TimeEngine::getByDayId(long long day)
{
    ChronologyEngine engine;

    return engine.getChronology(day);
}


Chronology TimeEngine::getBySolar(
    int year,
    int month,
    int day
)
{
    ChronologyEngine engine;

    long long id = engine.getDayId(year, month, day);

    return engine.getChronology(id);
}
