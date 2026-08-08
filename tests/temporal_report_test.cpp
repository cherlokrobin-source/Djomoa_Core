#include <iostream>
#include "report/TemporalReportEngine.h"

int main()
{
    TemporalReportEngine engine;

    const long long dayId = 739823;

    TemporalReport report =
        engine.generate(dayId);

    std::cout << "Temporal Report Validation Test\n";
    std::cout << "================================\n";

    std::cout << "Day ID: "
              << report.dayId << "\n";

    std::cout << "Solar: "
              << report.solar.day << "/"
              << report.solar.month << "/"
              << report.solar.year << "\n";

    std::cout << "Week: "
              << report.weekName << "\n";

    std::cout << "Cycle: "
              << report.cycleNumber << "\n";

    std::cout << "Historical Index: "
              << report.historicalIndex << "\n";


    // ============================================
    // Validation
    // ============================================

    if (report.dayId != 739823)
        return 1;

    if (report.solar.year != 2026)
        return 1;

    if (report.solar.month != 7)
        return 1;

    if (report.solar.day != 26)
        return 1;

    if (report.weekName != "Thursday")
        return 1;

    if (report.cycleNumber != 62)
        return 1;

    if (report.historicalIndex != 739823)
        return 1;


    std::cout << "\nTemporal Report Validation SUCCESS\n";

    return 0;
}
