const API_BASE = "";


// =====================================
// Load Gabary V2 Engine Status
// =====================================

async function loadStatus(){

    try{

        const response =
            await fetch(
                `${API_BASE}/api/status`
            );

        const data =
            await response.json();


        document.getElementById(
            "engineStatus"
        ).textContent =
            data.status;


        document.getElementById(
            "engineVersion"
        ).textContent =
            data.core;


        document.getElementById(
            "engineTests"
        ).textContent =
            data.validation;


    }
    catch(error){

        document.getElementById(
            "engineStatus"
        ).textContent =
            "Offline";

    }

}



// =====================================
// Global Solar Day Query
// =====================================

async function searchDay(){


      console.log("Gabary Solar Day Query");

    const day =
        document.getElementById(
            "dayInput"
        ).value;


    if(!day)
        return;


    try{

        const response =
            await fetch(
                `${API_BASE}/api/json/day/${day}`
            );


        const data =
            await response.json();


        document.getElementById(
            "globalSolarDay"
        ).textContent =
            data.globalSolarDay;


        document.getElementById(
            "solarDate"
        ).textContent =
            `${data.solarDate.weekday}, ${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}`;


        document.getElementById(
            "dayOfYear"
        ).textContent =
            data.solarDate.dayOfYear;


        document.getElementById(
            "weekIndex"
        ).textContent =
            data.calendarMetadata.weekIndex;


        document.getElementById(
            "cycleNumber"
        ).textContent =
            data.temporalMetadata.cycleNumber;


        document.getElementById(
            "historicalIndex"
        ).textContent =
            data.temporalMetadata.historicalIndex;


        document.getElementById(
            "engineName"
        ).textContent =
            data.architecture.engine;


        document.getElementById(
            "validationState"
        ).textContent =
            data.architecture.validation;


        document.getElementById(
            "result"
        ).textContent =
            JSON.stringify(
                data,
                null,
                4
            );



        const reportResponse =
            await fetch(
                `${API_BASE}/api/day/${day}`
            );


        const reportText =
            await reportResponse.text();


        document.getElementById(
            "textReport"
        ).textContent =
            reportText;


    }
    catch(error){

        document.getElementById(
            "result"
        ).textContent =
            "API CONNECTION ERROR";

    }

}
// =====================================
// Digital Clock
// =====================================

function updateClock(){

    const now =
        new Date();


    document.getElementById(
        "clock"
    ).textContent =
        now.toUTCString()
        .split(" ")[4];


    document.getElementById(
        "date"
    ).textContent =
        now.toDateString();

}
// =====================================
// Timeline Quick Range
// =====================================

function setTimelineRange(days){

    const startInput =
        document.getElementById("timelineStart");

    const endInput =
        document.getElementById("timelineEnd");

    let start =
        Number(startInput.value);

    if(!Number.isInteger(start) || start < 1){

        start = 1;

        startInput.value = start;
    }

    const end =
        start + days - 1;

    endInput.value = end;
}

// =====================================
// Timeline Explorer V3
// =====================================

