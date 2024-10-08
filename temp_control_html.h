#ifndef ESP_HTML_H
#define ESP_HTML_H

// Your HTML content or declarations go here
const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Temperature and Humidity Control</title>
    <style>
        /* Changes the style of the body */
        body {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            min-height: 100vh;
            margin: 0;
            font-family: Arial, sans-serif;
            text-align: center;
        }
        /* Changes the style of the title */
        .title {
            font-size: 2em;
            margin-bottom: 20px;
            font-family: Arial, sans-serif;
            font-weight: bold;
        }
        /* Changes the style of the mode title */
        .subtitle {
            padding-bottom: 20px;
            font-size: 1.5em;
            font-weight: bold;
        }
        /* Changes the style of the entire controls container */
        .controls {
            display: flex;
            flex-direction: column;
            align-items: center;
            border: 1px solid #ccc;
            padding: 20px;
            border-radius: 8px;
            background-color: #f9f9f9;
        }
        /* Changes the style of each of the containers of each mode */
        .modes-container {
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        /* Changes style of each of the modes */
        .Modes {
            padding: 10px;
            border: 1px solid #ccc;
            padding-top: 20px;
            margin-bottom: 10px;
            width: 300px;
            display: none;
        }
        /* Changes the style of the buttons */
        .button-container {
            display: flex;
            gap: 10px;
            margin-bottom: 20px;
        }
        /* Changes the style of the textboxes */
        .message {
            width: 90%;
            height: 20px;
            padding: 10px;
            box-sizing: border-box;
            margin-bottom: 10px;
        }
        /* Changes the style of the submit buttons */
        .modeButton {
            margin-left: 210px;
        }
        /* Changes the style of the color control section */
        .colorControl {
            display: flex;
            flex-direction: column;
            align-items: center; 
            margin-top: 20px;
        }
        /* Changes the style of the color display box */
        .colorDisplay {
            width: 200px;
            height: 200px;
            border: 1px solid #ccc;
            margin-top: 20px;
        }
        /* Changes the style of the slider */
        .slider-container {
            margin: 10px 0;
        }
        /* Style for the fan speed slider */
        .slider-container input[type="range"] {
        appearance: none;
        width: 300px;
        height: 8px;
        background: #ddd;
        border-radius: 5px;
        outline: none;
        opacity: 0.7;
        transition: opacity .2s;
        }
        .slider-container input[type="range"]::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 15px;
            height: 15px;
            background: #4CAF50;
            cursor: pointer;
            border-radius: 50%;
        }
        .slider-container input[type="range"]::-moz-range-thumb {
            width: 15px;
            height: 15px;
            background: #4CAF50;
            cursor: pointer;
            border-radius: 50%;
        }

        .fan {
            width: 150px;
            height: 150px;
            margin-bottom: 10px;
            transform-origin: 50% 50%;
        }

        /* Fan animation class */
        .spinning {
            animation: spin 1s linear infinite;
        }

        /* Default fan animation (speed 1) */
        @keyframes spin {
            100% {
                transform: rotate(360deg);
            }
        }
    </style>
