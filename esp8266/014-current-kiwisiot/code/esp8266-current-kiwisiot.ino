/*
 * Project: Current and Power Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-014
 * Board: ESP8266 NodeMCU
 * Sensor: ACS712-30A Current Sensor
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define CURRENT_SENSOR_PIN A0

KiwisIoT kiwisiot(ssid, pass, topic);

const float ACS712_SENSITIVITY = 0.066;
const float ADC_REFERENCE_VOLTAGE = 3.3;
const float SUPPLY_VOLTAGE = 3.7;

const int ZERO_SAMPLES = 500;

float zeroVoltage = 0.0;

void calibrateZeroCurrent() {

  float totalVoltage = 0.0;

  Serial.println();
  Serial.println("Calibrating ACS712 zero current...");
  Serial.println("Make sure NO current is flowing.");

  for (int i = 0; i < ZERO_SAMPLES; i++) {

    int sensorValue = analogRead(CURRENT_SENSOR_PIN);

    float sensorVoltage =
      sensorValue * (ADC_REFERENCE_VOLTAGE / 1023.0);

    totalVoltage += sensorVoltage;

    delay(2);
  }

  zeroVoltage = totalVoltage / ZERO_SAMPLES;

  Serial.print("Zero Current Voltage: ");
  Serial.print(zeroVoltage, 3);
  Serial.println(" V");

  Serial.println("Calibration complete");
}

void sendCurrentData() {

  long totalADC = 0;

  for (int i = 0; i < 20; i++) {

    totalADC += analogRead(CURRENT_SENSOR_PIN);

    delay(2);
  }

  float averageADC =
    (float)totalADC / 20.0;

  float sensorVoltage =
    averageADC * (ADC_REFERENCE_VOLTAGE / 1023.0);

  float current =
    (sensorVoltage - zeroVoltage) /
    ACS712_SENSITIVITY;

  if (abs(current) < 0.05) {

    current = 0.0;
  }

  float power =
    SUPPLY_VOLTAGE * abs(current);

  Serial.println();
  Serial.println("---------- CURRENT MONITORING ----------");

  Serial.print("Sensor Voltage: ");
  Serial.print(sensorVoltage, 3);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(abs(current), 2);
  Serial.println(" A");

  Serial.print("Battery Voltage: ");
  Serial.print(SUPPLY_VOLTAGE, 2);
  Serial.println(" V");

  Serial.print("Power: ");
  Serial.print(power, 2);
  Serial.println(" W");

  String currentData =
    String(abs(current), 2);

  kiwisiot.send("0", currentData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.print(currentData);
  Serial.println(" A");

  String powerData =
    String(power, 2);

  kiwisiot.send("1", powerData);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.print(powerData);
  Serial.println(" W");
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     CURRENT MONITORING     ");

  pinMode(CURRENT_SENSOR_PIN, INPUT);

  Serial.println("ACS712-30A initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");

  calibrateZeroCurrent();

  Serial.println("Starting current monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendCurrentData();
  }

  delay(100);
}
