#ifndef GABARY_WEEK_CYCLE_ENGINE_H
#define GABARY_WEEK_CYCLE_ENGINE_H

#include <string>
#include <cstdint>

namespace Gabary
{

class WeekCycleEngine
{
public:

    // Return weekday index (0..6)
    static int weekdayIndex(int64_t dayId);

    // Return weekday name
    static std::string weekdayName(int64_t dayId);

};

}

#endif
