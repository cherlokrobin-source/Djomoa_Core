cmake_minimum_required(VERSION 3.15)

project(GoldenCalendar2083_Core)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)



# ==============================
# Main Core Library
# ==============================

add_library(GoldenCalendar2083_Core

    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
    src/WeekEngine.cpp
    src/TimeEngine.cpp
    src/ArchiveEngine.cpp
    src/ArchiveGenerator.cpp

)



# ==============================
# Tests
# ==============================


add_executable(
    Cycle33Test

    tests/cycle_33_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)


add_executable(
    MultiCycleTest

    tests/multi_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)


add_executable(
    Year2083Test

    tests/year_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)


add_executable(
    CycleComparisonTest

    tests/cycle_comparison_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)


add_executable(
    EngineCycleCompare

    tests/engine_cycle_compare.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



add_executable(
    ChronologyMainTest

    tests/chronology_main_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



add_executable(
    DayIdTest

    tests/dayid_test.cpp
    src/SolarEngine.cpp
)



add_executable(
    LongCycleTest

    tests/long_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)



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



add_executable(
    LongTimeEngineTest

    src/LongTimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
    tests/long_time_engine_test.cpp

)



# ==============================
# Archive Engine Test
# ==============================

add_executable(
    ArchiveEngineTest

    tests/archive_engine_test.cpp

)


target_link_libraries(
    ArchiveEngineTest

    GoldenCalendar2083_Core

)


target_include_directories(
    ArchiveEngineTest PRIVATE include
)



# ==============================
# CLI Application
# ==============================

add_executable(
    GoldenCalendarCLI

    examples/GoldenCalendarCLI.cpp

)


target_link_libraries(
    GoldenCalendarCLI

    GoldenCalendar2083_Core

)

add_executable(
    ArchiveGeneratorTest

    tests/archive_generator_test.cpp
)

target_link_libraries(
    ArchiveGeneratorTest
    GoldenCalendar2083_Core
)

target_include_directories(
    ArchiveGeneratorTest PRIVATE
    include
)
add_executable(
    CycleAccuracyTest

    tests/cycle_accuracy_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

target_include_directories(
    CycleAccuracyTest PRIVATE include
)
add_executable(
    Cycle33_34_SynchronizationTest

    tests/Cycle33_34_SynchronizationTest.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

target_include_directories(
    Cycle33_34_SynchronizationTest PRIVATE include
)
add_executable(
    CycleSynchronizationLongTermTest

    tests/CycleSynchronizationLongTermTest.cpp
)
