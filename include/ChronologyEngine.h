#ifndef CHRONOLOGY_ENGINE_H
#define CHRONOLOGY_ENGINE_H

#include "SolarEngine.h"
#include "LunarEngine.h"
#include "Chronology.h"
#include "WeekEngine.h"

class ChronologyEngine
{

public:

    SolarEngine& getSolarEngine();
    ChronologyEngine();

    Chronology getChronology(long long day);

    Chronology getBySolar(
        int year,
        int month,
        int day
    );

    Chronology getByLunar(
        int year,
        int month,
        int day
    );

    long long getDayId(
        int year,
        int month,
        int day
    );

    void printDay(long long day);


private:

    SolarEngine solar;
    LunarEngine lunar;
    WeekEngine week;

};

#endif
