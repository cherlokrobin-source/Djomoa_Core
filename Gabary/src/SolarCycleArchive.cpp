#include "../include/SolarCycleArchive.h"

#include "../include/SolarEngineV2.h"
#include "../include/SolarCycleEngine.h"


namespace Gabary
{


void SolarCycleArchive::buildCycle(
    int cycleId
)
{

    SolarCycleEngine engine;


    SolarCycle cycle =
        engine.buildCycle(cycleId);


    SolarEngineV2 solar;


    days.clear();


    for(
        int64_t id = cycle.startDayId;
        id < cycle.startDayId + cycle.totalDays;
        id++
    )
    {

        days.push_back(
            solar.buildDay(id)
        );

    }

}



void SolarCycleArchive::buildCycles(
    int startCycle,
    int endCycle
)
{

    SolarCycleEngine engine;

    SolarEngineV2 solar;


    days.clear();


    for(
        int cycleId = startCycle;
        cycleId <= endCycle;
        cycleId++
    )
    {

        SolarCycle cycle =
            engine.buildCycle(cycleId);



        for(
            int64_t id = cycle.startDayId;
            id < cycle.startDayId + cycle.totalDays;
            id++
        )
        {

            days.push_back(
                solar.buildDay(id)
            );

        }

    }

}



int64_t SolarCycleArchive::size() const
{
    return days.size();
}



GlobalSolarDay SolarCycleArchive::getDay(
    int64_t index
) const
{

    return days.at(index);

}


}
