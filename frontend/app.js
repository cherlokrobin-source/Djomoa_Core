const API_BASE = "";

// =====================================
// Load Gabary V2 Engine Status
// =====================================
async function loadStatus(){
    try{
        const response = await fetch(`${API_BASE}/api/status`);
        const data = await response.json();

        document.getElementById("engineStatus").textContent = data.status || "Active";
        document.getElementById("engineVersion").textContent = data.core || "v2-engine";
        document.getElementById("engineTests").textContent = data.validation || "Passed";
    } catch(error){
        document.getElementById("engineStatus").textContent = "Offline";
    }
}

// =====================================
// Global Solar & Lunar Day Query
// =====================================
async function searchDay(){
    console.log("Gabary Solar & Lunar Day Query");
    const day = document.getElementById("dayInput").value;
    if(!day) return;

    try{
        // جلب البيانات الأساسية والتقرير النصي بالتوازي
        const [jsonRes, reportRes] = await Promise.all([
            fetch(`${API_BASE}/api/json/day/${day}`),
            fetch(`${API_BASE}/api/day/${day}`)
        ]);

        const data = await jsonRes.json();
        const reportText = await reportRes.text();

        document.getElementById("globalSolarDay").textContent = data.globalSolarDay;
        document.getElementById("solarDate").textContent = 
            `${data.solarDate.weekday}, ${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}`;
        document.getElementById("dayOfYear").textContent = data.solarDate.dayOfYear;
        document.getElementById("weekIndex").textContent = data.calendarMetadata.weekIndex;
        document.getElementById("cycleNumber").textContent = data.temporalMetadata.cycleNumber;
        document.getElementById("historicalIndex").textContent = data.temporalMetadata.historicalIndex;
        document.getElementById("engineName").textContent = data.architecture.engine;
        document.getElementById("validationState").textContent = data.architecture.validation;

        document.getElementById("result").textContent = JSON.stringify(data, null, 4);
        document.getElementById("textReport").textContent = reportText;

    } catch(error){
        document.getElementById("result").textContent = "API CONNECTION ERROR";
    }
}

// =====================================
// Digital Clock
// =====================================
function updateClock(){
    const now = new Date();
    document.getElementById("clock").textContent = now.toUTCString().split(" ")[4];
    document.getElementById("date").textContent = now.toDateString();
}

// =====================================
// Timeline Quick Range
// =====================================
function setTimelineRange(days){
    const startInput = document.getElementById("timelineStart");
    const endInput = document.getElementById("timelineEnd");
    let start = Number(startInput.value);
    if(!Number.isInteger(start) || start < 1){
        start = 1;
        startInput.value = start;
    }
    endInput.value = start + days - 1;
}

// =====================================
// Timeline Explorer V3 (Parallel & Dual-Calendar Support)
// =====================================
async function loadTimeline(){
    console.log("Gabary Visual Timeline V3");
    const startInput = document.getElementById("timelineStart");
    const endInput = document.getElementById("timelineEnd");
    const outputElement = document.getElementById("timelineResult");

    const start = Number(startInput.value);
    const end = Number(endInput.value);

    if(!Number.isInteger(start) || !Number.isInteger(end)){
        outputElement.innerHTML = `<div class="timeline-message">Please enter valid Global Solar Day IDs.</div>`;
        return;
    }
    if(start < 1){
        outputElement.innerHTML = `<div class="timeline-message">Global Solar Day must be >= 1.</div>`;
        return;
    }
    if(end < start){
        outputElement.innerHTML = `<div class="timeline-message">End Day ID must be greater than or equal to Start Day ID.</div>`;
        return;
    }

    const count = end - start + 1;
    if(count > 100){
        outputElement.innerHTML = `
            <div class="timeline-message">
                <strong>TIMELINE RANGE TOO LARGE</strong><br><br>
                Requested days : ${count}<br>
                Maximum per query : 100<br><br>
                Please use a smaller range.
            </div>`;
        return;
    }

    outputElement.innerHTML = `
        <div class="timeline-loading">
            <strong>GABARY V2 VISUAL TIMELINE</strong><br><br>
            Loading ${count} day${count === 1 ? "" : "s"}...
        </div>`;

    // تكوين مصفوفة الطلبات بالتوازي بدلاً من الحلقات البطيئة
    const dayIds = Array.from({length: count}, (_, i) => start + i);
    
    try {
        const responses = await Promise.all(
            dayIds.map(day => fetch(`${API_BASE}/api/json/day/${day}`).then(r => r.ok ? r.json() : null))
        );

        let timelineNodesHTML = "";
        responses.forEach((data, index) => {
            const day = start + index;
            if(!data){
                timelineNodesHTML += `
                    <article class="timeline-node timeline-error">
                        <div class="timeline-marker"><span></span></div>
                        <div class="timeline-content">
                            <div class="timeline-day-id">GLOBAL SOLAR DAY <strong>${day}</strong></div>
                            <div class="timeline-error-message">Timeline data unavailable</div>
                        </div>
                    </article>`;
                return;
            }

            const leapYear = data.calendarMetadata?.leapYear ? "LEAP YEAR" : "COMMON YEAR";
            const lunarText = data.lunarDate 
                ? `Year ${data.lunarDate.year}, Month ${data.lunarDate.month}, Day ${data.lunarDate.day}`
                : "Lunar Data N/A";

            timelineNodesHTML += `
                <article class="timeline-node">
                    <div class="timeline-marker"><span></span></div>
                    <div class="timeline-content">
                        <div class="timeline-day-id">GLOBAL SOLAR DAY <strong>${data.globalSolarDay}</strong></div>
                        <div class="timeline-date">
                            ${data.solarDate.weekday}, ${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}
                        </div>
                        <div class="timeline-grid">
                            <div class="timeline-stat"><span>LUNAR DATE</span><strong>${lunarText}</strong></div>
                            <div class="timeline-stat"><span>DAY OF YEAR</span><strong>${data.solarDate.dayOfYear}</strong></div>
                            <div class="timeline-stat"><span>WEEK INDEX</span><strong>${data.calendarMetadata.weekIndex}</strong></div>
                            <div class="timeline-stat"><span>YEAR TYPE</span><strong>${leapYear}</strong></div>
                            <div class="timeline-stat"><span>CYCLE</span><strong>${data.temporalMetadata.cycleNumber}</strong></div>
                        </div>
                        <div class="timeline-engine">
                            <span>${data.architecture.name}</span>
                            <span>${data.architecture.engine}</span>
                            <span class="timeline-validation">${data.architecture.validation}</span>
                        </div>
                    </div>
                </article>`;
        });

        outputElement.innerHTML = `
            <div class="visual-timeline">
                <div class="timeline-header">
                    <div><span class="timeline-label">START</span> <strong>${start}</strong></div>
                    <div class="timeline-range">${count} DAY${count === 1 ? "" : "S"}</div>
                    <div><span class="timeline-label">END</span> <strong>${end}</strong></div>
                </div>
                <div class="timeline-track">${timelineNodesHTML}</div>
                <div class="timeline-footer">
                    <strong>TIMELINE QUERY COMPLETE</strong>
                    <span>${count} day${count === 1 ? "" : "s"} processed</span>
                </div>
            </div>`;

    } catch(err) {
        outputElement.innerHTML = `<div class="timeline-message">Error fetching timeline data: ${err.message}</div>`;
    }
}

// =====================================
// Application Startup
// =====================================
setInterval(updateClock, 1000);
updateClock();
loadStatus();
