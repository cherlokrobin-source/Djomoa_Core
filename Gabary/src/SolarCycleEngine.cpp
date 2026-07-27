#include "../include/SolarCycleEngine.h"
#include "../include/LeapYearRules.h"

namespace Gabary
{

SolarCycle SolarCycleEngine::buildCycle(int cycleId)
{
    SolarCycle cycle;


    // Cycle identification
    cycle.cycleId = cycleId;


    // Each cycle contains 63 solar years
    cycle.startYear =
        (cycleId - 1) * 63 + 1;


    cycle.endYear =
        cycle.startYear + 62;



    // Calculate global starting DayID

    cycle.startDayId = 1;


    for(
        int year = 1;
        year < cycle.startYear;
        year++
    )
    {
        cycle.startDayId +=
            LeapYearRules::isLeapYear(year)
            ? 366
            : 365;
    }



    // Calculate total days inside this 63-year cycle

    cycle.totalDays = 0;


    for(
        int year = cycle.startYear;
        year <= cycle.endYear;
        year++
    )
    {
        cycle.totalDays +=
            LeapYearRules::isLeapYear(year)
            ? 366
            : 365;
    }



    return cycle;
}



}
