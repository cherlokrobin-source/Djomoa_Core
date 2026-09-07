#include <cassert>
#include <cstdint>
#include <iostream>

#include "GabaryDualCalendarEngine.h"
#include "GabaryNavigationEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Engine Contract Test\n"
        << "============================================\n";

    GabaryDualCalendarEngine engine;

    constexpr int64_t MIN_DAY =
        GabaryNavigationEngine::MIN_GLOBAL_DAY;

    constexpr int64_t MAX_DAY =
        GabaryNavigationEngine::MAX_GLOBAL_DAY;

    // ------------------------------------------------
    // EPOCH
    // ------------------------------------------------
    {
        DualCalendarDate date =
            engine.getDate(MIN_DAY);

        assert(date.dayId == MIN_DAY);

        assert(date.solar.solarYear == 1);
        assert(date.solar.solarMonth == 1);
        assert(date.solar.solarDay == 1);

        assert(date.lunar.year == 1);
        assert(date.lunar.month == 1);
        assert(date.lunar.day == 1);

        std::cout
            << "[PASS] Epoch dual-calendar coordinate\n";
    }

    // ------------------------------------------------
    // FINAL SOLAR BOUNDARY
    // ------------------------------------------------
    {
        DualCalendarDate date =
            engine.getDate(MAX_DAY);

        assert(date.dayId == MAX_DAY);

        assert(date.solar.solarYear == 50000);
        assert(date.solar.solarMonth == 12);
        assert(date.solar.solarDay == 31);

        std::cout
            << "[PASS] Final solar boundary\n";
    }

    // ------------------------------------------------
    // SOLAR -> GLOBAL DAY
    // ------------------------------------------------
    {
        int64_t dayId =
            engine.solarToDayId(2026, 7, 26);

        assert(dayId == 739823);

        DualCalendarDate date =
            engine.getDate(dayId);

        assert(date.dayId == 739823);
        assert(date.solar.solarYear == 2026);
        assert(date.solar.solarMonth == 7);
        assert(date.solar.solarDay == 26);

        std::cout
            << "[PASS] Solar to Global Solar Day\n";
    }

    // ------------------------------------------------
    // LUNAR -> GLOBAL DAY
    // ------------------------------------------------
    {
        int64_t dayId =
            engine.lunarToDayId(1, 1, 1);

        assert(dayId == MIN_DAY);

        DualCalendarDate date =
            engine.getDate(dayId);

        assert(date.dayId == MIN_DAY);
        assert(date.lunar.year == 1);
        assert(date.lunar.month == 1);
        assert(date.lunar.day == 1);

        std::cout
            << "[PASS] Lunar to Global Solar Day\n";
    }

    // ------------------------------------------------
    // SHARED GLOBAL COORDINATE
    // ------------------------------------------------
    {
        DualCalendarDate date =
            engine.getDate(739823);

        int64_t solarDay =
            engine.solarToDayId(
                date.solar.solarYear,
                date.solar.solarMonth,
                date.solar.solarDay
            );

        int64_t lunarDay =
            engine.lunarToDayId(
                date.lunar.year,
                date.lunar.month,
                date.lunar.day
            );

        assert(solarDay == 739823);
        assert(lunarDay == 739823);

        std::cout
            << "[PASS] Shared Global Solar Day coordinate\n";
    }

    // ------------------------------------------------
    // FINAL SOLAR ROUND-TRIP
    // ------------------------------------------------
    {
        DualCalendarDate date =
            engine.getDate(MAX_DAY);

        int64_t roundTrip =
            engine.solarToDayId(
                date.solar.solarYear,
                date.solar.solarMonth,
                date.solar.solarDay
            );

        assert(roundTrip == MAX_DAY);

        std::cout
            << "[PASS] Final solar round-trip\n";
    }

    // ------------------------------------------------
    // BOUNDARY CONSTANTS
    // ------------------------------------------------
    {
        assert(MIN_DAY == 1);
        assert(MAX_DAY == 18262125);
        assert(MAX_DAY > MIN_DAY);

        std::cout
            << "[PASS] Global Solar Day boundaries\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Engine Contract: PASSED\n"
        << "============================================\n";

    return 0;
}
