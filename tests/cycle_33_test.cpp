#include "../include/LunarEngine.h"
#include "../include/SolarEngine.h"
#include "../include/Names.h"

#include <iostream>


int main()
{
    LunarEngine lunar;
    SolarEngine solar;


    std::cout
    << "Golden Calendar - Lunar 33 Year Cycle Test\n";

    std::cout
    << "==========================================\n\n";


    std::cout
    << "Start:\n";
    std::cout
    << "Friday 1 January Year 1 = 1 Muharram Year 1\n\n";


    long long totalDays = 0;


    for(int year = 1; year <= 33; year++)
    {

        long long dayId = totalDays + 1;


        Date solarDate = solar.getDate(dayId);
        Date lunarDate = lunar.getDate(dayId);


        std::cout
        << "Lunar Year "
        << year
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


        int daysInYear;


        int cycle = ((year - 1) % 33) + 1;


        bool leap = false;


        int leapYears[] =
        {
            3,6,9,11,14,
            17,20,22,25,
            28,31
        };


        for(int y : leapYears)
        {
            if(cycle == y)
                leap = true;
        }


        daysInYear = leap ? 355 : 354;


        totalDays += daysInYear;


        std::cout
        << "Days from Epoch: "
        << totalDays
        << "\n";


        std::cout
        << "--------------------------\n";
    }


    std::cout
    << "\nEnd of 33 Lunar Years\n";


    std::cout
    << "Total Lunar Days: "
    << totalDays
    << "\n";

    std::cout << "\n==========================\n";
    std::cout << "Lunar Cycle 33 Complete\n";
    std::cout << "==========================\n\n";


    long long cycleDays = totalDays;


    Date endSolar = solar.getDate(cycleDays + 1);
    Date endLunar = lunar.getDate(cycleDays + 1);


    std::cout
    << "Total Lunar Days: "
    << cycleDays
    << "\n\n";


    std::cout
    << "Solar End Date: "
    << endSolar.day
    << " "
    << CalendarNames::SOLAR_MONTHS[endSolar.month-1]
    << " "
    << endSolar.year
    << "\n";


    std::cout
    << "Lunar End Date: "
    << endLunar.day
    << " "
    << CalendarNames::LUNAR_MONTHS[endLunar.month-1]
    << " "
    << endLunar.year
    << "\n";
    return 0;
}
