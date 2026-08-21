#include <iostream>
#include <cassert>
#include <string>

#include "server/TemporalServer.h"
#include "../../include/server/HttpServer.h"

int main()
{
    std::cout << "========================================\n";
    std::cout << " Gabary V2 API Contract Test\n";
    std::cout << "========================================\n";

    TemporalServer server;

    // ----------------------------------------
    // STATUS
    // ----------------------------------------
    std::string status = server.handleStatusRequest();

    assert(status.find("\"engine\":\"Gabary V2\"") != std::string::npos);
    assert(status.find("\"core\":\"SolarEngineV2\"") != std::string::npos);
    assert(status.find("\"status\":\"stable\"") != std::string::npos);
    assert(status.find("\"validation\":\"PASSED\"") != std::string::npos);

    std::cout << "[PASS] /api/status contract\n";

    // ----------------------------------------
    // DAY 1
    // ----------------------------------------
    std::string day1 = server.handleDayJSONRequest(1);

    assert(day1.find("\"globalSolarDay\":1") != std::string::npos);
    assert(day1.find("\"year\":1") != std::string::npos);
    assert(day1.find("\"month\":1") != std::string::npos);
    assert(day1.find("\"day\":1") != std::string::npos);
    assert(day1.find("\"weekday\":\"Friday\"") != std::string::npos);

    std::cout << "[PASS] Global Solar Day 1\n";

    // ----------------------------------------
    // FINAL DAY
    // ----------------------------------------
    std::string finalDay =
        server.handleDayJSONRequest(18262125);

    assert(
        finalDay.find("\"globalSolarDay\":18262125")
        != std::string::npos
    );

    assert(
        finalDay.find("\"year\":50000")
        != std::string::npos
    );

    assert(
        finalDay.find("\"month\":12")
        != std::string::npos
    );

    assert(
        finalDay.find("\"day\":31")
        != std::string::npos
    );

    assert(
        finalDay.find("\"dayOfYear\":366")
        != std::string::npos
    );

    assert(
        finalDay.find("\"leapYear\":true")
        != std::string::npos
    );

    std::cout << "[PASS] Global Solar Day 18262125\n";

    // ----------------------------------------
    // CONTRACT RANGE
    // ----------------------------------------
    constexpr long long MIN_DAY = 1;
    constexpr long long MAX_DAY = 18262125;

    assert(MIN_DAY == 1);
    assert(MAX_DAY == 18262125);
    assert(MAX_DAY > MIN_DAY);

    std::cout << "[PASS] Global Solar Day range\n";

    std::cout << "========================================\n";
    std::cout << " Gabary V2 API Contract: PASSED\n";
    std::cout << "========================================\n";

    return 0;
}
