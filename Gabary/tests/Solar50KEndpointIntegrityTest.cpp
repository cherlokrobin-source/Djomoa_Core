#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct EndpointCase
{
    int year;
    int month;
    int day;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<EndpointCase> tests =
    {
        {1, 1, 1},
        {1, 1, 2},
        {1, 12, 31},

        {2, 1, 1},
        {49998, 12, 31},
        {49999, 1, 1},
        {49999, 12, 31},

        {50000, 1, 1},
        {50000, 12, 31}
    };

    for(const auto& test : tests)
    {
        const int64_t dayId =
            engine.toDayId(
                test.year,
                test.month,
                test.day
            );

        if(dayId <= 0)
        {
            std::cerr
                << "Invalid Day ID at "
                << test.year << "-"
                << test.month << "-"
                << test.day
                << std::endl;

            return 1;
        }

        const SolarDate date =
            engine.fromDayId(dayId);

        if(date.year != test.year ||
           date.month != test.month ||
           date.day != test.day)
        {
            std::cerr
                << "Endpoint round-trip failure at "
                << test.year << "-"
                << test.month << "-"
                << test.day
                << std::endl;

            return 1;
        }

        const GlobalSolarDay global =
            engine.buildDay(dayId);

        if(global.dayId != dayId ||
           global.solarYear != test.year ||
           global.solarMonth != test.month ||
           global.solarDay != test.day)
        {
            std::cerr
                << "GlobalSolarDay endpoint mismatch at Day ID "
                << dayId
                << std::endl;

            return 1;
        }
    }

    const int64_t firstDayId =
        engine.toDayId(1, 1, 1);

    if(firstDayId != 1)
    {
        std::cerr
            << "First Day ID must be 1, got "
            << firstDayId
            << std::endl;

        return 1;
    }

    const int64_t finalDayId =
        engine.toDayId(50000, 12, 31);

    if(finalDayId <= 0)
    {
        std::cerr
            << "Invalid final Day ID"
            << std::endl;

        return 1;
    }

    const SolarDate finalDate =
        engine.fromDayId(finalDayId);

    if(finalDate.year != 50000 ||
       finalDate.month != 12 ||
       finalDate.day != 31)
    {
        std::cerr
            << "Invalid 50K endpoint"
            << std::endl;

        return 1;
    }

    std::cout
        << "Solar50KEndpointIntegrityTest PASSED"
        << std::endl;

    return 0;
}
