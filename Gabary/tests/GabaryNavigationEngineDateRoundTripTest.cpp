#include "GabaryNavigationEngine.h"

#include <cassert>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Date Round-Trip Test\n"
        << "============================================\n";

    GabaryNavigationEngine engine;

    // ------------------------------------------------
    // 1. Solar date -> Global Day -> Solar date
    // ------------------------------------------------
    {
        struct SolarCase
        {
            int year;
            int month;
            int day;
        };

        const SolarCase cases[] = {
            {1, 1, 1},
            {1, 12, 31},
            {2, 1, 1},
            {100, 6, 15},
            {1000, 3, 20},
            {2026, 7, 26},
            {10000, 1, 1},
            {25000, 6, 30},
            {49999, 12, 31}
        };

        for (const auto& c : cases)
        {
            const int64_t dayId =
                engine.jumpToSolarDate(c.year, c.month, c.day);

            assert(dayId >=
                   GabaryNavigationEngine::MIN_GLOBAL_DAY);

            assert(dayId <=
                   GabaryNavigationEngine::MAX_GLOBAL_DAY);

            auto result = engine.getDate(dayId);

            assert(result.solar.solarYear == c.year);
            assert(result.solar.solarMonth == c.month);
            assert(result.solar.solarDay == c.day);
        }

        std::cout
            << "[PASS] Solar date round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 2. Lunar date -> Global Day -> Lunar date
    // ------------------------------------------------
    {
        struct LunarCase
        {
            int year;
            int month;
            int day;
        };

        const LunarCase cases[] = {
            {1, 1, 1},
            {1, 12, 29},
            {100, 1, 1},
            {1000, 6, 15},
            {10000, 1, 1},
            {25000, 6, 15},
            {49999, 12, 29}
        };

        for (const auto& c : cases)
        {
            const int64_t dayId =
                engine.jumpToLunarDate(c.year, c.month, c.day);

            assert(dayId >=
                   GabaryNavigationEngine::MIN_GLOBAL_DAY);

            assert(dayId <=
                   GabaryNavigationEngine::MAX_GLOBAL_DAY);

            auto result = engine.getDate(dayId);

            assert(result.lunar.year == c.year);
            assert(result.lunar.month == c.month);
            assert(result.lunar.day == c.day);
        }

        std::cout
            << "[PASS] Lunar date round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 3. Solar/Lunar shared Global Day integrity
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.jumpToSolarDate(2026, 7, 26);

        auto result = engine.getDate(dayId);

        assert(result.dayId == dayId);

        const int64_t lunarDayId =
            engine.jumpToLunarDate(
                result.lunar.year,
                result.lunar.month,
                result.lunar.day
            );

        assert(lunarDayId == dayId);

        std::cout
            << "[PASS] Solar/Lunar shared coordinate integrity\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Date Round-Trip: PASSED\n"
        << "============================================\n";

    return 0;
}
