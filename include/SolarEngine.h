#ifndef SOLAR_ENGINE_H
#define SOLAR_ENGINE_H

#include "Calendar.h"

class SolarEngine
{
public:

    SolarEngine();

    Date getDate(long long day);

    long long getDayId(
        int year,
        int month,
        int day
    );

    long long daysUntilYear(int year);

    int daysInYear(int year);


private:

    bool isLeap(int year);

    long long leapYearsBefore(int year);

};

#endif
