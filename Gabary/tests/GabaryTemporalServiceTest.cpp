#include <cassert>
#include <iostream>
#include <string>

#include "GabaryTemporalService.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service Test\n"
        << "============================================\n";

    GabaryTemporalService service;

    // ------------------------------------------------
    // Query by Global Day
    // ------------------------------------------------
    {
        DualCalendarDate result = service.queryDay(1);

        assert(result.dayId == 1);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);

        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Service query by Global Day\n";
    }

    // ------------------------------------------------
    // Query by Solar Date
    // ------------------------------------------------
    {
        DualCalendarDate result =
            service.querySolar(2026, 7, 26);

        assert(result.dayId == 739823);
        assert(result.solar.solarYear == 2026);
        assert(result.solar.solarMonth == 7);
        assert(result.solar.solarDay == 26);

        std::cout << "[PASS] Service query by Solar Date\n";
    }

    // ------------------------------------------------
    // Global Day Round Trip
    // ------------------------------------------------
    {
        DualCalendarDate solar =
            service.querySolar(2026, 7, 26);

        DualCalendarDate byDay =
            service.queryDay(solar.dayId);

        assert(byDay.dayId == 739823);

        assert(
            byDay.solar.solarYear ==
            solar.solar.solarYear
        );

        assert(
            byDay.solar.solarMonth ==
            solar.solar.solarMonth
        );

        assert(
            byDay.solar.solarDay ==
            solar.solar.solarDay
        );

        assert(
            byDay.lunar.year ==
            solar.lunar.year
        );

        assert(
            byDay.lunar.month ==
            solar.lunar.month
        );

        assert(
            byDay.lunar.day ==
            solar.lunar.day
        );

        std::cout
            << "[PASS] Service Global Day Round-Trip\n";
    }

    // ------------------------------------------------
    // Query by Lunar Date
    // ------------------------------------------------
    {
        DualCalendarDate result =
            service.queryLunar(1, 1, 1);

        assert(result.dayId == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Service query by Lunar Date\n";
    }

    // ------------------------------------------------
    // Report by Global Day
    // ------------------------------------------------
    {
        std::string report =
            service.reportByDay(739823);

        assert(!report.empty());
        assert(report.find("GABARY V2 DUAL CALENDAR")
               != std::string::npos);
        assert(report.find("Global Day ID : 739823")
               != std::string::npos);
        assert(report.find("SOLAR CALENDAR")
               != std::string::npos);
        assert(report.find("LUNAR CALENDAR")
               != std::string::npos);
        assert(report.find("TEMPORAL COORDINATE")
               != std::string::npos);

        std::cout << "[PASS] Service report by Global Day\n";
    }

    // ------------------------------------------------
    // Report by Solar Date
    // ------------------------------------------------
    {
        std::string report =
            service.reportBySolar(2026, 7, 26);

        assert(!report.empty());
        assert(report.find("Global Day ID : 739823")
               != std::string::npos);
        assert(report.find("2026")
               != std::string::npos);

        std::cout << "[PASS] Service report by Solar Date\n";
    }

    // ------------------------------------------------
    // Report by Lunar Date
    // ------------------------------------------------
    {
        std::string report =
            service.reportByLunar(1, 1, 1);

        assert(!report.empty());
        assert(report.find("Global Day ID : 1")
               != std::string::npos);

        std::cout << "[PASS] Service report by Lunar Date\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service: PASSED\n"
        << "============================================\n";

    return 0;
}
