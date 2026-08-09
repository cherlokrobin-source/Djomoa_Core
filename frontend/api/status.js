/*
==========================================
 GOLDEN CALENDAR
 API STATUS MODULE
==========================================
*/


const API_BASE = "";


export async function getStatus()
{

    try
    {

        const response =
            await fetch(
                `${API_BASE}/api/status`
            );


        if(!response.ok)
        {
            throw new Error(
                "API connection failed"
            );
        }


        return await response.json();

    }

    catch(error)
    {

        console.error(
            "Status API Error:",
            error
        );


        return {
            status: "offline",
            error: error.message
        };

    }

}
