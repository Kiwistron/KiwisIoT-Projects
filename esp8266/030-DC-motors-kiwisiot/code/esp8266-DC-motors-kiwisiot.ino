/*
 * Project: DC Motor Direction Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-030
 * Board: ESP8266 NodeMCU
 * Component: Two DC Motors with L298N Motor Driver
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define IN1 D1
#define IN2 D2
#define IN3 D5
#define IN4 D6

int powerState = 0;

void motorForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Moving Forward");
}

void motorReverse() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Moving Backward");
}

void motorRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Turning Right");
}

void motorLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Turning Left");
}

void motorStop() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("Motors Stopped");
}

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- MOTOR CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (ch != "0") {
    Serial.println("Unknown channel. Use Channel 0.");
    Serial.println("-----------------------------------");
    return;
  }

  if (val == "power:1") {
    powerState = 1;
    Serial.println("Power ON");
    Serial.println("-----------------------------------");
    return;
  }

  if (val == "power:0") {
    powerState = 0;
    motorStop();
    Serial.println("Power OFF");
    Serial.println("-----------------------------------");
    return;
  }

  if (powerState == 0) {
    Serial.println("Motor power is OFF. Turn power ON first.");
    Serial.println("-----------------------------------");
    return;
  }

  if (val == "forward") {
    motorForward();
  }
  else if (val == "back") {
    motorReverse();
  }
  else if (val == "right") {
    motorRight();
  }
  else if (val == "left") {
    motorLeft();
  }
  else if (val == "stop") {
    motorStop();
  }
  else {
    Serial.println("Invalid command.");
  }

  Serial.println("-----------------------------------");
}

void setup() {

  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  motorStop();

  Serial.println();
  Serial.println("===== ESP8266 DC MOTOR CONTROL =====");
  Serial.println("Motor initialized: STOPPED");
  Serial.println("Power State: OFF");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT motor control initialized.");
  Serial.println("Channel 0: Motor Direction Control");
}

void loop() {
  kiwisiot.run();
}
