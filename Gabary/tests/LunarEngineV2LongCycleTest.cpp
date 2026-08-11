#include "LunarEngineV2.h"

#include <cassert>
#include <iostream>

int main()
{
    Gabary::LunarEngineV2 lunar;

    std::cout
        << "========================================\n"
        << " Gabary LunarEngineV2 Long Cycle Test\n"
        << "========================================\n\n";

    // --------------------------------------------------------
    // 1. Verify the fundamental 33-year cycle
    // --------------------------------------------------------

    assert(Gabary::LunarEngineV2::CYCLE_YEARS == 33);
    assert(Gabary::LunarEngineV2::CYCLE_DAYS == 11693);
    assert(Gabary::LunarEngineV2::LEAP_YEARS_PER_CYCLE == 11);

    std::cout << "[PASS] 33-year cycle constants\n";

    // --------------------------------------------------------
    // 2. Verify all leap years in the first cycle
    // --------------------------------------------------------

    const int expectedLeapYears[] =
    {
        3, 6, 9, 11, 14, 17,
        20, 22, 25, 28, 31
    };

    for (int year = 1; year <= 33; ++year)
    {
        bool expected = false;

        for (int leapYear : expectedLeapYears)
        {
            if (year == leapYear)
            {
                expected = true;
                break;
            }
        }

        assert(lunar.isLeap(year) == expected);
    }

    std::cout
        << "[PASS] All leap years in cycle 1\n";

    // --------------------------------------------------------
    // 3. Verify every 33-year cycle has exactly 11693 days
    // --------------------------------------------------------

    for (int cycle = 0; cycle < 10; ++cycle)
    {
        const int firstYear =
            cycle * 33 + 1;

        const int nextYear =
            firstYear + 33;

        const long long firstDay =
            lunar.getDayId(firstYear, 1, 1);

        const long long nextDay =
            lunar.getDayId(nextYear, 1, 1);

        assert(nextDay - firstDay == 11693);
    }

    std::cout
        << "[PASS] First 10 lunar cycles = 11693 days each\n";

    // --------------------------------------------------------
    // 4. Verify cycle boundaries
    // --------------------------------------------------------

    for (int cycle = 0; cycle < 10; ++cycle)
    {
        const int lastYear =
            cycle * 33 + 33;

        const int nextYear =
            lastYear + 1;

        const long long endDay =
            lunar.getDayId(lastYear, 12, 30);

        const long long nextDay =
            lunar.getDayId(nextYear, 1, 1);

        assert(endDay + 1 == nextDay);
    }

    std::cout
        << "[PASS] Cycle boundaries are contiguous\n";

    // --------------------------------------------------------
    // 5. Global Day -> Lunar Date -> Global Day
    // --------------------------------------------------------

    const long long testDays[] =
    {
        1,
        354,
        355,
        11693,
        11694,
        23386,
        35079,
        46772,
        100000,
        1000000,
        5000000
    };

    for (long long day : testDays)
    {
        Date lunarDate =
            lunar.getDate(day);

        long long restored =
            lunar.getDayId(
                lunarDate.year,
                lunarDate.month,
                lunarDate.day
            );

        assert(restored == day);
    }

    std::cout
        << "[PASS] Global Day -> Lunar Date -> Global Day\n";

    // --------------------------------------------------------
    // 6. Reverse conversion across multiple cycles
    // --------------------------------------------------------

    for (int cycle = 0; cycle < 20; ++cycle)
    {
        const int year =
            cycle * 33 + 1;

        const long long day =
            lunar.getDayId(year, 1, 1);

        Date date =
            lunar.getDate(day);

        assert(date.year == year);
        assert(date.month == 1);
        assert(date.day == 1);
    }

    std::cout
        << "[PASS] Cycle-start reverse conversion\n";

    // --------------------------------------------------------
    // 7. Verify leap-year 30th Dhul-Hijjah
    // --------------------------------------------------------

    for (int year : expectedLeapYears)
    {
        assert(
            lunar.getDayId(year, 12, 30) > 0
        );
    }

    std::cout
        << "[PASS] Leap years accept 30 Dhul-Hijjah\n";

    // --------------------------------------------------------
    // 8. Verify normal years reject 30 Dhul-Hijjah
    // --------------------------------------------------------

    for (int year = 1; year <= 33; ++year)
    {
        if (!lunar.isLeap(year))
        {
            assert(
                lunar.getDayId(year, 12, 30) == -1
            );
        }
    }

    std::cout
        << "[PASS] Normal years reject 30 Dhul-Hijjah\n";

    // --------------------------------------------------------
    // Final result
    // --------------------------------------------------------

    std::cout
        << "\n========================================\n"
        << " LunarEngineV2 Long Cycle Test: PASSED\n"
        << "========================================\n";

    return 0;
}
