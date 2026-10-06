/*
 * Project: MPU6050 Motion and Acceleration Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-012
 * Board: ESP8266 NodeMCU
 * Sensor: MPU6050 Accelerometer and Gyroscope
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define SDA_PIN D2
#define SCL_PIN D1

Adafruit_MPU6050 mpu;

KiwisIoT kiwisiot(ssid, pass, topic);

const float MOTION_THRESHOLD = 1.5;

void sendMPU6050Data() {

  sensors_event_t acceleration;
  sensors_event_t gyro;
  sensors_event_t temperature;

  mpu.getEvent(&acceleration, &gyro, &temperature);

  float ax = acceleration.acceleration.x;
  float ay = acceleration.acceleration.y;
  float az = acceleration.acceleration.z;

  float totalAcceleration =
    sqrt((ax * ax) + (ay * ay) + (az * az));

  float accelerationChange =
    abs(totalAcceleration - 9.81);

  String motionStatus;

  if (accelerationChange > MOTION_THRESHOLD) {

    motionStatus = "True";

  }
  else {

    motionStatus = "False";
  }

  Serial.println();
  Serial.println("---------- MPU6050 MONITORING ----------");

  Serial.print("Acceleration X: ");
  Serial.print(ax, 2);
  Serial.println(" m/s^2");

  Serial.print("Acceleration Y: ");
  Serial.print(ay, 2);
  Serial.println(" m/s^2");

  Serial.print("Acceleration Z: ");
  Serial.print(az, 2);
  Serial.println(" m/s^2");

  Serial.print("Total Acceleration: ");
  Serial.print(totalAcceleration, 2);
  Serial.println(" m/s^2");

  Serial.print("Motion Status: ");
  Serial.println(motionStatus);

  if (motionStatus == "True") {

    Serial.println("Motion: DETECTED");

  }
  else {

    Serial.println("Motion: NOT DETECTED");
  }

  String accelerationData =
    String(ax, 2) + "," +
    String(ay, 2) + "," +
    String(az, 2);

  kiwisiot.send("0", accelerationData);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(accelerationData);

  kiwisiot.send("1", motionStatus);

  Serial.print("Sent to KiwisIoT Channel 1: ");
  Serial.println(motionStatus);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("     MPU6050 MONITORING     ");

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!mpu.begin()) {

    Serial.println("MPU6050 not found!");

    while (1) {
      delay(1000);
    }
  }

  Serial.println("MPU6050 initialized");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting motion monitoring...");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {

    lastSend = millis();

    sendMPU6050Data();
  }

  delay(100);
}
