#include "../include/SolarEngineV2.h"
#include "../include/LeapYearRules.h"

namespace Gabary
{


int SolarEngineV2::daysInYear(int year)
{
    return LeapYearRules::isLeapYear(year) ? 366 : 365;
}



int SolarEngineV2::daysInMonth(
    int year,
    int month
)
{
    switch(month)
    {
        case 1:  return 31;
        case 2:  return LeapYearRules::isLeapYear(year) ? 29 : 28;
        case 3:  return 31;
        case 4:  return 30;
        case 5:  return 31;
        case 6:  return 30;
        case 7:  return 31;
        case 8:  return 31;
        case 9:  return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }

    return 0;
}



SolarDate SolarEngineV2::fromDayId(
    int64_t dayId
)
{
    SolarDate date;


    int64_t remaining = dayId - 1;


    int year = 1;


    while(true)
    {
        int days = daysInYear(year);

        if(remaining < days)
            break;

        remaining -= days;
        year++;
    }


    date.year = year;
    date.leapYear =
        LeapYearRules::isLeapYear(year);


    int month = 1;


    while(true)
    {
        int days = daysInMonth(year, month);

        if(remaining < days)
            break;

        remaining -= days;
        month++;
    }


    date.month = month;
    date.day = remaining + 1;
    date.dayOfYear = 1;

    for(int m = 1; m < month; ++m)
    {
        date.dayOfYear += daysInMonth(year, m);
    }

    date.dayOfYear += date.day - 1;



    return date;
}



int64_t SolarEngineV2::toDayId(
    int year,
    int month,
    int day
)
{
    int64_t total = 0;


    for(int y = 1; y < year; y++)
    {
        total += daysInYear(y);
    }


    for(int m = 1; m < month; m++)
    {
        total += daysInMonth(year, m);
    }


    total += day;


    return total;
}

GlobalSolarDay SolarEngineV2::buildDay(int64_t dayId)
{
    SolarDate date = fromDayId(dayId);

    GlobalSolarDay result;

    result.dayId = dayId;
    result.solarYear = date.year;
    result.solarMonth = date.month;
    result.solarDay = date.day;
    result.dayOfYear = date.dayOfYear;
    result.leapYear = date.leapYear;

    result.weekIndex = WeekCycleEngine::weekdayIndex(dayId);
    result.weekName = WeekCycleEngine::weekdayName(dayId);

    return result;
}

}
