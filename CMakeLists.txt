cmake_minimum_required(VERSION 3.15)

project(GoldenCalendar2083_Core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(include)


# ============================================
# Main Core Library
# ============================================

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


# ============================================
# Archive Tests
# ============================================

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


# ============================================
# Chronology Tests
# ============================================

add_executable(
    Cycle33Test
    tests/cycle_33_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(
    NAME Cycle33Test
    COMMAND Cycle33Test
)


add_executable(
    MultiCycleTest
    tests/multi_cycle_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(
    NAME MultiCycleTest
    COMMAND MultiCycleTest
)


add_executable(
    Year2083Test
    tests/year_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(
    NAME Year2083Test
    COMMAND Year2083Test
)


add_executable(
    ChronologyMainTest
    tests/chronology_main_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(
    NAME ChronologyMainTest
    COMMAND ChronologyMainTest
)


# ============================================
# Day / Time Tests
# ============================================

add_executable(
    DayIdTest
    tests/dayid_test.cpp
    src/SolarEngine.cpp
)

add_test(
    NAME DayIdTest
    COMMAND DayIdTest
)


add_executable(
    Reference2083Test
    tests/reference_2083_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/ChronologyEngine.cpp
)

add_test(
    NAME Reference2083Test
    COMMAND Reference2083Test
)


add_executable(
    TimeEngineTest
    tests/time_engine_test.cpp
    src/TimeEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

add_test(
    NAME TimeEngineTest
    COMMAND TimeEngineTest
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

add_test(
    NAME LongTimeEngineTest
    COMMAND LongTimeEngineTest
)
# ============================================
# Cycle Synchronization Tests
# ============================================

add_executable(
    Cycle33_34_SynchronizationTest
    tests/Cycle33_34_SynchronizationTest.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

add_test(
    NAME Cycle33_34_SynchronizationTest
    COMMAND Cycle33_34_SynchronizationTest
)


add_executable(
    CycleSynchronizationLongTermTest
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


# ============================================
# Archive Engine Tests
# ============================================

add_executable(
    ArchiveEngineTest
    tests/archive_engine_test.cpp
)

target_link_libraries(
    ArchiveEngineTest
    GoldenCalendar2083_Core
)

target_include_directories(
    ArchiveEngineTest PRIVATE
    include
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
    ArchiveGeneratorTest PRIVATE
    include
)

add_test(
    NAME ArchiveGeneratorTest
    COMMAND ArchiveGeneratorTest
)


# ============================================
# CLI Application
# ============================================

add_executable(
    GoldenCalendarCLI
    examples/GoldenCalendarCLI.cpp
)

target_link_libraries(
    GoldenCalendarCLI
    GoldenCalendar2083_Core
)


# ============================================
# Cycle Accuracy
# ============================================

add_executable(
    CycleAccuracyTest
    tests/cycle_accuracy_test.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
)

target_include_directories(
    CycleAccuracyTest PRIVATE
    include
)

add_test(
    NAME CycleAccuracyTest
    COMMAND CycleAccuracyTest
)


# ============================================
# Temporal Coordinate Engine
# ============================================

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
    TemporalCoordinateTest PRIVATE
    include
)

add_test(
    NAME TemporalCoordinateTest
    COMMAND TemporalCoordinateTest
)


# ============================================
# Global Temporal ID
# ============================================

add_executable(
    GlobalTemporalIDTest
    tests/global_temporal_id_test.cpp
    src/GlobalTemporalID.cpp
)

target_include_directories(
    GlobalTemporalIDTest PRIVATE
    include
)

add_test(
    NAME GlobalTemporalIDTest
    COMMAND GlobalTemporalIDTest
)


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
    GlobalTemporalIDIntegrationTest PRIVATE
    include
)

add_test(
    NAME GlobalTemporalIDIntegrationTest
    COMMAND GlobalTemporalIDIntegrationTest
)


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
    GlobalTemporalMetadataTest PRIVATE
    include
)

add_test(
    NAME GlobalTemporalMetadataTest
    COMMAND GlobalTemporalMetadataTest
)


# ============================================
# Temporal Query Engine
# ============================================

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
    TemporalQueryTest PRIVATE
    include
)

add_test(
    NAME TemporalQueryTest
    COMMAND TemporalQueryTest
)


# ============================================
# Temporal API Test
# ============================================

add_executable(
    TemporalAPITest
    tests/api/temporal_api_test.cpp
    src/api/TemporalAPI.cpp
    src/TemporalQueryEngine.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalAPITest PRIVATE
    include
    include/api
)

add_test(
    NAME TemporalAPITest
    COMMAND TemporalAPITest
)


# ============================================
# Temporal Server Application
# ============================================

add_executable(
    TemporalServer
    src/server/main.cpp
    src/server/HttpServer.cpp
    src/server/TemporalServer.cpp
    src/api/TemporalAPI.cpp
    src/TemporalQueryEngine.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalServer PRIVATE
    include
    include/api
    include/server
)

target_link_libraries(
    TemporalServer
    GoldenCalendar2083_Core
)
# ============================================
# Solar Cycle Engine Test
# ============================================

add_executable(
    SolarCycleEngineTest
    tests/SolarCycleEngineTest.cpp
    src/SolarCycleEngine.cpp
)

target_include_directories(
    SolarCycleEngineTest PRIVATE
    include
)

add_test(
    NAME SolarCycleEngineTest
    COMMAND SolarCycleEngineTest
)

# ============================================
# Solar Cycle Archive Range Test
# ============================================

add_executable(
    SolarCycleArchiveRangeTest

    tests/SolarCycleArchiveRangeTest.cpp

    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarCycleArchiveRangeTest PRIVATE
    include
    Gabary/include
)

add_test(
    NAME SolarCycleArchiveRangeTest
    COMMAND SolarCycleArchiveRangeTest
)
# ============================================
# Solar Cycle Archive Multi Test
# ============================================

add_executable(
    SolarCycleArchiveMultiTest

    tests/SolarCycleArchiveMultiTest.cpp

    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)


target_include_directories(
    SolarCycleArchiveMultiTest PRIVATE

    include
    Gabary/include
)


add_test(
    NAME SolarCycleArchiveMultiTest

    COMMAND SolarCycleArchiveMultiTest
)
# ============================================
# Solar Cycle Boundary Test
# ============================================

add_executable(
    SolarCycleBoundaryTest
    tests/SolarCycleBoundaryTest.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    SolarCycleBoundaryTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarCycleBoundaryTest
    COMMAND SolarCycleBoundaryTest
)
# ============================================
# Solar 50000 Year Archive Test (DISABLED)
# ============================================

# add_executable(
#     SolarCycleArchive50000Test
#     tests/SolarCycleArchive50000Test.cpp
#     Gabary/src/SolarCycleArchive.cpp
#     Gabary/src/SolarCycleEngine.cpp
#     Gabary/src/SolarEngineV2.cpp
#     Gabary/src/LeapYearRules.cpp
#     Gabary/src/WeekCycleEngine.cpp
# )

# target_include_directories(
#     SolarCycleArchive50000Test PRIVATE
#     Gabary/include
# )

# add_test(
#     NAME SolarCycleArchive50000Test
#     COMMAND SolarCycleArchive50000Test
# )
# ============================================
# Solar Archive Builder Test
# ============================================

add_executable(
    SolarArchiveBuilderTest
    Gabary/tests/SolarArchiveBuilderTest.cpp
    Gabary/src/SolarArchiveBuilder.cpp
    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarArchiveBuilderTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarArchiveBuilderTest
    COMMAND SolarArchiveBuilderTest
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
# Solar Cycle Long Range Test
# ============================================

add_executable(
    SolarCycleLongRangeTest
    Gabary/tests/SolarCycleLongRangeTest.cpp
    Gabary/src/SolarCycleArchive.cpp
    Gabary/src/SolarCycleEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/SolarArchiveBuilder.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarCycleLongRangeTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarCycleLongRangeTest
    COMMAND SolarCycleLongRangeTest
)
# ============================================
# Solar 50K Year Boundary Test
# ============================================

add_executable(
    Solar50KYearBoundaryTest
    Gabary/tests/Solar50KYearBoundaryTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KYearBoundaryTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KYearBoundaryTest
    COMMAND Solar50KYearBoundaryTest
)
# ============================================
# Global Solar Day Consistency Test
# ============================================

add_executable(
    GlobalSolarDayConsistencyTest
    Gabary/tests/GlobalSolarDayConsistencyTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    GlobalSolarDayConsistencyTest PRIVATE
    Gabary/include
)

add_test(
    NAME GlobalSolarDayConsistencyTest
    COMMAND GlobalSolarDayConsistencyTest
)
