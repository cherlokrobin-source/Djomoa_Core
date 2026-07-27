#include "../include/SolarCycleEngine.h"

namespace Gabary
{

SolarCycle SolarCycleEngine::buildCycle(
    int cycleId
)
{
    SolarCycle cycle;

    cycle.cycleId = cycleId;

    cycle.startYear =
        (cycleId - 1) * 63 + 1;

    cycle.endYear =
        cycle.startYear + 62;


    cycle.startDayId =
        (cycle.startYear - 1) * 365 + 1;


    return cycle;
}

}
