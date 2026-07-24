#include <iostream>

#include "ChronologyEngine.h"


int main()
{

    std::cout
    << "Global Temporal ID Integration Test"
    << std::endl;

    std::cout
    << "==================================="
    << std::endl;


    ChronologyEngine engine;


    long long testDay = 760436;


    GlobalTemporalID id =
        engine.generateGlobalID(testDay);


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
    << "Week Index: "
    << id.weekIndex
    << std::endl;


    std::cout
    << "Era: "
    << id.era
    << std::endl;


    if(id.dayId != testDay)
    {
        std::cout
        << "FAILED"
        << std::endl;

        return 1;
    }


    std::cout
    << "Global Temporal ID Integration SUCCESS"
    << std::endl;


    return 0;
}
