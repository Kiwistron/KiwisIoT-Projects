/*
 * Project: Solenoid Valve Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-028
 * Board: ESP8266 NodeMCU
 * Component: 12V DC Solenoid Valve with Relay Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define VALVE_RELAY_PIN D1

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

int valveState = 0;

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- SOLENOID VALVE CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (val != "1" && val != "0") {
    Serial.println("Invalid command. Use 1 or 0.");
    Serial.println("--------------------------------------------");
    return;
  }

  if (ch == "0") {

    valveState = (val == "1");

    digitalWrite(
      VALVE_RELAY_PIN,
      valveState ? RELAY_ON : RELAY_OFF
    );

    Serial.println(
      valveState ? "Solenoid Valve: OPEN" : "Solenoid Valve: CLOSED"
    );

  } else {
    Serial.println("Unknown channel. Use Channel 0.");
  }

  Serial.println("--------------------------------------------");
}

void setup() {

  Serial.begin(115200);

  digitalWrite(VALVE_RELAY_PIN, RELAY_OFF);
  pinMode(VALVE_RELAY_PIN, OUTPUT);

  Serial.println();
  Serial.println("===== ESP8266 SOLENOID VALVE CONTROL =====");
  Serial.println("Solenoid valve initialized: CLOSED");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT valve control initialized.");
  Serial.println("Channel 0: Solenoid Valve OPEN/CLOSE");
}

void loop() {
  kiwisiot.run();
}
