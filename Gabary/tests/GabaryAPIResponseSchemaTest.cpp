#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

static bool contains(const std::string& body, const std::string& key)
{
    return body.find(key) != std::string::npos;
}

int main()
{
    std::cout << "========================================\n";
    std::cout << " Gabary V2 API Response Schema v1 Test\n";
    std::cout << "========================================\n";

    const char* server = std::getenv("GABARY_HTTP_SERVER");

    if(server == nullptr)
    {
        std::cerr << "[ERROR] GABARY_HTTP_SERVER is not set\n";
        return 1;
    }

    std::string url = std::string(server) + "/api/json/day/1";

    std::string command =
        "curl -s \"" + url + "\" > gabary_schema_day1.json";

    if(std::system(command.c_str()) != 0)
    {
        std::cerr << "[FAIL] curl request failed\n";
        return 1;
    }

    std::ifstream file("gabary_schema_day1.json");

    if(!file)
    {
        std::cerr << "[FAIL] Cannot read API response\n";
        return 1;
    }

    std::string body(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );

    int passed = 0;

    const std::string requiredFields[] =
    {
        "\"globalSolarDay\"",
        "\"solarDate\"",
        "\"weekday\"",
        "\"year\"",
        "\"month\"",
        "\"monthName\"",
        "\"day\"",
        "\"dayOfYear\"",
        "\"calendarMetadata\"",
        "\"weekIndex\"",
        "\"leapYear\"",
        "\"lunarDate\"",
        "\"temporalMetadata\"",
        "\"cycleNumber\"",
        "\"cycleDay\"",
        "\"yearIndex\"",
        "\"historicalIndex\"",
        "\"era\"",
        "\"architecture\"",
        "\"name\"",
        "\"engine\"",
        "\"validation\""
    };

    for(const auto& field : requiredFields)
    {
        if(contains(body, field))
        {
            std::cout << "[PASS] Required field: "
                      << field << "\n";
            ++passed;
        }
        else
        {
            std::cout << "[FAIL] Missing field: "
                      << field << "\n";
        }
    }

    bool valuesOk =
        contains(body, "\"globalSolarDay\":1") &&
        contains(body, "\"weekday\":\"Friday\"") &&
        contains(body, "\"year\":1") &&
        contains(body, "\"month\":1") &&
        contains(body, "\"monthName\":\"January\"") &&
        contains(body, "\"day\":1") &&
        contains(body, "\"dayOfYear\":1") &&
        contains(body, "\"weekIndex\":0") &&
        contains(body, "\"leapYear\":false") &&
        contains(body, "\"lunarDate\":{\"year\":1,\"month\":1,\"day\":1") &&
        contains(body, "\"name\":\"Gabary V2\"") &&
        contains(body, "\"engine\":\"SolarEngineV2\"") &&
        contains(body, "\"validation\":\"PASSED\"");

    if(valuesOk)
    {
        std::cout << "[PASS] Day 1 schema values\n";
        ++passed;
    }
    else
    {
        std::cout << "[FAIL] Day 1 schema values\n";
    }

    std::cout << "========================================\n";

    if(passed == 23)
    {
        std::cout
            << " Gabary V2 API Response Schema v1: PASSED\n";
        std::cout << "========================================\n";
        return 0;
    }

    std::cout
        << " Gabary V2 API Response Schema v1: FAILED\n";
    std::cout << "========================================\n";

    return 1;
}
