#include "../include/SolarEngineV2.h"

#include <iostream>

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

    TestDate tests[] =
    {
        {1, 1, 1},
        {4, 2, 29},
        {100, 1, 1},
        {400, 12, 31},
        {2083, 1, 1},
        {10000, 6, 15},
        {49999, 12, 31},
        {50000, 12, 31}
    };

    for(const auto& t : tests)
    {
        int64_t dayId =
            engine.toDayId(
                t.year,
                t.month,
                t.day
            );

        SolarDate result =
            engine.fromDayId(dayId);

        if(result.year != t.year ||
           result.month != t.month ||
           result.day != t.day)
        {
            std::cerr
                << "Round-trip mismatch: "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << " -> DayID "
                << dayId
                << " -> "
                << result.year << "-"
                << result.month << "-"
                << result.day
                << std::endl;

            return 1;
        }

        std::cout
            << "Round-trip OK: "
            << t.year << "-"
            << t.month << "-"
            << t.day
            << " -> DayID "
            << dayId
            << std::endl;
    }

    std::cout
        << "SolarDateRoundTripTest PASSED"
        << std::endl;

    return 0;
}
