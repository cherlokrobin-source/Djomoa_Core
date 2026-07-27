#include "../include/SolarCycleEngine.h"
#include "../include/LeapYearRules.h"

namespace Gabary
{

SolarCycle SolarCycleEngine::buildCycle(int cycleId)
{
    SolarCycle cycle;

    cycle.cycleId = cycleId;

    cycle.startYear =
        (cycleId - 1) * 63 + 1;

    cycle.endYear =
        cycle.startYear + 62;


    cycle.startDayId = 1;


    for(int y = 1; y < cycle.startYear; y++)
    {
        cycle.startDayId +=
            LeapYearRules::isLeapYear(y)
            ? 366
            : 365;
    }


    for(
        int y = cycle.startYear;
        y <= cycle.endYear;
        y++
    )
    {
        cycle.totalDays +=
            LeapYearRules::isLeapYear(y)
            ? 366
            : 365;
    }


    return cycle;
}

}
