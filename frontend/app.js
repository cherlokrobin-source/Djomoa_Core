document.addEventListener('DOMContentLoaded', () => {
    const btnDay = document.getElementById('btn-query-day');
    const btnSolar = document.getElementById('btn-query-solar');
    const output = document.getElementById('json-output');

    btnDay.addEventListener('click', async () => {
        const dayId = document.getElementById('day-input').value || 1;
        output.textContent = "جاري الاستعلام...";
        try {
            const res = await fetch(`/api/json/day/${dayId}`);
            const data = await res.json();
            output.textContent = JSON.stringify(data, null, 2);
        } catch (err) {
            output.textContent = "حدث خطأ في جلب البيانات.";
        }
    });

    btnSolar.addEventListener('click', async () => {
        const y = document.getElementById('solar-y').value || 2026;
        const m = document.getElementById('solar-m').value || 9;
        const d = document.getElementById('solar-d').value || 5;
        output.textContent = "جاري التحويل...";
        try {
            const res = await fetch(`/api/solar/${y}/${m}/${d}`);
            const data = await res.json();
            output.textContent = JSON.stringify(data, null, 2);
        } catch (err) {
            output.textContent = "حدث خطأ في التحويل الشمسي.";
        }
    });
});
