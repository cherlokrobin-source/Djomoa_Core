#include "SolarEngine.h"
#include "Names.h"

SolarEngine::SolarEngine()
{
}


// حساب السنة الكبيسة
bool SolarEngine::isLeap(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    return (year % 4 == 0);
}


// عدد السنوات الكبيسة قبل سنة معينة
long long SolarEngine::leapYearsBefore(int year)
{
    long long y = year - 1;

    return
        (y / 4)
        - (y / 100)
        + (y / 400);
}


// عدد الأيام حتى بداية السنة
long long SolarEngine::daysUntilYear(int year)
{
    long long years = year - 1;

    return
        (years * 365)
        + leapYearsBefore(year);
}


// عدد أيام السنة
int SolarEngine::daysInYear(int year)
{
    return isLeap(year) ? 366 : 365;
}


// تحويل DayID إلى تاريخ شمسي
Date SolarEngine::getDate(long long day)
{
    Date result;

    // تقدير السنة مباشرة
    long long low = 1;
    long long high = 60000;

    long long year = 1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (daysUntilYear(mid) < day)
        {
            year = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    long long remaining =
        day - daysUntilYear(year);

    int months[] =
    {
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };

    bool leap = isLeap(year);

    if (leap)
        months[1] = 29;

    int month = 1;

    while (remaining > months[month - 1])
    {
        remaining -= months[month - 1];
        month++;
    }

    result.dayId = day;
    result.year = year;
    result.month = month;
    result.day = static_cast<int>(remaining);

    // بيانات إضافية
    result.leapYear = leap;

    result.dayOfYear = result.day;
    for (int i = 0; i < month - 1; i++)
    {
        result.dayOfYear += months[i];
    }

    result.monthName =
        CalendarNames::SOLAR_MONTHS[month - 1];

    return result;
}


// تحويل تاريخ شمسي إلى DayID
long long SolarEngine::getDayId(
    int year,
    int month,
    int day
)
{
    long long id =
        daysUntilYear(year);

    int months[] =
    {
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };

    if (isLeap(year))
        months[1] = 29;

    for (int m = 1; m < month; m++)
    {
        id += months[m - 1];
    }

    id += day;

    return id;
}
