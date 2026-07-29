#include "../include/SolarEngineV2.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    struct BoundaryTest
    {
        int year;
        int month;
        int day;
    };

    BoundaryTest tests[] =
    {
        {1, 1, 1},
        {1, 12, 31},
        {4, 2, 28},
        {4, 2, 29},
        {4, 12, 31},
        {2083, 12, 31},
        {10000, 12, 31},
        {49999, 12, 31}
    };

    for(const auto& t : tests)
    {
        int64_t dayId =
            engine.toDayId(
                t.year,
                t.month,
                t.day
            );

        GlobalSolarDay current =
            engine.buildDay(dayId);

        GlobalSolarDay next =
            engine.buildDay(dayId + 1);

        if(next.dayId != current.dayId + 1)
        {
            std::cerr
                << "Day ID continuity failure at "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << std::endl;

            return 1;
        }

        SolarDate reconstructed =
            engine.fromDayId(dayId);

        if(reconstructed.year != t.year ||
           reconstructed.month != t.month ||
           reconstructed.day != t.day)
        {
            std::cerr
                << "Current date mismatch at "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << std::endl;

            return 1;
        }

        SolarDate nextDate =
            engine.fromDayId(dayId + 1);

        int64_t nextDateId =
            engine.toDayId(
                nextDate.year,
                nextDate.month,
                nextDate.day
            );

        if(nextDateId != dayId + 1)
        {
            std::cerr
                << "Next-day mapping failure at "
                << t.year << "-"
                << t.month << "-"
                << t.day
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarDayContinuityTest PASSED"
        << std::endl;

    return 0;
}
