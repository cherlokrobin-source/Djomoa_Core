const http = require('http');
const { execFile } = require('child_process');
const path = require('path');
const fs = require('fs');

const PORT = 8080;
const binaryPath = path.join(__dirname, 'build', 'gabary_json');

const server = http.createServer((req, res) => {
    let url = req.url.split('?')[0]; // إزالة الـ query parameters إن وجدت

    // 1. تقديم الصفحة الرئيسية
    if (url === '/' || url === '/index.html') {
        const indexPath = path.join(__dirname, 'public', 'index.html');
        return fs.readFile(indexPath, (err, data) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'application/json' });
                return res.end(JSON.stringify({ error: "Index file not found", path: indexPath }));
            }
            res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
            res.end(data);
        });
    }

    // 2. مسار /api/json/day/:dayId
    const dayMatch = url.match(/^\/api\/json\/day\/(\d+)/);
    if (dayMatch) {
        return execFile(binaryPath, ['day', dayMatch[1]], (error, stdout) => {
            if (error) {
                res.writeHead(500, { 'Content-Type': 'application/json' });
                return res.end(JSON.stringify({ error: "Execution error", details: error.message }));
            }
            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(stdout);
        });
    }

    // 3. مسار /api/json/solar/:year/:month/:day
    const solarMatch = url.match(/^\/api\/json\/solar\/(\d+)\/(\d+)\/(\d+)/);
    if (solarMatch) {
        const [, year, month, day] = solarMatch;
        return execFile(binaryPath, ['solar', year, month, day], (error, stdout) => {
            if (error) {
                res.writeHead(500, { 'Content-Type': 'application/json' });
                return res.end(JSON.stringify({ error: "Execution error", details: error.message }));
            }
            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(stdout);
        });
    }

    // 4. مسار /api/json/lunar/:year/:month/:day
    const lunarMatch = url.match(/^\/api\/json\/lunar\/(\d+)\/(\d+)\/(\d+)/);
    if (lunarMatch) {
        const [, year, month, day] = lunarMatch;
        return execFile(binaryPath, ['lunar', year, month, day], (error, stdout) => {
            if (error) {
                res.writeHead(500, { 'Content-Type': 'application/json' });
                return res.end(JSON.stringify({ error: "Execution error", details: error.message }));
            }
            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(stdout);
        });
    }

    res.writeHead(404, { 'Content-Type': 'application/json' });
    res.end(JSON.stringify({ error: "Not Found" }));
});

server.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
