/*
 * Project: Soil Moisture Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-007
 * Board: ESP8266 NodeMCU
 * Sensor: Soil Moisture Sensor
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define SOIL_PIN A0

const int DRY_THRESHOLD = 850;

KiwisIoT kiwisiot(ssid, pass, topic);

void sendSoilMoisture() {

  int soilValue = analogRead(SOIL_PIN);

  String soilStatus;

  int statusIndicator;

  if (soilValue > DRY_THRESHOLD) {

    soilStatus = "DRY";
    statusIndicator = 1;

  }
  else {

    soilStatus = "WET";
    statusIndicator = 0;
  }

  Serial.println();
  Serial.println("---------- SOIL MOISTURE MONITORING ----------");

  Serial.print("Soil Moisture Value: ");
  Serial.println(soilValue);

  Serial.print("Soil Status: ");
  Serial.println(soilStatus);

  Serial.print("Status Indicator: ");
  Serial.println(statusIndicator);

  String soilData = String(soilValue);

  kiwisiot.send("0", soilData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(soilData);

  kiwisiot.send("1", soilStatus);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(soilStatus);

  kiwisiot.send("2", String(statusIndicator));

  Serial.print("Sent to KiwisIoT Channel 2: ");
  Serial.println(statusIndicator);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     SOIL MOISTURE MONITORING     ");

  pinMode(SOIL_PIN, INPUT);

  Serial.println("Soil moisture sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting soil moisture monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendSoilMoisture();
  }

  delay(100);
}
