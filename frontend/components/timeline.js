/*
==========================================
 GOLDEN CALENDAR
 TIMELINE COMPONENT
==========================================
*/


import { getDay } from "../api/day.js";



export function initializeTimeline()
{

    const slider =
        document.getElementById(
            "timelineRange"
        );


    const yearValue =
        document.getElementById(
            "yearValue"
        );



    if(!slider)
    {
        return;
    }



    slider.addEventListener(
        "input",
        async function()
        {


            const year =
                this.value;



            if(yearValue)
            {
                yearValue.textContent =
                    year;
            }


            /*
            تقريب السنة إلى Day ID
            لاختبار الاستكشاف
            */


            const dayId =
                Number(year) * 365;


            const result =
                await getDay(
                    dayId
                );


            const output =
                document.getElementById(
                    "result"
                );


            if(output)
            {

                output.textContent =
                    JSON.stringify(
                        result,
                        null,
                        4
                    );

            }


        }
    );

}
