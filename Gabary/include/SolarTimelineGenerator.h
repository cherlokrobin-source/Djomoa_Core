#ifndef GABARY_SOLAR_TIMELINE_GENERATOR_H
#define GABARY_SOLAR_TIMELINE_GENERATOR_H

#include "GlobalSolarDay.h"
#include "SolarEngineV2.h"

#include <vector>
#include <cstdint>

namespace Gabary
{

class SolarTimelineGenerator
{
public:

    std::vector<GlobalSolarDay> generateYear(int year);

    int64_t daysInYears(int startYear, int endYear);

};

}

#endif
