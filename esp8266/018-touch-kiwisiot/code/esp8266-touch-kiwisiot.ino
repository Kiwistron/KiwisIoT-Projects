/*
 * Project: Touch Sensor Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-018
 * Board: ESP8266 NodeMCU
 * Sensor: Capacitive Touch Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define TOUCH_SENSOR_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendTouchSensorData() {

  int sensorValue = digitalRead(TOUCH_SENSOR_PIN);

  String touchStatus;

  if (sensorValue == HIGH) {
    touchStatus = "TOUCHED";
  } else {
    touchStatus = "NOT TOUCHED";
  }

  Serial.println();
  Serial.println("---------- TOUCH SENSOR MONITORING ----------");

  Serial.print("Digital Output: ");
  Serial.println(sensorValue == HIGH ? "HIGH" : "LOW");

  Serial.print("Touch Status: ");
  Serial.println(touchStatus);

  kiwisiot.send("0", touchStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(touchStatus);
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== TOUCH SENSOR MONITORING =====");

  pinMode(TOUCH_SENSOR_PIN, INPUT);

  Serial.println("Touch sensor initialized");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting touch detection...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendTouchSensorData();
  }

  delay(100);
}
