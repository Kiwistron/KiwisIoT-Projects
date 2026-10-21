/*
 * Project: RGB LED Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-022
 * Board: ESP8266 NodeMCU
 * Component: RGB LED
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define RED_PIN   D1
#define GREEN_PIN D2
#define BLUE_PIN  D5

void onControl(String ch, String val) {

  if (ch != "1") return;

  val.trim();
  val.toUpperCase();

  Serial.println();
  Serial.println("---------- RGB LED CONTROL ----------");
  Serial.print("Received Command: ");
  Serial.println(val);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  if (val == "R") {
    digitalWrite(RED_PIN, HIGH);
    Serial.println("RGB LED Status: RED");
  }
  else if (val == "G") {
    digitalWrite(GREEN_PIN, HIGH);
    Serial.println("RGB LED Status: GREEN");
  }
  else if (val == "B") {
    digitalWrite(BLUE_PIN, HIGH);
    Serial.println("RGB LED Status: BLUE");
  }
  else if (val == "OFF") {
    Serial.println("RGB LED Status: ALL COLORS OFF");
  }
  else {
    Serial.println("Invalid input!");
    Serial.println("Enter R, G, B or OFF.");
  }

  Serial.println("-------------------------------------");
}

void setup() {

  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  Serial.println();
  Serial.println("===== ESP8266 RGB LED CONTROL =====");
  Serial.println("RGB LED initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT control initialized.");
  Serial.println("Input R = Red");
  Serial.println("Input G = Green");
  Serial.println("Input B = Blue");
  Serial.println("Input OFF = Turn all colors OFF");
}

void loop() {
  kiwisiot.run();
}
