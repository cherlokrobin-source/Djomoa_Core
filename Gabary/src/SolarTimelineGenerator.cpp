#include "../include/SolarTimelineGenerator.h"

namespace Gabary
{

std::vector<GlobalSolarDay>
SolarTimelineGenerator::generateYear(int year)
{
    SolarEngineV2 engine;

    std::vector<GlobalSolarDay> timeline;

    int64_t startDay =
        engine.toDayId(year, 1, 1);

    int days =
        engine.daysInYear(year);

    for(int i = 0; i < days; i++)
    {
        timeline.push_back(
            engine.buildDay(startDay + i)
        );
    }

    return timeline;
}


int64_t
SolarTimelineGenerator::daysInYears(
    int startYear,
    int endYear
)
{
    SolarEngineV2 engine;

    int64_t total = 0;

    for(int y = startYear; y <= endYear; y++)
    {
        total += engine.daysInYear(y);
    }

    return total;
}

}
