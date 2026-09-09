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

static std::string fetch(
    const std::string& server,
    long long dayId,
    const std::string& fileName
)
{
    const std::string url =
        server + "/api/json/day/" +
        std::to_string(dayId);

    const std::string command =
        "curl -s \"" + url + "\" > " + fileName;

    if(std::system(command.c_str()) != 0)
    {
        return "";
    }

    std::ifstream file(fileName);

    if(!file)
    {
        return "";
    }

    return std::string(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );
}

static bool check(
    const std::string& label,
    const std::string& body,
    const std::string& expected
)
{
    if(contains(body, expected))
    {
        std::cout
            << "[PASS] "
            << label
            << "\n";
        return true;
    }

    std::cout
        << "[FAIL] "
        << label
        << "\n";

    return false;
}

int main()
{
    std::cout
        << "========================================\n"
        << " Gabary V2 API Response Boundary Schema Test\n"
        << "========================================\n";

    const char* server =
        std::getenv("GABARY_HTTP_SERVER");

    if(server == nullptr)
    {
        std::cerr
            << "[ERROR] GABARY_HTTP_SERVER is not set\n";
        return 1;
    }

    const std::string serverUrl(server);

    const long long MIN_DAY = 1;
    const long long MAX_DAY = 18261759;

    int passed = 0;
    int total = 0;

    // ========================================================
    // Minimum Global Solar Day
    // ========================================================

    const std::string minBody =
        fetch(
            serverUrl,
            MIN_DAY,
            "gabary_boundary_min.json"
        );

    if(minBody.empty())
    {
        std::cerr
            << "[FAIL] Cannot retrieve minimum boundary response\n";
        return 1;
    }

    total++;
    if(check(
        "Global Solar Day 1 -> dayId",
        minBody,
        "\"dayId\":1"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> solar year",
        minBody,
        "\"year\":1"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> solar month",
        minBody,
        "\"month\":1"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> solar day",
        minBody,
        "\"day\":1"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> monthName",
        minBody,
        "\"monthName\":\"January\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> weekday",
        minBody,
        "\"weekday\":\"Friday\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> dayOfYear",
        minBody,
        "\"dayOfYear\":1"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> leapYear",
        minBody,
        "\"leapYear\":false"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> lunar",
        minBody,
        "\"lunar\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 1 -> architecture",
        minBody,
        "\"name\":\"Gabary V2\""
    ))
        passed++;

    // ========================================================
    // Maximum Global Solar Day
    // ========================================================

    const std::string maxBody =
        fetch(
            serverUrl,
            MAX_DAY,
            "gabary_boundary_max.json"
        );

    if(maxBody.empty())
    {
        std::cerr
            << "[FAIL] Cannot retrieve maximum boundary response\n";
        return 1;
    }

    total++;
    if(check(
        "Global Solar Day 18261759 -> dayId",
        maxBody,
        "\"dayId\":18261759"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> solar year",
        maxBody,
        "\"year\":49999"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> solar month",
        maxBody,
        "\"month\":12"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> solar day",
        maxBody,
        "\"day\":31"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> monthName",
        maxBody,
        "\"monthName\":\"December\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> weekday",
        maxBody,
        "\"weekday\":\"Tuesday\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> dayOfYear",
        maxBody,
        "\"dayOfYear\":365"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> leapYear",
        maxBody,
        "\"leapYear\":false"
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> lunar",
        maxBody,
        "\"lunar\""
    ))
        passed++;

    total++;
    if(check(
        "Global Solar Day 18261759 -> architecture",
        maxBody,
        "\"name\":\"Gabary V2\""
    ))
        passed++;

    std::remove("gabary_boundary_min.json");
    std::remove("gabary_boundary_max.json");

    std::cout
        << "========================================\n";

    if(passed == total)
    {
        std::cout
            << " Gabary V2 API Response Boundary Schema: PASSED\n"
            << " Checks: "
            << passed
            << "/"
            << total
            << "\n"
            << "========================================\n";

        return 0;
    }

    std::cout
        << " Gabary V2 API Response Boundary Schema: FAILED\n"
        << " Checks: "
        << passed
        << "/"
        << total
        << "\n"
        << "========================================\n";

    return 1;
}
