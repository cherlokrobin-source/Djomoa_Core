const http = require('http');
const { execFile } = require('child_process');
const path = require('path');

const PORT = 8080;
const binaryPath = path.join(__dirname, 'build', 'gabary_json');

console.log(`SERVER CONNECTED TO: ${binaryPath}`);

const server = http.createServer((req, res) => {
    const url = req.url;

    // مسار الاستعلام باليوم العالمي /api/json/day/454457
    const dayMatch = url.match(/^\/api\/json\/day\/(\d+)/);
    if (dayMatch) {
        const dayId = dayMatch[1];
        return execFile(binaryPath, ['day', dayId], (error, stdout) => {
            if (error) {
                res.writeHead(500, { 'Content-Type': 'application/json' });
                return res.end(JSON.stringify({ error: "Execution error", details: error.message }));
            }
            res.writeHead(200, { 'Content-Type': 'application/json' });
            res.end(stdout);
        });
    }

    // مسار تحويل التاريخ الشمسي /api/json/solar/1245/4/5
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

    // مسار تحويل التاريخ القمري /api/json/lunar/1283/7/24
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
