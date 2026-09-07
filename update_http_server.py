import re

path = "src/server/HttpServer.cpp"
with open(path, "r", encoding="utf-8") as f:
    code = f.read()

# منطق تقديم الملفات الثابتة
static_handler = '''
    // Static Files Handling for Frontend
    if (path == "/" || path == "/index.html") {
        std::ifstream file("frontend/index.html");
        if (file.is_open()) {
            std::stringstream ss;
            ss << file.rdbuf();
            std::string content = ss.str();
            std::string response = "HTTP/1.1 200 OK\\r\\n"
                                   "Content-Type: text/html; charset=utf-8\\r\\n"
                                   "Access-Control-Allow-Origin: *\\r\\n"
                                   "Content-Length: " + std::to_string(content.size()) + "\\r\\n"
                                   "Connection: close\\r\\n\\r\\n" + content;
            send(clientSocket, response.c_str(), response.size(), 0);
            close(clientSocket);
            return;
        }
    } else if (path == "/app.js") {
        std::ifstream file("frontend/app.js");
        if (file.is_open()) {
            std::stringstream ss;
            ss << file.rdbuf();
            std::string content = ss.str();
            std::string response = "HTTP/1.1 200 OK\\r\\n"
                                   "Content-Type: text/javascript; charset=utf-8\\r\\n"
                                   "Access-Control-Allow-Origin: *\\r\\n"
                                   "Content-Length: " + std::to_string(content.size()) + "\\r\\n"
                                   "Connection: close\\r\\n\\r\\n" + content;
            send(clientSocket, response.c_str(), response.size(), 0);
            close(clientSocket);
            return;
        }
    }
'''

print("Updating HttpServer.cpp...")
