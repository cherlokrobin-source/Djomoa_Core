#include "LunarEngine.h"


LunarEngine::LunarEngine()
{
}


bool LunarEngine::isLeap(int year)
{
    int cycle = ((year - 1) % 33) + 1;

    int leapYears[] =
    {
        3,6,9,11,14,
        17,20,22,25,
        28,31
    };


    for(int y : leapYears)
    {
        if(cycle == y)
            return true;
    }

    return false;
}



Date LunarEngine::getDate(long long day)
{
    Date result;


    long long remaining = day - 1;


    int year = 1;


    while(true)
    {
        int days = isLeap(year) ? 355 : 354;


        if(remaining < days)
            break;


        remaining -= days;
        year++;
    }


    int months[] =
    {
        30,29,30,29,
        30,29,30,29,
        30,29,30,29
    };


    if(isLeap(year))
        months[11] = 30;


    int month = 1;


    while(remaining >= months[month-1])
    {
        remaining -= months[month-1];
        month++;
    }


    result.dayId = day;
    result.year = year;
    result.month = month;
    result.day = remaining + 1;


    return result;
}
long long LunarEngine::getDayId(int year, int month, int day)
{
    long long dayId = 1;

    for(int y = 1; y < year; y++)
    {
        dayId += isLeap(y) ? 355 : 354;
    }

    int months[] =
    {
        30,29,30,29,
        30,29,30,29,
        30,29,30,29
    };

    if(isLeap(year))
        months[11] = 30;

    for(int m = 1; m < month; m++)
    {
        dayId += months[m-1];
    }

    dayId += day - 1;

    return dayId;
}
