#ifndef ARCHIVE_ENGINE_H
#define ARCHIVE_ENGINE_H

#include "ChronologyEngine.h"

class ArchiveEngine
{
private:

    ChronologyEngine engine;


public:

    ArchiveEngine();


    // جلب يوم محدد بواسطة Day ID
    Chronology getDay(long long dayId);


    // طباعة بداية سنة محددة
    void printYear(int year);
};

#endif
