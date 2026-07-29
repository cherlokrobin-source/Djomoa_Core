#include "../include/SolarEngineV2.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    int testYears[] =
    {
        1,
        4,
        100,
        400,
        2083,
        10000,
        50000
    };

    for(int year : testYears)
    {
        int days =
            engine.daysInYear(year);

        if(days != 365 && days != 366)
        {
            std::cerr
                << "Invalid year length: "
                << year
                << std::endl;

            return 1;
        }

        int64_t startDay =
            engine.toDayId(
                year,
                1,
                1
            );

        int64_t nextYearDay =
            engine.toDayId(
                year + 1,
                1,
                1
            );

        if(nextYearDay - startDay != days)
        {
            std::cerr
                << "Year boundary mismatch: "
                << year
                << std::endl;

            return 1;
        }

        std::cout
            << "Year "
            << year
            << " OK - Days: "
            << days
            << std::endl;
    }

    std::cout
        << "SolarYearIntegrityTest PASSED"
        << std::endl;

    return 0;
}
