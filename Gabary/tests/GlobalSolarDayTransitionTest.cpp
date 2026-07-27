#include "../include/SolarEngineV2.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    std::cout << "GlobalSolarDay Transition Test\n";
    std::cout << "==============================\n";

    auto day365 = engine.buildDay(365);

    std::cout << "Day 365: "
              << day365.solarDay << "/"
              << day365.solarMonth << "/"
              << day365.solarYear
              << "\n";


    auto day366 = engine.buildDay(366);

    std::cout << "Day 366: "
              << day366.solarDay << "/"
              << day366.solarMonth << "/"
              << day366.solarYear
              << "\n";


    if(day365.solarYear == 1 &&
       day365.solarMonth == 12 &&
       day365.solarDay == 31 &&
       day366.solarYear == 2 &&
       day366.solarMonth == 1 &&
       day366.solarDay == 1)
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
