#include <iostream>

#include "SolarEngine.h"
#include "LunarEngine.h"


int main()
{
    SolarEngine solar;
    LunarEngine lunar;


    std::cout
    << "Golden Calendar Engine Cycle Compare\n";

    std::cout
    << "===================================\n\n";


    long long day2083 = solar.daysUntilYear(2083) + 1;


    Date solarDate = solar.getDate(day2083);
    Date lunarDate = lunar.getDate(day2083);


    std::cout
    << "Day ID: "
    << day2083
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
