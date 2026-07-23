#ifndef LONG_TIME_ENGINE_H
#define LONG_TIME_ENGINE_H

#include "ChronologyEngine.h"


class LongTimeEngine
{
private:

    ChronologyEngine engine;


public:

    LongTimeEngine();


    Chronology getYearStart(int year);


    Chronology getDate(
        int year,
        int month,
        int day
    );
};


#endif
