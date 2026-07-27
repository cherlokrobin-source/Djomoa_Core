#include "../include/SolarTimelineArchive.h"
#include "../include/SolarEngineV2.h"

namespace Gabary
{


void SolarTimelineArchive::buildYear(int year)
{
    SolarEngineV2 engine;

    int daysInYear =
        engine.daysInYear(year);


    int64_t startDay = size() + 1;


    for(int day = 0; day < daysInYear; day++)
    {
        GlobalSolarDay solarDay =
            engine.buildDay(
                startDay + day
            );

        days.push_back(solarDay);
    }
}



void SolarTimelineArchive::buildRange(
    int startYear,
    int endYear
)
{
    for(int year = startYear;
        year <= endYear;
        year++)
    {
        buildYear(year);
    }
}



int64_t SolarTimelineArchive::size() const
{
    return days.size();
}



GlobalSolarDay SolarTimelineArchive::getDay(
    int64_t dayId
) const
{
    if(dayId < 1 ||
       dayId > (int64_t)days.size())
    {
        return GlobalSolarDay();
    }


    return days[dayId - 1];
}


}
