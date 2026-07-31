#include <iostream>
#include "report/TemporalReportEngine.h"

int main()
{
    TemporalReportEngine engine;

    long long dayId = 739823;

    TemporalReport report =
        engine.generate(dayId);


    std::cout << "Temporal Report Test\n";
    std::cout << "====================\n";

    std::cout << "Day ID: "
              << report.dayId
              << "\n";

    std::cout << "Solar Year: "
              << report.solar.year
              << "\n";

    std::cout << "Solar Month: "
              << report.solar.month
              << "\n";

    std::cout << "Solar Day: "
              << report.solar.day
              << "\n";

    std::cout << "Week: "
              << report.weekName
              << "\n";

    std::cout << "Cycle: "
              << report.cycleNumber
              << "\n";

    std::cout << "Historical Index: "
              << report.historicalIndex
              << "\n";


    return 0;
}
