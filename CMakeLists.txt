
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
# Temporal Report JSON Test
# ============================================

    add_executable(
    TemporalReportJSONTest
    tests/temporal_report_json_test.cpp
    src/report/TemporalReportEngine.cpp
    src/report/TemporalReportJSON.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalReportJSONTest PRIVATE
    include
)

add_test(
    NAME TemporalReportJSONTest
    COMMAND TemporalReportJSONTest
)


# ============================================
# Gabary Console
# ============================================

add_executable(
    GabaryConsole
    Gabary/console/main.cpp
    Gabary/console/ConsoleApp.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/WeekCycleEngine.cpp
Gabary/src/LeapYearRules.cpp
Gabary/src/ExportManager.cpp
Gabary/src/ReportFormatter.cpp
Gabary/src/ExportManager.cpp
    src/report/TemporalReportEngine.cpp
    src/report/TemporalReportJSON.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)


target_include_directories(
    GabaryConsole PRIVATE
    Gabary/console
    Gabary/include
    include
)



# ============================================
# Temporal Automation Engine
# ============================================
add_executable(
    TemporalReportTest
    tests/temporal_report_test.cpp
    src/report/TemporalReportEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalReportTest PRIVATE
    include
)

add_test(
    NAME TemporalReportTest
    COMMAND TemporalReportTest
)

