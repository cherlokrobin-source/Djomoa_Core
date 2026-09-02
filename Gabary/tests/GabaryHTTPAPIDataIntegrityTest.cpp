#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

static std::string getBody(const std::string& url)
{
    std::string command =
        "curl -s \"" + url + "\"";

    FILE* pipe = popen(command.c_str(), "r");

    if(!pipe)
        return "";

    char buffer[4096];
    std::string body;

    while(fgets(buffer, sizeof(buffer), pipe))
        body += buffer;

    pclose(pipe);

    return body;
}

static bool contains(
    const std::string& body,
    const std::string& key
)
{
    return body.find(key) != std::string::npos;
}

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 HTTP API Data Integrity Test\n"
        << "============================================\n";

    const char* server =
        std::getenv("GABARY_HTTP_SERVER");

    if(server == nullptr)
    {
        std::cerr
            << "[ERROR] GABARY_HTTP_SERVER is not set\n";

        return 1;
    }

    std::string base = server;

    int passed = 0;
    int total = 0;

    // ------------------------------------------------
    // Epoch
    // ------------------------------------------------

    {
        std::string json =
            getBody(base + "/api/json/day/1");

        ++total;

        bool ok =
            contains(json, "\"dayId\":1") &&
            contains(json, "\"solar\"") &&
            contains(json, "\"lunar\"") &&
            contains(json, "\"year\":1") &&
            contains(json, "\"month\":1") &&
            contains(json, "\"day\":1") &&
            contains(json, "\"monthName\":\"January\"") &&
            contains(json, "\"weekday\":\"Friday\"") &&
            contains(json, "\"architecture\"") &&
            contains(json, "\"name\":\"Gabary V2\"") &&
            contains(json, "\"engine\":\"GabaryDualCalendarEngine\"") &&
            contains(json, "\"coordinate\":\"Global Solar Day\"") &&
            contains(json, "\"validation\":\"PASSED\"");

        if(ok)
        {
            std::cout
                << "[PASS] HTTP epoch JSON integrity\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] HTTP epoch JSON integrity\n";
        }
    }

    // ------------------------------------------------
    // Known Global Solar Day
    // ------------------------------------------------

    {
        std::string json =
            getBody(base + "/api/json/day/739823");

        ++total;

        bool ok =
            contains(json, "\"dayId\":739823") &&
            contains(json, "\"year\":2026") &&
            contains(json, "\"month\":7") &&
            contains(json, "\"day\":26") &&
            contains(json, "\"monthName\":\"July\"") &&
            contains(json, "\"weekday\":\"Thursday\"") &&
            contains(json, "\"architecture\"") &&
            contains(json, "\"name\":\"Gabary V2\"") &&
            contains(json, "\"engine\":\"GabaryDualCalendarEngine\"") &&
            contains(json, "\"coordinate\":\"Global Solar Day\"") &&
            contains(json, "\"validation\":\"PASSED\"");

        if(ok)
        {
            std::cout
                << "[PASS] HTTP known Global Solar Day integrity\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] HTTP known Global Solar Day integrity\n";
        }
    }

    // ------------------------------------------------
    // Final boundary
    // ------------------------------------------------

    {
        std::string json =
            getBody(base + "/api/json/day/18261759");

        ++total;

        bool ok =
            contains(json, "\"dayId\":18261759") &&
            contains(json, "\"year\":49999") &&
            contains(json, "\"month\":12") &&
            contains(json, "\"day\":31") &&
            contains(json, "\"monthName\":\"December\"") &&
            contains(json, "\"weekday\":\"Tuesday\"") &&
            contains(json, "\"dayOfYear\":365") &&
            contains(json, "\"leapYear\":false") &&
            contains(json, "\"architecture\"") &&
            contains(json, "\"name\":\"Gabary V2\"") &&
            contains(json, "\"engine\":\"GabaryDualCalendarEngine\"") &&
            contains(json, "\"coordinate\":\"Global Solar Day\"") &&
            contains(json, "\"validation\":\"PASSED\"");

        if(ok)
        {
            std::cout
                << "[PASS] HTTP final boundary JSON integrity\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] HTTP final boundary JSON integrity\n";
        }
    }

    // ------------------------------------------------
    // Shared Global Solar Day identity
    // ------------------------------------------------

    {
        std::string json =
            getBody(base + "/api/json/day/739823");

        ++total;

        bool ok =
            contains(json, "\"dayId\":739823") &&
            contains(json, "\"solar\"") &&
            contains(json, "\"lunar\"");

        if(ok)
        {
            std::cout
                << "[PASS] HTTP shared Global Solar Day identity\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] HTTP shared Global Solar Day identity\n";
        }
    }

    std::cout
        << "============================================\n"
        << " Checks: "
        << passed
        << "/"
        << total
        << "\n";

    if(passed == total)
    {
        std::cout
            << " Gabary V2 HTTP API Data Integrity: PASSED\n"
            << "============================================\n";

        return 0;
    }

    std::cout
        << " Gabary V2 HTTP API Data Integrity: FAILED\n"
        << "============================================\n";

    return 1;
}
