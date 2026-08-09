from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import urlsplit
from pathlib import Path
import urllib.request

HOST = "127.0.0.1"
PORT = 8787

FRONTEND = Path("frontend").resolve()
API_BASE = "http://127.0.0.1:8080"


class ProxyHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        path = urlsplit(self.path).path

        # ==============================
        # Gabary API
        # ==============================
        if path.startswith("/api/"):
            self.proxy_api(path)
            return

        # ==============================
        # Frontend
        # ==============================
        self.serve_frontend(path)


    def proxy_api(self, path):

        target = API_BASE + path

        try:
            request = urllib.request.Request(
                target,
                headers={
                    "Accept": "*/*"
                }
            )

            with urllib.request.urlopen(request, timeout=10) as response:
                body = response.read()
                content_type = response.headers.get(
                    "Content-Type",
                    "application/json"
                )

            self.send_response(200)
            self.send_header(
                "Content-Type",
                content_type
            )
            self.send_header(
                "Access-Control-Allow-Origin",
                "*"
            )
            self.send_header(
                "Content-Length",
                str(len(body))
            )
            self.end_headers()

            self.wfile.write(body)

        except Exception as error:

            body = (
                '{"error":"Gabary API unavailable",'
                '"detail":"' +
                str(error).replace('"', '\\"') +
                '"}'
            ).encode()

            self.send_response(502)
            self.send_header(
                "Content-Type",
                "application/json"
            )
            self.send_header(
                "Content-Length",
                str(len(body))
            )
            self.end_headers()

            self.wfile.write(body)


    def serve_frontend(self, path):

        if path == "/":
            path = "/index.html"

        requested = (FRONTEND / path.lstrip("/")).resolve()

        # Security: prevent path traversal
        if (
            requested != FRONTEND
            and FRONTEND not in requested.parents
        ):
            self.send_error(403)
            return

        if not requested.is_file():
            self.send_error(404)
            return

        try:

            body = requested.read_bytes()

            if requested.suffix == ".html":
                content_type = "text/html; charset=utf-8"
            elif requested.suffix == ".css":
                content_type = "text/css; charset=utf-8"
            elif requested.suffix == ".js":
                content_type = "application/javascript; charset=utf-8"
            elif requested.suffix == ".json":
                content_type = "application/json"
            else:
                content_type = "application/octet-stream"

            self.send_response(200)
            self.send_header(
                "Content-Type",
                content_type
            )
            self.send_header(
                "Content-Length",
                str(len(body))
            )
            self.end_headers()

            self.wfile.write(body)

        except Exception:
            self.send_error(500)


    def log_message(self, format, *args):
        print(
            "[LOCAL PROXY]",
            format % args
        )


if __name__ == "__main__":

    print("=====================================")
    print(" Golden Calendar Local Proxy")
    print(" Port:", PORT)
    print(" Frontend:", FRONTEND)
    print(" API:", API_BASE)
    print(" Status: Running")
    print("=====================================")

    server = ThreadingHTTPServer(
        (HOST, PORT),
        ProxyHandler
    )

    server.serve_forever()
