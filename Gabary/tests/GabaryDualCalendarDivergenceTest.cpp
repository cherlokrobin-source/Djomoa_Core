#include <cassert>
#include <cstdint>
#include <iostream>

#include "GabaryDualCalendarEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Solar/Lunar Divergence Test\n"
        << "============================================\n";

    GabaryDualCalendarEngine engine;

    constexpr int64_t LUNAR_LAST_DAY = 17716312;
    constexpr int64_t FIRST_LUNAR_UNSUPPORTED_DAY = 17716313;
    constexpr int64_t SOLAR_LAST_DAY = 18261759;

    // ------------------------------------------------
    // 1. Last shared Solar/Lunar day
    // ------------------------------------------------
    {
        DualCalendarDate result =
            engine.getDate(LUNAR_LAST_DAY);

        assert(result.dayId == LUNAR_LAST_DAY);

        assert(result.solar.solarYear > 0);
        assert(result.solar.solarMonth > 0);
        assert(result.solar.solarDay > 0);

        assert(result.lunar.dayId == LUNAR_LAST_DAY);
        assert(result.lunar.year == 49999);
        assert(result.lunar.month == 12);
        assert(result.lunar.day == 29);

        std::cout
            << "[PASS] Last shared Solar/Lunar day\n";
    }

    // ------------------------------------------------
    // 2. First day after Lunar Timeline
    // ------------------------------------------------
    {
        DualCalendarDate result =
            engine.getDate(FIRST_LUNAR_UNSUPPORTED_DAY);

        assert(result.dayId == FIRST_LUNAR_UNSUPPORTED_DAY);

        // Solar timeline continues.
        assert(result.solar.solarYear > 0);
        assert(result.solar.solarMonth > 0);
        assert(result.solar.solarDay > 0);

        // Lunar timeline has ended.
        assert(result.lunar.dayId == 0);

        std::cout
            << "[PASS] Solar continues after Lunar boundary\n"
            << "[PASS] Lunar date is rejected after boundary\n";
    }

    // ------------------------------------------------
    // 3. Final Solar day
    // ------------------------------------------------
    {
        DualCalendarDate result =
            engine.getDate(SOLAR_LAST_DAY);

        assert(result.dayId == SOLAR_LAST_DAY);

        // Solar final boundary must remain valid.
        assert(result.solar.solarYear == 49999);
        assert(result.solar.solarMonth == 12);
        assert(result.solar.solarDay == 31);

        // Lunar timeline is already finished.
        assert(result.lunar.dayId == 0);

        std::cout
            << "[PASS] Final Solar day remains valid\n"
            << "[PASS] Lunar remains unsupported at Solar endpoint\n";
    }

    // ------------------------------------------------
    // Final result
    // ------------------------------------------------

    std::cout
        << "============================================\n"
        << " Gabary V2 Solar/Lunar Divergence: PASSED\n"
        << "============================================\n";

    return 0;
}
