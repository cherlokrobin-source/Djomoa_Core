#ifndef GABARY_SOLAR_CYCLE_ARCHIVE_H
#define GABARY_SOLAR_CYCLE_ARCHIVE_H

#include "GlobalSolarDay.h"
#include "SolarCycle.h"
#include <vector>
#include <cstdint>

namespace Gabary
{

class SolarCycleArchive
{

private:

    std::vector<GlobalSolarDay> days;


public:

    void buildCycle(
        int cycleId
    );


    int64_t size() const;


    GlobalSolarDay getDay(
        int64_t index
    ) const;


};

}

#endif
