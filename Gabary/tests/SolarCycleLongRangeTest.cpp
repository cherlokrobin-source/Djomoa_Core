#include "../include/SolarCycleArchive.h"
#include "../include/SolarCycleEngine.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarCycleArchive archive;

    archive.buildCycles(1, 10);

    if(archive.size() <= 0)
    {
        std::cerr << "Archive is empty\n";
        return 1;
    }

    GlobalSolarDay first =
        archive.getDay(0);

    GlobalSolarDay last =
        archive.getDay(
            archive.size() - 1
        );

    if(first.dayId != 1)
    {
        std::cerr << "Invalid first day\n";
        return 1;
    }

    if(last.dayId != archive.size())
    {
        std::cerr << "Day sequence broken\n";
        return 1;
    }

    std::cout
        << "Solar Cycle Long Range OK\n";

    std::cout
        << "Cycles tested: 1-10\n";

    std::cout
        << "Total days: "
        << archive.size()
        << "\n";

    return 0;
}
