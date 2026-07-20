#include "SolarEngine.h"

SolarEngine::SolarEngine()
{
}

bool SolarEngine::isLeap(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    return (year % 4 == 0);
}

Date SolarEngine::getDate(long long day)
{
    Date result;

    long long remaining = day - 1;

    int year = 1;

    while (true)
    {
        int days = isLeap(year) ? 366 : 365;

        if (remaining < days)
            break;

        remaining -= days;
        year++;
    }

    int months[] =
    {
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };

    if (isLeap(year))
        months[1] = 29;

    int month = 1;

    while (remaining >= months[month - 1])
    {
        remaining -= months[month - 1];
        month++;
    }

    result.dayId = day;
    result.year = year;
    result.month = month;
    result.day = remaining + 1;

    return result;
}

long long SolarEngine::daysUntilYear(int year)
{
    long long days = 0;

    for (int y = 1; y < year; y++)
    {
        days += isLeap(y) ? 366 : 365;
    }

    return days;
}
long long SolarEngine::getDayId(int year, int month, int day)
{
    long long dayId = 1;

    for(int y = 1; y < year; y++)
    {
        dayId += isLeap(y) ? 366 : 365;
    }

    int months[] =
    {
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };

    if(isLeap(year))
        months[1] = 29;

    for(int m = 1; m < month; m++)
    {
        dayId += months[m-1];
    }

    dayId += day - 1;

    return dayId;
}
