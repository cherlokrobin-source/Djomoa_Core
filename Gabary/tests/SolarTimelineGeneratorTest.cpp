#include "../include/SolarTimelineGenerator.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimelineGenerator generator;

    auto year1 = generator.generateYear(1);

    std::cout << "Solar Timeline Generator Test\n";
    std::cout << "=============================\n";

    std::cout << "Year 1 Days: "
              << year1.size()
              << "\n";

    if(year1.size() == 365 &&
       year1[0].dayId == 1 &&
       year1[0].solarYear == 1 &&
       year1[0].solarMonth == 1 &&
       year1[0].solarDay == 1)
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
