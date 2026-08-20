#ifndef GABARY_TEMPORAL_SERVICE_H
#define GABARY_TEMPORAL_SERVICE_H

#include <cstdint>
#include <string>

#include "GabaryQueryEngine.h"
#include "GabaryDualReportFormatter.h"

namespace Gabary
{

class GabaryTemporalService
{
public:
    GabaryTemporalService();

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

    std::string reportByDay(int64_t dayId);

    std::string reportBySolar(
        int year,
        int month,
        int day
    );

    std::string reportByLunar(
        int year,
        int month,
        int day
    );

private:
    GabaryQueryEngine queryEngine;
};

}

#endif
