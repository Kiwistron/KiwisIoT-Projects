/*
 * Project: LED Remote Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-021
 * Board: ESP8266 NodeMCU
 * Component: LED
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define LED_PIN D1

int ledState = 0;  

void onControl(String ch, String val) {

  if (ch != "0") return;

  Serial.println();
  Serial.println("---------- LED CONTROL ----------");
  Serial.print("Received Value: ");
  Serial.println(val);

  if (val == "1") {
    ledState = 1;
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED Status: ON");
  }

  else if (val == "0") {
    ledState = 0;
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED Status: OFF");
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println();
  Serial.println("===== ESP8266 LED IOT CONTROL =====");
  Serial.println("LED initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT control initialized.");
  Serial.println("Use the dashboard Toggle widget to control the LED.");
}

void loop() {
  kiwisiot.run();
}
