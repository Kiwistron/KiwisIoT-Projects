/*
 * Project: Rainfall Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-010
 * Board: ESP8266 NodeMCU
 * Sensor: Raindrop Sensor Module
 */
 
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define RAIN_SENSOR_PIN A0

const int RAIN_THRESHOLD = 700;

KiwisIoT kiwisiot(ssid, pass, topic);

void sendRainStatus() {

  int rainValue = analogRead(RAIN_SENSOR_PIN);

  String rainStatus;

  int statusIndicator;

  if (rainValue < RAIN_THRESHOLD) {

    rainStatus = "RAIN";
    statusIndicator = 1;

  }
  else {

    rainStatus = "NO RAIN";
    statusIndicator = 0;
  }

  Serial.println();
  Serial.println("---------- RAIN MONITORING ----------");

  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  Serial.print("Rain Status: ");
  Serial.println(rainStatus);

  Serial.print("Status Indicator: ");
  Serial.println(statusIndicator);

  String rainData = String(rainValue);

  kiwisiot.send("0", rainData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(rainData);

  kiwisiot.send("1", rainStatus);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(rainStatus);

  kiwisiot.send("2", String(statusIndicator));

  Serial.print("Sent to KiwisIoT Channel 2: ");
  Serial.println(statusIndicator);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     RAIN MONITORING     ");

  pinMode(RAIN_SENSOR_PIN, INPUT);

  Serial.println("Rain sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting rain monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendRainStatus();
  }

  delay(100);
}
