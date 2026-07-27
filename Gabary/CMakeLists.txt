cmake_minimum_required(VERSION 3.10)

project(Gabary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    include
)


enable_testing()


# ==========================
# Week Cycle Engine Test
# ==========================

add_executable(
    WeekCycleEngineTest
    src/WeekCycleEngine.cpp
    tests/WeekCycleEngineTest.cpp
)

add_test(
    NAME WeekCycleEngineTest
    COMMAND WeekCycleEngineTest
)



# ==========================
# Leap Year Rules Test
# ==========================

add_executable(
    LeapYearRulesTest
    src/LeapYearRules.cpp
    tests/LeapYearRulesTest.cpp
)

add_test(
    NAME LeapYearRulesTest
    COMMAND LeapYearRulesTest
)
add_executable(
    SolarEngineV2Test
    src/SolarEngineV2.cpp
    src/LeapYearRules.cpp
    tests/SolarEngineV2Test.cpp
)

add_test(
    NAME SolarEngineV2Test
    COMMAND SolarEngineV2Test
)
