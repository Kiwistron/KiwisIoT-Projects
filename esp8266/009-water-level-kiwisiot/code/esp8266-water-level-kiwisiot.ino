/*
 * Project: Water Level Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-009
 * Board: ESP8266 NodeMCU
 * Sensor: Water Level Sensor
 */
 
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define WATER_SENSOR_PIN A0

const int HIGH_THRESHOLD = 500;

KiwisIoT kiwisiot(ssid, pass, topic);

void sendWaterLevel() {

  int waterValue = analogRead(WATER_SENSOR_PIN);

  String waterStatus;

  if (waterValue >= HIGH_THRESHOLD) {

    waterStatus = "HIGH";

  }
  else {

    waterStatus = "LOW";
  }

  Serial.println();
  Serial.println("---------- WATER LEVEL MONITORING ----------");

  Serial.print("Water Level Value: ");
  Serial.println(waterValue);

  Serial.print("Water Level Status: ");
  Serial.println(waterStatus);

  String waterData = String(waterValue);

  kiwisiot.send("0", waterData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(waterData);

  kiwisiot.send("1", waterStatus);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(waterStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     WATER LEVEL MONITORING     ");

  pinMode(WATER_SENSOR_PIN, INPUT);

  Serial.println("Water level sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting water level monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendWaterLevel();
  }

  delay(100);
}
