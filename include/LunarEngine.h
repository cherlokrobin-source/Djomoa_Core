#ifndef LUNAR_ENGINE_H
#define LUNAR_ENGINE_H

#include "Calendar.h"

class LunarEngine
{
public:

    LunarEngine();

    Date getDate(long long day);

    long long getDayId(
        int year,
        int month,
        int day
    );


private:

    bool isLeap(int year);

    long long daysUntilYear(int year);

    long long leapYearsBefore(int year);

};

#endif
