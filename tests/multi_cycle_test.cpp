#include "../include/LunarEngine.h"
#include "../include/SolarEngine.h"
#include "../include/Names.h"

#include <iostream>


int main()
{

    LunarEngine lunar;
    SolarEngine solar;


    std::cout
    << "Golden Calendar - Multi 33 Year Cycle Test\n";

    std::cout
    << "==========================================\n\n";


    long long cycleDays = 11693;

    int cycles = 10;


    for(int i = 1; i <= cycles; i++)
    {

        long long dayId = (cycleDays * i) + 1;


        Date solarDate = solar.getDate(dayId);
        Date lunarDate = lunar.getDate(dayId);


        std::cout
        << "Cycle "
        << i
        << " ("
        << i * 33
        << " Lunar Years)"
        << "\n";


        std::cout
        << "Day ID: "
        << dayId
        << "\n";


        std::cout
        << "Solar: "
        << solarDate.day
        << " "
        << CalendarNames::SOLAR_MONTHS[solarDate.month-1]
        << " "
        << solarDate.year
        << "\n";


        std::cout
        << "Lunar: "
        << lunarDate.day
        << " "
        << CalendarNames::LUNAR_MONTHS[lunarDate.month-1]
        << " "
        << lunarDate.year
        << "\n";


        std::cout
        << "--------------------------\n";

    }


    return 0;
}
