#include <cassert>
#include <iostream>

#include "GabaryQueryEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Query Engine Test\n"
        << "============================================\n";

    GabaryQueryEngine query;

    // ------------------------------------------------
    // Query by Global Day
    // ------------------------------------------------
    {
        DualCalendarDate result = query.queryDay(1);

        assert(result.dayId == 1);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Query by Global Day 1\n";
    }

    // ------------------------------------------------
    // Solar Date -> Global Day -> Dual Calendar
    // ------------------------------------------------
    {
        DualCalendarDate result =
            query.querySolar(1, 1, 1);

        assert(result.dayId == 1);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);

        std::cout
            << "[PASS] Solar Date -> Global Day -> Dual Calendar\n";
    }

    // ------------------------------------------------
    // Solar Date Round Trip
    // ------------------------------------------------
    {
        DualCalendarDate result =
            query.querySolar(2026, 7, 26);

        assert(result.dayId == 739823);
        assert(result.solar.solarYear == 2026);
        assert(result.solar.solarMonth == 7);
        assert(result.solar.solarDay == 26);

        std::cout
            << "[PASS] Solar Query Round-Trip\n";
    }

    // ------------------------------------------------
    // Lunar Date -> Global Day -> Dual Calendar
    // ------------------------------------------------
    {
        DualCalendarDate result =
            query.queryLunar(1, 1, 1);

        assert(result.dayId == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout
            << "[PASS] Lunar Date -> Global Day -> Dual Calendar\n";
    }

    // ------------------------------------------------
    // Shared Global Day Coordinate
    // ------------------------------------------------
    {
        DualCalendarDate solar =
            query.querySolar(2026, 7, 26);

        DualCalendarDate byDay =
            query.queryDay(solar.dayId);

        assert(byDay.dayId == solar.dayId);
        assert(byDay.solar.solarYear ==
               solar.solar.solarYear);
        assert(byDay.solar.solarMonth ==
               solar.solar.solarMonth);
        assert(byDay.solar.solarDay ==
               solar.solar.solarDay);

        std::cout
            << "[PASS] Shared Global Day Coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Query Engine: PASSED\n"
        << "============================================\n";

    return 0;
}
