#include "../include/SolarArchiveBuilder.h"

namespace Gabary
{

void SolarArchiveBuilder::build(
    int startCycle,
    int endCycle
)
{
    archive.buildCycles(
        startCycle,
        endCycle
    );
}


SolarCycleArchive& SolarArchiveBuilder::getArchive()
{
    return archive;
}


const SolarCycleArchive& SolarArchiveBuilder::getArchive() const
{
    return archive;
}

}
