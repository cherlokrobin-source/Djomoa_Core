#include <cassert>
#include <iostream>
#include <string>

#include "GabaryQueryEngine.h"
#include "GabaryDualReportFormatter.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Report Formatter Test\n"
        << "============================================\n";

    GabaryQueryEngine query;

    // ------------------------------------------------
    // Global Day 1
    // ------------------------------------------------
    {
        DualCalendarDate date = query.queryDay(1);

        std::string report =
            GabaryDualReportFormatter::createReport(date);

        assert(report.find("Global Day ID : 1") != std::string::npos);
        assert(report.find("SOLAR CALENDAR") != std::string::npos);
        assert(report.find("LUNAR CALENDAR") != std::string::npos);
        assert(report.find("TEMPORAL COORDINATE") != std::string::npos);

        std::cout
            << "[PASS] Global Day 1 dual report\n";
    }

    // ------------------------------------------------
    // Known Solar Coordinate
    // ------------------------------------------------
    {
        DualCalendarDate date =
            query.querySolar(2026, 7, 26);

        assert(date.dayId == 739823);

        std::string report =
            GabaryDualReportFormatter::createReport(date);

        assert(report.find("Global Day ID : 739823")
               != std::string::npos);

        assert(report.find("2026") != std::string::npos);
        assert(report.find("July") != std::string::npos);

        std::cout
            << "[PASS] Solar 2026-07-26 dual report\n";
    }

    // ------------------------------------------------
    // Shared Global Coordinate
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

        std::string report =
            GabaryDualReportFormatter::createReport(byDay);

        assert(report.find("Global Day ID : 739823")
               != std::string::npos);

        std::cout
            << "[PASS] Shared Global Day report coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Report Formatter: PASSED\n"
        << "============================================\n";

    return 0;
}
