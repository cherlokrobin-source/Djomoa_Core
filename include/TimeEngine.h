#ifndef TIME_ENGINE_H
#define TIME_ENGINE_H

#include "ChronologyEngine.h"

class TimeEngine
{
public:

    TimeEngine();

    Chronology getByDayId(long long day);

    Chronology getBySolar(
        int year,
        int month,
        int day
    );

};

#endif
