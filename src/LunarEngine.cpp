#include "LunarEngine.h"
#include "Names.h"


LunarEngine::LunarEngine()
{
}


// تحديد السنة الكبيسة القمرية حسب دورة 33 سنة
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


// عدد السنوات الكبيسة قبل سنة معينة
long long LunarEngine::leapYearsBefore(int year)
{
    long long cycles = (year - 1) / 33;

    int remaining = (year - 1) % 33;


    long long leaps = cycles * 12;


    int leapYears[] =
    {
        3,6,9,11,14,
        17,20,22,25,
        28,31
    };


    for(int y : leapYears)
    {
        if(y <= remaining)
            leaps++;
    }


    return leaps;
}


// عدد الأيام قبل بداية السنة القمرية
long long LunarEngine::daysUntilYear(int year)
{
    long long years = year - 1;


    return
        (years * 354)
        + leapYearsBefore(year);
}



// تحويل DayID إلى تاريخ قمري
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


    while(month <= 12 &&
          remaining >= months[month-1])
    {
        remaining -= months[month-1];
        month++;
    }


    result.dayId = day;
    result.year = year;
    result.month = month;
    result.day = remaining + 1;


    if(month >= 1 && month <= 12)
    {
        result.monthName =
            CalendarNames::LUNAR_MONTHS[month-1];
    }


    return result;
}

// تحويل تاريخ قمري إلى DayID
long long LunarEngine::getDayId(
    int year,
    int month,
    int day
)
{
    long long id =
        daysUntilYear(year) + 1;



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
        id += months[m-1];
    }


    id += day - 1;


    return id;
}
