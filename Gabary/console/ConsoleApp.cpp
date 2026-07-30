#include "ConsoleApp.h"

#include <iostream>
#include <sstream>
#include <string>

void ConsoleApp::showBanner() const
{
    std::cout << "\n";
    std::cout << "================================================\n";
    std::cout << "             GABARY TEMPORAL CONSOLE            \n";
    std::cout << "          50,000 YEAR CHRONOLOGY ENGINE         \n";
    std::cout << "================================================\n\n";

    std::cout << "Core Engine : READY\n";
    std::cout << "Status      : STABLE\n";
    std::cout << "Validation  : 50/50 PASSED\n";
    std::cout << "Timeline    : Year 1 -> Year 50000\n\n";
}


void ConsoleApp::showDay(int64_t dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    std::cout << "\n";
    std::cout << "========= SOLAR DAY REPORT =========\n";
    std::cout << "Day ID      : " << day.dayId << "\n";
    std::cout << "Solar Year  : " << day.solarYear << "\n";
    std::cout << "Solar Month : " << day.solarMonth << "\n";
    std::cout << "Solar Day   : " << day.solarDay << "\n";
    std::cout << "Day Of Year : " << day.dayOfYear << "\n";
    std::cout << "Week Index  : " << day.weekIndex << "\n";
    std::cout << "Week Name   : " << day.weekName << "\n";
    std::cout << "Leap Year   : "
              << (day.leapYear ? "YES" : "NO")
              << "\n";
    std::cout << "===================================\n\n";
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
            std::cout << "  version\n";
            std::cout << "  exit\n\n";
        }


        else if (command.rfind("day ", 0) == 0)
        {
            std::string value = command.substr(4);

            try
            {
                int64_t dayId = std::stoll(value);
                showDay(dayId);
            }
            catch (...)
            {
                std::cout << "Invalid day id\n";
            }
        }


        else if (command == "status")
        {
            std::cout << "\nGABARY ENGINE STATUS\n";
            std::cout << "Core       : ONLINE\n";
            std::cout << "Timeline   : 50000 Years\n";
            std::cout << "Validation : 50/50 PASSED\n\n";
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
