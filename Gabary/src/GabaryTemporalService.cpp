#include "GabaryTemporalService.h"

namespace Gabary
{

GabaryTemporalService::GabaryTemporalService()
{
}

DualCalendarDate
GabaryTemporalService::queryDay(int64_t dayId)
{
    return queryEngine.queryDay(dayId);
}

DualCalendarDate
GabaryTemporalService::querySolar(
    int year,
    int month,
    int day
)
{
    return queryEngine.querySolar(year, month, day);
}

DualCalendarDate
GabaryTemporalService::queryLunar(
    int year,
    int month,
    int day
)
{
    return queryEngine.queryLunar(year, month, day);
}

std::string
GabaryTemporalService::reportByDay(int64_t dayId)
{
    return GabaryDualReportFormatter::createReport(
        queryDay(dayId)
    );
}

std::string
GabaryTemporalService::reportBySolar(
    int year,
    int month,
    int day
)
{
    return GabaryDualReportFormatter::createReport(
        querySolar(year, month, day)
    );
}

std::string
GabaryTemporalService::reportByLunar(
    int year,
    int month,
    int day
)
{
    return GabaryDualReportFormatter::createReport(
        queryLunar(year, month, day)
    );
}

}
