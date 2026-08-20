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
        assert(json.find("\"dayId\":1") != std::string::npos);
        assert(json.find("\"solar\"") != std::string::npos);
        assert(json.find("\"lunar\"") != std::string::npos);
        assert(json.find("\"year\":1") != std::string::npos);

        std::cout << "[PASS] API getDay(1)\n";
    }

    // ------------------------------------------------
    // GET by Solar Date
    // ------------------------------------------------
    {
        std::string json = api.getSolar(2026, 7, 26);

        assert(!json.empty());
        assert(json.find("\"dayId\":739823") != std::string::npos);
        assert(json.find("\"year\":2026") != std::string::npos);
        assert(json.find("\"month\":7") != std::string::npos);
        assert(json.find("\"day\":26") != std::string::npos);

        std::cout << "[PASS] API getSolar(2026-07-26)\n";
    }

    // ------------------------------------------------
    // GET by Lunar Date
    // ------------------------------------------------
    {
        std::string json = api.getLunar(1, 1, 1);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);
        assert(json.find("\"lunar\"") != std::string::npos);

        std::cout << "[PASS] API getLunar(1-1-1)\n";
    }

    // ------------------------------------------------
    // Shared Global Day Coordinate
    // ------------------------------------------------
    {
        std::string bySolar = api.getSolar(2026, 7, 26);
        std::string byDay   = api.getDay(739823);

        assert(bySolar.find("\"dayId\":739823") != std::string::npos);
        assert(byDay.find("\"dayId\":739823") != std::string::npos);

        std::cout << "[PASS] Shared Global Day API coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter: PASSED\n"
        << "============================================\n";

    return 0;
}
