const API_BASE = "http://localhost:8080";



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
).textContent=data.status;


document.getElementById(
"engineVersion"
).textContent=data.version;


document.getElementById(
"engineTests"
).textContent=data.tests;


}

catch(error){

document.getElementById(
"engineStatus"
).textContent="Offline";

}

}





async function searchDay(){

const day =
document.getElementById(
"dayInput"
).value;


if(!day)return;


try{


const response =
await fetch(
`${API_BASE}/api/day/${day}`
);


const data =
await response.json();


document.getElementById(
"result"
).textContent=
JSON.stringify(
data,
null,
4
);


}

catch(error){


document.getElementById(
"result"
).textContent=
"API ERROR";


}

}





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



setInterval(
updateClock,
1000
);


updateClock();


loadStatus();
