### Welcome to Climate Change Detector.
Climate Change Detector is a school project device that reads values from five sensors
1. Rain Detector 
2. Soil Moisture Sensor
3. Humidity
4. Temperature
5. Photo Resistor

...and saves the data into an SD card. This project is created for an Ecology class and it is detecting the climate change in a specific time.


***


### Rain Detector
![Rain Detector](https://raw.githubusercontent.com/solotsopa/ClimateChangeDetector/master/ClimateChangeDetector/images/rainD.jpg)
<br><br>
Rain Detector is a sensor that detects the raindrops. It can be used for all kinds of weather monitoring.
Product introduction:
1. the sensor USES the high quality FR - 04 double material, large area of 5.0 * 4.0 CM, treatment of nickel plating and surface, have fight oxidation, electrical conductivity, and life has more superior performance;
2. the comparator output, signal clean, good waveform, driving ability is strong, for more than 15 ma;
3. with potentiometer sensitivity adjustment;
4. the working voltage of 3.3 V to 5 V
5. the output format: digital switch output (0 and 1) and analog AO voltage output;
6. has a fixed bolt hole, convenient installation
7. small board PCB size: 3.2 cm x 1.4 cm
8. the LM393, use of wide voltage comparator
Function is introduced:
Connected to 5 v power supply, power indicator, no water droplets on induction plate, the DO output high level, switch indicator light out, drop a drop of water on, the DO output for the low level, the switch light is lit,Brush away the water droplets, again to return to, the output high level...
AO analog output, which can be connected to the microcontroller AD mouth detection drops of rainfall in the above size.
DO TTL digital output also can connect to the single chip microcomputer detect whether there is rain.
Connection mode:
1. VCC: positive (3-5 v)
2. GND: connect power anode
3. DO: TTL switch signal output
4. AO: analog signal output

[Link](http://www.ebay.com/itm/Humidity-Detection-Sensor-Module-Rain-Detection-for-Arduino-/121126110187?ssPageName=ADME:L:OU:GB:3160)

### Soil Moisture Sensor
![Soil Moisture Sensor](https://raw.githubusercontent.com/solotsopa/ClimateChangeDetector/master/ClimateChangeDetector/images/soilD.jpg)
<br><br>
This is a simple water sensor can be used to detect soil moisture when the soil moisture deficit module outputs a high level, and vice versa output low. 
1. Sensitivity adjustable the blue digital potentiometer adjustment
2. Operating voltage 3.3V-5V 
3. Module dual output mode, digital output, analog output more accurate. 
4. With fixed bolt hole for easy installation 
5. PCB size: 3cm * 1.6cm 
6. Power indicator (red) and digital switching output indicator (green) 
7. Comparator LM393 chip, stable

Interface Description (4-wire) 
1. VCC: .3 V-5V 
2. GND: GND 
3. DO: digital output interface (0 and 1) 
4. AO: Analog Output Interface

Instructions for use 
1. Soil moisture module is most sensitive to the ambient humidity is generally used to detect the moisture content of the soil. 
2. Module to reach the threshold value is set in the soil moisture, DO port output high, when the the soil humidity exceeds a set threshold value, the module D0 output low; 
3. The digital output D0 can be connected directly with the microcontroller to detect high and low by the microcontroller to detect soil moisture; 
4. The digital outputs DO shop relay module can directly drive the buzzer module, which can form a soil moisture alarm equipment; 
5. Analog output AO and AD module connected through the AD converter, you can get more precise values of soil moisture

[Link](http://www.ebay.com/itm/Soil-Hygrometer-Detection-Module-Soil-Moisture-Sensor-/281043772532?ssPageName=ADME:X:AAQ:US:1123)

### Humidity and Temperature Sensor (DHT11)
![Humidity](https://raw.githubusercontent.com/solotsopa/ClimateChangeDetector/master/ClimateChangeDetector/images/DHT1.jpg)
<br><br>
DHT11 digital humidity temperature sensor is the composition sensor which contains calibrated digital output. It applies to specialized digital module, and collects technology and humidity & temperature sensor technology. All of this can guarantee the product with extremely high reliability and excellent long-term stability.

This sensor contains one resistance type moisture element and one NTC temperature-testing component, which connected to high-performance 8 pro SCM. Therefore, there are so many advantages below: high quality and excellent, extremely fast response, high antijamming capability. For each DHT11 sensor, it can calibrate in the extremely exact temperature check room. The calibration factor is stored in the OTP RAM in the form of procedural. When it tests processing of the signal inside the sensor, it needs to call the calibration factor. The single wire system port makes the system intergration simplier and faster. The excellent advantage like extreme minimum volume and ultralow energy consumption and the signal transmission distance up 20m or above, makes it become the best choice even under harshest application environment. Variously.

It is 4 pin single row package. Convenient connecting, if you need the special package type, we can customize it per your requirement.

[Link](http://www.ebay.com/itm/2pcs-DHT11-Digital-Humidity-Temperature-Sensor-DHT11-NEW-/121347042442?pt=LH_DefaultDomain_0&hash=item1c40d8ec8a)

### Photo Resistor
![Photoresistor](https://raw.githubusercontent.com/solotsopa/ClimateChangeDetector/master/ClimateChangeDetector/images/photoresistor1.jpg)
<br><br>
Photoresistors are sensors that allow you to detect light. They are small, inexpensive, low-power, easy to use and don't wear out. For that reason they often appear in toys, gadgets and appliances. They are often referred to as CdS cells (they are made of Cadmium-Sulfide), light-dependent resistors (LDR), and photoresistors. Photocells are basically a resistor that changes its resistive value (in ohms Ω) depending on how much light is shining onto the squiggly face. They are very low cost, easy to get in many sizes and specifications, but are very innacurate. Each photocell sensor will act a little differently than the other, even if they are from the same batch. The variations can be really large, 50% or higher! For this reason, they shouldn't be used to try to determine precise light levels in lux or millicandela. Instead, you can expect to only be able to determine basic light changes.

[Link](http://www.ebay.com/itm/KY-018-photoresistor-module-for-Arduino-AVR-PIC-/121167420768?pt=LH_DefaultDomain_0&hash=item1c36241d60)

### About Code
The code is targeted for the Arduino Yún and Arduino IDE 1.5.6-r2. 
* It includes two header files (the DHT.h file is provided)<br>
`#include <FileIO.h>`<br>
`#include "DHT.h"`<br>
* You have to define the DHT pin that you have connected the Humidity-Temperature sensor and the type of your module.<br>
`#define DHTPIN 2`<br>
`#define DHTTYPE DHT11`<br>
* Initialise everything that you need to<br>
`Bridge.begin();`<br>
`Serial.begin(9600);`<br>
`FileSystem.begin();`<br>
`dht.begin();`<br>
* Read all analog values in a for loop and save them in a string variable<br>
`for (int analogPin = 0; analogPin < 3; analogPin++) {`<br>
    `int sensor = analogRead(analogPin);`<br>
    `dataString += String(sensor);`<br>
    `if (analogPin < 2) {`<br>
      `dataString += ",";`<br>
    `}`<br>
  `}`<br>
* Write the values in a txt file in the SD card <br>
`File dataFile = FileSystem.open("/mnt/sd/datalog.txt", FILE_APPEND);`<br>
  `if (dataFile) {`<br>
    `dataFile.println(dataString);`<br>
    `dataFile.close();`<br>
  `}`<br>
* The .txt file should look like this<br>
`05/22/14-16:44:20 = 979,979,465,59.00,27.00`<br>
`05/22/14-16:44:26 = 970,560,477,58.00,27.00`<br>
`05/22/14-16:44:32 = 979,560,469,58.00,27.00`<br>
`05/22/14-16:44:37 = 330,560,450,58.00,27.00`<br>
`05/22/14-16:44:43 = 329,562,456,58.00,27.00`<br>
`05/22/14-16:44:49 = 328,563,456,58.00,27.00`<br>
