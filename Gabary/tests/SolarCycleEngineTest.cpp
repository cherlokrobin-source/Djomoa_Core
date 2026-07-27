#include "../include/SolarCycleEngine.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarCycleEngine engine;

    SolarCycle cycle = engine.buildCycle(1);


    std::cout << "Cycle ID: "
              << cycle.cycleId
              << "\n";

    std::cout << "Years: "
              << cycle.startYear
              << " - "
              << cycle.endYear
              << "\n";


    if(cycle.cycleId == 1 &&
       cycle.startYear == 1 &&
       cycle.endYear == 63 &&
       cycle.startDayId == 1)
    {
        std::cout << "PASS\n";
        return 0;
    }


    std::cout << "FAIL\n";
    return 1;
}
