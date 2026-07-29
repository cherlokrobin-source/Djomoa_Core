#include "../include/SolarEngineV2.h"

#include <iostream>
#include <cstdint>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    const int64_t firstDayId = 1;

    const int64_t lastDayId =
        engine.toDayId(
            50000,
            12,
            31
        );

    if(lastDayId <= firstDayId)
    {
        std::cerr
            << "Invalid 50K Day ID range"
            << std::endl;

        return 1;
    }

    SolarDate first =
        engine.fromDayId(firstDayId);

    SolarDate last =
        engine.fromDayId(lastDayId);

    if(first.year != 1 ||
       first.month != 1 ||
       first.day != 1)
    {
        std::cerr
            << "First Day ID does not map to Year 1/1/1"
            << std::endl;

        return 1;
    }

    if(last.year != 50000 ||
       last.month != 12 ||
       last.day != 31)
    {
        std::cerr
            << "Final Day ID does not map to Year 50000/12/31"
            << std::endl;

        return 1;
    }

    if(engine.toDayId(
            first.year,
            first.month,
            first.day
       ) != firstDayId)
    {
        std::cerr
            << "First Day ID round-trip failed"
            << std::endl;

        return 1;
    }

    if(engine.toDayId(
            last.year,
            last.month,
            last.day
       ) != lastDayId)
    {
        std::cerr
            << "Final Day ID round-trip failed"
            << std::endl;

        return 1;
    }

    GlobalSolarDay firstGlobal =
        engine.buildDay(firstDayId);

    GlobalSolarDay lastGlobal =
        engine.buildDay(lastDayId);

    if(firstGlobal.dayId != firstDayId ||
       lastGlobal.dayId != lastDayId)
    {
        std::cerr
            << "Global Day ID mismatch"
            << std::endl;

        return 1;
    }

    std::cout
        << "First Day ID: "
        << firstDayId
        << std::endl;

    std::cout
        << "Final Day ID: "
        << lastDayId
        << std::endl;

    std::cout
        << "Total Days: "
        << lastDayId - firstDayId + 1
        << std::endl;

    std::cout
        << "Solar50KDayIDRangeTest PASSED"
        << std::endl;

    return 0;
}
