/*
 * Project: Motor Speed Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-029
 * Board: ESP8266 NodeMCU
 * Component: DC Motor with L298N Motor Driver
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define ENA D1
#define IN1 D5
#define IN2 D6

int speedLevel = 0;
int pwmValue = 0;

void stopMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- MOTOR SPEED CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (ch != "0") {
    Serial.println("Unknown channel. Use Channel 0.");
    Serial.println("-----------------------------------------");
    return;
  }

  if (!val.startsWith("speed:")) {
    Serial.println("Invalid command. Use speed:0 to speed:10.");
    Serial.println("-----------------------------------------");
    return;
  }

  String levelText = val.substring(6);

  if (levelText.length() == 0) {
    Serial.println("Invalid speed value.");
    Serial.println("-----------------------------------------");
    return;
  }

  for (unsigned int i = 0; i < levelText.length(); i++) {
    if (!isDigit(levelText[i])) {
      Serial.println("Invalid speed value.");
      Serial.println("-----------------------------------------");
      return;
    }
  }

  int newSpeed = levelText.toInt();

  if (newSpeed < 0 || newSpeed > 10) {
    Serial.println("Speed must be between 0 and 10.");
    Serial.println("-----------------------------------------");
    return;
  }

  speedLevel = newSpeed;

  if (speedLevel == 0) {
    stopMotor();
    pwmValue = 0;
  } else {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    pwmValue = map(speedLevel, 0, 10, 0, 1023);
    analogWrite(ENA, pwmValue);
  }

  Serial.print("Speed Level: ");
  Serial.println(speedLevel);

  Serial.print("PWM Value: ");
  Serial.println(pwmValue);

  Serial.println(
    speedLevel == 0 ? "Motor: STOPPED" : "Motor: RUNNING"
  );

  Serial.println("-----------------------------------------");
}

void setup() {

  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  analogWriteRange(1023);

  stopMotor();

  Serial.println();
  Serial.println("===== ESP8266 MOTOR SPEED CONTROL =====");
  Serial.println("Motor initialized: STOPPED");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT motor control initialized.");
  Serial.println("Channel 0: speed:0 to speed:10");
}

void loop() {
  kiwisiot.run();
}
