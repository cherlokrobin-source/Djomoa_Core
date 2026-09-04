#include "GabaryNavigationEngine.h"

#include <cassert>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Boundary Date Test\n"
        << "============================================\n";

    GabaryNavigationEngine engine;

    const int64_t MIN =
        GabaryNavigationEngine::MIN_GLOBAL_DAY;

    const int64_t MAX =
        GabaryNavigationEngine::MAX_GLOBAL_DAY;

    // ------------------------------------------------
    // 1. Solar epoch
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.jumpToSolarDate(1, 1, 1);

        assert(dayId == MIN);

        auto date = engine.getDate(dayId);

        assert(date.dayId == MIN);
        assert(date.solar.solarYear == 1);
        assert(date.solar.solarMonth == 1);
        assert(date.solar.solarDay == 1);

        std::cout
            << "[PASS] Solar epoch boundary\n";
    }

    // ------------------------------------------------
    // 2. Solar final day
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.jumpToSolarDate(49999, 12, 31);

        assert(dayId == MAX);

        auto date = engine.getDate(dayId);

        assert(date.dayId == MAX);
        assert(date.solar.solarYear == 49999);
        assert(date.solar.solarMonth == 12);
        assert(date.solar.solarDay == 31);

        std::cout
            << "[PASS] Solar final boundary\n";
    }

    // ------------------------------------------------
    // 3. Solar first-day navigation
    // ------------------------------------------------
    {
        auto next = engine.nextDay(MIN);

        assert(next.dayId == MIN + 1);

        auto previous = engine.previousDay(next.dayId);

        assert(previous.dayId == MIN);

        std::cout
            << "[PASS] Solar epoch navigation boundary\n";
    }

    // ------------------------------------------------
    // 4. Solar final-day navigation
    // ------------------------------------------------
    {
        auto previous = engine.previousDay(MAX);

        assert(previous.dayId == MAX - 1);

        auto next = engine.nextDay(previous.dayId);

        assert(next.dayId == MAX);

        std::cout
            << "[PASS] Solar final navigation boundary\n";
    }

    // ------------------------------------------------
    // 5. Lunar epoch
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.jumpToLunarDate(1, 1, 1);

        assert(dayId == MIN);

        auto date = engine.getDate(dayId);

        assert(date.dayId == MIN);
        assert(date.lunar.year == 1);
        assert(date.lunar.month == 1);
        assert(date.lunar.day == 1);

        std::cout
            << "[PASS] Lunar epoch boundary\n";
    }

    // ------------------------------------------------
    // 6. Lunar final supported date
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.jumpToLunarDate(49999, 12, 29);

        assert(dayId >= MIN);
        assert(dayId <= MAX);

        auto date = engine.getDate(dayId);

        assert(date.dayId == dayId);
        assert(date.lunar.year == 49999);
        assert(date.lunar.month == 12);
        assert(date.lunar.day == 29);

        std::cout
            << "[PASS] Lunar final supported boundary\n";
    }

    // ------------------------------------------------
    // 7. Shared coordinate at solar epoch
    // ------------------------------------------------
    {
        auto date = engine.getDate(MIN);

        const int64_t lunarDayId =
            engine.jumpToLunarDate(
                date.lunar.year,
                date.lunar.month,
                date.lunar.day
            );

        assert(lunarDayId == MIN);

        std::cout
            << "[PASS] Epoch shared coordinate\n";
    }

    // ------------------------------------------------
    // 8. Final solar day has no lunar mapping
    // ------------------------------------------------
    {
        auto date = engine.getDate(MAX);

        assert(date.dayId == MAX);

        assert(date.solar.solarYear == 49999);
        assert(date.solar.solarMonth == 12);
        assert(date.solar.solarDay == 31);

        // Lunar timeline ended earlier at Global Day 17716312.
        // Therefore Solar MAX has no supported lunar date.
        assert(date.lunar.year == 0);
        assert(date.lunar.month == 0);
        assert(date.lunar.day == 0);

        const int64_t lunarDayId =
            engine.jumpToLunarDate(
                date.lunar.year,
                date.lunar.month,
                date.lunar.day
            );

        assert(lunarDayId == -1);

        std::cout
            << "[PASS] Final solar boundary has no lunar mapping\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Boundary Date: PASSED\n"
        << "============================================\n";

    return 0;
}
