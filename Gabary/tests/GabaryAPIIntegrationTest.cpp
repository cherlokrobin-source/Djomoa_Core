#include <cassert>
#include <iostream>
#include <string>

#include "GabaryAPIAdapter.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 API Integration Test\n"
        << "============================================\n";

    GabaryAPIAdapter api;

    // ------------------------------------------------
    // GET Day 1
    // ------------------------------------------------
    {
        std::string json = api.getDay(1);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);

        assert(json.find("\"solar\":") != std::string::npos);
        assert(json.find("\"year\":1") != std::string::npos);
        assert(json.find("\"month\":1") != std::string::npos);
        assert(json.find("\"day\":1") != std::string::npos);

        assert(json.find("\"lunar\":") != std::string::npos);

        std::cout
            << "[PASS] API Day 1\n";
    }

    // ------------------------------------------------
    // GET Solar 2026-07-26
    // ------------------------------------------------
    {
        std::string json = api.getSolar(2026, 7, 26);

        assert(!json.empty());
        assert(json.find("\"dayId\":739823") != std::string::npos);

        assert(json.find("\"solar\":") != std::string::npos);
        assert(json.find("\"lunar\":") != std::string::npos);

        std::cout
            << "[PASS] API Solar 2026-07-26\n";
    }

    // ------------------------------------------------
    // GET Lunar 1-1-1
    // ------------------------------------------------
    {
        std::string json = api.getLunar(1, 1, 1);

        assert(!json.empty());
        assert(json.find("\"dayId\":1") != std::string::npos);

        assert(json.find("\"solar\":") != std::string::npos);
        assert(json.find("\"lunar\":") != std::string::npos);

        std::cout
            << "[PASS] API Lunar 1-1-1\n";
    }

    // ------------------------------------------------
    // Shared Global Day Coordinate
    // ------------------------------------------------
    {
        std::string solar = api.getSolar(2026, 7, 26);

        assert(
            solar.find("\"dayId\":739823")
            != std::string::npos
        );

        std::cout
            << "[PASS] Shared Global Day API coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 API Integration: PASSED\n"
        << "============================================\n";

    return 0;
}
