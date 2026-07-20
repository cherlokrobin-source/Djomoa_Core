#ifndef SOLAR_ENGINE_H
#define SOLAR_ENGINE_H

#include "Calendar.h"

class SolarEngine
{
public:
    long long getDayId(int year, int month, int day);
    SolarEngine();

    Date getDate(long long day);

    long long daysUntilYear(int year);

private:

    bool isLeap(int year);

};

#endif
