#include "../include/SolarEngine.h"
#include "../include/LunarEngine.h"

#include <iostream>


int main()
{

    SolarEngine solar;
    LunarEngine lunar;


    std::cout
    << "Golden Calendar 50000-Year Chronology Engine Reference Test\n";

    std::cout
    << "===================================\n\n";


    // Day ID لبداية السنة الشمسية 2083
    long long dayId = solar.daysUntilYear(2083) + 1;


    Date solarDate = solar.getDate(dayId);
    Date lunarDate = lunar.getDate(dayId);


    std::cout
    << "Day ID: "
    << dayId
    << "\n\n";


    std::cout
    << "Solar:\n";

    std::cout
    << solarDate.day
    << "/"
    << solarDate.month
    << "/"
    << solarDate.year
    << "\n\n";


    std::cout
    << "Lunar:\n";

    std::cout
    << lunarDate.day
    << "/"
    << lunarDate.month
    << "/"
    << lunarDate.year
    << "\n";


    return 0;
}
