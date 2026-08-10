#include "LunarEngineV2.h"
#include "Names.h"

namespace Gabary
{

LunarEngineV2::LunarEngineV2()
{
}

// ============================================================
// Lunar leap-year rule
//
// 33-year cycle
//
// Leap years:
// 3, 6, 9, 11, 14, 17, 20, 22, 25, 28, 31
//
// Total leap years = 11
// ============================================================

bool LunarEngineV2::isLeap(int year) const
{
    const int cycleYear = yearInCycle(year);

    switch (cycleYear)
    {
        case 3:
        case 6:
        case 9:
        case 11:
        case 14:
        case 17:
        case 20:
        case 22:
        case 25:
        case 28:
        case 31:
            return true;

        default:
            return false;
    }
}

// ============================================================
// Number of complete 33-year cycles before a given year
// ============================================================

long long LunarEngineV2::cyclesBefore(int year) const
{
    return (year - 1) / CYCLE_YEARS;
}

// ============================================================
// Year position inside the 33-year cycle
//
// Returns: 1..33
// ============================================================

int LunarEngineV2::yearInCycle(int year) const
{
    return ((year - 1) % CYCLE_YEARS) + 1;
}

// ============================================================
// Number of leap years before a given year
// ============================================================

long long LunarEngineV2::leapYearsBefore(int year) const
{
    const long long cycles = cyclesBefore(year);
    const int remainingYears = (year - 1) % CYCLE_YEARS;

    long long leapYears =
        cycles * LEAP_YEARS_PER_CYCLE;

    const int leapYearsInCycle[] =
    {
        3, 6, 9, 11,
        14, 17, 20, 22,
        25, 28, 31
    };

    for (int leapYear : leapYearsInCycle)
    {
        if (leapYear <= remainingYears)
        {
            ++leapYears;
        }
    }

    return leapYears;
}

// ============================================================
// Number of days before the beginning of a lunar year
// ============================================================

long long LunarEngineV2::daysUntilYear(int year) const
{
    const long long completeYears = year - 1;

    return
        (completeYears * NORMAL_YEAR_DAYS)
        + leapYearsBefore(year);
}

// ============================================================
// Global Solar Day -> Lunar Date
//
// Day 1 = Lunar 1/1/1
//
// V2 optimization:
// The 33-year cycle is located directly using division.
// Only the years inside the selected cycle are inspected.
// ============================================================

Date LunarEngineV2::getDate(long long globalSolarDay) const
{
    Date result{};

    if (globalSolarDay < 1)
    {
        return result;
    }

    long long remaining = globalSolarDay - 1;

    // --------------------------------------------------------
    // Locate the 33-year cycle directly
    // --------------------------------------------------------

    const long long cycleIndex =
        remaining / CYCLE_DAYS;

    remaining %= CYCLE_DAYS;

    int year =
        static_cast<int>(
            cycleIndex * CYCLE_YEARS
        ) + 1;

    // --------------------------------------------------------
    // Locate the year inside the selected cycle
    // --------------------------------------------------------

    while (true)
    {
        const int yearDays =
            isLeap(year)
                ? LEAP_YEAR_DAYS
                : NORMAL_YEAR_DAYS;

        if (remaining < yearDays)
        {
            break;
        }

        remaining -= yearDays;
        ++year;
    }

    // --------------------------------------------------------
    // Lunar month lengths
    //
    // Normal year:
    // 30,29,30,29,30,29,30,29,30,29,30,29
    //
    // Leap year:
    // Dhul-Hijjah = 30
    // --------------------------------------------------------

    int monthLengths[12] =
    {
        30, 29, 30, 29,
        30, 29, 30, 29,
        30, 29, 30, 29
    };

    if (isLeap(year))
    {
        monthLengths[11] = 30;
    }

    // --------------------------------------------------------
    // Locate lunar month
    // --------------------------------------------------------

    int month = 1;

    while (
        month <= 12 &&
        remaining >= monthLengths[month - 1]
    )
    {
        remaining -= monthLengths[month - 1];
        ++month;
    }

    // --------------------------------------------------------
    // Build result
    // --------------------------------------------------------

    result.dayId = globalSolarDay;
    result.year = year;
    result.month = month;
    result.day =
        static_cast<int>(remaining) + 1;

    if (month >= 1 && month <= 12)
    {
        result.monthName =
            CalendarNames::LUNAR_MONTHS[month - 1];
    }

    return result;
}

// ============================================================
// Lunar Date -> Global Solar Day
//
// Lunar 1/1/1 = Global Day 1
// ============================================================

long long LunarEngineV2::getDayId(
    int year,
    int month,
    int day
) const
{
    if (year < 1 ||
        month < 1 ||
        month > 12 ||
        day < 1)
    {
        return -1;
    }

    // --------------------------------------------------------
    // Lunar month lengths
    // --------------------------------------------------------

    int monthLengths[12] =
    {
        30, 29, 30, 29,
        30, 29, 30, 29,
        30, 29, 30, 29
    };

    if (isLeap(year))
    {
        monthLengths[11] = 30;
    }

    // --------------------------------------------------------
    // Validate actual day-of-month
    // --------------------------------------------------------

    if (day > monthLengths[month - 1])
    {
        return -1;
    }

    // --------------------------------------------------------
    // Days before the beginning of the lunar year
    // --------------------------------------------------------

    long long dayId =
        daysUntilYear(year) + 1;

    // --------------------------------------------------------
    // Add complete months before the requested month
    // --------------------------------------------------------

    for (int m = 1; m < month; ++m)
    {
        dayId += monthLengths[m - 1];
    }

    // --------------------------------------------------------
    // Add days inside the requested month
    // --------------------------------------------------------

    dayId += day - 1;

    return dayId;
}

}
