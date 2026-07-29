#include "../include/SolarEngineV2.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    const int startYear = 1;
    const int endYear = 100;

    int64_t previousDayId = 0;

    for(int year = startYear; year <= endYear; year++)
    {
        int64_t dayId =
            engine.toDayId(
                year,
                1,
                1
            );

        if(dayId <= previousDayId)
        {
            std::cerr
                << "Timeline order error at year "
                << year
                << std::endl;

            return 1;
        }

        GlobalSolarDay day =
            engine.buildDay(dayId);

        if(day.solarYear != year)
        {
            std::cerr
                << "Year mismatch at "
                << year
                << std::endl;

            return 1;
        }

        previousDayId = dayId;
    }

    std::cout
        << "Solar Timeline Generation OK\n";

    std::cout
        << "Years tested: "
        << endYear
        << std::endl;

    return 0;
}
