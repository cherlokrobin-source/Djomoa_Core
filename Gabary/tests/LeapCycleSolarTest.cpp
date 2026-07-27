#include "../include/SolarEngineV2.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    std::cout << "Leap Cycle Solar Test\n";
    std::cout << "=====================\n";

    auto feb29 = engine.buildDay(1155);

    std::cout << "Day ID: " << feb29.dayId << "\n";
    std::cout << "Date: "
              << feb29.solarDay << "/"
              << feb29.solarMonth << "/"
              << feb29.solarYear << "\n";


    if(feb29.solarYear == 4 &&
       feb29.solarMonth == 2 &&
       feb29.solarDay == 29 &&
       feb29.leapYear == true)
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
