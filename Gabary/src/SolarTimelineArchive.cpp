#include "../include/SolarTimelineArchive.h"

namespace Gabary
{

void SolarTimelineArchive::buildYear(int year)
{
    SolarTimelineGenerator generator;

    auto days = generator.generateYear(year);

    archive.insert(
        archive.end(),
        days.begin(),
        days.end()
    );
}


int64_t SolarTimelineArchive::size() const
{
    return archive.size();
}


GlobalSolarDay
SolarTimelineArchive::getDay(int64_t dayId) const
{
    return archive.at(dayId - 1);
}

}
