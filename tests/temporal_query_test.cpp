#include <iostream>

#include "TemporalQueryEngine.h"

int main()
{
    std::cout
    << "Temporal Query Engine Test"
    << std::endl;

    std::cout
    << "=========================="
    << std::endl;

    TemporalQueryEngine query;

    GlobalTemporalID record =
        query.queryDay(18261395);

    std::cout
    << "Day ID: "
    << record.dayId
    << std::endl;

    std::cout
    << "Solar: "
    << record.solarDay << "/"
    << record.solarMonth << "/"
    << record.solarYear
    << std::endl;

    std::cout
    << "Lunar: "
    << record.lunarDay << "/"
    << record.lunarMonth << "/"
    << record.lunarYear
    << std::endl;

    std::cout
    << "Cycle: "
    << record.cycleNumber
    << std::endl;

    std::cout
    << "Historical Index: "
    << record.historicalIndex
    << std::endl;

    std::cout
    << "SUCCESS"
    << std::endl;

    return 0;
}
