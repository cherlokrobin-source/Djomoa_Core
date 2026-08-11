#include "GabaryDualCalendarEngine.h"

#include <cassert>
#include <cstdint>
#include <iostream>

int main()
{
    Gabary::GabaryDualCalendarEngine engine;

    std::cout
        << "============================================\n"
        << " Gabary Dual Calendar Engine Test\n"
        << "============================================\n\n";

    // --------------------------------------------------------
    // 1. Global Day 1
    // --------------------------------------------------------

    auto day1 = engine.getDate(1);

    assert(day1.dayId == 1);

    assert(day1.solar.solarYear == 1);
    assert(day1.solar.solarMonth == 1);
    assert(day1.solar.solarDay == 1);

    assert(day1.lunar.year == 1);
    assert(day1.lunar.month == 1);
    assert(day1.lunar.day == 1);

    std::cout << "[PASS] Global Day 1 dual mapping\n";

    // --------------------------------------------------------
    // 2. Solar round-trip
    // --------------------------------------------------------

    const int64_t solarDay =
        engine.solarToDayId(2026, 7, 26);

    auto solarMapped =
        engine.getDate(solarDay);

    assert(
        solarMapped.solar.solarYear == 2026
    );

    assert(
        solarMapped.solar.solarMonth == 7
    );

    assert(
        solarMapped.solar.solarDay == 26
    );

    assert(
        engine.solarToDayId(
            solarMapped.solar.solarYear,
            solarMapped.solar.solarMonth,
            solarMapped.solar.solarDay
        ) == solarDay
    );

    std::cout
        << "[PASS] Solar date round-trip\n";

    // --------------------------------------------------------
    // 3. Lunar cycle boundary
    // --------------------------------------------------------

    auto cycleEnd =
        engine.getDate(11693);

    assert(cycleEnd.dayId == 11693);

    assert(cycleEnd.lunar.year == 33);
    assert(cycleEnd.lunar.month == 12);
    assert(cycleEnd.lunar.day == 30);

    assert(
        engine.lunarToDayId(
            33,
            12,
            30
        ) == 11693
    );

    std::cout
        << "[PASS] Lunar 33-year cycle boundary\n";

    // --------------------------------------------------------
    // 4. Shared Global Day coordinate
    // --------------------------------------------------------

    const int64_t testDays[] =
    {
        1,
        354,
        355,
        11693,
        11694,
        100000,
        1000000,
        5000000
    };

    for (int64_t dayId : testDays)
    {
        auto result =
            engine.getDate(dayId);

        assert(result.dayId == dayId);
        assert(result.solar.dayId == dayId);
        assert(result.lunar.dayId == dayId);
    }

    std::cout
        << "[PASS] Shared Global Day coordinate\n";

    // --------------------------------------------------------
    // 5. Long-range dual mapping
    // --------------------------------------------------------

    const int64_t longRangeDays[] =
    {
        100000,
        1000000,
        5000000,
        10000000,
        15000000
    };

    for (int64_t dayId : longRangeDays)
    {
        auto result =
            engine.getDate(dayId);

        assert(result.dayId == dayId);

        assert(
            engine.solarToDayId(
                result.solar.solarYear,
                result.solar.solarMonth,
                result.solar.solarDay
            ) == dayId
        );

        assert(
            engine.lunarToDayId(
                result.lunar.year,
                result.lunar.month,
                result.lunar.day
            ) == dayId
        );
    }

    std::cout
        << "[PASS] Long-range dual mapping\n";

    // --------------------------------------------------------
    // Final result
    // --------------------------------------------------------

    std::cout
        << "\n============================================\n"
        << " Gabary Dual Calendar Engine: PASSED\n"
        << "============================================\n";

    return 0;
}
