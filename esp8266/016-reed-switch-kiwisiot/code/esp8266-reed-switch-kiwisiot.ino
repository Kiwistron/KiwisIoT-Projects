/*
 * Project: Door and Window Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-016
 * Board: ESP8266 NodeMCU
 * Sensor: Magnetic Reed Switch Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define REED_SWITCH_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendReedSwitchData() {

  int switchValue = digitalRead(REED_SWITCH_PIN);

  String doorStatus;

  if (switchValue == LOW) {
    doorStatus = "CLOSED";
  } else {
    doorStatus = "OPEN";
  }

  Serial.println();
  Serial.println("---------- DOOR / WINDOW MONITORING ----------");

  Serial.print("Digital Output: ");
  Serial.println(switchValue == HIGH ? "HIGH" : "LOW");

  Serial.print("Door / Window Status: ");
  Serial.println(doorStatus);

  kiwisiot.send("0", doorStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(doorStatus);
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== REED SWITCH MONITORING =====");

  pinMode(REED_SWITCH_PIN, INPUT);

  Serial.println("Reed switch module initialized");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting door / window monitoring...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendReedSwitchData();
  }

  delay(100);
}
