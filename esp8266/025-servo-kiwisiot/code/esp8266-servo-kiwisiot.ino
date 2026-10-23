/*
 * Project: Servo Motor Control with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-025
 * Board: ESP8266 NodeMCU
 * Component: SG90 Servo Motor
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Servo.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

#define SERVO_PIN D5

Servo myServo;

int servoAngle = 90;

void onControl(String ch, String val) {

  val.trim();

  Serial.println();
  Serial.println("---------- SERVO CONTROL ----------");
  Serial.print("Channel: ");
  Serial.println(ch);
  Serial.print("Received Value: ");
  Serial.println(val);

  if (ch == "0") {

    if (val.length() == 0) {
      Serial.println("Invalid command. Enter an angle from 0 to 180.");
      return;
    }

    for (unsigned int i = 0; i < val.length(); i++) {
      if (!isDigit(val[i])) {
        Serial.println("Invalid command. Enter an angle from 0 to 180.");
        return;
      }
    }

    int angle = val.toInt();

    if (angle >= 0 && angle <= 180) {

      servoAngle = angle;
      myServo.write(servoAngle);

      Serial.print("Servo Position: ");
      Serial.print(servoAngle);
      Serial.println(" degrees");

    } else {
      Serial.println("Invalid angle. Use a value from 0 to 180.");
    }
  } else {
    Serial.println("Unknown channel. Use Channel 0.");
  }

  Serial.println("-----------------------------------");
}

void setup() {

  Serial.begin(115200);

  myServo.attach(SERVO_PIN);
  myServo.write(servoAngle);

  Serial.println();
  Serial.println("===== ESP8266 SERVO MOTOR =====");
  Serial.println("Servo initialized: 90 degrees");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();
  kiwisiot.onReceive(onControl);

  Serial.println("KiwisIoT servo control initialized.");
  Serial.println("Channel 0: Servo position (0-180 degrees)");
}

void loop() {
  kiwisiot.run();
}
