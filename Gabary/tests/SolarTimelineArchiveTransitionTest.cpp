#include "../include/SolarTimelineArchive.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimelineArchive archive;

    archive.buildRange(1,4);

    auto lastDay = archive.getDay(1461);

    std::cout
        << lastDay.solarDay
        << "/"
        << lastDay.solarMonth
        << "/"
        << lastDay.solarYear
        << "\n";


    if(lastDay.dayId == 1461 &&
       lastDay.solarYear == 4 &&
       lastDay.solarMonth == 12 &&
       lastDay.solarDay == 31)
    {
        std::cout << "PASS\n";
        return 0;
    }


    std::cout << "FAIL\n";
    return 1;
}
