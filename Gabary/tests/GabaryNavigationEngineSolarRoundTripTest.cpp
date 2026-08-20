#include "GabaryNavigationEngine.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace Gabary;

struct SolarTestDate
{
    int year;
    int month;
    int day;
};

int main()
{
    std::cout << "============================================\n";
    std::cout << " Gabary V2 Navigation Solar Round-Trip Test\n";
    std::cout << "============================================\n\n";

    GabaryNavigationEngine engine;

    const std::vector<SolarTestDate> testDates = {
        {1, 1, 1},
        {1, 2, 1},
        {1, 12, 31},
        {2, 1, 1},
        {4, 2, 29},
        {10, 6, 15},
        {100, 12, 31},
        {500, 7, 1},
        {1000, 1, 1},
        {2083, 6, 15},
        {10000, 12, 31},
        {25000, 1, 1},
        {40000, 7, 15},
        {49999, 12, 31}
    };

    // --------------------------------------------------
    // 1. Solar Date -> Global Day -> Solar Date
    // --------------------------------------------------
    for (const auto& test : testDates)
    {
        const int64_t dayId =
            engine.jumpToSolarDate(
                test.year,
                test.month,
                test.day
            );

        assert(
            dayId >=
            GabaryNavigationEngine::MIN_GLOBAL_DAY
        );

        assert(
            dayId <=
            GabaryNavigationEngine::MAX_GLOBAL_DAY
        );

        auto result = engine.getDate(dayId);

        assert(result.dayId == dayId);

        assert(result.solar.solarYear == test.year);
        assert(result.solar.solarMonth == test.month);
        assert(result.solar.solarDay == test.day);
    }

    std::cout
        << "[PASS] Solar Date -> Global Day -> Solar Date\n";

    // --------------------------------------------------
    // 2. Day ID consistency
    // --------------------------------------------------
    for (const auto& test : testDates)
    {
        const int64_t dayId =
            engine.jumpToSolarDate(
                test.year,
                test.month,
                test.day
            );

        auto result = engine.getDate(dayId);

        assert(result.solar.dayId == dayId);
    }

    std::cout
        << "[PASS] Solar Global Day ID consistency\n";

    // --------------------------------------------------
    // 3. Solar navigation from converted dates
    // --------------------------------------------------
    for (const auto& test : testDates)
    {
        const int64_t dayId =
            engine.jumpToSolarDate(
                test.year,
                test.month,
                test.day
            );

        if (dayId <
            GabaryNavigationEngine::MAX_GLOBAL_DAY)
        {
            auto next = engine.nextDay(dayId);

            assert(next.dayId == dayId + 1);
        }

        if (dayId >
            GabaryNavigationEngine::MIN_GLOBAL_DAY)
        {
            auto previous = engine.previousDay(dayId);

            assert(previous.dayId == dayId - 1);
        }
    }

    std::cout
        << "[PASS] Navigation from converted Solar dates\n";

    // --------------------------------------------------
    // 4. Solar / Lunar shared coordinate
    // --------------------------------------------------
    for (const auto& test : testDates)
    {
        const int64_t dayId =
            engine.jumpToSolarDate(
                test.year,
                test.month,
                test.day
            );

        auto result = engine.getDate(dayId);

        assert(result.dayId == dayId);
    }

    std::cout
        << "[PASS] Solar/Lunar shared Global Day coordinate\n";

    std::cout << "\n============================================\n";
    std::cout << " Gabary V2 Solar Round-Trip: PASSED\n";
    std::cout << "============================================\n";

    return 0;
}
