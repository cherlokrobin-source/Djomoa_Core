#ifndef GABARY_SOLAR_TIMELINE_ARCHIVE_H
#define GABARY_SOLAR_TIMELINE_ARCHIVE_H

#include "GlobalSolarDay.h"
#include <vector>
#include <cstdint>

namespace Gabary
{

class SolarTimelineArchive
{

private:

    std::vector<GlobalSolarDay> days;


public:

    void buildYear(int year);

    void buildRange(
        int startYear,
        int endYear
    );

    int64_t size() const;

    GlobalSolarDay getDay(
        int64_t dayId
    ) const;

};

}

#endif
