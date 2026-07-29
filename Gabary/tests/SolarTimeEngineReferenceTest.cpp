#include "../include/SolarTimeEngine.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimeEngine engine;

    engine.loadCycles(1, 1);

    if(engine.size() <= 0)
    {
        std::cerr << "Archive is empty\n";
        return 1;
    }

    GlobalSolarDay firstDay =
        engine.getDay(1);

    if(firstDay.dayId != 1)
    {
        std::cerr << "Invalid first Solar Day ID\n";
        return 1;
    }

    std::cout << "SolarTimeEngine Reference OK\n";
    std::cout << "First Day ID: "
              << firstDay.dayId
              << "\n";

    return 0;
}
