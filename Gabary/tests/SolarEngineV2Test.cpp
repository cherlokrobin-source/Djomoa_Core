#include "../include/SolarEngineV2.h"
#include <iostream>

using namespace Gabary;


int main()
{
    std::cout
    << "Gabary Solar Engine V2 Test\n";
    std::cout
    << "===========================\n\n";


    SolarEngineV2 engine;


    auto test1 = engine.fromDayId(1);

    std::cout
    << "Day 1: "
    << test1.day << "/"
    << test1.month << "/"
    << test1.year
    << "\n";


    if(test1.year != 1 ||
       test1.month != 1 ||
       test1.day != 1)
    {
        std::cout << "FAIL Day 1\n";
        return 1;
    }



    auto test2 = engine.fromDayId(365);

    std::cout
    << "Day 365: "
    << test2.day << "/"
    << test2.month << "/"
    << test2.year
    << "\n";


    if(test2.year != 1 ||
       test2.month != 12 ||
       test2.day != 31)
    {
        std::cout << "FAIL Day 365\n";
        return 1;
    }



    auto test3 = engine.fromDayId(366);

    std::cout
    << "Day 366: "
    << test3.day << "/"
    << test3.month << "/"
    << test3.year
    << "\n";


    if(test3.year != 2 ||
       test3.month != 1 ||
       test3.day != 1)
    {
        std::cout << "FAIL Day 366\n";
        return 1;
    }



    auto leap =
        engine.fromDayId(
            engine.toDayId(4,2,29)
        );


    std::cout
    << "Leap date: "
    << leap.day << "/"
    << leap.month << "/"
    << leap.year
    << "\n";


    if(!leap.leapYear ||
       leap.year != 4 ||
       leap.month != 2 ||
       leap.day != 29)
    {
        std::cout << "FAIL Leap Year\n";
        return 1;
    }



    std::cout
    << "\nSolar Engine V2 Validation PASSED\n";


    return 0;
}
