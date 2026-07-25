#include "TemporalQueryEngine.h"
#include <iostream>


TemporalQueryEngine::TemporalQueryEngine()
{
}


// ===============================
// Query by Day ID
// ===============================

GlobalTemporalID TemporalQueryEngine::queryDay(
    long long dayId
)
{
    return chronology.generateGlobalID(dayId);
}



// ===============================
// Query by Solar Date
// ===============================

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



// ===============================
// Query by Lunar Date
// ===============================

GlobalTemporalID TemporalQueryEngine::queryLunar(
    int year,
    int month,
    int day
)
{
    std::cout << "LUNAR QUERY START\n";


    Chronology c =
        chronology.getByLunar(
            year,
            month,
            day
        );


    std::cout
        << "LUNAR DAY ID = "
        << c.dayId
        << "\n";


    return chronology.generateGlobalID(
        c.dayId
    );
}
