#include <cassert>
#include <iostream>
#include <string>

#include "GabaryAPIAdapter.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter Contract Test\n"
        << "============================================\n";

    GabaryAPIAdapter api;

    constexpr int64_t MIN_DAY = 1;
    constexpr int64_t MAX_DAY = 18261759;

    // ------------------------------------------------
    // Minimum Global Day contract
    // ------------------------------------------------
    {
        std::string json = api.getDay(MIN_DAY);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);
        assert(json.find("\"solar\"") != std::string::npos);
        assert(json.find("\"lunar\"") != std::string::npos);

        std::cout << "[PASS] Minimum Global Day contract\n";
    }

    // ------------------------------------------------
    // Maximum Global Day contract
    // ------------------------------------------------
    {
        std::string json = api.getDay(MAX_DAY);

        assert(!json.empty());
        assert(
            json.find("\"dayId\":18261759")
            != std::string::npos
        );

        std::cout << "[PASS] Maximum Global Day contract\n";
    }

    // ------------------------------------------------
    // Solar epoch contract
    // ------------------------------------------------
    {
        std::string json = api.getSolar(1, 1, 1);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);
        assert(json.find("\"year\":1") != std::string::npos);
        assert(json.find("\"month\":1") != std::string::npos);
        assert(json.find("\"day\":1") != std::string::npos);

        std::cout << "[PASS] Solar epoch query\n";
    }

    // ------------------------------------------------
    // Solar final boundary contract
    // ------------------------------------------------
    {
        std::string json = api.getSolar(49999, 12, 31);

        assert(!json.empty());
        assert(
            json.find("\"dayId\":18261759")
            != std::string::npos
        );

        assert(
            json.find("\"year\":49999")
            != std::string::npos
        );

        assert(
            json.find("\"month\":12")
            != std::string::npos
        );

        assert(
            json.find("\"day\":31")
            != std::string::npos
        );

        std::cout << "[PASS] Solar final boundary query\n";
    }

    // ------------------------------------------------
    // Lunar epoch contract
    // ------------------------------------------------
    {
        std::string json = api.getLunar(1, 1, 1);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);
        assert(json.find("\"lunar\"") != std::string::npos);

        std::cout << "[PASS] Lunar epoch query\n";
    }

    // ------------------------------------------------
    // Lunar final supported boundary
    // ------------------------------------------------
    {
        std::string json =
            api.getLunar(49999, 12, 30);

        assert(!json.empty());
        assert(json.find("\"lunar\"") != std::string::npos);
        assert(json.find("\"dayId\"") != std::string::npos);

        std::cout
            << "[PASS] Lunar final supported boundary\n";
    }

    // ------------------------------------------------
    // Solar round-trip across timeline
    // ------------------------------------------------
    {
        const int solarDates[][3] =
        {
            {1, 1, 1},
            {100, 1, 1},
            {1000, 6, 15},
            {2026, 7, 26},
            {10000, 12, 31},
            {25000, 1, 1},
            {49999, 12, 31},
            {50000, 12, 31}
        };

        for (const auto& date : solarDates)
        {
            std::string json =
                api.getSolar(
                    date[0],
                    date[1],
                    date[2]
                );

            assert(!json.empty());
            assert(json.find("\"dayId\"") != std::string::npos);
            assert(json.find("\"solar\"") != std::string::npos);
            assert(json.find("\"lunar\"") != std::string::npos);
        }

        std::cout
            << "[PASS] Solar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // Lunar round-trip across timeline
    // ------------------------------------------------
    {
        const int lunarDates[][3] =
        {
            {1, 1, 1},
            {100, 1, 1},
            {1000, 6, 15},
            {10000, 1, 1},
            {25000, 6, 15},
            {49999, 12, 30}
        };

        for (const auto& date : lunarDates)
        {
            std::string json =
                api.getLunar(
                    date[0],
                    date[1],
                    date[2]
                );

            assert(!json.empty());
            assert(json.find("\"dayId\"") != std::string::npos);
            assert(json.find("\"solar\"") != std::string::npos);
            assert(json.find("\"lunar\"") != std::string::npos);
        }

        std::cout
            << "[PASS] Lunar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // Shared Global Solar Day contract
    // ------------------------------------------------
    {
        std::string bySolar =
            api.getSolar(2026, 7, 26);

        std::string byDay =
            api.getDay(739823);

        assert(
            bySolar.find("\"dayId\":739823")
            != std::string::npos
        );

        assert(
            byDay.find("\"dayId\":739823")
            != std::string::npos
        );

        std::cout
            << "[PASS] Shared Global Solar Day contract\n";
    }

    // ------------------------------------------------
    // Architecture metadata contract
    // ------------------------------------------------
    {
        std::string json = api.getDay(739823);

        assert(
            json.find("\"architecture\"")
            != std::string::npos
        );

        assert(
            json.find("\"name\":\"Gabary V2\"")
            != std::string::npos
        );

        assert(
            json.find(
                "\"engine\":\"GabaryDualCalendarEngine\""
            )
            != std::string::npos
        );

        assert(
            json.find(
                "\"coordinate\":\"Global Solar Day\""
            )
            != std::string::npos
        );

        assert(
            json.find("\"validation\":\"PASSED\"")
            != std::string::npos
        );

        std::cout
            << "[PASS] API architecture metadata contract\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter Contract: PASSED\n"
        << "============================================\n";

    return 0;
}
