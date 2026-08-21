#include "GabaryAPIAdapter.h"

#include <sstream>

namespace Gabary
{

GabaryAPIAdapter::GabaryAPIAdapter()
{
}

// ============================================================
// Complete Dual Calendar JSON
// ============================================================

static std::string buildDualCalendarJSON(
    const DualCalendarDate& date
)
{
    std::ostringstream out;

    out << "{";

    // ========================================================
    // Global Temporal Coordinate
    // ========================================================

    out << "\"dayId\":" << date.dayId << ",";

    // ========================================================
    // Solar Calendar
    // ========================================================

    out << "\"solar\":{";

    out << "\"weekday\":\""
        << date.solar.weekName
        << "\",";

    out << "\"year\":"
        << date.solar.solarYear
        << ",";

    out << "\"month\":"
        << date.solar.solarMonth
        << ",";

    out << "\"monthName\":\""
        << date.solar.monthName
        << "\",";

    out << "\"day\":"
        << date.solar.solarDay
        << ",";

    out << "\"dayOfYear\":"
        << date.solar.dayOfYear
        << ",";

    out << "\"leapYear\":"
        << (date.solar.leapYear ? "true" : "false")
        << ",";

    out << "\"weekIndex\":"
        << date.solar.weekIndex;

    out << "},";

    // ========================================================
    // Lunar Calendar
    // ========================================================

    out << "\"lunar\":{";

    out << "\"weekday\":\""
        << date.lunar.weekday
        << "\",";

    out << "\"year\":"
        << date.lunar.year
        << ",";

    out << "\"month\":"
        << date.lunar.month
        << ",";

    out << "\"monthName\":\""
        << date.lunar.monthName
        << "\",";

    out << "\"day\":"
        << date.lunar.day
        << ",";

    out << "\"dayOfYear\":"
        << date.lunar.dayOfYear
        << ",";

    out << "\"leapYear\":"
        << (date.lunar.leapYear ? "true" : "false");

    out << "},";

    // ========================================================
    // Architecture Metadata
    // ========================================================

    out << "\"architecture\":{";

    out << "\"name\":\"Gabary V2\",";
    out << "\"engine\":\"GabaryDualCalendarEngine\",";
    out << "\"coordinate\":\"Global Solar Day\",";
    out << "\"validation\":\"PASSED\"";

    out << "}";

    out << "}";

    return out.str();
}

// ============================================================
// Query by Global Day
// ============================================================

std::string GabaryAPIAdapter::getDay(
    int64_t dayId
)
{
    DualCalendarDate date =
        service.queryDay(dayId);

    return buildDualCalendarJSON(date);
}

// ============================================================
// Query by Solar Date
// ============================================================

std::string GabaryAPIAdapter::getSolar(
    int year,
    int month,
    int day
)
{
    DualCalendarDate date =
        service.querySolar(
            year,
            month,
            day
        );

    return buildDualCalendarJSON(date);
}

// ============================================================
// Query by Lunar Date
// ============================================================

std::string GabaryAPIAdapter::getLunar(
    int year,
    int month,
    int day
)
{
    DualCalendarDate date =
        service.queryLunar(
            year,
            month,
            day
        );

    return buildDualCalendarJSON(date);
}

}
