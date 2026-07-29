#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct TransitionCase
{
    int year;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<TransitionCase> tests =
    {
        {1},
        {3},
        {4},
        {99},
        {100},
        {399},
        {400},
        {401},
        {999},
        {1000},
        {1899},
        {1900},
        {1999},
        {2000},
        {2001},
        {2099},
        {2100},
        {2399},
        {2400},
        {9999},
        {10000},
        {19999},
        {20000},
        {39999},
        {40000},
        {49999}
    };

    for(const auto& test : tests)
    {
        const int year = test.year;
        const int nextYear = year + 1;

        const int64_t lastDayId =
            engine.toDayId(year, 12, 31);

        const int64_t firstNextDayId =
            engine.toDayId(nextYear, 1, 1);

        if(firstNextDayId != lastDayId + 1)
        {
            std::cerr
                << "Day ID discontinuity between Year "
                << year << " and "
                << nextYear
                << std::endl;

            return 1;
        }

        const SolarDate lastDate =
            engine.fromDayId(lastDayId);

        const SolarDate nextDate =
            engine.fromDayId(firstNextDayId);

        if(lastDate.year != year ||
           lastDate.month != 12 ||
           lastDate.day != 31)
        {
            std::cerr
                << "Invalid year-end date at Year "
                << year
                << std::endl;

            return 1;
        }

        if(nextDate.year != nextYear ||
           nextDate.month != 1 ||
           nextDate.day != 1)
        {
            std::cerr
                << "Invalid next-year start at Year "
                << nextYear
                << std::endl;

            return 1;
        }

        if(lastDate.dayOfYear != engine.daysInYear(year))
        {
            std::cerr
                << "Invalid final dayOfYear at Year "
                << year
                << std::endl;

            return 1;
        }

        if(nextDate.dayOfYear != 1)
        {
            std::cerr
                << "Invalid first dayOfYear at Year "
                << nextYear
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarYearTransitionIntegrityTest PASSED"
        << std::endl;

    return 0;
}
