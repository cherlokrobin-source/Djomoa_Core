#ifndef ARCHIVE_ENGINE_H
#define ARCHIVE_ENGINE_H

#include "ChronologyEngine.h"


class ArchiveEngine
{

private:

    ChronologyEngine engine;


public:
int daysInSolarYear(int year);
    ArchiveEngine();


    Chronology getDay(
        long long dayId
    );


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


    void printYear(
        int year
    );

};


#endif
