#ifndef GABARY_NAVIGATION_ENGINE_H
#define GABARY_NAVIGATION_ENGINE_H

#include <cstdint>
#include "GabaryDualCalendarEngine.h"

namespace Gabary
{

class GabaryNavigationEngine
{
public:
    static constexpr int64_t MIN_GLOBAL_DAY = 1;
    static constexpr int64_t MAX_GLOBAL_DAY = 18261759;

    GabaryNavigationEngine();

    DualCalendarDate getDate(int64_t dayId);
    DualCalendarDate nextDay(int64_t dayId);
    DualCalendarDate previousDay(int64_t dayId);

    int64_t jumpToLunarDate(
        int year,
        int month,
        int day
    );

    int64_t jumpToSolarDate(
        int year,
        int month,
        int day
    );

private:
    GabaryDualCalendarEngine dualCalendarEngine;
};

} // namespace Gabary

#endif // GABARY_NAVIGATION_ENGINE_H
