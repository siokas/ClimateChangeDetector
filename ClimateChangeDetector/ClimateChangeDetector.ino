/*
 This is an example that read values from 3 analog and 1 pwm sensors and saves the values on
 an external sd card. This project is targeting the Arduino Yun.

 About the project: It is a school project for Ecology 101 class and reads values from a:
    1. Rain Detector Sensor (A0)
    2. Soil Moisture Sensor (A1)
    3. Photo-Resistor       (A3)
    4. Humidity-Temperature (pin 2) 
    
 and saves the data in order to keep tracking about the climate change rate.

-- Apostolos Siokas --

*/

#include <FileIO.h>
#include "DHT.h"

#define DHTPIN 2  // DHT sensor conected to pin 2
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);
int looptimes = 0;

void setup() {
  // Initialize the Bridge and the Serial
  Bridge.begin();
  Serial.begin(9600);
  FileSystem.begin();
  dht.begin();

  while (!Serial); // wait for Serial port to connect.
  Serial.println("Filesystem datalogger\n");
}


void loop () {
  // make a string that start with a timestamp for assembling the data to log:
  String dataString;
  dataString += getTimeStamp();
  dataString += " = ";
  String th = printTempHum();

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";  // separate the values with a comma
    }
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  // The FileSystem card is mounted at the following "/mnt/FileSystema1"
  File dataFile = FileSystem.open("/mnt/sd/datalog.txt", FILE_APPEND);

  // if the file is available, write to it:
  if (dataFile) {
    if(looptimes == 0){
      dataFile.println("Start Tracking: Rain Detector - Soil Moisture Detector - Light Detector - Humidity in Air - Temperature");
      looptimes++;
    }
    dataString+="," + th;
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

  delay(5000);

}

String printTempHum(){
  String tempHum = "";
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    tempHum = "Failed to read from DHT";
  } else {
    tempHum = String(h,2) + "," + String (t,2);
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  return tempHum;
}

// This function return a string with the time stamp
String getTimeStamp() {
  String result;
  Process time;
  // date is a command line utility to get the date and the time
  // in different formats depending on the additional parameter
  time.begin("date");
  time.addParameter("+%D-%T");  // parameters: D for the complete date mm/dd/yy
  //             T for the time hh:mm:ss
  time.run();  // run the command

  // read the output of the command
  while (time.available() > 0) {
    char c = time.read();
    if (c != '\n')
      result += c;
  }

  return result;
}
