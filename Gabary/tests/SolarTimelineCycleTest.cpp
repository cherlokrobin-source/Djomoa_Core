#include "../include/SolarTimelineGenerator.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimelineGenerator generator;

    std::cout << "Solar Timeline Cycle Test\n";
    std::cout << "=========================\n";

    int64_t totalDays = 0;

    for(int year = 1; year <= 4; year++)
    {
        auto timeline = generator.generateYear(year);

        std::cout << "Year "
                  << year
                  << ": "
                  << timeline.size()
                  << " days\n";

        totalDays += timeline.size();
    }

    std::cout << "Total: "
              << totalDays
              << " days\n";


    if(totalDays == 1461)
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
