/*
 * Project: Sound Level Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-011
 * Board: ESP8266 NodeMCU
 * Sensor: Sound Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define SOUND_SENSOR_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

void sendSoundLevel() {

  int soundValue = analogRead(SOUND_SENSOR_PIN);

  Serial.println();
  Serial.println("---------- SOUND MONITORING ----------");

  Serial.print("Sound Sensor Value: ");
  Serial.println(soundValue);

  String soundData = String(soundValue);

  kiwisiot.send("0", soundData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(soundData);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     SOUND MONITORING     ");

  pinMode(SOUND_SENSOR_PIN, INPUT);

  Serial.println("Sound sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting sound monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendSoundLevel();
  }

  delay(100);
}
