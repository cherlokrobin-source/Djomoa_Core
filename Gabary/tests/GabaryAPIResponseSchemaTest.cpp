#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

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
        << "========================================\n"
        << " Gabary V2 API Response Schema v2 Test\n"
        << "========================================\n";

    const char* server =
        std::getenv("GABARY_HTTP_SERVER");

    if(server == nullptr)
    {
        std::cerr
            << "[ERROR] GABARY_HTTP_SERVER is not set\n";
        return 1;
    }

    const std::string url =
        std::string(server) + "/api/json/day/1";

    const std::string fileName =
        "gabary_schema_day1.json";

    const std::string command =
        "curl -s \"" + url + "\" > " + fileName;

    if(std::system(command.c_str()) != 0)
    {
        std::cerr
            << "[FAIL] curl request failed\n";
        return 1;
    }

    std::ifstream file(fileName);

    if(!file)
    {
        std::cerr
            << "[FAIL] Cannot read API response\n";
        return 1;
    }

    std::string body(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    int passed = 0;
    int total = 0;

    const std::string requiredFields[] =
    {
        "\"dayId\"",
        "\"solar\"",
        "\"weekday\"",
        "\"year\"",
        "\"month\"",
        "\"monthName\"",
        "\"day\"",
        "\"dayOfYear\"",
        "\"leapYear\"",
        "\"weekIndex\"",
        "\"lunar\"",
        "\"architecture\"",
        "\"name\"",
        "\"engine\"",
        "\"coordinate\"",
        "\"validation\""
    };

    for(const auto& field : requiredFields)
    {
        ++total;

        if(contains(body, field))
        {
            std::cout
                << "[PASS] Required field: "
                << field << "\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] Missing field: "
                << field << "\n";
        }
    }

    const std::string expectedValues[] =
    {
        "\"dayId\":1",

        "\"weekday\":\"Friday\"",
        "\"year\":1",
        "\"month\":1",
        "\"monthName\":\"January\"",
        "\"day\":1",
        "\"dayOfYear\":1",
        "\"leapYear\":false",
        "\"weekIndex\":0",

        "\"lunar\"",
        "\"name\":\"Gabary V2\"",
        "\"engine\":\"GabaryDualCalendarEngine\"",
        "\"coordinate\":\"Global Solar Day\"",
        "\"validation\":\"PASSED\""
    };

    for(const auto& value : expectedValues)
    {
        ++total;

        if(contains(body, value))
        {
            std::cout
                << "[PASS] Schema value: "
                << value << "\n";
            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] Schema value missing: "
                << value << "\n";
        }
    }

    std::cout
        << "========================================\n";

    if(passed == total)
    {
        std::cout
            << " Gabary V2 API Response Schema v2: PASSED\n";
        std::cout
            << " Checks: "
            << passed
            << "/"
            << total
            << "\n";
        std::cout
            << "========================================\n";

        std::remove(fileName.c_str());

        return 0;
    }

    std::cout
        << " Gabary V2 API Response Schema v2: FAILED\n";
    std::cout
        << " Checks: "
        << passed
        << "/"
        << total
        << "\n";
    std::cout
        << "========================================\n";

    return 1;
}
