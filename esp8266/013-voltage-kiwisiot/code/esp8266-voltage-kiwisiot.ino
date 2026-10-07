/*
 * Project: Voltage Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-013
 * Board: ESP8266 NodeMCU
 * Sensor: 0-25V DC Voltage Sensor
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define VOLTAGE_SENSOR_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

const float VOLTAGE_DIVIDER_RATIO = 5.0;

const float ADC_REFERENCE_VOLTAGE = 3.3;

void sendVoltage() {

  int sensorValue = analogRead(VOLTAGE_SENSOR_PIN);

  float sensorVoltage =
    sensorValue * (ADC_REFERENCE_VOLTAGE / 1023.0);

  float inputVoltage =
    sensorVoltage * VOLTAGE_DIVIDER_RATIO;

  Serial.println();
  Serial.println("---------- VOLTAGE MONITORING ----------");

  Serial.print("ADC Value: ");
  Serial.println(sensorValue);

  Serial.print("Sensor Output Voltage: ");
  Serial.print(sensorVoltage, 2);
  Serial.println(" V");

  Serial.print("Input Voltage: ");
  Serial.print(inputVoltage, 2);
  Serial.println(" V");

  String voltageData =
    String(inputVoltage, 2);

  kiwisiot.send("0", voltageData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.print(voltageData);
  Serial.println(" V");
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     VOLTAGE MONITORING     ");

  pinMode(VOLTAGE_SENSOR_PIN, INPUT);

  Serial.println("Voltage sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting voltage monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();

    sendVoltage();
  }

  delay(100);
}
