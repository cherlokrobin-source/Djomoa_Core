#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>

#include "GabaryAPIAdapter.h"
#include "GabaryDualCalendarEngine.h"

using namespace Gabary;

static bool contains(
    const std::string& json,
    const std::string& value
)
{
    return json.find(value) != std::string::npos;
}

static void assertField(
    const std::string& json,
    const std::string& field,
    const std::string& value
)
{
    const std::string expected =
        "\"" + field + "\":" + value;

    assert(contains(json, expected));
}

static void assertStringField(
    const std::string& json,
    const std::string& field,
    const std::string& value
)
{
    const std::string expected =
        "\"" + field + "\":\"" + value + "\"";

    assert(contains(json, expected));
}

static void verifyDay(
    GabaryAPIAdapter& api,
    GabaryDualCalendarEngine& engine,
    int64_t dayId
)
{
    const DualCalendarDate date =
        engine.getDate(dayId);

    const std::string json =
        api.getDay(dayId);

    assert(!json.empty());

    // Global coordinate
    assertField(
        json,
        "dayId",
        std::to_string(date.dayId)
    );

    // Solar
    assertField(
        json,
        "year",
        std::to_string(date.solar.solarYear)
    );

    assertField(
        json,
        "month",
        std::to_string(date.solar.solarMonth)
    );

    assertStringField(
        json,
        "monthName",
        date.solar.monthName
    );

    assertField(
        json,
        "day",
        std::to_string(date.solar.solarDay)
    );

    assertField(
        json,
        "dayOfYear",
        std::to_string(date.solar.dayOfYear)
    );

    assertField(
        json,
        "weekIndex",
        std::to_string(date.solar.weekIndex)
    );

    assertStringField(
        json,
        "weekday",
        date.solar.weekName
    );

    assertField(
        json,
        "leapYear",
        date.solar.leapYear ? "true" : "false"
    );

    // Lunar
    assertStringField(
        json,
        "weekday",
        date.lunar.weekday
    );

    assertField(
        json,
        "year",
        std::to_string(date.lunar.year)
    );

    assertField(
        json,
        "month",
        std::to_string(date.lunar.month)
    );

    assertStringField(
        json,
        "monthName",
        date.lunar.monthName
    );

    assertField(
        json,
        "day",
        std::to_string(date.lunar.day)
    );

    assertField(
        json,
        "dayOfYear",
        std::to_string(date.lunar.dayOfYear)
    );

    assertField(
        json,
        "leapYear",
        date.lunar.leapYear ? "true" : "false"
    );
}

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter Data Integrity Test\n"
        << "============================================\n";

    GabaryAPIAdapter api;
    GabaryDualCalendarEngine engine;

    // ------------------------------------------------
    // EPOCH
    // ------------------------------------------------
    verifyDay(api, engine, 1);

    std::cout
        << "[PASS] Epoch JSON data integrity\n";

    // ------------------------------------------------
    // KNOWN INTERNAL COORDINATE
    // 2026-07-26
    // ------------------------------------------------
    verifyDay(api, engine, 739823);

    std::cout
        << "[PASS] Known Global Solar Day JSON integrity\n";

    // ------------------------------------------------
    // FINAL BOUNDARY
    // ------------------------------------------------
    verifyDay(api, engine, 18262125);

    std::cout
        << "[PASS] Final boundary JSON data integrity\n";

    // ------------------------------------------------
    // SHARED COORDINATE
    // ------------------------------------------------
    {
        const DualCalendarDate date =
            engine.getDate(739823);

        const std::string json =
            api.getDay(739823);

        assert(
            contains(
                json,
                "\"dayId\":739823"
            )
        );

        assert(
            date.dayId == 739823
        );
    }

    std::cout
        << "[PASS] Shared Global Solar Day identity\n";

    std::cout
        << "============================================\n"
        << " Gabary V2 API Adapter Data Integrity: PASSED\n"
        << "============================================\n";

    return 0;
}
