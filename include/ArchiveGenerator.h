#ifndef ARCHIVE_GENERATOR_H
#define ARCHIVE_GENERATOR_H

#include "ArchiveEngine.h"
#include <fstream>
#include <string>

class ArchiveGenerator
{
private:

    ArchiveEngine archive;

public:

    ArchiveGenerator();

    // توليد رؤوس السنوات (الاختبار الحالي)
    void generateCSV(
        int startYear,
        int endYear,
        const std::string& filename
    );

    // توليد سنة كاملة (كل الأيام)
    void generateYear(
        int year,
        std::ofstream& file
    );

    // توليد أرشيف كامل
    void generateFullArchive(
        int startYear,
        int endYear,
        const std::string& filename
    );

};

#endif
