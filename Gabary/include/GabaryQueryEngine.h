#ifndef GABARY_QUERY_ENGINE_H
#define GABARY_QUERY_ENGINE_H

#include <cstdint>

#include "GabaryNavigationEngine.h"

namespace Gabary
{

class GabaryQueryEngine
{
public:
    GabaryQueryEngine();

    DualCalendarDate queryDay(int64_t dayId);

    DualCalendarDate querySolar(
        int year,
        int month,
        int day
    );

    DualCalendarDate queryLunar(
        int year,
        int month,
        int day
    );

private:
    GabaryNavigationEngine navigationEngine;
};

} // namespace Gabary

#endif // GABARY_QUERY_ENGINE_H
