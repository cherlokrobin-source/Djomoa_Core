#include "../include/SolarEngineV2.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    GlobalSolarDay day = engine.buildDay(1);

    std::cout << "GlobalSolarDay Test\n";
    std::cout << "===================\n";

    std::cout << "Day ID: " << day.dayId << "\n";
    std::cout << "Date: "
              << day.solarDay << "/"
              << day.solarMonth << "/"
              << day.solarYear << "\n";
    std::cout << "Week: "
              << day.weekName << "\n";

    if(day.dayId == 1 &&
       day.solarYear == 1 &&
       day.solarMonth == 1 &&
       day.solarDay == 1 &&
       day.weekName == "Friday")
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
