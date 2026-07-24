#include <iostream>

#include "ChronologyEngine.h"


int main()
{

    std::cout
    << "Global Temporal Metadata Validation Test"
    << std::endl;

    std::cout
    << "========================================"
    << std::endl;


    ChronologyEngine engine;


    long long day = 18261395;


    GlobalTemporalID id =
        engine.generateGlobalID(day);


    std::cout
    << "Day ID: "
    << id.dayId
    << std::endl;


    std::cout
    << "Solar Year: "
    << id.solarYear
    << std::endl;


    std::cout
    << "Lunar Year: "
    << id.lunarYear
    << std::endl;


    std::cout
    << "Cycle Number: "
    << id.cycleNumber
    << std::endl;


    std::cout
    << "Cycle Day: "
    << id.cycleDay
    << std::endl;


    std::cout
    << "Year Index: "
    << id.yearIndex
    << std::endl;


    std::cout
    << "Historical Index: "
    << id.historicalIndex
    << std::endl;


    std::cout
    << "Era: "
    << id.era
    << std::endl;


    if(id.dayId != day)
    {
        std::cout
        << "FAILED"
        << std::endl;

        return 1;
    }


    std::cout
    << "Global Temporal Metadata SUCCESS"
    << std::endl;


    return 0;
}
