/*
 * Project: Water Pump Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-027
 * Board: ESP8266 NodeMCU
 * Component: 12V DC Water Pump with Relay Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define PUMP_RELAY_PIN D1

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

int pumpState = 0;

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- WATER PUMP CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (val != "1" && val != "0") {
    Serial.println("Invalid command. Use 1 or 0.");
    Serial.println("----------------------------------------");
    return;
  }

  if (ch == "0") {

    pumpState = (val == "1");

    digitalWrite(
      PUMP_RELAY_PIN,
      pumpState ? RELAY_ON : RELAY_OFF
    );

    Serial.println(
      pumpState ? "Water Pump: ON" : "Water Pump: OFF"
    );

  } else {
    Serial.println("Unknown channel. Use Channel 0.");
  }

  Serial.println("----------------------------------------");
}

void setup() {

  Serial.begin(115200);

  digitalWrite(PUMP_RELAY_PIN, RELAY_OFF);
  pinMode(PUMP_RELAY_PIN, OUTPUT);

  Serial.println();
  Serial.println("===== ESP8266 WATER PUMP CONTROL =====");
  Serial.println("Water pump initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT water pump control initialized.");
  Serial.println("Channel 0: Water Pump ON/OFF");
}

void loop() {
  kiwisiot.run();
}
