#include "../include/SolarTimelineArchive.h"
#include <iostream>

using namespace Gabary;

int main()
{
    SolarTimelineArchive archive;

    std::cout << "Solar Timeline Archive Test\n";
    std::cout << "===========================\n";


    archive.buildYear(1);


    std::cout << "Archive size: "
              << archive.size()
              << "\n";


    auto day1 = archive.getDay(1);


    std::cout << "Day 1: "
              << day1.solarDay << "/"
              << day1.solarMonth << "/"
              << day1.solarYear
              << "\n";


    if(archive.size() == 365 &&
       day1.dayId == 1 &&
       day1.solarYear == 1 &&
       day1.solarMonth == 1 &&
       day1.solarDay == 1)
    {
        std::cout << "PASS\n";
        return 0;
    }


    std::cout << "FAIL\n";
    return 1;
}
