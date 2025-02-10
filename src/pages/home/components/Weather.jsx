import React, { useEffect, useState } from "react";

// icon import
import icon01d from './assets/icons/01d.png';
import icon01n from './assets/icons/01n.png';
import icon02d from './assets/icons/02d.png';
import icon02n from './assets/icons/02n.png';
import icon03d from './assets/icons/03d.png';
import icon03n from './assets/icons/03n.png';
import icon04d from './assets/icons/04d.png';
import icon04n from './assets/icons/04n.png';
import icon09d from './assets/icons/09d.png';
import icon09n from './assets/icons/09n.png';
import icon10d from './assets/icons/10d.png';
import icon10n from './assets/icons/10n.png';
import icon11d from './assets/icons/11d.png';
import icon11n from './assets/icons/11n.png';
import icon13d from './assets/icons/13d.png';
import icon13n from './assets/icons/13n.png';
import icon50d from './assets/icons/50d.png';
import icon50n from './assets/icons/50n.png';
import iconUnknown from './assets/icons/unknown.png';

const CONFIG = {
	// Weather
	weatherKey: 'dfe4d2bae9ec68449e69ccaf720e15d3', // Write here your API Key
	weatherIcons: 'OneDark', // 'Onedark', 'Nord', 'Dark', 'White'
	weatherUnit: 'C', // 'F', 'C'
	language: 'en',

	trackLocation: true, // If false or an error occurs, the app will use the lat/lon below
	defaultLatitude: '20.960',
	defaultLongitude: '105.786',
}

const weatherIcon = {
	"01d": icon01d,
	"01n": icon01n,
	"02d": icon02d,
	"02n": icon02n,
	"03d": icon03d,
	"03n": icon03n,
	"04d": icon04d,
	"04n": icon04n,
	"09d": icon09d,
	"09n": icon09n,
	"10d": icon10d,
	"10n": icon10n,
	"11d": icon11d,
	"11n": icon11n,
	"13d": icon13d,
	"13n": icon13n,
	"50d": icon50d,
	"50n": icon50n,
	"unknown": iconUnknown,
}

export default function Weather() {
	const [time, setTime] = useState({
		month: "",
		day: "",
	});
	const [weather, setWeather] = useState({
		temperature: {
			value: 0,
			unit: 'C',
		},
		description: "",
		iconId: "",
	});

	const displayTime = () => {
		const monthNames = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec",];

		const timer = setInterval(() => {
			const d = new Date();
			const mm = monthNames[d.getMonth()];
			const dd = d.getDate();

			setTime({
				month: mm,
				day: dd,
			});
		}, 1000);
	}

	const getWeather = (latitude, longitude) => {
		let api = `https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&lang=${CONFIG.language}&appid=${CONFIG.weatherKey}`;
		fetch(api)
		.then(function(response) {
			let data = response.json();
			return data;
		})
		.then(function(data) {
			let celsius = Math.floor(data.main.temp - 273.15);
			setWeather({
				temperature: {
					value: celsius,
					unit: 'C',
				},
				description: data.weather[0].description,
				iconId: data.weather[0].icon,
			});
		})
	}

	useEffect(() => {
		getWeather(CONFIG.defaultLatitude, CONFIG.defaultLongitude);
	}, []);

	useEffect(() => {
		displayTime();

		return () => {
			clearInterval(displayTime);
		}
	}, []);

	return (
		<div className="flex flex-col items-center justify-center col-start-3 col-span-2 row-start-1 row-span-2">
			<div className="flex items-center justify-center mt-8 text-[130px]">
				<div className="font-bold">{time.month + " " + time.day}</div>
			</div>

			<div className="weather flex items-center justify-center text-3xl">
				<div className="">
					<img 
						className="w-18 h-18" 
						src={weatherIcon[weather.iconId] ?? weatherIcon["unknown"]}
					/>
				</div>
				<div className="">
					<p className="font-bold ml-4">
						{weather.temperature.value ?? "-"}°<span>C</span>
					</p>
				</div>
					<div className="ml-4">
					<p>{weather.description}</p>
				</div>
			</div>
		</div>
	);
}
