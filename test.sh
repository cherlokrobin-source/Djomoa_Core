#!/bin/bash

# خيار التنظيف عند تمرير --clean
if [ "$1" == "--clean" ]; then
    echo "--- Cleaning Build Artifacts ---"
    rm -f test_engine *.o
    echo "Done! Removed generated binaries."
    exit 0
fi

echo "--- Building Test Engine ---"

# أمر التجميع
clang++ -std=c++17 -IGabary/include -Iinclude \
    Gabary/tests/GabaryNavigationEngineTest.cpp \
    Gabary/src/GabaryNavigationEngine.cpp \
    Gabary/src/GabaryDualCalendarEngine.cpp \
    Gabary/src/LunarEngineV2.cpp \
    Gabary/src/SolarEngineV2.cpp \
    Gabary/src/WeekCycleEngine.cpp \
    Gabary/src/LeapYearRules.cpp \
    -o test_engine

# التحقق من نجاح التجميع والتشغيل
if [ $? -eq 0 ]; then
    echo "--- Build Successful! Running Test ---"
    ./test_engine
else
    echo "--- Build Failed! ---"
fi
