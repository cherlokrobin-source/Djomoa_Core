#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

struct BoundaryCase
{
    std::string name;
    std::string path;

    std::string globalSolarDay;
    std::string year;
    std::string month;
    std::string day;
    std::string monthName;
    std::string weekday;
    std::string dayOfYear;
    std::string leapYear;
    std::string lunarYear;
};

bool contains(
    const std::string& text,
    const std::string& value
)
{
    return text.find(value) != std::string::npos;
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

    const std::string base = server;

    const BoundaryCase tests[] =
    {
        {
            "Global Solar Day 1",
            "/api/json/day/1",
            "\"globalSolarDay\":1",
            "\"year\":1",
            "\"month\":1",
            "\"day\":1",
            "\"monthName\":\"January\"",
            "\"weekday\":\"Friday\"",
            "\"dayOfYear\":1",
            "\"leapYear\":false",
            "\"year\":1"
        },

        {
            "Global Solar Day 18262125",
            "/api/json/day/18262125",
            "\"globalSolarDay\":18262125",
            "\"year\":50000",
            "\"month\":12",
            "\"day\":31",
            "\"monthName\":\"December\"",
            "\"weekday\":\"Thursday\"",
            "\"dayOfYear\":366",
            "\"leapYear\":true",
            "\"year\":49999"
        }
    };

    int passed = 0;
    const int expectedChecks = 18;

    for(const auto& test : tests)
    {
        const std::string fileName =
            "/data/data/com.termux/files/home/"
            "GoldenCalendar_Project/"
            "GoldenCalendar_50000_Chronology_Engine/"
            "gabary_boundary_response.json";

        const std::string command =
            "curl -s "
            "\"" + base + test.path + "\""
            " > "
            "\"" + fileName + "\"";

        int result = std::system(command.c_str());

        if(result != 0)
        {
            std::cerr
                << "[FAIL] "
                << test.name
                << " - curl request failed\n";
            continue;
        }

        std::ifstream file(fileName);

        if(!file)
        {
            std::cerr
                << "[FAIL] "
                << test.name
                << " - response body unavailable\n";
            continue;
        }

        std::string body(
            (std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>()
        );

        const std::string checks[] =
        {
            test.globalSolarDay,
            test.year,
            test.month,
            test.day,
            test.monthName,
            test.weekday,
            test.dayOfYear,
            test.leapYear
        };

        const char* names[] =
        {
            "globalSolarDay",
            "year",
            "month",
            "day",
            "monthName",
            "weekday",
            "dayOfYear",
            "leapYear"
        };

        for(int i = 0; i < 8; ++i)
        {
            if(contains(body, checks[i]))
            {
                std::cout
                    << "[PASS] "
                    << test.name
                    << " -> "
                    << names[i]
                    << "\n";

                ++passed;
            }
            else
            {
                std::cout
                    << "[FAIL] "
                    << test.name
                    << " -> "
                    << names[i]
                    << "\n";
            }
        }

        const bool lunarDateValid =
            contains(body, "\"lunarDate\"") &&
            contains(body, test.lunarYear);

        if(lunarDateValid)
        {
            std::cout
                << "[PASS] "
                << test.name
                << " -> lunarDate\n";

            ++passed;
        }
        else
        {
            std::cout
                << "[FAIL] "
                << test.name
                << " -> lunarDate\n";
        }
    }

    std::cout
        << "========================================\n";

    if(passed == expectedChecks)
    {
        std::cout
            << " Gabary V2 API Response Boundary Schema: PASSED\n"
            << " Checks: "
            << passed
            << "/"
            << expectedChecks
            << "\n"
            << "========================================\n";

        return 0;
    }

    std::cout
        << " Gabary V2 API Response Boundary Schema: FAILED\n"
        << " Checks: "
        << passed
        << "/"
        << expectedChecks
        << "\n"
        << "========================================\n";

    return 1;
}
