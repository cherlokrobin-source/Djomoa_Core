#include "ChronologyEngine.h"
#include <iostream>


int main()
{
    std::cout
    << "Golden Calendar 50000-Year Chronology EngineY 3M 3D Test\n"
    << "================================\n\n";


    ChronologyEngine engine;


    Chronology result =
        engine.getBySolar(2083,4,3);


    std::cout
    << "Day ID: "
    << result.dayId
    << "\n\n";


    std::cout
    << "Solar:\n"
    << result.solar.day
    << "/"
    << result.solar.month
    << "/"
    << result.solar.year
    << "\n\n";


    std::cout
    << "Lunar:\n"
    << result.lunar.day
    << "/"
    << result.lunar.month
    << "/"
    << result.lunar.year
    << "\n";


    return 0;
}
