#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct TestDate
{
    int year;
    int month;
    int day;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<TestDate> tests =
    {
        {1, 1, 1},
        {137, 6, 15},
        {1024, 3, 20},
        {2083, 1, 1},
        {5000, 12, 31},
        {10000, 6, 15},
        {17321, 9, 10},
        {25000, 12, 31},
        {32768, 4, 12},
        {40000, 7, 7},
        {49999, 12, 31},
        {50000, 12, 31}
    };

    for(const auto& t : tests)
    {
        const int64_t dayId =
            engine.toDayId(
                t.year,
                t.month,
                t.day
            );

        if(dayId < 1)
        {
            std::cerr
                << "Invalid Day ID for "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << std::endl;

            return 1;
        }

        const SolarDate result =
            engine.fromDayId(dayId);

        if(result.year != t.year ||
           result.month != t.month ||
           result.day != t.day)
        {
            std::cerr
                << "Round-trip failure: "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << " -> "
                << dayId
                << " -> "
                << result.year << "-"
                << result.month << "-"
                << result.day
                << std::endl;

            return 1;
        }

        const GlobalSolarDay global =
            engine.buildDay(dayId);

        if(global.dayId != dayId ||
           global.solarYear != t.year ||
           global.solarMonth != t.month ||
           global.solarDay != t.day)
        {
            std::cerr
                << "GlobalSolarDay mismatch at Day ID "
                << dayId
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "Solar50KRandomSamplingTest PASSED"
        << std::endl;

    return 0;
}
