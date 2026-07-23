#include "LongTimeEngine.h"
#include <iostream>


int main()
{
    std::cout
    << "Golden Calendar Long Time Engine Test\n"
    << "====================================\n\n";


    LongTimeEngine engine;


    int years[] =
    {
        2083,
        5000,
        10000,
        50000
    };


    for(int y : years)
    {
        Chronology c = engine.getYearStart(y);


        std::cout
        << "Year: "
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
        << "-----------------\n";
    }


    return 0;
}
