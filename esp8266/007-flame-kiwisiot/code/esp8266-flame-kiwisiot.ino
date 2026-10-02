/*
 * Project: Flame Detection with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-007
 * Board: ESP8266 NodeMCU
 * Sensor: Flame Sensor Module
 */
 
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define FLAME_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendFlameStatus() {

  int flameState = digitalRead(FLAME_PIN);

  String flameStatus;

  int ledStatus;

  if (flameState == LOW) {

    flameStatus = "True";
    ledStatus = 1;

  }

  else {

    flameStatus = "False";
    ledStatus = 0;

  }

  Serial.println();
  Serial.println("---------- FLAME MONITORING ----------");

  Serial.print("Flame Sensor Value: ");
  Serial.println(flameState);

  Serial.print("Flame Status: ");
  Serial.println(flameStatus);

  Serial.print("LED Status: ");
  Serial.println(ledStatus);

  if (flameState == LOW) {

    Serial.println("Flame: DETECTED");

  }

  else {

    Serial.println("Flame: NOT DETECTED");
  }

  kiwisiot.send("0", flameStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(flameStatus);

  kiwisiot.send("1", String(ledStatus));

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(ledStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println("     FLAME MONITORING     ");

  pinMode(FLAME_PIN, INPUT);

  Serial.println("Flame sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");

  Serial.println("Starting flame monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendFlameStatus();
  }

  delay(100);
}
