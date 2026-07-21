#ifndef ARCHIVE_GENERATOR_H
#define ARCHIVE_GENERATOR_H

#include "ArchiveEngine.h"
#include <string>

class ArchiveGenerator
{
private:

    ArchiveEngine archive;

public:

    ArchiveGenerator();

    void generateCSV(
        int startYear,
        int endYear,
        const std::string& filename
    );

};

#endif
