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
        << " Gabary V2 Query Engine Contract Test\n"
        << "============================================\n";

    GabaryQueryEngine query;

    constexpr int64_t MIN_DAY = 1;
    constexpr int64_t MAX_DAY = 18261759;

    // ------------------------------------------------
    // 1. Minimum Global Day
    // ------------------------------------------------
    {
        auto result = query.queryDay(MIN_DAY);

        assert(result.dayId == MIN_DAY);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout
            << "[PASS] Minimum Global Day contract\n";
    }

    // ------------------------------------------------
    // 2. Maximum Global Day
    // ------------------------------------------------
    {
        auto result = query.queryDay(MAX_DAY);

        assert(result.dayId == MAX_DAY);
        assert(result.solar.solarYear == 49999);
        assert(result.solar.solarMonth == 12);
        assert(result.solar.solarDay == 31);
        assert(result.lunar.year == 0); assert(result.lunar.month == 0); assert(result.lunar.day == 0);

        std::cout
            << "[PASS] Maximum Global Day contract\n";
    }

    // ------------------------------------------------
    // 3. Solar epoch query
    // ------------------------------------------------
    {
        auto result = query.querySolar(1, 1, 1);

        assert(result.dayId == MIN_DAY);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);

        std::cout
            << "[PASS] Solar epoch query\n";
    }

    // ------------------------------------------------
    // 4. Solar final boundary query
    // ------------------------------------------------
    {
        auto result = query.querySolar(49999, 12, 31);

        assert(result.dayId == MAX_DAY);
        assert(result.solar.solarYear == 49999);
        assert(result.solar.solarMonth == 12);
        assert(result.solar.solarDay == 31);

        std::cout
            << "[PASS] Solar final boundary query\n";
    }

    // ------------------------------------------------
    // 5. Lunar epoch query
    // ------------------------------------------------
    {
        auto result = query.queryLunar(1, 1, 1);

        assert(result.dayId == MIN_DAY);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout
            << "[PASS] Lunar epoch query\n";
    }

    // ------------------------------------------------
    // 6. Lunar final supported boundary
    // ------------------------------------------------
    {
        auto result = query.queryLunar(49999, 12, 29);

        assert(result.dayId >= MIN_DAY);
        assert(result.dayId <= MAX_DAY);
        assert(result.lunar.year == 49999);
        assert(result.lunar.month == 12);
        assert(result.lunar.day == 29);

        std::cout
            << "[PASS] Lunar final supported boundary\n";
    }

    // ------------------------------------------------
    // 7. Solar round-trip across timeline
    // ------------------------------------------------
    {
        struct SolarPoint
        {
            int year;
            int month;
            int day;
        };

        const std::vector<SolarPoint> points =
        {
            {1, 1, 1},
            {100, 1, 1},
            {1000, 6, 15},
            {2026, 7, 26},
            {10000, 1, 1},
            {25000, 6, 15},
            {40000, 12, 1},
            {49999, 12, 31}
        };

        for (const auto& point : points)
        {
            auto result =
                query.querySolar(
                    point.year,
                    point.month,
                    point.day
                );

            auto restored =
                query.queryDay(result.dayId);

            assert(
                restored.dayId == result.dayId
            );

            assert(
                restored.solar.solarYear ==
                point.year
            );

            assert(
                restored.solar.solarMonth ==
                point.month
            );

            assert(
                restored.solar.solarDay ==
                point.day
            );
        }

        std::cout
            << "[PASS] Solar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 8. Lunar round-trip across timeline
    // ------------------------------------------------
    {
        struct LunarPoint
        {
            int year;
            int month;
            int day;
        };

        const std::vector<LunarPoint> points =
        {
            {1, 1, 1},
            {100, 1, 1},
            {1000, 6, 15},
            {10000, 1, 1},
            {25000, 6, 15},
            {40000, 12, 1},
            {49999, 12, 29}
        };

        for (const auto& point : points)
        {
            auto result =
                query.queryLunar(
                    point.year,
                    point.month,
                    point.day
                );

            auto restored =
                query.queryDay(result.dayId);

            assert(
                restored.dayId == result.dayId
            );

            assert(
                restored.lunar.year ==
                point.year
            );

            assert(
                restored.lunar.month ==
                point.month
            );

            assert(
                restored.lunar.day ==
                point.day
            );
        }

        std::cout
            << "[PASS] Lunar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 9. Shared Global Solar Day
    // ------------------------------------------------
    {
        const std::vector<int64_t> days =
        {
            1,
            365,
            366,
            1000,
            739823,
            1000000,
            5000000,
            10000000,
            15000000,
            MAX_DAY
        };

        constexpr int64_t LUNAR_MAX_DAY = 17716312;

        for (int64_t day : days)
        {
            auto result = query.queryDay(day);

            assert(result.dayId == day);

            auto solar =
                query.querySolar(
                    result.solar.solarYear,
                    result.solar.solarMonth,
                    result.solar.solarDay
                );

            assert(solar.dayId == day);

            if (day <= LUNAR_MAX_DAY)
            {
                auto lunar =
                    query.queryLunar(
                        result.lunar.year,
                        result.lunar.month,
                        result.lunar.day
                    );

                assert(lunar.dayId == day);
            }
            else
            {
                assert(result.lunar.year == 0);
                assert(result.lunar.month == 0);
                assert(result.lunar.day == 0);
                assert(result.lunar.dayId == 0);
            }
        }

        std::cout
            << "[PASS] Shared Global Solar Day contract\n";
    }

    // ------------------------------------------------
    // 10. Temporal coordinate integrity
    // ------------------------------------------------
    {
        auto solar =
            query.querySolar(2026, 7, 26);

        auto lunar =
            query.queryLunar(
                solar.lunar.year,
                solar.lunar.month,
                solar.lunar.day
            );

        auto byDay =
            query.queryDay(solar.dayId);

        assert(lunar.dayId == solar.dayId);
        assert(byDay.dayId == solar.dayId);

        assert(
            byDay.solar.solarYear ==
            solar.solar.solarYear
        );

        assert(
            byDay.lunar.year ==
            lunar.lunar.year
        );

        assert(
            byDay.lunar.month ==
            lunar.lunar.month
        );

        assert(
            byDay.lunar.day ==
            lunar.lunar.day
        );

        std::cout
            << "[PASS] Temporal coordinate integrity\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Query Engine Contract: PASSED\n"
        << "============================================\n";

    return 0;
}
