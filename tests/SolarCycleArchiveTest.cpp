#include "../include/SolarCycleEngine.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarCycleEngine engine;

    auto cycle = engine.buildCycle(1);


    std::cout
    << "Days: "
    << cycle.totalDays
    << "\n";


    if(
       cycle.startYear == 1 &&
       cycle.endYear == 63 &&
       cycle.totalDays > 22900 &&
       cycle.totalDays < 23000
      )
    {
        std::cout<<"PASS\n";
        return 0;
    }


    std::cout<<"FAIL\n";
    return 1;
}
