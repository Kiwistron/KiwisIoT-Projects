/*
 * Project: BMP180 Temperature and Air Pressure Monitoring
 * Project ID: KIWISIOT-019
 * Board: ESP8266 NodeMCU
 * Sensor: BMP180
 */

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);
Adafruit_BMP085 bmp;

void sendBMP180Data() {

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0; 

  Serial.println();
  Serial.println("---------- BMP180 MONITORING ----------");

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  Serial.print("Air Pressure: ");
  Serial.print(pressure, 2);
  Serial.println(" hPa");

  String temperatureData = String(temperature, 2);
  String pressureData = String(pressure, 2);

  kiwisiot.send("0", temperatureData);
  kiwisiot.send("1", pressureData);

  Serial.print("Sent to KiwisIoT Channel 0 (Temperature): ");
  Serial.println(temperatureData);

  Serial.print("Sent to KiwisIoT Channel 1 (Pressure): ");
  Serial.println(pressureData);
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== BMP180 SENSOR MONITORING =====");

  Wire.begin(D2, D1); 

  if (!bmp.begin()) {
    Serial.println("ERROR: BMP180 sensor not detected!");
    Serial.println("Check VCC, GND, SDA and SCL connections.");

    while (true) {
      delay(1000);
    }
  }

  Serial.println("BMP180 initialized successfully.");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized.");
  Serial.println("Starting temperature and pressure monitoring...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendBMP180Data();
  }

  delay(100);
}
