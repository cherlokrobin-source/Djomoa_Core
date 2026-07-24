cmake_minimum_required(VERSION 3.15)

project(GoldenCalendar2083_Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

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
    Archive50000Test
    tests/archive_50000_test.cpp
)

target_link_libraries(
    Archive50000Test
    GoldenCalendar2083_Core
)

add_test(
    NAME Archive50000Test
    COMMAND Archive50000Test
)

add_executable(Cycle33Test
    tests/cycle_33_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(NAME Cycle33Test COMMAND Cycle33Test)



add_executable(MultiCycleTest
    tests/multi_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(NAME MultiCycleTest COMMAND MultiCycleTest)



add_executable(Year2083Test
    tests/year_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(NAME Year2083Test COMMAND Year2083Test)



add_executable(ChronologyMainTest
    tests/chronology_main_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(NAME ChronologyMainTest COMMAND ChronologyMainTest)



add_executable(DayIdTest
    tests/dayid_test.cpp
    src/SolarEngine.cpp
)

add_test(NAME DayIdTest COMMAND DayIdTest)



add_executable(Reference2083Test
    tests/reference_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(NAME Reference2083Test COMMAND Reference2083Test)



add_executable(TimeEngineTest
    tests/time_engine_test.cpp
    src/TimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

add_test(NAME TimeEngineTest COMMAND TimeEngineTest)



add_executable(LongTimeEngineTest
    src/LongTimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
    tests/long_time_engine_test.cpp
)

add_test(NAME LongTimeEngineTest COMMAND LongTimeEngineTest)



# ==============================
# Cycle Synchronization Tests
# ==============================


add_executable(Cycle33_34_SynchronizationTest
    tests/Cycle33_34_SynchronizationTest.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

add_test(
    NAME Cycle33_34_SynchronizationTest
    COMMAND Cycle33_34_SynchronizationTest
)



add_executable(CycleSynchronizationLongTermTest
    tests/CycleSynchronizationLongTermTest.cpp
)

target_link_libraries(
    CycleSynchronizationLongTermTest
    GoldenCalendar2083_Core
)

add_test(
    NAME CycleSynchronizationLongTermTest
    COMMAND CycleSynchronizationLongTermTest
)



# ==============================
# Archive Engine
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

add_test(
    NAME ArchiveEngineTest
    COMMAND ArchiveEngineTest
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
    ArchiveGeneratorTest PRIVATE include
)

add_test(
    NAME ArchiveGeneratorTest
    COMMAND ArchiveGeneratorTest
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



# ==============================
# Cycle Accuracy
# ==============================


add_executable(
    CycleAccuracyTest
    tests/cycle_accuracy_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

target_include_directories(
    CycleAccuracyTest PRIVATE include
)

add_test(
    NAME CycleAccuracyTest
    COMMAND CycleAccuracyTest
)
add_test(
    NAME TemporalCoordinateTest
    COMMAND TemporalCoordinateTest
)
add_executable(
    TemporalCoordinateTest
    tests/temporal_coordinate_test.cpp
    src/TemporalCoordinateEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalCoordinateTest PRIVATE include
)
# ==============================
# Global Temporal ID Test
# ==============================

add_executable(
    GlobalTemporalIDTest
    tests/global_temporal_id_test.cpp
    src/GlobalTemporalID.cpp
)

target_include_directories(
    GlobalTemporalIDTest PRIVATE include
)

add_test(
    NAME GlobalTemporalIDTest
    COMMAND GlobalTemporalIDTest
)
# ==============================
# Global Temporal ID Integration Test
# ==============================

add_executable(
    GlobalTemporalIDIntegrationTest
    tests/global_temporal_id_integration_test.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    GlobalTemporalIDIntegrationTest PRIVATE include
)

add_test(
    NAME GlobalTemporalIDIntegrationTest
    COMMAND GlobalTemporalIDIntegrationTest
)
# ==============================
# Global Temporal Metadata Test
# ==============================

add_executable(
    GlobalTemporalMetadataTest
    tests/global_temporal_metadata_test.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    GlobalTemporalMetadataTest PRIVATE include
)

add_test(
    NAME GlobalTemporalMetadataTest
    COMMAND GlobalTemporalMetadataTest
)
# ==============================
# Temporal Query Engine Test
# ==============================

add_executable(
    TemporalQueryTest
    tests/temporal_query_test.cpp
    src/TemporalQueryEngine.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalQueryTest PRIVATE include
)

add_test(
    NAME TemporalQueryTest
    COMMAND TemporalQueryTest
)
