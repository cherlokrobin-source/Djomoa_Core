#include <iostream>

#include "TemporalAPI.h"

int main()
{
    TemporalAPI api;

    std::string json =
        api.getDayAsJSON(18261395);

    std::cout
        << "Temporal API Test"
        << std::endl;

    std::cout
        << "================="
        << std::endl;

    std::cout
        << json
        << std::endl;

    return 0;
}
