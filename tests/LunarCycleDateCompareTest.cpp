#include "ChronologyEngine.h"
#include <iostream>


int main()
{
    std::cout
    << "Golden Calendar Lunar Cycle Date Compare\n"
    << "========================================\n\n";


    ChronologyEngine engine;


    Chronology ref =
        engine.getBySolar(2083,4,3);


    std::cout
    << "Reference Solar Date:\n"
    << ref.solar.day << "/"
    << ref.solar.month << "/"
    << ref.solar.year
    << "\n\n";


    std::cout
    << "Engine Lunar Result:\n"
    << ref.lunar.day << "/"
    << ref.lunar.month << "/"
    << ref.lunar.year
    << "\n\n";


    std::cout
    << "Day ID: "
    << ref.dayId
    << "\n\n";


    std::cout
    << "Cycle 30:\n";
    
    int lunarYear30 = 1 + (ref.dayId / 354);

    std::cout
    << "Approx Lunar Year: "
    << lunarYear30
    << "\n";


    std::cout
    << "Cycle 33:\n";

    int lunarYear33 = 1 + (ref.dayId / 354);

    std::cout
    << "Approx Lunar Year: "
    << lunarYear33
    << "\n";


    std::cout
    << "\nFinal Engine Reference:\n"
    << "Solar 2083 + 3M + 3D\n"
    << "Lunar "
    << ref.lunar.day << "/"
    << ref.lunar.month << "/"
    << ref.lunar.year
    << "\n";


    return 0;
}
