#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "GabaryTemporalService.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service Contract Test\n"
        << "============================================\n";

    GabaryTemporalService service;

    constexpr int64_t MIN_DAY = 1;
    constexpr int64_t MAX_DAY = 18261759;

    // ------------------------------------------------
    // 1. Minimum Global Day contract
    // ------------------------------------------------
    {
        const auto result = service.queryDay(MIN_DAY);

        assert(result.dayId == MIN_DAY);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Minimum Global Day contract\n";
    }

    // ------------------------------------------------
    // 2. Maximum Global Day contract
    // ------------------------------------------------
    {
        const auto result = service.queryDay(MAX_DAY);

        assert(result.dayId == MAX_DAY);
        assert(result.solar.solarYear > 0);
        assert(result.lunar.year > 0);

        std::cout << "[PASS] Maximum Global Day contract\n";
    }

    // ------------------------------------------------
    // 3. Solar epoch query
    // ------------------------------------------------
    {
        const auto result = service.querySolar(1, 1, 1);

        assert(result.dayId == MIN_DAY);
        assert(result.solar.solarYear == 1);
        assert(result.solar.solarMonth == 1);
        assert(result.solar.solarDay == 1);

        std::cout << "[PASS] Solar epoch query\n";
    }

    // ------------------------------------------------
    // 4. Solar final boundary query
    // ------------------------------------------------
    {
        const auto result = service.queryDay(MAX_DAY);

        assert(result.dayId == MAX_DAY);
        assert(result.solar.solarYear == 49999);

        std::cout << "[PASS] Solar final boundary query\n";
    }

    // ------------------------------------------------
    // 5. Lunar epoch query
    // ------------------------------------------------
    {
        const auto result = service.queryLunar(1, 1, 1);

        assert(result.dayId == MIN_DAY);
        assert(result.lunar.year == 1);
        assert(result.lunar.month == 1);
        assert(result.lunar.day == 1);

        std::cout << "[PASS] Lunar epoch query\n";
    }

    // ------------------------------------------------
    // 6. Lunar final supported boundary
    // ------------------------------------------------
    {
        const auto result = service.queryDay(MAX_DAY);

        assert(result.dayId == MAX_DAY);
        assert(result.lunar.year > 0);
        assert(result.lunar.month > 0);
        assert(result.lunar.day > 0);

        std::cout << "[PASS] Lunar final supported boundary\n";
    }

    // ------------------------------------------------
    // 7. Solar round-trip across timeline
    // ------------------------------------------------
    {
        const std::vector<int64_t> days = {
            1,
            365,
            366,
            1000,
            36525,
            100000,
            500000,
            1000000,
            5000000,
            10000000,
            15000000,
            MAX_DAY
        };

        for (const int64_t dayId : days)
        {
            const auto original = service.queryDay(dayId);

            const auto restored =
                service.querySolar(
                    original.solar.solarYear,
                    original.solar.solarMonth,
                    original.solar.solarDay
                );

            assert(restored.dayId == dayId);
            assert(
                restored.solar.solarYear ==
                original.solar.solarYear
            );
            assert(
                restored.solar.solarMonth ==
                original.solar.solarMonth
            );
            assert(
                restored.solar.solarDay ==
                original.solar.solarDay
            );
        }

        std::cout
            << "[PASS] Solar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 8. Lunar round-trip across timeline
    // ------------------------------------------------
    {
        const std::vector<int64_t> days = {
            1,
            1000,
            36525,
            100000,
            500000,
            1000000,
            5000000,
            10000000,
            15000000,
            MAX_DAY
        };

        for (const int64_t dayId : days)
        {
            const auto original = service.queryDay(dayId);

            const auto restored =
                service.queryLunar(
                    original.lunar.year,
                    original.lunar.month,
                    original.lunar.day
                );

            assert(restored.dayId == dayId);
            assert(
                restored.lunar.year ==
                original.lunar.year
            );
            assert(
                restored.lunar.month ==
                original.lunar.month
            );
            assert(
                restored.lunar.day ==
                original.lunar.day
            );
        }

        std::cout
            << "[PASS] Lunar query round-trip across timeline\n";
    }

    // ------------------------------------------------
    // 9. Shared Global Solar Day contract
    // ------------------------------------------------
    {
        const auto solar =
            service.querySolar(2026, 7, 26);

        assert(solar.dayId == 739823);

        const auto byDay =
            service.queryDay(solar.dayId);

        assert(byDay.dayId == solar.dayId);
        assert(
            byDay.solar.solarYear ==
            solar.solar.solarYear
        );
        assert(
            byDay.solar.solarMonth ==
            solar.solar.solarMonth
        );
        assert(
            byDay.solar.solarDay ==
            solar.solar.solarDay
        );

        std::cout
            << "[PASS] Shared Global Solar Day contract\n";
    }

    // ------------------------------------------------
    // 10. Temporal coordinate integrity
    // ------------------------------------------------
    {
        const auto result =
            service.queryDay(739823);

        assert(result.dayId == 739823);
        assert(result.solar.solarYear == 2026);
        assert(result.solar.solarMonth == 7);
        assert(result.solar.solarDay == 26);
        assert(result.lunar.year > 0);
        assert(result.lunar.month > 0);
        assert(result.lunar.day > 0);

        std::cout
            << "[PASS] Temporal coordinate integrity\n";
    }

    // ------------------------------------------------
    // 11. Report by Global Day contract
    // ------------------------------------------------
    {
        const std::string report =
            service.reportByDay(739823);

        assert(!report.empty());
        assert(
            report.find("Global Day ID : 739823") !=
            std::string::npos
        );
        assert(
            report.find("SOLAR CALENDAR") !=
            std::string::npos
        );
        assert(
            report.find("LUNAR CALENDAR") !=
            std::string::npos
        );

        std::cout
            << "[PASS] Report by Global Day contract\n";
    }

    // ------------------------------------------------
    // 12. Report by Solar Date contract
    // ------------------------------------------------
    {
        const std::string report =
            service.reportBySolar(2026, 7, 26);

        assert(!report.empty());
        assert(
            report.find("Global Day ID : 739823") !=
            std::string::npos
        );

        std::cout
            << "[PASS] Report by Solar Date contract\n";
    }

    // ------------------------------------------------
    // 13. Report by Lunar Date contract
    // ------------------------------------------------
    {
        const std::string report =
            service.reportByLunar(1, 1, 1);

        assert(!report.empty());
        assert(
            report.find("Global Day ID : 1") !=
            std::string::npos
        );

        std::cout
            << "[PASS] Report by Lunar Date contract\n";
    }

    // ------------------------------------------------
    // Final result
    // ------------------------------------------------
    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service Contract: PASSED\n"
        << "============================================\n";

    return 0;
}
