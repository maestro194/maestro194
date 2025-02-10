import React from 'react'
import { useEffect, useState } from 'react'

export default function () {
    const [time, setTime] = useState({
        "hour": 0,
        "separator": ":",
        "minutes": 0,
        "separator2": ":",
        "seconds": 0,
        "month": "",
        "day": ""
    })
    const [greeting, setGreeting] = useState("a");

    const displayClock = () => {
        const monthNames = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
        
        const timer = setInterval(() => {
            var d = new Date();
            var mm = monthNames[d.getMonth()];
            var dd = d.getDate();
            var min = (('0' + d.getMinutes()).slice(-2));
            var hh = d.getHours();
            var ss = (('0' + d.getSeconds()).slice(-2));
            
            setTime({
                "hour": hh,
                "separator": ":",
                "minutes": min,
                "separator2": ":",
                "seconds": ss,
                "month": mm,
                "day": dd
            })
        }, 1000);
    }

    const greetingText = () => {
        const greet = [
            "Go to Sleep, Maestro!",
            "Good morning, Maestro",
            "Good afternoon, Maestro",
            "Good evening Maestro"
        ];
        var d = new Date();
        var hour = d.getHours();
        hour = Math.floor(hour / 6);
        
        return greet.at(hour);
    }

    useEffect(() => {
        displayClock();
        setGreeting(greetingText);

        return () => {
            clearInterval(displayClock)
        }
    },[]);

    return (
        <div className='flex flex-col items-center justify-center col-start-1 col-span-2 row-start-1 row-span-2'>
            <div className="flex items-center justify-center text-[130px] mb-10">
                <div className='font-bold'>{time.hour}</div>
                <div className='font-bold'>{time.separator}</div>
                <div className='font-bold'>{time.minutes}</div>
                <div className='font-bold'>{time.separator2}</div>
                <div className='font-bold'>{time.seconds}</div>
            </div>
            
            <div className="text-black text-3xl">{greeting}</div>
        </div>
    )
}
