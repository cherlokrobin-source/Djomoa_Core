cmake_minimum_required(VERSION 3.15)

project(GoldenCalendar2083_Core)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)



# Main Engine

add_library(GoldenCalendar2083_Core

    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
    src/WeekEngine.cpp
    src/TimeEngine.cpp

)



# Lunar 33 Year Cycle Test

add_executable(
    Cycle33Test

    tests/cycle_33_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Multi 33 Cycle Test

add_executable(
    MultiCycleTest

    tests/multi_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Year 2083 Test

add_executable(
    Year2083Test

    tests/year_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Cycle Comparison

add_executable(
    CycleComparisonTest

    tests/cycle_comparison_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Engine Cycle Compare

add_executable(
    EngineCycleCompare

    tests/engine_cycle_compare.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Chronology Main Test

add_executable(
    ChronologyMainTest

    tests/chronology_main_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Day ID Test

add_executable(
    DayIdTest

    tests/dayid_test.cpp
    src/SolarEngine.cpp
)



# Long Cycle Test

add_executable(
    LongCycleTest

    tests/long_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



# Reference 2083 Years + 3 Months + 3 Days

add_executable(
    Reference2083Test

    tests/reference_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)
add_executable(
    CycleReferenceCompare

    tests/cycle_reference_compare.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)
add_executable(
    LunarAlignmentTest

    tests/lunar_alignment_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)
add_executable(
    LunarCycleDateCompareTest

    tests/LunarCycleDateCompareTest.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)
add_executable(
    TimeEngineTest

    tests/time_engine_test.cpp
    src/TimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)
add_executable(LongTimeEngineTest
    src/LongTimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
    tests/long_time_engine_test.cpp
)
add_executable(GoldenCalendarCLI
    examples/GoldenCalendarCLI.cpp
)

target_link_libraries(GoldenCalendarCLI
    GoldenCalendar2083_Core
)
target_include_directories(LongTimeEngineTest PRIVATE include)
