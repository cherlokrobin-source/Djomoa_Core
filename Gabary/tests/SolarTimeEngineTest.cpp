#include "../include/SolarTimeEngine.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimeEngine engine;

    engine.loadCycles(1, 10);

    if(engine.size() == 0)
    {
        std::cerr << "Engine build failed\n";
        return 1;
    }

    GlobalSolarDay day =
        engine.getDay(1);

    if(day.dayId != 1)
    {
        std::cerr << "Invalid first day\n";
        return 1;
    }

    std::cout << "SolarTimeEngine OK\n";
    std::cout << "Days: "
              << engine.size()
              << "\n";

    return 0;
}
