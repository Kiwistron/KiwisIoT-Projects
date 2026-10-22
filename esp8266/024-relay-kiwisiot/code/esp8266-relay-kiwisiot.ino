/*
 * Project: 2-Channel Relay Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-024
 * Board: ESP8266 NodeMCU
 * Component: 5V 2-Channel Relay Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define RELAY1_PIN D1
#define RELAY2_PIN D2

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

int relay1State = 0;
int relay2State = 0;

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- RELAY CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (val != "1" && val != "0") {
    Serial.println("Invalid command. Use 1 or 0.");
    return;
  }

  if (ch == "0") {
    relay1State = (val == "1");

    digitalWrite(
      RELAY1_PIN,
      relay1State ? RELAY_ON : RELAY_OFF
    );

    Serial.println(
      relay1State ? "Relay 1: ON" : "Relay 1: OFF"
    );
  }
  else if (ch == "1") {
    relay2State = (val == "1");

    digitalWrite(
      RELAY2_PIN,
      relay2State ? RELAY_ON : RELAY_OFF
    );

    Serial.println(
      relay2State ? "Relay 2: ON" : "Relay 2: OFF"
    );
  }

  Serial.println("-----------------------------------");
}

void setup() {

  Serial.begin(115200);

  digitalWrite(RELAY1_PIN, RELAY_OFF);
  digitalWrite(RELAY2_PIN, RELAY_OFF);

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  Serial.println();
  Serial.println("===== ESP8266 2-CHANNEL RELAY =====");
  Serial.println("Relay 1 initialized: OFF");
  Serial.println("Relay 2 initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT relay control initialized.");
  Serial.println("Channel 0: Relay 1");
  Serial.println("Channel 1: Relay 2");
}

void loop() {
  kiwisiot.run();
}
