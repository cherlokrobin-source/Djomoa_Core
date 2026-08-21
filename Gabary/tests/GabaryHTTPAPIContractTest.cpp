#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::cout << "========================================\n";
    std::cout << " Gabary V2 HTTP API Contract Test\n";
    std::cout << "========================================\n";

    const char* server = std::getenv("GABARY_HTTP_SERVER");

    if(server == nullptr)
    {
        std::cerr
            << "[ERROR] GABARY_HTTP_SERVER is not set\n";
        return 1;
    }

    std::string base = server;

    struct TestCase
    {
        std::string name;
        std::string path;
        int expectedStatus;
    };

    const TestCase tests[] =
    {
        {
            "GET /api/status",
            "/api/status",
            200
        },
        {
            "GET /api/json/day/1",
            "/api/json/day/1",
            200
        },
        {
            "GET /api/json/day/18262125",
            "/api/json/day/18262125",
            200
        },
        {
            "GET /api/json/day/0",
            "/api/json/day/0",
            400
        },
        {
            "GET /api/json/day/18262126",
            "/api/json/day/18262126",
            400
        }
    };

    int passed = 0;

    for(const auto& test : tests)
    {
        std::string command =
            "curl -s -o /tmp/gabary_http_body.txt "
            "-w \"%{http_code}\" "
            "\"" + base + test.path + "\"";

        FILE* pipe = popen(command.c_str(), "r");

        if(!pipe)
        {
            std::cerr
                << "[FAIL] "
                << test.name
                << " - curl failed\n";

            continue;
        }

        char buffer[32]{};
        std::string status;

        if(fgets(buffer, sizeof(buffer), pipe))
            status = buffer;

        pclose(pipe);

        int actualStatus = std::stoi(status);

        if(actualStatus == test.expectedStatus)
        {
            std::cout
                << "[PASS] "
                << test.name
                << " -> HTTP "
                << actualStatus
                << "\n";

            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] "
                << test.name
                << " -> expected HTTP "
                << test.expectedStatus
                << ", got HTTP "
                << actualStatus
                << "\n";
        }
    }

    std::cout << "========================================\n";

    if(passed == 5)
    {
        std::cout
            << " Gabary V2 HTTP API Contract: PASSED\n";
        std::cout << "========================================\n";
        return 0;
    }

    std::cout
        << " Gabary V2 HTTP API Contract: FAILED\n";
    std::cout << "========================================\n";

    return 1;
}
