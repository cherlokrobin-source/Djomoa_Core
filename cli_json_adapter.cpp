#include <iostream>
#include <string>
#include <cstdlib>

#include "GabaryDualCalendarEngine.h"
#include "SolarEngineV2.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "{\"error\": \"Invalid arguments\"}\n";
        return 1;
    }

    std::string mode = argv[1];
    Gabary::GabaryDualCalendarEngine engine;
    Gabary::SolarEngineV2 solarEngine;

    if (mode == "day" && argc >= 3) {
        uint64_t day = std::strtoull(argv[2], nullptr, 10);
        auto result = engine.getDate(day);
        auto solarDate = solarEngine.fromDayId(day);

        std::cout << "{\n"
                  << "  \"globalSolarDay\": " << day << ",\n"
                  << "  \"solarDate\": {\"day\": " << solarDate.day << ", \"month\": " << solarDate.month << ", \"year\": " << solarDate.year << "},\n"
                  << "  \"lunarDate\": {\"day\": " << result.lunar.day << ", \"month\": " << result.lunar.month << ", \"year\": " << result.lunar.year << "}\n"
                  << "}\n";
    } 
    else if (mode == "solar" && argc >= 5) {
        int year = std::atoi(argv[2]);
        int month = std::atoi(argv[3]);
        int day = std::atoi(argv[4]);

        uint64_t dayId = solarEngine.toDayId(year, month, day);
        auto result = engine.getDate(dayId);

        std::cout << "{\n"
                  << "  \"calculatedDayId\": " << dayId << ",\n"
                  << "  \"querySolar\": {\"day\": " << day << ", \"month\": " << month << ", \"year\": " << year << "},\n"
                  << "  \"lunarDate\": {\"day\": " << result.lunar.day << ", \"month\": " << result.lunar.month << ", \"year\": " << result.lunar.year << "}\n"
                  << "}\n";
    }
    else if (mode == "lunar" && argc >= 5) {
        int year = std::atoi(argv[2]);
        int month = std::atoi(argv[3]);
        int day = std::atoi(argv[4]);

        int64_t dayId = engine.lunarToDayId(year, month, day);
        auto solarDate = solarEngine.fromDayId(dayId);

        std::cout << "{\n"
                  << "  \"calculatedDayId\": " << dayId << ",\n"
                  << "  \"queryLunar\": {\"day\": " << day << ", \"month\": " << month << ", \"year\": " << year << "},\n"
                  << "  \"solarDate\": {\"day\": " << solarDate.day << ", \"month\": " << solarDate.month << ", \"year\": " << solarDate.year << "}\n"
                  << "}\n";
    }

    return 0;
}
