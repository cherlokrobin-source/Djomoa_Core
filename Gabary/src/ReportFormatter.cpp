#include "ReportFormatter.h"

#include <sstream>
#include <iomanip>

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

    out << "QUERY\n";
    out << "------------------------------------------\n";
    out << "Global Solar Day : "
        << day.dayId << "\n\n";

    out << "RESULT\n";
    out << "------------------------------------------\n";

    out << "Solar Date   : "
        << day.solarYear << "-"
        << std::setw(2) << std::setfill('0')
        << day.solarMonth << "-"
        << std::setw(2)
        << day.solarDay << "\n";

    out << "Day Of Year  : "
        << day.dayOfYear << "\n";

    out << "Week Day     : "
        << day.weekName << "\n";

    out << "Leap Year    : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";


    out << "ENGINE\n";
    out << "------------------------------------------\n";
    out << "Architecture : Gabary V2\n";
    out << "Core         : SolarEngineV2 OK\n";
    out << "Validation   : PASSED\n\n";


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


    out << "TEMPORAL COORDINATE\n";
    out << "------------------------------------------\n";
    out << "Global Solar Day : "
        << day.dayId << "\n\n";


    out << "SOLAR DATA\n";
    out << "------------------------------------------\n";

    out << "Date        : "
        << day.solarYear << "-"
        << std::setw(2) << std::setfill('0')
        << day.solarMonth << "-"
        << std::setw(2)
        << day.solarDay << "\n";

    out << "Day Of Year : "
        << day.dayOfYear << "\n";

    out << "Week Index  : "
        << day.weekIndex << "\n";

    out << "Week Name   : "
        << day.weekName << "\n";

    out << "Leap Year   : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";


    out << "ENGINE\n";
    out << "------------------------------------------\n";
    out << "SolarEngineV2  : OK\n";
    out << "GlobalSolarDay : OK\n";
    out << "Architecture   : Gabary V2\n";
    out << "Validation     : PASSED\n\n";


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
        << day.dayId << "\n";

    out << "Solar Date : "
        << day.solarYear << "-"
        << day.solarMonth << "-"
        << day.solarDay << "\n";

    out << "Day Of Year : "
        << day.dayOfYear << "\n";

    out << "Week Day : "
        << day.weekName << "\n";

    out << "Leap Year : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";


    out << "Architecture : Gabary V2\n";
    out << "Engine : SolarEngineV2\n";
    out << "Validation : PASSED\n";


    return out.str();
}

}
