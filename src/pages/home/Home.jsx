import React from 'react'



export default function Home() {
  return (
    <>
        <body>
            <button id="themeButton">
                <i id="themeIcon" icon-name="moon"></i>
            </button>
            <div class="container">

                <div class="timeBlock">
                    <div class="clock">
                        <div id="hour"></div>
                        <div id="separator"></div>
                        <div id="minutes"></div>
                        <div id="separator2"></div>
                        <div id="seconds"></div>
                    </div>
                    <div id="greetings"></div>
                </div>

                <div class="weatherBlock">
                    <div class="date">
                        <div id="month"></div>
                        <div id="day"></div>
                    </div>
                    <div class="weather">
                        <div class="weatherIcon">
                            {/* <img src="assets/icons/OneDark/unknown.png" /> */}
                        </div>
                        <div class="weatherValue">
                            <p>- °<span class="g">c</span></p>
                        </div>
                        <div class="weatherDescription">
                            <p></p>
                        </div>
                    </div>
                </div>

                <div class="linksBlock" id="linksBlock">
                    <div class="linksBlockLeft" id="linksBlockLeft"></div>
                    <div class="linksBlockRight" id="linksBlockRight"></div>
                </div>
            </div>

            <script src="config.js"></script>

            <script src="assets/js/layout.js"></script>
            <script src="assets/js/theme.js"></script>
            <script src="assets/js/time.js"></script>
            <script src="assets/js/greeting.js"></script>
            <script src="assets/js/weather.js"></script>

            <script src="assets/js/buttons.js"></script>
            <script src="assets/js/lists.js"></script>

            <script>
                lucide.createIcons();
            </script>
        </body>
    </>
  )
}
