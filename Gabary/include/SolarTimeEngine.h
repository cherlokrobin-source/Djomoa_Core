#ifndef GABARY_SOLAR_TIME_ENGINE_H
#define GABARY_SOLAR_TIME_ENGINE_H

#include "SolarArchiveBuilder.h"
#include "GlobalSolarDay.h"
#include <cstdint>

namespace Gabary
{

class SolarTimeEngine
{
private:

    SolarArchiveBuilder builder;

public:

    void loadCycles(
        int startCycle,
        int endCycle
    );

    int64_t size() const;

    GlobalSolarDay getDay(
        int64_t dayId
    ) const;
};

}

#endif
