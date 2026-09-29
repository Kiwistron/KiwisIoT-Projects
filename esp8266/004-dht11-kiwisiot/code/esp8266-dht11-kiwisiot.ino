/*
 * Project: DHT11 Temperature and Humidity Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-004
 * Board: ESP8266 NodeMCU
 * Sensor: DHT11
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define DHT_PIN D5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

KiwisIoT kiwisiot(ssid, pass, topic);

void sendDHTData() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {

    Serial.println();
    Serial.println("Failed to read DHT11!");

    return;
  }

  Serial.println();
  Serial.println("---------- DHT11 MONITORING ----------");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  String temperatureData = String(temperature, 1);

  kiwisiot.send("0", temperatureData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(temperatureData);

  String humidityData = String(humidity, 1);

  kiwisiot.send("1", humidityData);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(humidityData);
}

void setup() {

  Serial.begin(115200);

  Serial.println("     DHT11 MONITORING     ");

  dht.begin();

  Serial.println("DHT11 initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting temperature and humidity monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendDHTData();
  }

  delay(100);
}