</head>
<body>
    <div class="title">Controls</div>
    <div class="controls">
        <label class="subtitle" id="subTexts">Under 20 degrees</label>
        <div class="button-container">
            <button class="buttons" id="mode1" onclick="switchMode(this.id)">Mode 1</button>
            <button class="buttons" id="mode2" onclick="switchMode(this.id)">Mode 2</button>
            <button class="buttons" id="mode3" onclick="switchMode(this.id)">Mode 3</button>
            <button class="buttons" id="mode4" onclick="switchMode(this.id)">Mode 4</button>
        </div>
        <div class="modes-container">
            <div class="Modes" id="Mode1">
                <input type="text" class="message" id="temp1" placeholder="Enter your message for the temperature"><br><br>
                <input type="text" class="message" id="hum1" placeholder="Enter your message for the humidity"><br><br>
                <button class="modeButton" id="mode1Button" onclick="sendMessage(this.id)">Submit</button>
                <div class="colorControl">
                    <h2>Mode 1 Color Control</h2>
                    <div class="slider-container">
                        <label for="redRange1">Red: <span id="redValue1">0</span></label><br>
                        <input type="range" id="redRange1" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="greenRange1">Green: <span id="greenValue1">0</span></label><br>
                        <input type="range" id="greenRange1" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="blueRange1">Blue: <span id="blueValue1">0</span></label><br>
                        <input type="range" id="blueRange1" min="0" max="255" value="0">
                    </div>
                    <div id="colorDisplay1" class="colorDisplay"></div>
                    <p id="colorValue1">Selected Color: #000000</p>
                </div>
                <button class="modeButton" id="color1Button" onclick="sendColor(this.id)">Submit</button>
                <h1 class="subtitle">Fan Speed</h1>
                <svg id="fanSvg1" class="fan spinning" viewBox="0 0 100 100">
                    <circle cx="50" cy="50" r="40" fill="#ccc" />
                    <polygon points="50,10 55,50 45,50" fill="#4CAF50" />
                    <polygon points="90,50 50,55 50,45" fill="#4CAF50" />
                    <polygon points="50,90 55,50 45,50" fill="#4CAF50" />
                    <polygon points="10,50 50,45 50,55" fill="#4CAF50" />
                </svg>

                <div class="slider-container">
                    <label for="fanSpeedRange">Fan Speed: <span id="fanSpeedValue1">0</span>%</label><br>
                    <input type="range" id="fanSpeedRange1" min="0" max="100" value="0">
                </div>
                <button class="modeButton" id="fan1Button" onclick="sendSpeed(this.id)">Submit</button>
            </div>
            <div class="Modes" id="Mode2">
                <input type="text" class="message" id="temp2" placeholder="Enter your message for the temperature"><br><br>
                <input type="text" class="message" id="hum2" placeholder="Enter your message for the humidity"><br><br>
                <button class="modeButton" id="mode2Button" onclick="sendMessage(this.id)">Submit</button>
                <div class="colorControl">
                    <h2>Mode 2 Color Control</h2>
                    <div class="slider-container">
                        <label for="redRange2">Red: <span id="redValue2">0</span></label><br>
                        <input type="range" id="redRange2" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="greenRange2">Green: <span id="greenValue2">0</span></label><br>
                        <input type="range" id="greenRange2" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="blueRange2">Blue: <span id="blueValue2">0</span></label><br>
                        <input type="range" id="blueRange2" min="0" max="255" value="0">
                    </div>
                    <div id="colorDisplay2" class="colorDisplay"></div>
                    <p id="colorValue2">Selected Color: #000000</p>
                </div>
                <button class="modeButton" id="color2Button" onclick="sendColor(this.id)">Submit</button>
                <h1 class="subtitle">Fan Speed</h1><br>
                <svg id="fanSvg2" class="fan spinning" viewBox="0 0 100 100">
                    <circle cx="50" cy="50" r="40" fill="#ccc" />
                    <polygon points="50,10 55,50 45,50" fill="#4CAF50" />
                    <polygon points="90,50 50,55 50,45" fill="#4CAF50" />
                    <polygon points="50,90 55,50 45,50" fill="#4CAF50" />
                    <polygon points="10,50 50,45 50,55" fill="#4CAF50" />
                </svg>

                <div class="slider-container">
                    <label for="fanSpeedRange">Fan Speed: <span id="fanSpeedValue2">0</span>%</label><br>
                    <input type="range" id="fanSpeedRange2" min="0" max="100" value="0">
                </div>
                <button class="modeButton" id="fan2Button" onclick="sendSpeed(this.id)">Submit</button>
            </div>
            <div class="Modes" id="Mode3">
                <input type="text" class="message" id="temp3" placeholder="Enter your message for the temperature"><br><br>
                <input type="text" class="message" id="hum3" placeholder="Enter your message for the humidity"><br><br>
                <button class="modeButton" id="mode3Button" onclick="sendMessage(this.id)">Submit</button>
                <div class="colorControl">
                    <h2>Mode 3 Color Control</h2>
                    <div class="slider-container">
                        <label for="redRange3">Red: <span id="redValue3">0</span></label><br>
                        <input type="range" id="redRange3" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="greenRange3">Green: <span id="greenValue3">0</span></label><br>
                        <input type="range" id="greenRange3" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="blueRange3">Blue: <span id="blueValue3">0</span></label><br>
                        <input type="range" id="blueRange3" min="0" max="255" value="0">
                    </div>
                    <div id="colorDisplay3" class="colorDisplay"></div>
                    <p id="colorValue3">Selected Color: #000000</p>
                </div>
                <button class="modeButton" id="color3Button" onclick="sendColor(this.id)">Submit</button>
                <h1 class="subtitle">Fan Speed</h1><br>
                <svg id="fanSvg3" class="fan spinning" viewBox="0 0 100 100">
                    <circle cx="50" cy="50" r="40" fill="#ccc" />
                    <polygon points="50,10 55,50 45,50" fill="#4CAF50" />
                    <polygon points="90,50 50,55 50,45" fill="#4CAF50" />
                    <polygon points="50,90 55,50 45,50" fill="#4CAF50" />
                    <polygon points="10,50 50,45 50,55" fill="#4CAF50" />
                </svg>

                <div class="slider-container">
                    <label for="fanSpeedRange">Fan Speed: <span id="fanSpeedValue3">0</span>%</label><br>
                    <input type="range" id="fanSpeedRange3" min="0" max="100" value="0">
                </div>
                <button class="modeButton" id="fan3Button" onclick="sendSpeed(this.id)">Submit</button>
            </div>
            <div class="Modes" id="Mode4">
                <input type="text" class="message" id="temp4" placeholder="Enter your message for the temperature"><br><br>
                <input type="text" class="message" id="hum4" placeholder="Enter your message for the humidity"><br><br>
                <button class="modeButton" id="mode4Button"  onclick="sendMessage(this.id)">Submit</button>
                <div class="colorControl">
                    <h2>Mode 4 Color Control</h2>
                    <div class="slider-container">
                        <label for="redRange4">Red: <span id="redValue4">0</span></label><br>
                        <input type="range" id="redRange4" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="greenRange4">Green: <span id="greenValue4">0</span></label><br>
                        <input type="range" id="greenRange4" min="0" max="255" value="0">
                    </div>
                    <div class="slider-container">
                        <label for="blueRange4">Blue: <span id="blueValue4">0</span></label><br>
                        <input type="range" id="blueRange4" min="0" max="255" value="0">
                    </div>
                    <div id="colorDisplay4" class="colorDisplay"></div>
                    <p id="colorValue4">Selected Color: #000000</p>
                </div>
                <button class="modeButton" id="color4Button" onclick="sendColor(this.id)">Submit</button>
                <h1 class="subtitle">Fan Speed</h1> <br>

                <svg id="fanSvg4" class="fan spinning" viewBox="0 0 100 100">
                    <circle cx="50" cy="50" r="40" fill="#ccc" />
                    <polygon points="50,10 55,50 45,50" fill="#4CAF50" />
                    <polygon points="90,50 50,55 50,45" fill="#4CAF50" />
                    <polygon points="50,90 55,50 45,50" fill="#4CAF50" />
                    <polygon points="10,50 50,45 50,55" fill="#4CAF50" />
                </svg>

                <div class="slider-container">
                    <label for="fanSpeedRange">Fan Speed: <span id="fanSpeedValue4">0</span>%</label><br>
                    <input type="range" id="fanSpeedRange4" min="0" max="100" value="0">
                </div>
                <button class="modeButton" id="fan4Button" onclick="sendSpeed(this.id)">Submit</button>
            </div>
        </div>
    </div>
    <script type="text/javascript">
        // Initialize the page to show only mode 1 by default
        switchMode('mode1');
        defaultValues();
        //Switches which mode is active
        function switchMode(id) {
            //Hides all modes at the begining
            document.querySelectorAll('.Modes').forEach(function(mode) {
                mode.style.display = 'none';
            });
            //Shows a mode depending on which mode button and submit button is pressed
            switch (id) {
                case "mode1":
                    document.getElementById('Mode1').style.display = 'block';
                    document.getElementById('subTexts').innerHTML = "Under 20 degrees";
                    break;
                case "mode2":
                    document.getElementById('Mode2').style.display = 'block';
                    document.getElementById('subTexts').innerHTML = "Between 21 to 25 degrees";
                    break;
                case "mode3":
                    document.getElementById('Mode3').style.display = 'block';
                    document.getElementById('subTexts').innerHTML = "Between 25 to 30 degrees";
                    break;
                case "mode4":
                    document.getElementById('Mode4').style.display = 'block';
                    document.getElementById('subTexts').innerHTML = "Over 30 degrees";
                    break;
            }
        }
        //Adds a delay to sendMessage function
        function delay(ms) {
            return new Promise(resolve => setTimeout(resolve, ms));
        }
        //Sends both temperature message and humidity message
        function sendMessage(mode){
            var modes = mode.replace('mode', '').replace('Button', '');
            var idTemp = mode.replace('mode', 'temp').replace('Button', '');
            var idHum = mode.replace('mode', 'hum').replace('Button', '');
            var tempMessage = document.getElementById(idTemp).value;
            var humMessage = document.getElementById(idHum).value;
                if(tempMessage != ""){
                    var xhttp = new XMLHttpRequest();
                    xhttp.open("PUT", "/TEMP?T="+tempMessage, true);
                    xhttp.send();
                }
                if(humMessage != ""){
                    var xhttp = new XMLHttpRequest();
                    xhttp.open("PUT", "/HUM?H="+humMessage, true);
                    xhttp.send();
                }
                var xhttp = new XMLHttpRequest();
                    xhttp.open("PUT", "/MODEa?Ma="+modes, true);
                    xhttp.send();
            }

        function sendColor(mode){
            var modes = mode.replace('color', '').replace('Button', '');
            var color = document.getElementById(mode.replace('color', 'colorValue').replace('Button', '')).textContent;
            console.log(color);
            var regex = /rgb\((\d+),\s*(\d+),\s*(\d+)\)/;
            var match = color.match(regex);
            if (match) {
                var red = match[1];
                var green = match[2];
                var blue = match[3];
            }
            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "/COLOR?R=" + red + "&G=" + green + "&B=" + blue, true);
            xhttp.send();

            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "/MODEb?Mb=" + modes, true);
            xhttp.send();
        }
        function sendSpeed(mode){
            var modes = mode.replace('fan', '').replace('Button', '');
            var fan = document.getElementById(mode.replace('fan', 'fanSpeedValue').replace('Button', '')).textContent;
            var actualSpeed = Math.round((parseInt(fan)/100)*255);
            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "/FAN?F=" + actualSpeed, true);
            xhttp.send();

            var xhttp = new XMLHttpRequest();
            xhttp.open("PUT", "/MODEc?Mc=" + modes, true);
            xhttp.send();

        }
        function defaultValues(){
            const color1 = `rgb(0,0,225)`;
            colorDisplay1.style.backgroundColor = color1;
            colorValue1.textContent = `Selected Color: ${color1}`;
            blueRange1.value = 255;
            blueValue1.textContent = 255;
            const color2 = `rgb(0,255,0)`;
            colorDisplay2.style.backgroundColor = color2;
            colorValue2.textContent = `Selected Color: ${color2}`;
            greenRange2.value = 255;
            greenValue2.textContent = 255;
            const color3 = `rgb(209,15,0)`;
            colorDisplay3.style.backgroundColor = color3;
            colorValue3.textContent = `Selected Color: ${color3}`;
            redRange3.value = 209;
            redValue3.textContent = 209; 
            greenRange3.value = 15;
            greenValue3.textContent = 15;
            const color4 = `rgb(255,0,0)`;
            colorDisplay4.style.backgroundColor = color4;
            colorValue4.textContent = `Selected Color: ${color4}`;
            redRange4.value = 255;
            redValue4.textContent = 255;
            const fanSpeedRange1 = 0;
            const fanSpeedValue1 = 0;
            const fanSvg1 = document.getElementById(`fanSvg1`);
            const fanSpeed1 = fanSpeedRange1.value;
            fanSpeedValue1.textContent = `${fanSpeed1}`;
            fanSvg1.classList.remove('spinning');
            const fanSpeedRange2 = 0;
            const fanSpeedValue2 = 0;
            const fanSvg2 = document.getElementById(`fanSvg2`);
            const fanSpeed2 = fanSpeedRange2.value;
            fanSpeedValue2.textContent = `${fanSpeed2}`;
            fanSvg2.classList.remove('spinning');
            const fanSpeedRange3 = 50;
            const fanSpeedValue3 = 50;
            const fanSvg3 = document.getElementById(`fanSvg3`);
            const fanSpeed3 = fanSpeedRange3.value;
            fanSpeedValue3.textContent = `${fanSpeed3}`;
            fanSvg3.classList.add('spinning');
            const speedFactor3 = 0.5;
            fanSvg3.style.animationDuration = `${speedFactor3}s`;
            document.getElementById(`fanSpeedValue3`).textContent = 50;
            document.getElementById(`fanSpeedRange3`).value = 50;
            const fanSpeedRange4 = 100;
            const fanSpeedValue4 = 100;
            const fanSvg4 = document.getElementById(`fanSvg4`);
            const fanSpeed4 = fanSpeedRange1.value;
            fanSpeedValue4.textContent = `${fanSpeed4}`;
            fanSvg4.classList.add('spinning');
            const speedFactor4 = 0.1;
            fanSvg4.style.animationDuration = `${speedFactor4}s`;
            document.getElementById(`fanSpeedValue4`).textContent = 100;
            document.getElementById(`fanSpeedRange4`).value = 100;
          
        }

        function updateColor(mode) {
            const redRange = document.getElementById(`redRange${mode}`);
            const greenRange = document.getElementById(`greenRange${mode}`);
            const blueRange = document.getElementById(`blueRange${mode}`);

            const redValue = document.getElementById(`redValue${mode}`);
            const greenValue = document.getElementById(`greenValue${mode}`);
            const blueValue = document.getElementById(`blueValue${mode}`);

            const colorDisplay = document.getElementById(`colorDisplay${mode}`);
            const colorValue = document.getElementById(`colorValue${mode}`);

            const red = redRange.value;
            const green = greenRange.value;
            const blue = blueRange.value;

            const color = `rgb(${red}, ${green}, ${blue})`;
            colorDisplay.style.backgroundColor = color;
            colorValue.textContent = `Selected Color: ${color}`;

            redValue.textContent = red;
            greenValue.textContent = green;
            blueValue.textContent = blue;
        }

        function updateSpeed(mode){
            const fanSpeedRange = document.getElementById(`fanSpeedRange${mode}`); 
            const fanSpeedValue = document.getElementById(`fanSpeedValue${mode}`);
            const fanSvg = document.getElementById(`fanSvg${mode}`);
            const fanSpeed = fanSpeedRange.value;
            fanSpeedValue.textContent = `${fanSpeed}`;

            if (fanSpeed == 0) {
                fanSvg.classList.remove('spinning');
            } else {
                fanSvg.classList.add('spinning');
                const speedFactor = Math.max(0.1, 1 - fanSpeed / 100);
                fanSvg.style.animationDuration = `${speedFactor}s`;
            }
           
        }
       

        document.querySelectorAll('.Modes').forEach(function(mode) {
            const modeId = mode.id.replace('Mode', '');

            document.getElementById(`redRange${modeId}`).addEventListener('input', function() {
                updateColor(modeId);
            });
            document.getElementById(`greenRange${modeId}`).addEventListener('input', function() {
                updateColor(modeId);
            });
            document.getElementById(`blueRange${modeId}`).addEventListener('input', function() {
                updateColor(modeId);
            });
            document.getElementById(`fanSpeedRange${modeId}`).addEventListener('input', function() {
                updateSpeed(modeId);
            });
        });


        
    </script>
</body>
</html>

)=====";

#endif // ESP_HTML_H
