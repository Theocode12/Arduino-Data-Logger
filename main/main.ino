#include <RTClib.h>
#include "DHT.h"
#include "SD.h"
#include "SPI.h"

#define DHTPIN 2     
#define DHTTYPE DHT11   // DHT 11
#define CS_PIN 10
#define VOLTPIN A0

RTC_DS1307 rtc;
DHT dht(DHTPIN, DHTTYPE);
File mylogger;
DateTime now;
DateTime fut_time;
char filename[13] = {"hhmmss"};

int isValidTemp() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return 0;
  }
  return 1;
}

int isValidReadings() {
 // && isValidTemp()
  if (isValidTime() && isValidVolt()) {
    Serial.println("valid Readings");
    return 1;
  }
  Serial.println("Invalid Readings");
  return 0;
}

void takeReadings() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
//   Serial.println(filename);
  if (openFileToWrite(filename)) {
    char buffer[10] = {"hh:mm:ss"};
    writeToFile(now.toString(buffer));
    writeToFile(String(temperature));
    writeToFile(String(humidity), 1);

    Serial.print(now.toString(buffer));
    Serial.print(F(","));
    Serial.print(humidity);
    Serial.print(F(","));
    Serial.println(temperature);
    closeFile();
  }
}

int findMode(int volts) {
  if (volts < 15) {
    return 1;
  } else if (volts < 80) {
    return 2;
  } else {
    return 0;
  }
}

void storeData(int volts) {
  if (openFileToWrite(filename)) {
//    char Date[10] = {"YYYYMMDD"};
    char Time[10] = {"hh:mm:ss"};
//    writeToFile(now.toString(Date));
    writeToFile(now.toString(Time));
    writeToFile(String(volts), 1);

//    Serial.print(now.toString(Date));
//    Serial.print(F(","));
    Serial.print(now.toString(Time));
    Serial.print(F(","));
    Serial.println(String(volts));
    closeFile();
  } else {
    Serial.println("Data not saved");
  }
}


void serialDisplayReadings(float volts) {
  if (openFileToWrite(filename)) {
  char Time[10] = {"hh:mm:ss"};
  Serial.print(now.toString(Time));
  Serial.print(F(","));
  Serial.println(String(volts));

  writeToFile(now.toString(Time));
  writeToFile(String(volts), 1);
  closeFile();
  }
}
void takeVoltReadings() {
  float volts = voltReadings();
  int mode = findMode(volts);
  
  if (mode == 0) {
    // display reduce voltage
    serialDisplayReadings(volts);
  } else if (mode == 1) {
    serialDisplayReadings(volts);
  } else {
    // display voltage and percent data
    
    storeData(volts);
  }
}

void getFilename() {
  Serial.println(strlen(rtc.now().toString(filename)));
  if (openFileToWrite(rtc.now().toString(filename))) {
    Serial.println("File successfully created");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT22 example with SD card Module for Data Logging"));
  pinMode(VOLTPIN, INPUT);
  initializeSD();
 
  dht.begin();
  if (! rtc.begin() ) {
    Serial.println("Clock unavailable");
    delay(2000);
    Serial.flush();
    return;
  } else {
    Serial.println("Clock available");
  }
 
 Serial.println("Clock and DHT available");
  
  rtc.adjust(DateTime(2023,5,02,15,04,20));
  initializeFutTime();
 
  getFilename();
  
}


void loop() {
  now = rtc.now();
  if (isValidReadings()) {
    Serial.print("Taking readings: ");
    initializeFutTime();
    takeVoltReadings();
//    takeReadings();
  } else {
    Serial.println("No readings to display");
  }
  
  // Wait a few seconds between measurements.
  delay(3000);

}
