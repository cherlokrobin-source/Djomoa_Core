#include "ChronologyEngine.h"
#include <iostream>


int main()
{
    std::cout
    << "Golden Calendar Lunar Alignment Test\n"
    << "====================================\n\n";


    ChronologyEngine engine;


    Chronology result =
        engine.getBySolar(2083,4,3);


    std::cout
    << "Reference Solar Date:\n"
    << result.solar.day << "/"
    << result.solar.month << "/"
    << result.solar.year
    << "\n\n";


    std::cout
    << "Engine Lunar Date:\n"
    << result.lunar.day << "/"
    << result.lunar.month << "/"
    << result.lunar.year
    << "\n\n";


    std::cout
    << "Day ID: "
    << result.dayId
    << "\n\n";


    long long lunar30 =
        (2083 / 30) * 10631 +
        (2083 % 30) * 354;


    long long lunar33 =
        (2083 / 33) * 11693 +
        (2083 % 33) * 354;


    std::cout
    << "30 Cycle Total Lunar Days: "
    << lunar30
    << "\n";


    std::cout
    << "33 Cycle Total Lunar Days: "
    << lunar33
    << "\n\n";


    std::cout
    << "Difference From Engine Day ID:\n";


    std::cout
    << "30 Cycle: "
    << result.dayId - lunar30
    << " days\n";


    std::cout
    << "33 Cycle: "
    << result.dayId - lunar33
    << " days\n";


    return 0;
}
