#include <cassert>
#include <cstdint>
#include <iostream>

#include "GabaryDualCalendarEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Boundary Test\n"
        << "============================================\n";

    GabaryDualCalendarEngine engine;

    // ------------------------------------------------
    // Global Day 1
    // ------------------------------------------------
    {
        DualCalendarDate result = engine.getDate(1);

        assert(result.dayId == 1);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Global Day 1 boundary\n";
    }

    // ------------------------------------------------
    // Solar -> Global Day -> Dual Calendar
    // ------------------------------------------------
    {
        const int64_t dayId = engine.solarToDayId(1, 1, 1);

        assert(dayId == 1);

        DualCalendarDate result = engine.getDate(dayId);

        assert(result.dayId == 1);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);

        std::cout << "[PASS] Solar epoch round-trip\n";
    }

    // ------------------------------------------------
    // Lunar -> Global Day -> Dual Calendar
    // ------------------------------------------------
    {
        const int64_t dayId = engine.lunarToDayId(1, 1, 1);

        assert(dayId == 1);

        DualCalendarDate result = engine.getDate(dayId);

        assert(result.dayId == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Lunar epoch round-trip\n";
    }

    // ------------------------------------------------
    // Known Solar Coordinate
    // ------------------------------------------------
    {
        const int64_t dayId =
            engine.solarToDayId(2026, 7, 26);

        assert(dayId == 739823);

        DualCalendarDate result = engine.getDate(dayId);

        assert(result.dayId == 739823);
        assert(result.solar.solarYear == 2026);
        assert(result.solar.solarMonth == 7);
        assert(result.solar.solarDay == 26);

        std::cout << "[PASS] Known Solar boundary coordinate\n";
    }

    // ------------------------------------------------
    // Shared Global Coordinate
    // ------------------------------------------------
    {
        const int64_t solarDay =
            engine.solarToDayId(2026, 7, 26);

        DualCalendarDate byDay =
            engine.getDate(solarDay);

        assert(byDay.dayId == solarDay);

        const int64_t lunarDay =
            engine.lunarToDayId(
                byDay.lunar.year,
                byDay.lunar.month,
                byDay.lunar.day
            );

        assert(lunarDay == solarDay);

        std::cout
            << "[PASS] Solar/Lunar shared Global Day coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Boundary: PASSED\n"
        << "============================================\n";

    return 0;
}
