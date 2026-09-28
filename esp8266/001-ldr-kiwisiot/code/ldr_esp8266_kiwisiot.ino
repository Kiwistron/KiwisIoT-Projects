/*
 * Project: LDR Light Sensor Module with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-001
 * Board: ESP8266 NodeMCU
 * Sensor: LDR Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define LDR_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

void sendLightData() {

  int rawValue = analogRead(LDR_PIN);

  int lightLevel = 1023 - rawValue;

  String lightStatus;

  if (lightLevel >= 700) {
    lightStatus = "BRIGHT";
  }
  else if (lightLevel >= 300) {
    lightStatus = "MEDIUM";
  }
  else {
    lightStatus = "DARK";
  }

  Serial.println();
  Serial.println("---------- LIGHT MONITORING ----------");

  Serial.print("Raw LDR Value: ");
  Serial.println(rawValue);

  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  Serial.print("Light Status: ");
  Serial.println(lightStatus);

  kiwisiot.send("0", String(lightLevel));

  kiwisiot.send("1", lightStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(lightLevel);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(lightStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("    LDR LIGHT MONITORING    ");

  pinMode(LDR_PIN, INPUT);

  Serial.println("LDR initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting light monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendLightData();
  }

  delay(100);
}
