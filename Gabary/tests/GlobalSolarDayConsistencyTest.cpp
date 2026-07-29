#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    std::vector<int64_t> testDays =
    {
        1,
        365,
        739823,
        1000000,
        18250000
    };

    for(auto dayId : testDays)
    {
        SolarDate date =
            engine.fromDayId(dayId);

        int64_t restoredId =
            engine.toDayId(
                date.year,
                date.month,
                date.day
            );

        if(restoredId != dayId)
        {
            std::cerr
                << "Mismatch at Day ID: "
                << dayId
                << std::endl;

            std::cerr
                << "Restored: "
                << restoredId
                << std::endl;

            return 1;
        }

        std::cout
            << "OK Day ID: "
            << dayId
            << std::endl;
    }

    std::cout
        << "GlobalSolarDayConsistencyTest PASSED"
        << std::endl;

    return 0;
}
