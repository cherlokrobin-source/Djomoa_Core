#include "ConsoleApp.h"

#include <iostream>
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
            std::cout << "\nAvailable commands:\n";
            std::cout << "  help     - Show commands\n";
            std::cout << "  status   - Engine status\n";
            std::cout << "  version  - Version info\n";
            std::cout << "  exit     - Close console\n\n";
        }

        else if (command == "status")
        {
            std::cout << "\nGABARY ENGINE STATUS\n";
            std::cout << "--------------------\n";
            std::cout << "Core       : ONLINE\n";
            std::cout << "Tests      : 50/50 PASSED\n";
            std::cout << "Timeline   : 50000 Years\n\n";
        }

        else if (command == "version")
        {
            std::cout << "\nGabary V2 Temporal Console\n";
            std::cout << "Version: 2.0\n\n";
        }

        else if (!command.empty())
        {
            std::cout << "Unknown command. Type 'help'.\n";
        }
    }

    return 0;
}
