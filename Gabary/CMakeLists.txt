cmake_minimum_required(VERSION 3.10)

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
