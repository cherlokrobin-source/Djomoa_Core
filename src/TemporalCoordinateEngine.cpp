#include "TemporalCoordinateEngine.h"


TemporalCoordinateEngine::TemporalCoordinateEngine()
{
}



Chronology TemporalCoordinateEngine::getCoordinate(
    long long dayId
)
{

    return chronology.getChronology(dayId);

}



Chronology TemporalCoordinateEngine::getCoordinateBySolar(
    int year,
    int month,
    int day
)
{

    return chronology.getBySolar(
        year,
        month,
        day
    );

}



Chronology TemporalCoordinateEngine::getCoordinateByLunar(
    int year,
    int month,
    int day
)
{

    return chronology.getByLunar(
        year,
        month,
        day
    );

}
