#ifndef GABARY_API_ADAPTER_H
#define GABARY_API_ADAPTER_H

#include <cstdint>
#include <string>

#include "GabaryTemporalService.h"

namespace Gabary
{

class GabaryAPIAdapter
{
public:
    GabaryAPIAdapter();

    std::string getDay(int64_t dayId);

    std::string getSolar(
        int year,
        int month,
        int day
    );

    std::string getLunar(
        int year,
        int month,
        int day
    );

private:
    GabaryTemporalService service;
};

}

#endif
