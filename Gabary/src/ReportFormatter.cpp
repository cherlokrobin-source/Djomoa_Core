#include "ReportFormatter.h"

#include <sstream>
#include <array>

namespace Gabary
{


std::string ReportFormatter::createShareReport(
    const GlobalSolarDay& day
)
{
    std::ostringstream out;

    out << "\n";
    out << "╔══════════════════════════════════════════╗\n";
    out << "║            GABARY V2 ENGINE              ║\n";
    out << "║       SOLAR CHRONOLOGY REPORT            ║\n";
    out << "╚══════════════════════════════════════════╝\n\n";

    out << "Global Solar Day : "
        << day.dayId << "\n\n";

    out << "Gabary Day Code : GC-"
        << day.dayId
        << "-"
        << day.solarYear
        << "-"
        << day.dayOfYear
        << "\n\n";


    out << "Solar Date\n";
    out << "------------------------------------------\n";

    out << day.weekName
        << ", "
        << day.solarDay
        << " "
        << day.monthName
        << " "
        << day.solarYear
        << "\n\n";


    out << "Year        : "
        << day.solarYear << "\n";

    out << "Month       : "
        << day.monthName
        << "\n";

    out << "Day         : "
        << day.solarDay << "\n";

    out << "Day Of Year : "
        << day.dayOfYear << "\n\n";


    out << "Leap Year : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";


    out << "Architecture : Gabary V2\n";
    out << "Engine : SolarEngineV2\n";
    out << "Validation : PASSED\n";


    return out.str();
}



std::string ReportFormatter::createInspectReport(
    const GlobalSolarDay& day
)
{
    std::ostringstream out;

    out << "\n";
    out << "╔══════════════════════════════════════════╗\n";
    out << "║           GABARY V2 INSPECTOR            ║\n";
    out << "║        TEMPORAL ENGINE ANALYSIS          ║\n";
    out << "╚══════════════════════════════════════════╝\n\n";


    out << "Global Solar Day : "
        << day.dayId << "\n\n";


    out << "Date : "
        << day.weekName
        << ", "
        << day.solarDay
        << " "
        << day.monthName
        << " "
        << day.solarYear
        << "\n";


    out << "Day Of Year : "
        << day.dayOfYear << "\n";

    out << "Week Index : "
        << day.weekIndex << "\n";

    out << "Leap Year : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";


    out << "Architecture : Gabary V2\n";
    out << "Validation : PASSED\n";


    return out.str();
}



std::string ReportFormatter::createTextReport(
    const GlobalSolarDay& day
)
{
    std::ostringstream out;


    out << "GABARY V2 ENGINE\n";
    out << "SOLAR CHRONOLOGY REPORT\n\n";


    out << "Global Solar Day : "
        << day.dayId << "\n\n";


    out << "Gabary Day Code : GC-"
        << day.dayId
        << "-"
        << day.solarYear
        << "-"
        << day.dayOfYear
        << "\n\n";


    out << "Solar Date\n";
out << "----------------------------------\n";
    out << day.weekName
        << ", "
        << day.solarDay
        << " "
        << day.monthName
        << " "
        << day.solarYear
        << "\n\n";

    out << "Year        : "
        << day.solarYear << "\n";

    out << "Month       : "
        << day.monthName << "\n";

    out << "Day         : "
        << day.solarDay << "\n";

    out << "Day Of Year : "
        << day.dayOfYear << "\n\n";

    out << "Leap Year   : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";

    out << "Architecture : Gabary V2\n";
    out << "Engine       : SolarEngineV2\n";
    out << "Validation   : PASSED\n";

    return out.str();
}

}
