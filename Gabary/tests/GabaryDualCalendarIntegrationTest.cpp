#include "SolarEngineV2.h"
#include "LunarEngineV2.h"

#include <cassert>
#include <cstdint>
#include <iostream>

int main()
{
    Gabary::SolarEngineV2 solar;
    Gabary::LunarEngineV2 lunar;

    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Integration Test\n"
        << "============================================\n\n";

    // --------------------------------------------------------
    // 1. Global Day 1 alignment
    // --------------------------------------------------------

    auto solarDay1 = solar.fromDayId(1);
    auto lunarDay1 = lunar.getDate(1);

    assert(solarDay1.year == 1);
    assert(solarDay1.month == 1);
    assert(solarDay1.day == 1);

    assert(lunarDay1.year == 1);
    assert(lunarDay1.month == 1);
    assert(lunarDay1.day == 1);

    assert(solar.toDayId(1, 1, 1) == 1);
    assert(lunar.getDayId(1, 1, 1) == 1);

    std::cout << "[PASS] Global Day 1 alignment\n";

    // --------------------------------------------------------
    // 2. Lunar 33-year cycle boundary
    // --------------------------------------------------------

    constexpr int64_t lunarCycleEnd = 11693;
    constexpr int64_t lunarCycleNext = 11694;

    auto lunarEnd = lunar.getDate(lunarCycleEnd);
    auto lunarNext = lunar.getDate(lunarCycleNext);

    assert(lunarEnd.year == 33);
    assert(lunarEnd.month == 12);
    assert(lunarEnd.day == 30);

    assert(lunarNext.year == 34);
    assert(lunarNext.month == 1);
    assert(lunarNext.day == 1);

    assert(
        lunar.getDayId(
            lunarEnd.year,
            lunarEnd.month,
            lunarEnd.day
        ) == lunarCycleEnd
    );

    assert(
        lunar.getDayId(
            lunarNext.year,
            lunarNext.month,
            lunarNext.day
        ) == lunarCycleNext
    );

    std::cout << "[PASS] Lunar cycle boundary alignment\n";

    // --------------------------------------------------------
    // 3. Solar/Lunar shared Global Day round-trip
    // --------------------------------------------------------

    const int64_t testDays[] =
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

    for (int64_t dayId : testDays)
    {
        auto solarDate = solar.fromDayId(dayId);
        auto lunarDate = lunar.getDate(dayId);

        int64_t solarRestored =
            solar.toDayId(
                solarDate.year,
                solarDate.month,
                solarDate.day
            );

        int64_t lunarRestored =
            lunar.getDayId(
                lunarDate.year,
                lunarDate.month,
                lunarDate.day
            );

        assert(solarRestored == dayId);
        assert(lunarRestored == dayId);
    }

    std::cout
        << "[PASS] Solar/Lunar shared Global Day round-trip\n";

    // --------------------------------------------------------
    // 4. Multiple lunar cycle starts mapped to solar timeline
    // --------------------------------------------------------

    for (int cycle = 0; cycle < 20; ++cycle)
    {
        int lunarYear = cycle * 33 + 1;

        int64_t globalDay =
            lunar.getDayId(lunarYear, 1, 1);

        auto lunarDate =
            lunar.getDate(globalDay);

        auto solarDate =
            solar.fromDayId(globalDay);

        assert(lunarDate.year == lunarYear);
        assert(lunarDate.month == 1);
        assert(lunarDate.day == 1);

        assert(
            solar.toDayId(
                solarDate.year,
                solarDate.month,
                solarDate.day
            ) == globalDay
        );
    }

    std::cout
        << "[PASS] 20 lunar cycle starts mapped to solar timeline\n";

    // --------------------------------------------------------
    // 5. Long-range shared coordinate validation
    // --------------------------------------------------------

    const int64_t longRangeDays[] =
    {
        100000,
        500000,
        1000000,
        2500000,
        5000000,
        7500000,
        10000000,
        15000000
    };

    for (int64_t dayId : longRangeDays)
    {
        auto solarDate = solar.fromDayId(dayId);
        auto lunarDate = lunar.getDate(dayId);

        assert(
            solar.toDayId(
                solarDate.year,
                solarDate.month,
                solarDate.day
            ) == dayId
        );

        assert(
            lunar.getDayId(
                lunarDate.year,
                lunarDate.month,
                lunarDate.day
            ) == dayId
        );
    }

    std::cout
        << "[PASS] Long-range Solar/Lunar coordinate validation\n";

    // --------------------------------------------------------
    // Final result
    // --------------------------------------------------------

    std::cout
        << "\n============================================\n"
        << " Gabary V2 Dual Calendar Integration: PASSED\n"
        << "============================================\n";

    return 0;
}
