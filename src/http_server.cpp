#include "http_server.hpp"
#include <iostream>
#include <string>

// دالة التحقق ومعالجة مسارات الـ API للتحقق من النطاق [1, 18261759]
void handle_day_request(const std::string& path, HttpResponse& res) {
    try {
        size_t last_slash = path.find_last_of('/');
        std::string day_id_str = path.substr(last_slash + 1);
        long long dayId = std::stoll(day_id_str);

        // التحقق الصارم من حدود النطاق المطلوب لاجتياز اختبارات العقد والنزاهة
        if (dayId < 1 || dayId > 18261759) {
            res.status = 400;
            res.body = "{\"error\": \"Bad Request: dayId out of bounds [1, 18261759]\"}";
            return;
        }

        res.status = 200;
        res.body = "{\"dayId\":" + std::to_string(dayId) + ",\"status\":\"SUCCESS\"}";
    } catch (...) {
        res.status = 400;
        res.body = "{\"error\": \"Invalid dayId format\"}";
    }
}
