/*
 * Project: Fan Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-026
 * Board: ESP8266 NodeMCU
 * Component: 12V DC Fan with Relay Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define FAN_RELAY_PIN D1

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

int fanState = 0;

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- FAN CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (ch == "0") {

    if (val != "1" && val != "0") {
      Serial.println("Invalid command. Use 1 or 0.");
      return;
    }

    fanState = (val == "1");

    digitalWrite(
      FAN_RELAY_PIN,
      fanState ? RELAY_ON : RELAY_OFF
    );

    Serial.println(fanState ? "Fan: ON" : "Fan: OFF");

  } else {
    Serial.println("Unknown channel. Use Channel 0.");
  }

  Serial.println("---------------------------------");
}

void setup() {

  Serial.begin(115200);

  digitalWrite(FAN_RELAY_PIN, RELAY_OFF);
  pinMode(FAN_RELAY_PIN, OUTPUT);

  Serial.println();
  Serial.println("===== ESP8266 DC FAN CONTROL =====");
  Serial.println("Fan initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT fan control initialized.");
  Serial.println("Channel 0: Fan ON/OFF");
}

void loop() {
  kiwisiot.run();
}
