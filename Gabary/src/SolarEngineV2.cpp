#include "../include/SolarEngineV2.h"
#include "../include/LeapYearRules.h"

#include <array>
#include <string>

namespace Gabary
{

static const std::array<std::string, 12> MONTH_NAMES =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};


// =====================================
// Calendar constants
// =====================================

namespace
{
    constexpr int64_t DAYS_PER_400_YEARS = 146097;
    constexpr int YEARS_PER_CYCLE = 400;
}


// =====================================
// Leap-year / year length
// =====================================

int SolarEngineV2::daysInYear(int year)
{
    return LeapYearRules::isLeapYear(year) ? 366 : 365;
}


// =====================================
// Month length
// =====================================

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


// =====================================
// Number of leap years from year 1
// through year n
// =====================================

namespace
{
    int64_t leapYearsThrough(int64_t n)
    {
        if(n <= 0)
            return 0;

        return
            n / 4
            - n / 100
            + n / 400;
    }
}


// =====================================
// Convert Global Solar Day -> Solar Date
// =====================================

SolarDate SolarEngineV2::fromDayId(
    int64_t dayId
)
{
    SolarDate date;

    int64_t remaining = dayId - 1;

    // ---------------------------------
    // Jump directly across 400-year
    // Gregorian-style cycles.
    // ---------------------------------

    int64_t cycle =
        remaining / DAYS_PER_400_YEARS;

    int year =
        static_cast<int>(
            cycle * YEARS_PER_CYCLE
        ) + 1;

    remaining %= DAYS_PER_400_YEARS;


    // ---------------------------------
    // Resolve the remaining year.
    // Maximum: 400 iterations.
    // ---------------------------------

    while(true)
    {
        int days = daysInYear(year);

        if(remaining < days)
            break;

        remaining -= days;
        ++year;
    }


    // ---------------------------------
    // Resolve month.
    // Maximum: 12 iterations.
    // ---------------------------------

    int month = 1;

    while(true)
    {
        int days =
            daysInMonth(year, month);

        if(remaining < days)
            break;

        remaining -= days;
        ++month;
    }


    date.year = year;

    date.month = month;

    date.day =
        static_cast<int>(remaining) + 1;

    date.leapYear =
        LeapYearRules::isLeapYear(year);


    // ---------------------------------
    // Day of year
    // ---------------------------------

    date.dayOfYear =
        static_cast<int>(
            dayId
            - toDayId(year, 1, 1)
            + 1
        );


    return date;
}


// =====================================
// Convert Solar Date -> Global Solar Day
// =====================================

int64_t SolarEngineV2::toDayId(
    int year,
    int month,
    int day
)
{
    const int64_t yearsBefore =
        static_cast<int64_t>(year) - 1;


    // ---------------------------------
    // Days contributed by complete years
    // ---------------------------------

    const int64_t totalDays =
        yearsBefore * 365
        + leapYearsThrough(yearsBefore);


    // ---------------------------------
    // Days contributed by complete months
    // ---------------------------------

    int64_t monthDays = 0;

    for(int m = 1; m < month; ++m)
    {
        monthDays +=
            daysInMonth(year, m);
    }


    return
        totalDays
        + monthDays
        + day;
}


// =====================================
// Build Global Solar Day
// =====================================

GlobalSolarDay SolarEngineV2::buildDay(
    int64_t dayId
)
{
    SolarDate date =
        fromDayId(dayId);


    GlobalSolarDay result;

    result.dayId =
        dayId;

    result.solarYear =
        date.year;

    result.solarMonth =
        date.month;

    result.monthName =
        MONTH_NAMES[
            date.month - 1
        ];

    result.solarDay =
        date.day;

    result.dayOfYear =
        date.dayOfYear;

    result.leapYear =
        date.leapYear;


    result.weekIndex =
        WeekCycleEngine::weekdayIndex(
            dayId
        );

    result.weekName =
        WeekCycleEngine::weekdayName(
            dayId
        );


    return result;
}

}
