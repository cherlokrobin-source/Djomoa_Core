#include "../Gabary/include/SolarCycleEngine.h"

#include <iostream>
#include <cassert>

using namespace Gabary;

int main()
{
    SolarCycleEngine engine;

    SolarCycle cycle1 =
        engine.buildCycle(1);

    SolarCycle cycle2 =
        engine.buildCycle(2);


    long long cycle1End =
        cycle1.startDayId +
        cycle1.totalDays -
        1;


    long long cycle2Start =
        cycle2.startDayId;


    std::cout
        << "Cycle 1 End Day ID: "
        << cycle1End
        << std::endl;


    std::cout
        << "Cycle 2 Start Day ID: "
        << cycle2Start
        << std::endl;


    assert(
        cycle2Start == cycle1End + 1
    );


    std::cout
        << "SolarCycleBoundaryTest Passed"
        << std::endl;


    return 0;
}
