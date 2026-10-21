/*
 * Project: Buzzer Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-023
 * Board: ESP8266 NodeMCU
 * Component: 3-5V Buzzer
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define BUZZER_PIN D1

int buzzerState = 0;

void onControl(String ch, String val) {

  if (ch != "1") return;

  val.trim();
  val.toLowerCase();

  Serial.println();
  Serial.println("---------- BUZZER CONTROL ----------");
  Serial.print("Received Command: ");
  Serial.println(val);

  if (val == "turn on" || val == "on") {
    buzzerState = 1;
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Buzzer Status: ON");
  }
  else if (val == "turn off" || val == "off") {
    buzzerState = 0;
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Buzzer Status: OFF");
  }
  else {
    Serial.println("Invalid command!");
    Serial.println("Say: Turn on or Turn off");
  }

  Serial.println("------------------------------------");
}

void setup() {

  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println();
  Serial.println("===== ESP8266 BUZZER IOT CONTROL =====");
  Serial.println("Buzzer initialized: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT voice control initialized.");
  Serial.println("Channel ID: 1");
  Serial.println("Say 'Turn on' to activate the buzzer.");
  Serial.println("Say 'Turn off' to stop the buzzer.");
}

void loop() {
  kiwisiot.run();
}
