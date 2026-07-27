#include "../include/SolarCycleEngine.h"

namespace Gabary
{

static bool isLeapYear(int year)
{
    if(year % 400 == 0)
        return true;

    if(year % 100 == 0)
        return false;

    if(year % 4 == 0)
        return true;

    return false;
}


SolarCycle SolarCycleEngine::buildCycle(int cycleId)
{
    SolarCycle cycle;

    cycle.cycleId = cycleId;


    cycle.startYear =
        (cycleId - 1) * 63 + 1;


    cycle.endYear =
        cycle.startYear + 62;


    cycle.startDayId = 1;


    cycle.totalDays = 0;


    for(int y = 1; y < cycle.startYear; y++)
    {
        cycle.startDayId +=
            isLeapYear(y) ? 366 : 365;
    }


    for(
        int y = cycle.startYear;
        y <= cycle.endYear;
        y++
    )
    {
        cycle.totalDays +=
            isLeapYear(y) ? 366 : 365;
    }


    return cycle;
}

}
