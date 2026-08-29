#ifndef GABARY_LUNAR_ENGINE_V2_H
#define GABARY_LUNAR_ENGINE_V2_H

#include "Calendar.h"

namespace Gabary
{

class LunarEngineV2
{
public:
static constexpr long long MIN_GLOBAL_DAY = 1LL;
static constexpr long long MAX_GLOBAL_DAY = 17716312LL;
static constexpr int MIN_LUNAR_YEAR = 1;
static constexpr int MAX_LUNAR_YEAR = 49999;
    static constexpr int CYCLE_YEARS = 33;

    static constexpr int NORMAL_YEAR_DAYS = 354;

    static constexpr int LEAP_YEAR_DAYS = 355;

    static constexpr int LEAP_YEARS_PER_CYCLE = 11;

    static constexpr long long CYCLE_DAYS = 11693LL;

    LunarEngineV2();

    // Global Solar Day -> Lunar Date
    Date getDate(long long globalSolarDay) const;

    // Lunar Date -> Global Solar Day
    long long getDayId(
        int year,
        int month,
        int day
    ) const;

    // Lunar leap-year test
    bool isLeap(int year) const;

    // Number of complete lunar years before year
    long long daysUntilYear(int year) const;

    // Number of leap years before year
    long long leapYearsBefore(int year) const;

    // Number of complete 33-year cycles before year
    long long cyclesBefore(int year) const;

    // Year position inside 33-year cycle
    int yearInCycle(int year) const;
};

}

#endif
