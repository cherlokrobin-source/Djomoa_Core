#include "../include/SolarEngineV2.h"

#include <iostream>
#include <cstdint>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    int64_t previousEndDayId = 0;

    for(int year = 1; year <= 50000; ++year)
    {
        const int64_t firstDayId =
            engine.toDayId(year, 1, 1);

        const int64_t lastDayId =
            engine.toDayId(year, 12, 31);

        const int days =
            engine.daysInYear(year);

        if(lastDayId - firstDayId + 1 != days)
        {
            std::cerr
                << "Year length mismatch at Year "
                << year
                << std::endl;

            return 1;
        }

        if(year == 1)
        {
            if(firstDayId != 1)
            {
                std::cerr
                    << "Invalid first Day ID"
                    << std::endl;

                return 1;
            }
        }
        else
        {
            if(firstDayId != previousEndDayId + 1)
            {
                std::cerr
                    << "Year boundary discontinuity at Year "
                    << year
                    << std::endl;

                return 1;
            }
        }

        const SolarDate firstDate =
            engine.fromDayId(firstDayId);

        const SolarDate lastDate =
            engine.fromDayId(lastDayId);

        if(firstDate.year != year ||
           firstDate.month != 1 ||
           firstDate.day != 1)
        {
            std::cerr
                << "Year-start mapping failure at Year "
                << year
                << std::endl;

            return 1;
        }

        if(lastDate.year != year ||
           lastDate.month != 12 ||
           lastDate.day != 31)
        {
            std::cerr
                << "Year-end mapping failure at Year "
                << year
                << std::endl;

            return 1;
        }

        previousEndDayId = lastDayId;
    }

    const int64_t finalDayId =
        engine.toDayId(50000, 12, 31);

    if(previousEndDayId != finalDayId)
    {
        std::cerr
            << "Final Day ID mismatch"
            << std::endl;

        return 1;
    }

    std::cout
        << "Years verified: 50000"
        << std::endl;

    std::cout
        << "Final Day ID: "
        << finalDayId
        << std::endl;

    std::cout
        << "Solar50KFullYearCountTest PASSED"
        << std::endl;

    return 0;
}

