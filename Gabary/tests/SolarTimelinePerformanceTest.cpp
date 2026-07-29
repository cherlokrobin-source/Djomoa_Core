#include "../include/SolarEngineV2.h"

#include <iostream>
#include <chrono>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    const int64_t startDay = 1;
    const int64_t endDay   = 100000;

    auto start =
        std::chrono::high_resolution_clock::now();

    int64_t processed = 0;

    for(
        int64_t day = startDay;
        day <= endDay;
        day++
    )
    {
        GlobalSolarDay result =
            engine.buildDay(day);

        if(result.dayId != day)
        {
            std::cerr
                << "Invalid Day ID at "
                << day
                << std::endl;

            return 1;
        }

        processed++;
    }

    auto finish =
        std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            finish - start
        ).count();

    std::cout
        << "Solar Timeline Performance OK\n";

    std::cout
        << "Days processed: "
        << processed
        << "\n";

    std::cout
        << "Time(ms): "
        << duration
        << "\n";

    return 0;
}
