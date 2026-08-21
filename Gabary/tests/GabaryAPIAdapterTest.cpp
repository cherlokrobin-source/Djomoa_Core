#include <cassert>
#include <iostream>
#include <string>

#include "GabaryAPIAdapter.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter Test\n"
        << "============================================\n";

    GabaryAPIAdapter api;

    // ------------------------------------------------
    // GET by Global Day
    // ------------------------------------------------
    {
        std::string json = api.getDay(1);

        assert(!json.empty());

        // Global coordinate
        assert(
            json.find("\"dayId\":1")
            != std::string::npos
        );

        // Solar calendar
        assert(
            json.find("\"solar\"")
            != std::string::npos
        );

        assert(
            json.find("\"weekday\"")
            != std::string::npos
        );

        assert(
            json.find("\"year\":1")
            != std::string::npos
        );

        assert(
            json.find("\"month\":1")
            != std::string::npos
        );

        assert(
            json.find("\"monthName\"")
            != std::string::npos
        );

        assert(
            json.find("\"day\":1")
            != std::string::npos
        );

        assert(
            json.find("\"dayOfYear\":1")
            != std::string::npos
        );

        assert(
            json.find("\"leapYear\"")
            != std::string::npos
        );

        assert(
            json.find("\"weekIndex\"")
            != std::string::npos
        );

        // Lunar calendar
        assert(
            json.find("\"lunar\"")
            != std::string::npos
        );

        assert(
            json.find("\"architecture\"")
            != std::string::npos
        );

        std::cout
            << "[PASS] API getDay(1) complete JSON\n";
    }

    // ------------------------------------------------
    // GET by Solar Date
    // ------------------------------------------------
    {
        std::string json =
            api.getSolar(2026, 7, 26);

        assert(!json.empty());

        assert(
            json.find("\"dayId\":739823")
            != std::string::npos
        );

        assert(
            json.find("\"year\":2026")
            != std::string::npos
        );

        assert(
            json.find("\"month\":7")
            != std::string::npos
        );

        assert(
            json.find("\"day\":26")
            != std::string::npos
        );

        assert(
            json.find("\"monthName\"")
            != std::string::npos
        );

        assert(
            json.find("\"dayOfYear\"")
            != std::string::npos
        );

        assert(
            json.find("\"leapYear\"")
            != std::string::npos
        );

        assert(
            json.find("\"lunar\"")
            != std::string::npos
        );

        std::cout
            << "[PASS] API getSolar(2026-07-26) complete JSON\n";
    }

    // ------------------------------------------------
    // GET by Lunar Date
    // ------------------------------------------------
    {
        std::string json =
            api.getLunar(1, 1, 1);

        assert(!json.empty());

        assert(
            json.find("\"dayId\":1")
            != std::string::npos
        );

        assert(
            json.find("\"lunar\"")
            != std::string::npos
        );

        assert(
            json.find("\"year\":1")
            != std::string::npos
        );

        assert(
            json.find("\"month\":1")
            != std::string::npos
        );

        assert(
            json.find("\"day\":1")
            != std::string::npos
        );

        assert(
            json.find("\"monthName\"")
            != std::string::npos
        );

        assert(
            json.find("\"dayOfYear\"")
            != std::string::npos
        );

        std::cout
            << "[PASS] API getLunar(1-1-1) complete JSON\n";
    }

    // ------------------------------------------------
    // Shared Global Day Coordinate
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
            << "[PASS] Shared Global Day API coordinate\n";
    }

    // ------------------------------------------------
    // Architecture Metadata
    // ------------------------------------------------
    {
        std::string json =
            api.getDay(739823);

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
            << "[PASS] API architecture metadata\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter: PASSED\n"
        << "============================================\n";

    return 0;
}
