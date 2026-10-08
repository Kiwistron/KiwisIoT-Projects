/*
 * Project: Vibration Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-015
 * Board: ESP8266 NodeMCU
 * Sensor: SW-420 Vibration Sensor
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define VIBRATION_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendVibrationData() {

  int vibrationValue =
    digitalRead(VIBRATION_PIN);

  String vibrationStatus;

  if (vibrationValue == HIGH) {

    vibrationStatus = "True";
  }
  else {

    vibrationStatus = "False";
  }

  Serial.println();
  Serial.println("---------- VIBRATION MONITORING ----------");

  Serial.print("Vibration Status: ");
  Serial.println(vibrationStatus);

  if (vibrationStatus == "True") {

    Serial.println("Vibration: DETECTED");
  }
  else {

    Serial.println("Vibration: NOT DETECTED");
  }

  kiwisiot.send("0", vibrationStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(vibrationStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     VIBRATION MONITORING     ");

  pinMode(VIBRATION_PIN, INPUT);

  Serial.println("SW-420 vibration sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting vibration monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendVibrationData();
  }

  delay(100);
}
