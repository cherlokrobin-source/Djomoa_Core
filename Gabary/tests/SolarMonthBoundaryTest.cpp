#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct MonthBoundaryCase
{
    int year;
    int month;
    int lastDay;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<MonthBoundaryCase> tests =
    {
        {1, 1, 31},
        {1, 2, 28},
        {1, 3, 31},
        {1, 4, 30},
        {1, 5, 31},
        {1, 6, 30},
        {1, 7, 31},
        {1, 8, 31},
        {1, 9, 30},
        {1, 10, 31},
        {1, 11, 30},

        {4, 2, 29},
        {4, 3, 31},
        {100, 2, 28},
        {400, 2, 29},
        {2000, 2, 29},
        {1900, 2, 28},

        {10000, 2, 29},
        {49999, 2, 28},
        {50000, 2, 29}
    };

    for(const auto& test : tests)
    {
        const int64_t lastDayId =
            engine.toDayId(
                test.year,
                test.month,
                test.lastDay
            );

        const SolarDate lastDate =
            engine.fromDayId(lastDayId);

        if(lastDate.year != test.year ||
           lastDate.month != test.month ||
           lastDate.day != test.lastDay)
        {
            std::cerr
                << "Month-end mismatch at "
                << test.year << "-"
                << test.month << "-"
                << test.lastDay
                << std::endl;

            return 1;
        }

        if(test.month < 12)
        {
            const int64_t nextDayId = lastDayId + 1;

            const SolarDate nextDate =
                engine.fromDayId(nextDayId);

            if(nextDate.year != test.year ||
               nextDate.month != test.month + 1 ||
               nextDate.day != 1)
            {
                std::cerr
                    << "Month transition failure after "
                    << test.year << "-"
                    << test.month << "-"
                    << test.lastDay
                    << std::endl;

                return 1;
            }

            if(nextDayId !=
               engine.toDayId(
                   test.year,
                   test.month + 1,
                   1))
            {
                std::cerr
                    << "Day ID transition failure at Year "
                    << test.year
                    << ", Month "
                    << test.month
                    << std::endl;

                return 1;
            }
        }

        const GlobalSolarDay global =
            engine.buildDay(lastDayId);

        if(global.dayId != lastDayId ||
           global.solarYear != test.year ||
           global.solarMonth != test.month ||
           global.solarDay != test.lastDay)
        {
            std::cerr
                << "GlobalSolarDay mismatch at "
                << test.year << "-"
                << test.month << "-"
                << test.lastDay
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarMonthBoundaryTest PASSED"
        << std::endl;

    return 0;
}
