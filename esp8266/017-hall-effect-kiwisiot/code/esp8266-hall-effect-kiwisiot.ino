/*
 * Project: Hall Effect Sensor Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-017
 * Board: ESP8266 NodeMCU
 * Sensor: Digital Hall Effect Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define HALL_SENSOR_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendHallSensorData() {

  int sensorValue = digitalRead(HALL_SENSOR_PIN);

  String magneticStatus;

  if (sensorValue == LOW) {
    magneticStatus = "DETECTED";
  } else {
    magneticStatus = "NOT DETECTED";
  }

  Serial.println();
  Serial.println("---------- HALL EFFECT MONITORING ----------");

  Serial.print("Digital Output: ");
  Serial.println(sensorValue == HIGH ? "HIGH" : "LOW");

  Serial.print("Magnetic Event: ");
  Serial.println(magneticStatus);

  kiwisiot.send("0", magneticStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(magneticStatus);
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== HALL EFFECT SENSOR =====");

  pinMode(HALL_SENSOR_PIN, INPUT);

  Serial.println("Hall sensor initialized");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting magnetic event monitoring...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendHallSensorData();
  }

  delay(100);
}
