#include <iostream>

#include "GlobalTemporalID.h"


int main()
{

    std::cout
    << "Golden Calendar Global Temporal ID Test"
    << std::endl;

    std::cout
    << "======================================="
    << std::endl;


    GlobalTemporalID id;


    id.dayId = 760436;

    id.solarYear = 2083;
    id.solarMonth = 1;
    id.solarDay = 1;


    id.lunarYear = 2147;
    id.lunarMonth = 2;
    id.lunarDay = 7;


    id.weekIndex = 2;

    id.era = "Golden Calendar Epoch";


    std::cout
    << "Day ID: "
    << id.dayId
    << std::endl;


    std::cout
    << "Solar: "
    << id.solarDay << "/"
    << id.solarMonth << "/"
    << id.solarYear
    << std::endl;


    std::cout
    << "Lunar: "
    << id.lunarDay << "/"
    << id.lunarMonth << "/"
    << id.lunarYear
    << std::endl;


    std::cout
    << "Era: "
    << id.era
    << std::endl;


    return 0;
}
