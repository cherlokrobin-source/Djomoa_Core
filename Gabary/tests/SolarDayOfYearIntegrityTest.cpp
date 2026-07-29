#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct DayOfYearCase
{
    int year;
    int month;
    int day;
    int expectedDayOfYear;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<DayOfYearCase> tests =
    {
        {1, 1, 1, 1},
        {1, 2, 1, 32},
        {1, 3, 1, 60},
        {1, 12, 31, 365},

        {4, 2, 29, 60},
        {4, 3, 1, 61},
        {4, 12, 31, 366},

        {100, 3, 1, 60},
        {400, 3, 1, 61},
        {400, 12, 31, 366},

        {2000, 2, 29, 60},
        {2000, 3, 1, 61},

        {10000, 12, 31, 366},
        {25000, 12, 31, 365},
        {49999, 12, 31, 365},
        {50000, 12, 31, 366}
    };

    for(const auto& test : tests)
    {
        const int64_t dayId =
            engine.toDayId(
                test.year,
                test.month,
                test.day
            );

        const SolarDate result =
            engine.fromDayId(dayId);

        if(result.year != test.year ||
           result.month != test.month ||
           result.day != test.day)
        {
            std::cerr
                << "Date round-trip failure at "
                << test.year << "-"
                << test.month << "-"
                << test.day
                << std::endl;

            return 1;
        }

        if(result.dayOfYear != test.expectedDayOfYear)
        {
            std::cerr
                << "dayOfYear mismatch at "
                << test.year << "-"
                << test.month << "-"
                << test.day
                << ": expected "
                << test.expectedDayOfYear
                << ", got "
                << result.dayOfYear
                << std::endl;

            return 1;
        }

        GlobalSolarDay global =
            engine.buildDay(dayId);

        if(global.dayOfYear != test.expectedDayOfYear)
        {
            std::cerr
                << "GlobalSolarDay dayOfYear mismatch at Day ID "
                << dayId
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarDayOfYearIntegrityTest PASSED"
        << std::endl;

    return 0;
}
