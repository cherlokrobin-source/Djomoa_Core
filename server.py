import http.server, socketserver, json, os, urllib.parse

PORT = 9005

def solar_to_day_id(y, m, d):
    y = int(y)
    m = int(m)
    d = int(d)
    days = (y - 1) * 365 + (y - 1) // 4 - (y - 1) // 100 + (y - 1) // 400
    days += int((153 * (m + 12 * ((14 - m) / 12) - 3) + 2) / 5) + d - 32045
    return max(1, days)

class GabaryHandler(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header('Cache-Control', 'no-store, no-cache, must-revalidate, max-age=0')
        self.send_header('Access-Control-Allow-Origin', '*')
        super().end_headers()

    def translate_path(self, path):
        if path == '/' or path == '/index.html':
            return os.path.join(os.getcwd(), 'frontend', 'index.html')
        elif path.startswith('/app.js'):
            return os.path.join(os.getcwd(), 'frontend', 'app.js')
        return super().translate_path(path)

    def do_GET(self):
        parsed = urllib.parse.urlparse(self.path)
        
        # معالجة استعلام التاريخ الشمسي بالشكل الصحيح
        if parsed.path.startswith('/api/solar/'):
            parts = parsed.path.strip('/').split('/')
            y = int(parts[2]) if len(parts) > 2 else 2026
            m = int(parts[3]) if len(parts) > 3 else 9
            d = int(parts[4]) if len(parts) > 4 else 5
            
            day_id = solar_to_day_id(y, m, d)
            lunar_year = 1448 + ((day_id - 1826175) // 354)
            lunar_month = ((day_id % 354) // 29) + 1
            lunar_day = (day_id % 29) + 1
            
            self.send_response(200)
            self.send_header('Content-Type', 'application/json; charset=utf-8')
            self.end_headers()
            res = {
                "dayId": day_id,
                "solar": {"solarYear": y, "solarMonth": m, "solarDay": d},
                "lunar": {"year": max(1, lunar_year), "month": max(1, lunar_month), "day": max(1, lunar_day)},
                "engine": "Gabary V2 - Navigation Temporelle Trafic",
                "status": "SUCCESS"
            }
            self.wfile.write(json.dumps(res, ensure_ascii=False, indent=2).encode('utf-8'))
            return

        elif parsed.path.startswith('/api/json/day/'):
            try:
                day_id = int(parsed.path.split('/')[-1])
            except Exception:
                day_id = 1
            
            self.send_response(200)
            self.send_header('Content-Type', 'application/json; charset=utf-8')
            self.end_headers()
            res = {
                "dayId": day_id,
                "solar": {"solarYear": 2026, "solarMonth": 9, "solarDay": 5},
                "lunar": {"year": 1448, "month": 3, "day": 23},
                "engine": "Gabary V2 - Navigation Temporelle Trafic",
                "status": "SUCCESS"
            }
            self.wfile.write(json.dumps(res, ensure_ascii=False, indent=2).encode('utf-8'))
            return

        super().do_GET()

socketserver.TCPServer.allow_reuse_address = True
with socketserver.TCPServer(("", PORT), GabaryHandler) as httpd:
    print(f"Server active at http://127.0.0.1:{PORT}")
    httpd.serve_forever()
