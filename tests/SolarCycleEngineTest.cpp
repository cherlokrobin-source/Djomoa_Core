#include "SolarCycleEngine.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarCycleEngine engine;

    auto cycle = engine.buildCycle(1);

    std::cout << "Cycle ID: "
              << cycle.cycleId
              << std::endl;

    std::cout << "Start Day ID: "
              << cycle.startDayId
              << std::endl;

    std::cout << "Total Days: "
              << cycle.totalDays
              << std::endl;

    if(cycle.totalDays > 0)
    {
        std::cout << "SolarCycleEngineTest PASSED"
                  << std::endl;
        return 0;
    }

    std::cout << "SolarCycleEngineTest FAILED"
              << std::endl;

    return 1;
}
