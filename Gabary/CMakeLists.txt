cmake_minimum_required(VERSION 3.15)

project(GoldenCalendar2083_Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(include)


# Core Library

add_library(
    GoldenCalendar2083_Core

    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
    src/WeekEngine.cpp
    src/TimeEngine.cpp
    src/ArchiveEngine.cpp
    src/ArchiveGenerator.cpp
)


# Solar Cycle Engine Test

add_executable(
    SolarCycleEngineTest

    src/SolarCycleEngine.cpp
    src/LeapYearRules.cpp
    tests/SolarCycleEngineTest.cpp
)


target_include_directories(
    SolarCycleEngineTest PRIVATE
    include
)


add_test(
    NAME SolarCycleEngineTest
    COMMAND SolarCycleEngineTest
)cmake_minimum_required(VERSION 3.10)

project(Gabary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    include
)


enable_testing()



# ==========================
# Leap Year Rules Test
# ==========================
add_executable(
    SolarEngineV2Test
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    tests/SolarEngineV2Test.cpp
)

add_test(
    NAME SolarEngineV2Test
    COMMAND SolarEngineV2Test
)
add_executable(
    GlobalSolarDayTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    tests/GlobalSolarDayTest.cpp
)

add_test(
    NAME GlobalSolarDayTest
    COMMAND GlobalSolarDayTest
)
add_executable(
    GlobalSolarDayTransitionTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    tests/GlobalSolarDayTransitionTest.cpp
)

add_test(
    NAME GlobalSolarDayTransitionTest
    COMMAND GlobalSolarDayTransitionTest
)
add_executable(
    LeapCycleSolarTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    tests/LeapCycleSolarTest.cpp
)

add_test(
    NAME LeapCycleSolarTest
    COMMAND LeapCycleSolarTest
)
add_executable(
    SolarTimelineGeneratorTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    src/SolarTimelineGenerator.cpp
    tests/SolarTimelineGeneratorTest.cpp
)

add_test(
    NAME SolarTimelineGeneratorTest
    COMMAND SolarTimelineGeneratorTest
)
add_executable(
    SolarTimelineCycleTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    src/SolarTimelineGenerator.cpp
    tests/SolarTimelineCycleTest.cpp
)

add_test(
    NAME SolarTimelineCycleTest
    COMMAND SolarTimelineCycleTest
)
add_executable(
    SolarTimelineArchiveTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    src/SolarTimelineGenerator.cpp
    src/SolarTimelineArchive.cpp
    tests/SolarTimelineArchiveTest.cpp
)

add_test(
    NAME SolarTimelineArchiveTest
    COMMAND SolarTimelineArchiveTest
)
add_executable(
    SolarTimelineArchiveRangeTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    src/SolarTimelineGenerator.cpp
    src/SolarTimelineArchive.cpp
    tests/SolarTimelineArchiveRangeTest.cpp
)

add_test(
    NAME SolarTimelineArchiveRangeTest
    COMMAND SolarTimelineArchiveRangeTest
)
add_executable(
    SolarTimelineArchiveTransitionTest
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    src/WeekCycleEngine.cpp
    src/SolarTimelineGenerator.cpp
    src/SolarTimelineArchive.cpp
    tests/SolarTimelineArchiveTransitionTest.cpp
)

add_test(
    NAME SolarTimelineArchiveTransitionTest
    COMMAND SolarTimelineArchiveTransitionTest
)
add_executable(
    SolarCycleEngineTest
    src/SolarCycleEngine.cpp
    tests/SolarCycleEngineTest.cpp
)

add_test(
    NAME SolarCycleEngineTest
    COMMAND SolarCycleEngineTest
)
# ============================================
# Solar Time Engine Test
# ============================================

add_executable(
    SolarTimeEngineTest
    Gabary/tests/SolarTimeEngineTest.cpp
    Gabary/src/SolarTimeEngine.cpp
    Gabary/src/SolarArchiveBuilder.cpp
    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarTimeEngineTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarTimeEngineTest
    COMMAND SolarTimeEngineTest
)
# ============================================
# Solar Time Engine Reference Test
# ============================================

add_executable(
    SolarTimeEngineReferenceTest
    Gabary/tests/SolarTimeEngineReferenceTest.cpp
    Gabary/src/SolarTimeEngine.cpp
    Gabary/src/SolarArchiveBuilder.cpp
    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarTimeEngineReferenceTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarTimeEngineReferenceTest
    COMMAND SolarTimeEngineReferenceTest
)
# ============================================
# Gabary Lunar Engine V2
# ============================================

add_executable(
    LunarEngineV2Test
    Gabary/src/LunarEngineV2.cpp
    Gabary/tests/LunarEngineV2Test.cpp
)

target_include_directories(
    LunarEngineV2Test PRIVATE
    Gabary/include
    include
)

add_test(
    NAME LunarEngineV2Test
    COMMAND LunarEngineV2Test
)
# ============================================
# Gabary Lunar Engine V2 - Long Cycle Test
# ============================================

add_executable(
    LunarEngineV2LongCycleTest
    Gabary/src/LunarEngineV2.cpp
    Gabary/tests/LunarEngineV2LongCycleTest.cpp
)

target_include_directories(
    LunarEngineV2LongCycleTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME LunarEngineV2LongCycleTest
    COMMAND LunarEngineV2LongCycleTest
)
