/*
 * Project: IR Sensor Object Detection with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-002
 * Board: ESP8266 NodeMCU
 * Sensor: IR Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define IR_PIN D7

KiwisIoT kiwisiot(ssid, pass, topic);

void sendObjectStatus() {

  int irState = digitalRead(IR_PIN);

  String objectStatus;

  if (irState == LOW) {

    objectStatus = "DETECTED";

  }
  else {

    objectStatus = "NOT DETECTED";
  }

  Serial.println();
  Serial.println("---------- IR MONITORING ----------");

  Serial.print("IR Sensor Value: ");
  Serial.println(irState);

  Serial.print("Object Status: ");
  Serial.println(objectStatus);

  kiwisiot.send("0", objectStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(objectStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     IR OBJECT MONITORING     ");

  pinMode(IR_PIN, INPUT);

  Serial.println("IR sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting object monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendObjectStatus();
  }

  delay(100);
}
