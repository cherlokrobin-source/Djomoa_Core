#include "automation/TemporalAutomationEngine.h"
#include "TemporalCoordinateEngine.h"


Chronology TemporalAutomationEngine::Generate(long long dayId)
{
    TemporalCoordinateEngine engine;

    return engine.getCoordinate(dayId);
}


Chronology TemporalAutomationEngine::FromSolar(
    int year,
    int month,
    int day
)
{
    TemporalCoordinateEngine engine;

    return engine.getCoordinateBySolar(
        year,
        month,
        day
    );
}


Chronology TemporalAutomationEngine::FromLunar(
    int year,
    int month,
    int day
)
{
    TemporalCoordinateEngine engine;

    return engine.getCoordinateByLunar(
        year,
        month,
        day
    );
}
