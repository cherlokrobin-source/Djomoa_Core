#include "TemporalQueryEngine.h"


TemporalQueryEngine::TemporalQueryEngine()
{
}


GlobalTemporalID TemporalQueryEngine::queryDay(long long dayId)
{
    return chronology.generateGlobalID(dayId);
}


GlobalTemporalID TemporalQueryEngine::querySolar(
    int year,
    int month,
    int day
)
{
    long long id =
        chronology.getDayId(
            year,
            month,
            day
        );

    return chronology.generateGlobalID(id);
}


GlobalTemporalID TemporalQueryEngine::queryLunar(
    int year,
    int month,
    int day
)
{
    Chronology c =
        chronology.getByLunar(
            year,
            month,
            day
        );

    return chronology.generateGlobalID(c.dayId);
}
