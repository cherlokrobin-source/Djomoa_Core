#ifndef GABARY_SOLAR_TIMELINE_ARCHIVE_H
#define GABARY_SOLAR_TIMELINE_ARCHIVE_H

#include "GlobalSolarDay.h"
#include "SolarTimelineGenerator.h"

#include <vector>

namespace Gabary
{

class SolarTimelineArchive
{

private:

    std::vector<GlobalSolarDay> archive;


public:

    void buildYear(int year);

    int64_t size() const;

    GlobalSolarDay getDay(int64_t dayId) const;

};

}

#endif
