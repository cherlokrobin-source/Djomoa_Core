#include "GabaryQueryEngine.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Query Engine Long-Range Test\n"
        << "============================================\n";

    GabaryQueryEngine query;

    constexpr int64_t MIN_DAY = 1;
    constexpr int64_t MAX_DAY = 18261759;

    const std::vector<int64_t> days =
    {
        1,
        354,
        355,
        11693,
        11694,
        739823,
        5000000,
        10000000,
        15000000,
        18261758,
        18261759
    };

    // ------------------------------------------------
    // Global Day -> Dual Calendar
    // ------------------------------------------------

    for (int64_t day : days)
    {
        auto result = query.queryDay(day);

        assert(result.dayId == day);
        assert(result.solar.solarYear >= 1);
        assert(result.solar.solarYear <= 49999);
        assert(result.solar.solarMonth >= 1);
        assert(result.solar.solarMonth <= 12);
        assert(result.solar.solarDay >= 1);
        assert(result.lunar.year >= 1);
        assert(result.lunar.year <= 49999);
        assert(result.lunar.month >= 1);
        assert(result.lunar.month <= 12);
        assert(result.lunar.day >= 1);

        std::cout
            << "[PASS] Query Global Day "
            << day
            << " across timeline\n";
    }

    // ------------------------------------------------
    // Solar round-trip across full timeline
    // ------------------------------------------------

    for (int64_t day : days)
    {
        auto result = query.queryDay(day);

        auto restored = query.querySolar(
            result.solar.solarYear,
            result.solar.solarMonth,
            result.solar.solarDay
        );

        assert(restored.dayId == day);

        std::cout
            << "[PASS] Solar round-trip at Day "
            << day
            << "\n";
    }

    // ------------------------------------------------
    // Lunar round-trip across full timeline
    // ------------------------------------------------

    for (int64_t day : days)
    {
        auto result = query.queryDay(day);

        auto restored = query.queryLunar(
            result.lunar.year,
            result.lunar.month,
            result.lunar.day
        );

        assert(restored.dayId == day);

        std::cout
            << "[PASS] Lunar round-trip at Day "
            << day
            << "\n";
    }

    // ------------------------------------------------
    // Shared Global Solar Day integrity
    // ------------------------------------------------

    for (int64_t day : days)
    {
        auto result = query.queryDay(day);

        auto solar = query.querySolar(
            result.solar.solarYear,
            result.solar.solarMonth,
            result.solar.solarDay
        );

        auto lunar = query.queryLunar(
            result.lunar.year,
            result.lunar.month,
            result.lunar.day
        );

        assert(solar.dayId == day);
        assert(lunar.dayId == day);

        assert(
            solar.dayId ==
            lunar.dayId
        );

        std::cout
            << "[PASS] Shared Global Day integrity at Day "
            << day
            << "\n";
    }

    // ------------------------------------------------
    // Global boundaries
    // ------------------------------------------------

    auto first = query.queryDay(MIN_DAY);

    assert(first.dayId == MIN_DAY);
    assert(first.solar.solarYear == 1);
    assert(first.solar.solarMonth == 1);
    assert(first.solar.solarDay == 1);
    assert(first.lunar.year == 1);
    assert(first.lunar.month == 1);
    assert(first.lunar.day == 1);

    auto last = query.queryDay(MAX_DAY);

    assert(last.dayId == MAX_DAY);
    assert(last.solar.solarYear == 49999);
    assert(last.solar.solarMonth == 12);
    assert(last.solar.solarDay == 31);

    std::cout
        << "[PASS] Global timeline boundaries\n";

    // ------------------------------------------------
    // Final result
    // ------------------------------------------------

    std::cout
        << "============================================\n"
        << " Gabary V2 Query Engine Long-Range: PASSED\n"
        << "============================================\n";

    return 0;
}
