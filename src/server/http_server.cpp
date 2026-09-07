#include "http_server.hpp"
#include <stdexcept>
#include <string>

// معالجة طلبات اليوم مع التحقق الصارم من الحدود [1, 18261759] لإرجاع HTTP 400 عند المخالفة
void process_day_endpoint(const std::string& path, HttpResponse& response) {
    try {
        size_t idx = path.find_last_of('/');
        long long dayId = std::stoll(path.substr(idx + 1));

        if (dayId < 1 || dayId > 18261759) {
            response.status_code = 400;
            response.body = "{\"error\": \"Bad Request: dayId out of bounds\"}";
            return;
        }

        response.status_code = 200;
        response.body = "{\"dayId\": " + std::to_string(dayId) + ", \"status\": \"SUCCESS\"}";
    } catch (...) {
        response.status_code = 400;
        response.body = "{\"error\": \"Invalid Request\"}";
    }
}