add_executable(
    TemporalAutomationReportTest
    tests/temporal_automation_report_test.cpp
    src/automation/TemporalAutomationEngine.cpp
    src/TemporalCoordinateEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
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
# Temporal Automation Engine
# ============================================

add_executable(
    TemporalAutomationTest
    tests/temporal_automation_test.cpp
    src/automation/TemporalAutomationEngine.cpp
    src/TemporalCoordinateEngine.cpp
    src/ChronologyEngine.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
)

target_include_directories(
    TemporalAutomationTest PRIVATE
    include
)

add_test(
    NAME TemporalAutomationTest
    COMMAND TemporalAutomationTest
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
    src/automation/TemporalAutomationEngine.cpp
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

    # Gabary V2 Core
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
)

target_include_directories(
    TemporalAPITest PRIVATE

    include
    include/api

    Gabary/include
)

add_test(
    NAME TemporalAPITest
    COMMAND TemporalAPITest
)

# ============================================
# Temporal JSON API Test
# ============================================

add_executable(
    TemporalJSONAPITest

    tests/api/temporal_json_api_test.cpp

    src/server/TemporalServer.cpp
    src/api/TemporalAPI.cpp

    src/TemporalQueryEngine.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp

    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp

    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
)


target_include_directories(
    TemporalJSONAPITest PRIVATE

    include
    include/api
    include/server

    Gabary/include
)


add_test(
    NAME TemporalJSONAPITest
    COMMAND TemporalJSONAPITest
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

    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
)

target_include_directories(
    TemporalServer PRIVATE

    include
    include/api
    include/server

    Gabary/include
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
# ============================================
# Solar Timeline Performance Test
# ============================================

add_executable(
    SolarTimelinePerformanceTest
    Gabary/tests/SolarTimelinePerformanceTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarTimelinePerformanceTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarTimelinePerformanceTest
    COMMAND SolarTimelinePerformanceTest
)
# ============================================
# Solar Timeline Generation Test
# ============================================

add_executable(
    SolarTimelineGenerationTest
    Gabary/tests/SolarTimelineGenerationTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarTimelineGenerationTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarTimelineGenerationTest
    COMMAND SolarTimelineGenerationTest
)
# ============================================
# Solar Year Integrity Test
# ============================================

add_executable(
    SolarYearIntegrityTest
    Gabary/tests/SolarYearIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarYearIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarYearIntegrityTest
    COMMAND SolarYearIntegrityTest
)
# ============================================
# Solar Month Integrity Test
# ============================================

add_executable(
    SolarMonthIntegrityTest
    Gabary/tests/SolarMonthIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarMonthIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarMonthIntegrityTest
    COMMAND SolarMonthIntegrityTest
)
# ============================================
# Solar Date Round Trip Test
# ============================================

add_executable(
    SolarDateRoundTripTest
    Gabary/tests/SolarDateRoundTripTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarDateRoundTripTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarDateRoundTripTest
    COMMAND SolarDateRoundTripTest
)
# ============================================
# Solar Day Continuity Test
# ============================================

add_executable(
    SolarDayContinuityTest
    Gabary/tests/SolarDayContinuityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarDayContinuityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarDayContinuityTest
    COMMAND SolarDayContinuityTest
)
# ============================================
# Solar 50K Day ID Range Test
# ============================================

add_executable(
    Solar50KDayIDRangeTest
    Gabary/tests/Solar50KDayIDRangeTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KDayIDRangeTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KDayIDRangeTest
    COMMAND Solar50KDayIDRangeTest
)
# ============================================
# Solar 50K Random Sampling Test
# ============================================

add_executable(
    Solar50KRandomSamplingTest
    Gabary/tests/Solar50KRandomSamplingTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KRandomSamplingTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KRandomSamplingTest
    COMMAND Solar50KRandomSamplingTest
)
# ============================================
# Solar Leap Year Consistency Test
# ============================================

add_executable(
    SolarLeapYearConsistencyTest
    Gabary/tests/SolarLeapYearConsistencyTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarLeapYearConsistencyTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarLeapYearConsistencyTest
    COMMAND SolarLeapYearConsistencyTest
)
# ============================================
# Solar 50K Full Year Count Test
# ============================================

add_executable(
    SolarDayOfYearStatisticsValidationTest
    Gabary/tests/SolarDayOfYearStatisticsValidationTest.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    SolarDayOfYearStatisticsValidationTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarDayOfYearStatisticsValidationTest
    COMMAND SolarDayOfYearStatisticsValidationTest
)


# ============================================
# Solar Metadata Test
# ============================================

add_executable(
    SolarMetadataTest
    tests/solar_metadata_test.cpp
    src/SolarEngine.cpp
)

target_include_directories(
    SolarMetadataTest PRIVATE
    include
)

add_test(
    NAME SolarMetadataTest
    COMMAND SolarMetadataTest
)


# ============================================
# Solar 50K Chronology Report Test
# ============================================

add_executable(
    Solar50KChronologyReportTest
    Gabary/tests/Solar50KChronologyReportTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KChronologyReportTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KChronologyReportTest
    COMMAND Solar50KChronologyReportTest
)

# ============================================
# Solar Day Of Year Integrity Test
# ============================================

# ============================================
# Solar Day Of Year Integrity Test
# ============================================

add_executable(
    SolarDayOfYearIntegrityTest
    Gabary/tests/SolarDayOfYearIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarDayOfYearIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarDayOfYearIntegrityTest
    COMMAND SolarDayOfYearIntegrityTest
)


# ============================================
# Solar Month Boundary Test
# ============================================

add_executable(
    SolarMonthBoundaryTest
    Gabary/tests/SolarMonthBoundaryTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarMonthBoundaryTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarMonthBoundaryTest
    COMMAND SolarMonthBoundaryTest
)


# ============================================
# Solar Year Transition Integrity Test
# ============================================

add_executable(
    SolarYearTransitionIntegrityTest
    Gabary/tests/SolarYearTransitionIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarYearTransitionIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarYearTransitionIntegrityTest
    COMMAND SolarYearTransitionIntegrityTest
)


# ============================================
# Solar Month Year Sum Integrity Test
# ============================================

add_executable(
    SolarMonthYearSumIntegrityTest
    Gabary/tests/SolarMonthYearSumIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarMonthYearSumIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarMonthYearSumIntegrityTest
    COMMAND SolarMonthYearSumIntegrityTest
)


# ============================================
# Solar 50K Endpoint Integrity Test
# ============================================

add_executable(
    Solar50KEndpointIntegrityTest
    Gabary/tests/Solar50KEndpointIntegrityTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KEndpointIntegrityTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KEndpointIntegrityTest
    COMMAND Solar50KEndpointIntegrityTest
)


# ============================================
# Solar Statistics Validation Test
# ============================================

add_executable(
    SolarStatisticsValidationTest
    Gabary/tests/SolarStatisticsValidationTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    SolarStatisticsValidationTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarStatisticsValidationTest
    COMMAND SolarStatisticsValidationTest
)


# ============================================
# Solar Month Statistics Validation Test
# ============================================

add_executable(
    SolarMonthStatisticsValidationTest
    Gabary/tests/SolarMonthStatisticsValidationTest.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    SolarMonthStatisticsValidationTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarMonthStatisticsValidationTest
    COMMAND SolarMonthStatisticsValidationTest
)


# ============================================
# Solar Leap Statistics Validation Test
# ============================================

add_executable(
    SolarLeapStatisticsValidationTest
    Gabary/tests/SolarLeapStatisticsValidationTest.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    SolarLeapStatisticsValidationTest PRIVATE
    Gabary/include
)

add_test(
    NAME SolarLeapStatisticsValidationTest
    COMMAND SolarLeapStatisticsValidationTest
)


# ============================================
# Gabary V2 - Lunar Engine Test
# ============================================

add_executable(
    LunarEngineV2Test
    tests/lunar_engine_v2_test.cpp
    Gabary/src/LunarEngineV2.cpp
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
# Gabary V2 - Lunar Engine Boundary Test
# ============================================

add_executable(
    LunarEngineV2BoundaryTest
    tests/lunar_engine_v2_boundary_test.cpp
    Gabary/src/LunarEngineV2.cpp
)

target_include_directories(
    LunarEngineV2BoundaryTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME LunarEngineV2BoundaryTest
    COMMAND LunarEngineV2BoundaryTest
)
# ============================================
# Gabary V2 - Lunar Engine Long Cycle Test
# ============================================

add_executable(
    LunarEngineV2LongCycleTest
    Gabary/tests/LunarEngineV2LongCycleTest.cpp
    Gabary/src/LunarEngineV2.cpp
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
# ============================================
# Gabary V2 - Dual Calendar Integration Test
# ============================================

add_executable(
    GabaryDualCalendarIntegrationTest
    Gabary/tests/GabaryDualCalendarIntegrationTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    GabaryDualCalendarIntegrationTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryDualCalendarIntegrationTest
    COMMAND GabaryDualCalendarIntegrationTest
)
# ============================================
# Gabary V2 - Dual Calendar Engine Test
# ============================================

add_executable(
    GabaryDualCalendarEngineTest
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/tests/GabaryDualCalendarEngineTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryDualCalendarEngineTest PRIVATE
    Gabary/include
    include
)

# ============================================
# Gabary V2 - Navigation Engine Test
# ============================================

add_executable(
    GabaryNavigationEngineTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryNavigationEngineTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryNavigationEngineTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryNavigationEngineTest
    COMMAND GabaryNavigationEngineTest
)

# ============================================
# Gabary V2 - Navigation Engine Boundary Test
# ============================================

add_executable(
    GabaryNavigationEngineBoundaryTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryNavigationEngineBoundaryTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryNavigationEngineBoundaryTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryNavigationEngineBoundaryTest
    COMMAND GabaryNavigationEngineBoundaryTest
)

# ============================================
# Gabary V2 - Navigation Engine Long-Range Test
# ============================================

add_executable(
    GabaryNavigationEngineLongRangeTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryNavigationEngineLongRangeTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryNavigationEngineLongRangeTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryNavigationEngineLongRangeTest
    COMMAND GabaryNavigationEngineLongRangeTest
)

# ============================================
# Gabary V2 - Navigation Solar Round-Trip Test
# ============================================

add_executable(
    GabaryNavigationEngineSolarRoundTripTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryNavigationEngineSolarRoundTripTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryNavigationEngineSolarRoundTripTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryNavigationEngineSolarRoundTripTest
    COMMAND GabaryNavigationEngineSolarRoundTripTest
)

# ============================================
# Gabary V2 - Query Engine Test
# ============================================

add_executable(
    GabaryQueryEngineTest
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryQueryEngineTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryQueryEngineTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryQueryEngineTest
    COMMAND GabaryQueryEngineTest
)

# ============================================
# Gabary V2 - Dual Report Formatter Test
# ============================================

add_executable(
    GabaryDualReportFormatterTest
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/tests/GabaryDualReportFormatterTest.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
)

target_include_directories(
    GabaryDualReportFormatterTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryDualReportFormatterTest
    COMMAND GabaryDualReportFormatterTest
)
# ============================================
# Gabary V2 - Dual Calendar Boundary Test
# ============================================

add_executable(
    GabaryDualCalendarBoundaryTest
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryDualCalendarBoundaryTest.cpp
)

target_include_directories(
    GabaryDualCalendarBoundaryTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryDualCalendarBoundaryTest
    COMMAND GabaryDualCalendarBoundaryTest
)
# ============================================
# Gabary V2 - 50,000-Year End Boundary Test
# ============================================

add_executable(
    GabaryDualCalendarEndBoundaryTest
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryDualCalendarEndBoundaryTest.cpp
)

target_include_directories(
    GabaryDualCalendarEndBoundaryTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryDualCalendarEndBoundaryTest
    COMMAND GabaryDualCalendarEndBoundaryTest
)

# ============================================
# Gabary V2 - Temporal Service Test
# ============================================

add_executable(
    GabaryTemporalServiceTest
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryTemporalServiceTest.cpp
)

target_include_directories(
    GabaryTemporalServiceTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryTemporalServiceTest
    COMMAND GabaryTemporalServiceTest
)
# ============================================
# Gabary V2 - API Adapter Test
# ============================================

add_executable(
    GabaryAPIAdapterTest
    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryAPIAdapterTest.cpp
)

target_include_directories(
    GabaryAPIAdapterTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryAPIAdapterTest
    COMMAND GabaryAPIAdapterTest
)

# ============================================
# Gabary V2 - API Integration Test
# ============================================

add_executable(
    GabaryAPIIntegrationTest
    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryAPIIntegrationTest.cpp
)

target_include_directories(
    GabaryAPIIntegrationTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryAPIIntegrationTest
    COMMAND GabaryAPIIntegrationTest
)


# ============================================
# Gabary V2 - Final API Contract Test
# ============================================

add_executable(
    GabaryAPIContractTest
    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
    src/TemporalQueryEngine.cpp
    src/ChronologyEngine.cpp
    src/GlobalTemporalID.cpp
    src/SolarEngine.cpp
    src/LunarEngine.cpp
    src/WeekEngine.cpp
    src/server/TemporalServer.cpp
    Gabary/tests/GabaryAPIContractTest.cpp
)

target_include_directories(
    GabaryAPIContractTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryAPIContractTest
    COMMAND GabaryAPIContractTest
)

# ============================================
# Gabary V2 - HTTP API Contract Test
# ============================================

add_executable(
    GabaryHTTPAPIContractTest
    Gabary/tests/GabaryHTTPAPIContractTest.cpp
)

target_include_directories(
    GabaryHTTPAPIContractTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryHTTPAPIContractTest
    COMMAND GabaryHTTPAPIContractTest
)

# ============================================
# Gabary V2 - API Response Schema v1 Test
# ============================================

add_executable(
    GabaryAPIResponseSchemaTest
    Gabary/tests/GabaryAPIResponseSchemaTest.cpp
)

target_include_directories(
    GabaryAPIResponseSchemaTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryAPIResponseSchemaTest
    COMMAND GabaryAPIResponseSchemaTest
)

# ============================================
# Gabary V2 - API Response Boundary Schema Test
# ============================================

add_executable(
    GabaryAPIResponseBoundarySchemaTest
    Gabary/tests/GabaryAPIResponseBoundarySchemaTest.cpp
)

target_include_directories(
    GabaryAPIResponseBoundarySchemaTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryAPIResponseBoundarySchemaTest
    COMMAND GabaryAPIResponseBoundarySchemaTest
)

# ============================================
# Gabary V2 - Navigation Engine Contract Test
# ============================================

add_executable(
    GabaryNavigationEngineContractTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
    Gabary/tests/GabaryNavigationEngineContractTest.cpp
)

target_include_directories(
    GabaryNavigationEngineContractTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryNavigationEngineContractTest
    COMMAND GabaryNavigationEngineContractTest
)

# ============================================
# Gabary V2 - Navigation Date Round-Trip Test
# ============================================

add_executable(
    GabaryNavigationEngineDateRoundTripTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
    Gabary/tests/GabaryNavigationEngineDateRoundTripTest.cpp
)

target_include_directories(
    GabaryNavigationEngineDateRoundTripTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryNavigationEngineDateRoundTripTest
    COMMAND GabaryNavigationEngineDateRoundTripTest
)

# ============================================
# Gabary V2 - Navigation Boundary Date Test
# ============================================

add_executable(
    GabaryNavigationEngineBoundaryDateTest
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/GlobalSolarDay.cpp
    Gabary/src/ReportFormatter.cpp
    Gabary/tests/GabaryNavigationEngineBoundaryDateTest.cpp
)

target_include_directories(
    GabaryNavigationEngineBoundaryDateTest PRIVATE
    Gabary/include
    include
    include/server
)

add_test(
    NAME GabaryNavigationEngineBoundaryDateTest
    COMMAND GabaryNavigationEngineBoundaryDateTest
)

# ============================================
# Gabary V2 - Query Engine Contract Test
# ============================================

add_executable(
    GabaryQueryEngineContractTest
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryQueryEngineContractTest.cpp
)

target_include_directories(
    GabaryQueryEngineContractTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryQueryEngineContractTest
    COMMAND GabaryQueryEngineContractTest
)
# ============================================
# Gabary V2 - Temporal Service Contract Test
# ============================================

add_executable(
    GabaryTemporalServiceContractTest
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryTemporalServiceContractTest.cpp
)

target_include_directories(
    GabaryTemporalServiceContractTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryTemporalServiceContractTest
    COMMAND GabaryTemporalServiceContractTest
)

# ============================================
# EOF
# ============================================
# ============================================
# Gabary V2 - API Adapter Contract Test
# ============================================

add_executable(
    GabaryAPIAdapterContractTest
    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryAPIAdapterContractTest.cpp
)

target_include_directories(
    GabaryAPIAdapterContractTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryAPIAdapterContractTest
    COMMAND GabaryAPIAdapterContractTest
)

# ============================================
# Gabary V2 - Dual Calendar Engine Contract Test
# ============================================

add_executable(
    GabaryDualCalendarEngineContractTest
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryDualCalendarEngineContractTest.cpp
)

target_include_directories(
    GabaryDualCalendarEngineContractTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryDualCalendarEngineContractTest
    COMMAND GabaryDualCalendarEngineContractTest
)

# ============================================

# ============================================
# Gabary V2 - API Adapter Data Integrity Test
# ============================================

add_executable(
    GabaryAPIAdapterDataIntegrityTest
    Gabary/src/GabaryAPIAdapter.cpp
    Gabary/src/GabaryTemporalService.cpp
    Gabary/src/GabaryDualReportFormatter.cpp
    Gabary/src/GabaryQueryEngine.cpp
    Gabary/src/GabaryNavigationEngine.cpp
    Gabary/src/GabaryDualCalendarEngine.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LunarEngineV2.cpp
    Gabary/src/WeekCycleEngine.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/tests/GabaryAPIAdapterDataIntegrityTest.cpp
)

target_include_directories(
    GabaryAPIAdapterDataIntegrityTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryAPIAdapterDataIntegrityTest
    COMMAND GabaryAPIAdapterDataIntegrityTest
)

# ============================================

# ============================================
# Gabary V2 - HTTP API Data Integrity Test
# ============================================

add_executable(
    GabaryHTTPAPIDataIntegrityTest
    Gabary/tests/GabaryHTTPAPIDataIntegrityTest.cpp
)

target_include_directories(
    GabaryHTTPAPIDataIntegrityTest PRIVATE
    Gabary/include
    include
)

add_test(
    NAME GabaryHTTPAPIDataIntegrityTest
    COMMAND GabaryHTTPAPIDataIntegrityTest
)

# ============================================

# ============================================
# Solar 50K Full Year Count Test
# ============================================

add_executable(
    Solar50KFullYearCountTest
    Gabary/tests/Solar50KFullYearCountTest.cpp
    Gabary/src/SolarEngineV2.cpp
    Gabary/src/LeapYearRules.cpp
    Gabary/src/WeekCycleEngine.cpp
)

target_include_directories(
    Solar50KFullYearCountTest PRIVATE
    Gabary/include
)

add_test(
    NAME Solar50KFullYearCountTest
    COMMAND Solar50KFullYearCountTest
)
