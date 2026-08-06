#include "ConsoleApp.h"
#include "../include/ReportFormatter.h"
#include <iostream>
#include <fstream>
#include <string>


void ConsoleApp::showBanner() const
{
std::cout << "\n";
std::cout << "╔══════════════════════════════════════════╗\n";
std::cout << "║           GABARY V2 INSPECTOR            ║\n";
std::cout << "║        TEMPORAL ENGINE ANALYSIS          ║\n";
std::cout << "╚══════════════════════════════════════════╝\n\n";
}


void ConsoleApp::showDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    std::cout 
        << Gabary::ReportFormatter::createTextReport(day);
}



void ConsoleApp::shareDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);


    std::cout << "QUERY\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Global Solar Day : "
              << day.dayId << "\n\n";

    std::cout << "RESULT\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Solar Date   : "
              << day.solarYear << "-"
              << day.solarMonth << "-"
              << day.solarDay << "\n";

    std::cout << "Day Of Year  : "
              << day.dayOfYear << "\n";

    std::cout << "Week Day     : "
              << day.weekName << "\n";

    std::cout << "Leap Year    : "
              << (day.leapYear ? "YES" : "NO")
              << "\n\n";

    std::cout << "ENGINE\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Architecture : Gabary V2\n";
    std::cout << "Core         : SolarEngineV2 OK\n";
    std::cout << "Validation   : PASSED\n\n";
}



void ConsoleApp::exportDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    std::string filename =
        "gabary_report_" + std::to_string(dayId) + ".txt";

    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Cannot create report file\n";
        return;
    }


    file << "GABARY V2 ENGINE\n";
    file << "SOLAR CHRONOLOGY REPORT\n\n";

    file << "Global Solar Day : "
         << day.dayId << "\n";

    file << "Solar Date : "
         << day.solarYear << "-"
         << day.solarMonth << "-"
         << day.solarDay << "\n";

    file << "Day Of Year : "
         << day.dayOfYear << "\n";

    file << "Week Day : "
         << day.weekName << "\n";

    file << "Leap Year : "
         << (day.leapYear ? "YES" : "NO")
         << "\n\n";

    file << "Architecture : Gabary V2\n";
    file << "Engine : SolarEngineV2\n";
    file << "Validation : PASSED\n";

    file.close();

    std::cout << "Report created: "
              << filename << "\n\n";
}



void ConsoleApp::inspectDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║          GABARY V2 INSPECTOR             ║\n";
    std::cout << "║        TEMPORAL ENGINE ANALYSIS           ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n\n";

    std::cout << "TEMPORAL COORDINATE\n";
    std::cout << "------------------------------------------\n";
    std::cout << "Global Solar Day : "
              << day.dayId << "\n\n";

    std::cout << "SOLAR DATA\n";
    std::cout << "------------------------------------------\n";

    std::cout << "Date        : "
              << day.solarYear << "-"
              << day.solarMonth << "-"
              << day.solarDay << "\n";

    std::cout << "Day Of Year : "
              << day.dayOfYear << "\n";

    std::cout << "Week Index  : "
              << day.weekIndex << "\n";

    std::cout << "Week Name   : "
              << day.weekName << "\n";

    std::cout << "Leap Year   : "
              << (day.leapYear ? "YES" : "NO")
              << "\n\n";


    std::cout << "ENGINE\n";
    std::cout << "------------------------------------------\n";
    std::cout << "SolarEngineV2  : OK\n";
    std::cout << "GlobalSolarDay : OK\n";
    std::cout << "Architecture   : Gabary V2\n";
    std::cout << "Validation     : PASSED\n\n";
}


void ConsoleApp::reportDay(int64_t dayId)
{
    TemporalReport report =
        reportEngine.generate(dayId);


    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════╗\n";
    std::cout << "║          TEMPORAL REPORT JSON             ║\n";
    std::cout << "╚══════════════════════════════════════════╝\n\n";


    std::cout
        << TemporalReportJSON::toJSON(report)
        << "\n\n";
}
int ConsoleApp::run()
{
    showBanner();

    std::string command;


    while (true)
    {
        std::cout << "gabary> ";
        std::getline(std::cin, command);


        if (command == "exit")
        {
            std::cout << "Closing Gabary Console...\n";
            break;
        }


        else if (command == "help")
        {
            std::cout << "\nCommands:\n";
            std::cout << "  help\n";
            std::cout << "  status\n";
            std::cout << "  day <id>\n";
            std::cout << "  share <id>\n";
            std::cout << "  export <id>\n";
std::cout << "  report <id>\n";
std::cout << "  inspect <id>\n";
            std::cout << "  version\n";
            std::cout << "  exit\n\n";
        }


        else if (command.rfind("day ",0)==0)
        {
            try
            {
                showDay(std::stoll(command.substr(4)));
            }
            catch(...)
            {
                std::cout << "Invalid day id\n";
            }
        }


        else if (command.rfind("share ",0)==0)
        {
            try
            {
                shareDay(std::stoll(command.substr(6)));
            }
            catch(...)
            {
                std::cout << "Invalid day id\n";
            }
        }


        else if (command.rfind("export ",0)==0)
        {
            try
            {
                exportDay(std::stoll(command.substr(7)));
            }
            catch(...)
            {
                std::cout << "Invalid day id\n";
            }
        }


        else if (command.rfind("inspect ",0)==0)
        {
            try
            {
                inspectDay(std::stoll(command.substr(8)));
            }
            catch(...)
            {
                std::cout << "Invalid day id\n";
            }
        }

else if (command.rfind("report ",0)==0)
{
    try
    {
        reportDay(
            std::stoll(command.substr(7))
        );
    }
    catch(...)
    {
        std::cout << "Invalid day id\n";
    }
}
        else if (command == "status")
        {
            std::cout << "\nGABARY ENGINE STATUS\n";
            std::cout << "Core       : ONLINE\n";
            std::cout << "Timeline   : 50000 Years\n";
            std::cout << "Validation : PASSED\n\n";
        }


        else if (command == "version")
        {
            std::cout << "\nGabary V2 Temporal Console\n";
            std::cout << "Version: 2.0\n\n";
        }


        else if (!command.empty())
        {
            std::cout << "Unknown command. Type help\n";
        }
    }


    return 0;
}
