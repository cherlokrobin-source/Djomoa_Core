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
