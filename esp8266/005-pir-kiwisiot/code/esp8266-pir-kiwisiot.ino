/*
 * Project: PIR Motion Detection with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-005
 * Board: ESP8266 NodeMCU
 * Sensor: PIR Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define PIR_PIN D7

KiwisIoT kiwisiot(ssid, pass, topic);

void sendMotionStatus() {

  int pirState = digitalRead(PIR_PIN);

  String motionStatus;

  if (pirState == HIGH) {

    motionStatus = "True";

  }
  else {

    motionStatus = "False";
  }

  Serial.println();
  Serial.println("---------- PIR MONITORING ----------");

  Serial.print("PIR Sensor Value: ");
  Serial.println(pirState);

  Serial.print("Motion Status: ");
  Serial.println(motionStatus);

  if (pirState == HIGH) {

    Serial.println("Motion: DETECTED");

  }
  else {

    Serial.println("Motion: NOT DETECTED");
  }

  kiwisiot.send("0", motionStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(motionStatus);
}

void setup() {

  Serial.begin(115200);
  Serial.println("     PIR MOTION MONITORING    ");

  pinMode(PIR_PIN, INPUT);

  Serial.println("PIR sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting motion monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendMotionStatus();
  }

  delay(100);
}