async function loadTimeline(){

    console.log("Gabary Visual Timeline V3");

    const startInput =
        document.getElementById("timelineStart");

    const endInput =
        document.getElementById("timelineEnd");

    const outputElement =
        document.getElementById("timelineResult");

    const start =
        Number(startInput.value);

    const end =
        Number(endInput.value);

    // ==============================
    // Input Validation
    // ==============================

    if(
        !Number.isInteger(start) ||
        !Number.isInteger(end)
    ){

        outputElement.innerHTML =
            "<div class=\"timeline-message\">Please enter valid Global Solar Day IDs.</div>";

        return;
    }

    if(start < 1){

        outputElement.innerHTML =
            "<div class=\"timeline-message\">Global Solar Day must be >= 1.</div>";

        return;
    }

    if(end < start){

        outputElement.innerHTML =
            "<div class=\"timeline-message\">End Day ID must be greater than or equal to Start Day ID.</div>";

        return;
    }

    const count =
        end - start + 1;

    // ==============================
    // Safety Limit
    // ==============================

    if(count > 100){

        outputElement.innerHTML = `
            <div class="timeline-message">
                <strong>TIMELINE RANGE TOO LARGE</strong>
                <br><br>
                Requested days : ${count}
                <br>
                Maximum per query : 100
                <br><br>
                Please use a smaller range.
            </div>
        `;

        return;
    }

    // ==============================
    // Loading State
    // ==============================

    outputElement.innerHTML = `
        <div class="timeline-loading">
            <strong>GABARY V2 VISUAL TIMELINE</strong>
            <br><br>
            Loading ${count} day${count === 1 ? "" : "s"}...
        </div>
    `;

    // ==============================
    // Timeline Container
    // ==============================

    let timelineHTML = `
        <div class="visual-timeline">

            <div class="timeline-header">

                <div>
                    <span class="timeline-label">
                        START
                    </span>

                    <strong>
                        ${start}
                    </strong>
                </div>

                <div class="timeline-range">
                    ${count} DAY${count === 1 ? "" : "S"}
                </div>

                <div>
                    <span class="timeline-label">
                        END
                    </span>

                    <strong>
                        ${end}
                    </strong>
                </div>

            </div>

            <div class="timeline-track">
    `;

    // ==============================
    // Query Timeline
    // ==============================

    for(
        let day = start;
        day <= end;
        day++
    ){

        try{

            const response =
                await fetch(
                    `${API_BASE}/api/json/day/${day}`
                );

            if(!response.ok){

                throw new Error(
                    `HTTP ${response.status}`
                );

            }

            const data =
                await response.json();

            const leapYear =
                data.calendarMetadata.leapYear
                    ? "LEAP YEAR"
                    : "COMMON YEAR";

            timelineHTML += `
                <article class="timeline-node">

                    <div class="timeline-marker">
                        <span></span>
                    </div>

                    <div class="timeline-content">

                        <div class="timeline-day-id">
                            GLOBAL SOLAR DAY
                            <strong>
                                ${data.globalSolarDay}
                            </strong>
                        </div>

                        <div class="timeline-date">
                            ${data.solarDate.weekday},
                            ${data.solarDate.day}
                            ${data.solarDate.monthName}
                            ${data.solarDate.year}
                        </div>

                        <div class="timeline-grid">

                            <div class="timeline-stat">
                                <span>DAY OF YEAR</span>
                                <strong>
                                    ${data.solarDate.dayOfYear}
                                </strong>
                            </div>

                            <div class="timeline-stat">
                                <span>WEEK INDEX</span>
                                <strong>
                                    ${data.calendarMetadata.weekIndex}
                                </strong>
                            </div>

                            <div class="timeline-stat">
                                <span>YEAR TYPE</span>
                                <strong>
                                    ${leapYear}
                                </strong>
                            </div>

                            <div class="timeline-stat">
                                <span>CYCLE</span>
                                <strong>
                                    ${data.temporalMetadata.cycleNumber}
                                </strong>
                            </div>

                            <div class="timeline-stat">
                                <span>HISTORICAL INDEX</span>
                                <strong>
                                    ${data.temporalMetadata.historicalIndex}
                                </strong>
                            </div>

                        </div>

                        <div class="timeline-engine">

                            <span>
                                ${data.architecture.name}
                            </span>

                            <span>
                                ${data.architecture.engine}
                            </span>

                            <span class="timeline-validation">
                                ${data.architecture.validation}
                            </span>

                        </div>

                    </div>

                </article>
            `;

        }
        catch(error){

            timelineHTML += `
                <article class="timeline-node timeline-error">

                    <div class="timeline-marker">
                        <span></span>
                    </div>

                    <div class="timeline-content">

                        <div class="timeline-day-id">
                            GLOBAL SOLAR DAY
                            <strong>${day}</strong>
                        </div>

                        <div class="timeline-error-message">
                            Timeline data unavailable
                            <br>
                            ${error.message}
                        </div>

                    </div>

                </article>
            `;

        }

        // Render progressively during the query.
        outputElement.innerHTML =
            timelineHTML +
            `
                </div>
                <div class="timeline-progress">
                    Processed ${day - start + 1} / ${count}
                </div>
            </div>
            `;

    }

    // ==============================
    // Complete Timeline
    // ==============================

    timelineHTML += `
            </div>

            <div class="timeline-footer">

                <strong>
                    TIMELINE QUERY COMPLETE
                </strong>

                <span>
                    ${count} day${count === 1 ? "" : "s"} processed
                </span>

            </div>

        </div>
    `;

    outputElement.innerHTML =
        timelineHTML;

}


// =====================================
// Application Startup
// =====================================

setInterval(
    updateClock,
    1000
);

updateClock();

loadStatus();
