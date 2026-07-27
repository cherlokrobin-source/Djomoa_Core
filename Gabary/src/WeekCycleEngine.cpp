#include "../include/WeekCycleEngine.h"

namespace Gabary
{

static const char* WEEK_NAMES[7] =
{
    "Friday",
    "Saturday",
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday"
};

int WeekCycleEngine::weekdayIndex(int64_t dayId)
{
    return static_cast<int>((dayId - 1) % 7);
}

std::string WeekCycleEngine::weekdayName(int64_t dayId)
{
    return WEEK_NAMES[weekdayIndex(dayId)];
}

}
