#include "../include/SolarTimelineArchive.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimelineArchive archive;

    archive.buildRange(1, 4);

    std::cout << "Archive size: "
              << archive.size()
              << "\n";

    if(archive.size() == 1461)
    {
        std::cout << "PASS\n";
        return 0;
    }

    std::cout << "FAIL\n";
    return 1;
}
