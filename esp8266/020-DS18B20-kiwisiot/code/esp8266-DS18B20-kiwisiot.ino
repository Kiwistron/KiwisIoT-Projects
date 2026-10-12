/*
 * Project: DS18B20 Temperature Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-020
 * Board: ESP8266 NodeMCU
 * Sensor: Waterproof DS18B20 Temperature Sensor
 */

#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define DS18B20_PIN D5

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

KiwisIoT kiwisiot(ssid, pass, topic);

void sendTemperatureData() {

  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  Serial.println();
  Serial.println("---------- DS18B20 TEMPERATURE MONITORING ----------");

  if (temperature == DEVICE_DISCONNECTED_C ||
      temperature < -55.0 || temperature > 125.0) {
    Serial.println("ERROR: DS18B20 sensor not detected!");
    Serial.println("Check DATA wiring and the 4.7k ohm resistor.");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  String temperatureData = String(temperature, 2);

  kiwisiot.send("0", temperatureData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.print(temperatureData);
  Serial.println(" °C");
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== DS18B20 TEMPERATURE MONITORING =====");

  sensors.begin();

  Serial.println("DS18B20 sensor initialized.");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized.");
  Serial.println("Starting temperature monitoring...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2500) {
    lastSend = millis();
    sendTemperatureData();
  }

  delay(100);
}
