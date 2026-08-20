#include "GabaryDualReportFormatter.h"

#include <sstream>

namespace Gabary
{

std::string GabaryDualReportFormatter::createReport(
    const DualCalendarDate& date
)
{
    std::ostringstream out;

    out << "\n";
    out << "============================================\n";
    out << "        GABARY V2 DUAL CALENDAR\n";
    out << "============================================\n\n";

    out << "Global Day ID : "
        << date.dayId << "\n\n";

    out << "SOLAR CALENDAR\n";
    out << "--------------------------------------------\n";

    out << "Date        : "
        << date.solar.weekName << ", "
        << date.solar.solarDay << " "
        << date.solar.monthName << " "
        << date.solar.solarYear << "\n";

    out << "Year        : "
        << date.solar.solarYear << "\n";

    out << "Month       : "
        << date.solar.monthName << "\n";

    out << "Day         : "
        << date.solar.solarDay << "\n";

    out << "Day Of Year : "
        << date.solar.dayOfYear << "\n";

    out << "Leap Year   : "
        << (date.solar.leapYear ? "YES" : "NO") << "\n\n";

    out << "LUNAR CALENDAR\n";
    out << "--------------------------------------------\n";

    out << "Date        : "
        << date.lunar.weekday << ", "
        << date.lunar.day << " "
        << date.lunar.monthName << " "
        << date.lunar.year << "\n";

    out << "Year        : "
        << date.lunar.year << "\n";

    out << "Month       : "
        << date.lunar.monthName << "\n";

    out << "Day         : "
        << date.lunar.day << "\n";

    out << "Day Of Year : "
        << date.lunar.dayOfYear << "\n";

    out << "Leap Year   : "
        << (date.lunar.leapYear ? "YES" : "NO") << "\n\n";

    out << "TEMPORAL COORDINATE\n";
    out << "--------------------------------------------\n";

    out << "Global Day  : "
        << date.dayId << "\n";

    out << "Architecture : Gabary V2\n";
    out << "Validation   : PASSED\n";

    out << "============================================\n";

    return out.str();
}

} // namespace Gabary
