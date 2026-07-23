#include "ChronologyEngine.h"
#include <iostream>


int main()
{
    std::cout
    << "Golden Calendar Long Cycle Test\n"
    << "================================\n\n";


    ChronologyEngine engine;


    int years[] =
    {
        1,
        33,
        66,
        330,
        2083
    };


    for(int y : years)
    {

        Chronology c =
            engine.getBySolar(y,1,1);


        std::cout
        << "Solar Year: "
        << y
        << "\n";


        std::cout
        << "Day ID: "
        << c.dayId
        << "\n";


        std::cout
        << "Solar: "
        << c.solar.day
        << "/"
        << c.solar.month
        << "/"
        << c.solar.year
        << "\n";


        std::cout
        << "Lunar: "
        << c.lunar.day
        << "/"
        << c.lunar.month
        << "/"
        << c.lunar.year
        << "\n";


        std::cout
        << "----------------------\n";
    }


    return 0;
}
