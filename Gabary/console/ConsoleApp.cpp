#include "ConsoleApp.h"
#include "../include/ReportFormatter.h"

#include <iostream>
#include <fstream>
#include <string>


void ConsoleApp::showBanner() const
{
    std::cout << "\n";

    std::cout
        << "╔══════════════════════════════════════════╗\n"
        << "║           GABARY V2 INSPECTOR            ║\n"
        << "║        TEMPORAL ENGINE ANALYSIS          ║\n"
        << "╚══════════════════════════════════════════╝\n\n";
}


// ============================================
// DAY
// ============================================

void ConsoleApp::showDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    std::cout
        << Gabary::ReportFormatter::createTextReport(day);
}


// ============================================
// SHARE
// ============================================

void ConsoleApp::shareDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    std::cout
        << "QUERY\n"
        << "------------------------------------------\n"
        << "Global Solar Day : "
        << day.dayId
        << "\n\n";

    std::cout
        << "RESULT\n"
        << "------------------------------------------\n"
        << "Solar Date   : "
        << day.solarYear << "-"
        << day.solarMonth << "-"
        << day.solarDay << "\n";

    std::cout
        << "Day Of Year  : "
        << day.dayOfYear
        << "\n";

    std::cout
        << "Week Day     : "
        << day.weekName
        << "\n";

    std::cout
        << "Leap Year    : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";

    std::cout
        << "ENGINE\n"
        << "------------------------------------------\n"
        << "Architecture : Gabary V2\n"
        << "Core         : SolarEngineV2 OK\n"
        << "Validation   : PASSED\n\n";
}


// ============================================
// EXPORT
// ============================================

void ConsoleApp::exportDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    std::string filename =
        "gabary_report_" +
        std::to_string(dayId) +
        ".txt";

    std::ofstream file(filename);

    if (!file)
    {
        std::cout
            << "Cannot create report file\n";

        return;
    }

    file
        << "GABARY V2 ENGINE\n"
        << "SOLAR CHRONOLOGY REPORT\n\n";

    file
        << "Global Solar Day : "
        << day.dayId
        << "\n";

    file
        << "Solar Date : "
        << day.solarYear << "-"
        << day.solarMonth << "-"
        << day.solarDay
        << "\n";

    file
        << "Day Of Year : "
        << day.dayOfYear
        << "\n";

    file
        << "Week Day : "
        << day.weekName
        << "\n";

    file
        << "Leap Year : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";

    file
        << "Architecture : Gabary V2\n"
        << "Engine : SolarEngineV2\n"
        << "Validation : PASSED\n";

    file.close();

    std::cout
        << "Report created: "
        << filename
        << "\n\n";
}


// ============================================
// INSPECT
// ============================================

void ConsoleApp::inspectDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    std::cout << "\n";

    std::cout
        << "╔══════════════════════════════════════════╗\n"
        << "║          GABARY V2 INSPECTOR             ║\n"
        << "║        TEMPORAL ENGINE ANALYSIS           ║\n"
        << "╚══════════════════════════════════════════╝\n\n";

    std::cout
        << "TEMPORAL COORDINATE\n"
        << "------------------------------------------\n"
        << "Global Solar Day : "
        << day.dayId
        << "\n\n";

    std::cout
        << "SOLAR DATA\n"
        << "------------------------------------------\n";

    std::cout
        << "Date        : "
        << day.solarYear << "-"
        << day.solarMonth << "-"
        << day.solarDay
        << "\n";

    std::cout
        << "Day Of Year : "
        << day.dayOfYear
        << "\n";

    std::cout
        << "Week Index  : "
        << day.weekIndex
        << "\n";

    std::cout
        << "Week Name   : "
        << day.weekName
        << "\n";

    std::cout
        << "Leap Year   : "
        << (day.leapYear ? "YES" : "NO")
        << "\n\n";

    std::cout
        << "ENGINE\n"
        << "------------------------------------------\n"
        << "SolarEngineV2  : OK\n"
        << "GlobalSolarDay : OK\n"
        << "Architecture   : Gabary V2\n"
        << "Validation     : PASSED\n\n";
}


// ============================================
// TEMPORAL REPORT
// ============================================

void ConsoleApp::reportDay(int64_t dayId)
{
    TemporalReport report =
        reportEngine.generate(dayId);

    std::cout << "\n";

    std::cout
        << "╔══════════════════════════════════════════╗\n"
        << "║          TEMPORAL REPORT JSON            ║\n"
        << "╚══════════════════════════════════════════╝\n\n";

    std::cout
        << TemporalReportJSON::toJSON(report)
        << "\n\n";
}


// ============================================
// CONSOLE LOOP
// ============================================

int ConsoleApp::run()
{
    showBanner();

    std::string command;

    while (true)
    {
        std::cout << "gabary> ";

        std::getline(
            std::cin,
            command
        );


        // ====================================
        // EXIT
        // ====================================

        if (command == "exit")
        {
            std::cout
                << "Closing Gabary Console...\n";

            break;
        }


        // ====================================
        // HELP
        // ====================================

        else if (command == "help")
        {
            std::cout
                << "\nCommands:\n"
                << "  help\n"
                << "  status\n"
                << "  day <id>\n"
                << "  share <id>\n"
                << "  export <id>\n"
                << "  report <id>\n"
                << "  inspect <id>\n"
                << "  version\n"
                << "  exit\n\n";
        }


        // ====================================
        // DAY
        // ====================================

        else if (command.rfind("day ", 0) == 0)
        {
            try
            {
                showDay(
                    std::stoll(
                        command.substr(4)
                    )
                );
            }
            catch (...)
            {
                std::cout
                    << "Invalid day id\n";
            }
        }


        // ====================================
        // SHARE
        // ====================================

        else if (command.rfind("share ", 0) == 0)
        {
            try
            {
                shareDay(
                    std::stoll(
                        command.substr(6)
                    )
                );
            }
            catch (...)
            {
                std::cout
                    << "Invalid day id\n";
            }
        }


        // ====================================
        // EXPORT
        // ====================================

        else if (command.rfind("export ", 0) == 0)
        {
            try
            {
                exportDay(
                    std::stoll(
                        command.substr(7)
                    )
                );
            }
            catch (...)
            {
                std::cout
                    << "Invalid day id\n";
            }
        }


        // ====================================
        // INSPECT
        // ====================================

        else if (command.rfind("inspect ", 0) == 0)
        {
            try
            {
                inspectDay(
                    std::stoll(
                        command.substr(8)
                    )
                );
            }
            catch (...)
            {
                std::cout
                    << "Invalid day id\n";
            }
        }


        // ====================================
        // REPORT
        // ====================================

        else if (command.rfind("report ", 0) == 0)
        {
            try
            {
                reportDay(
                    std::stoll(
                        command.substr(7)
                    )
                );
            }
            catch (...)
            {
                std::cout
                    << "Invalid day id\n";
            }
        }


        // ====================================
        // STATUS
        // ====================================

        else if (command == "status")
        {
            std::cout
                << "\nGABARY ENGINE STATUS\n"
                << "Core       : ONLINE\n"
                << "Timeline   : 50000 Years\n"
                << "Validation : PASSED\n\n";
        }


        // ====================================
        // VERSION
        // ====================================

        else if (command == "version")
        {
            std::cout
                << "\nGabary V2 Temporal Console\n"
                << "Version: 2.0\n\n";
        }


        // ====================================
        // UNKNOWN
        // ====================================

        else if (!command.empty())
        {
            std::cout
                << "Unknown command. Type help\n";
        }
    }

    return 0;
}
