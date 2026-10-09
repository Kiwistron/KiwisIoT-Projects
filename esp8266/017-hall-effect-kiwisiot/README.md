# Hall Effect ESP8266 Hall Effect Sensor IoT Project: Monitor Magnetic Events with KiwisIoT 🧲

Build an **ESP8266 Hall Effect sensor IoT project** to detect magnetic events using a **digital Hall Effect sensor module, ESP8266 NodeMCU, Arduino IDE, and KiwisIoT**.

In this project, the ESP8266 reads the digital output from the Hall Effect sensor, identifies whether a magnetic event is detected, and sends the status to a KiwisIoT dashboard over Wi-Fi.

The dashboard displays the **magnetic event status** as `DETECTED` or `NOT DETECTED`, providing a simple example of digital sensor monitoring with IoT.

## 🚀 Project Highlights

* Detect magnetic events using a digital Hall Effect sensor module
* Monitor sensor output using ESP8266 NodeMCU
* Read digital signals through GPIO pin D5
* Display magnetic event status as `DETECTED` or `NOT DETECTED`
* Send sensor status to KiwisIoT using Wi-Fi
* Visualize live status through a KiwisIoT dashboard widget
* Monitor sensor readings through the Arduino Serial Monitor
* Update the dashboard approximately every 2 seconds
* Suitable for learning digital sensing, magnetic detection, and IoT communication

## 🔎 Project Overview

The Hall Effect sensor detects a magnetic field and provides a digital output. The ESP8266 reads this output and determines the magnetic event status based on the configured logic.

When the sensor output is `LOW`, the program reports `DETECTED`. When the output is `HIGH`, it reports `NOT DETECTED`.

The status is then sent to KiwisIoT through Channel 0 and displayed on the dashboard.

| Parameter         | Description                       |
| ----------------- | --------------------------------- |
| Project ID        | KIWISIOT-017                      |
| Microcontroller   | ESP8266 NodeMCU                   |
| Sensor            | Digital Hall Effect sensor module |
| Sensor interface  | Digital output                    |
| Sensor signal pin | D5                                |
| Communication     | Wi-Fi                             |
| IoT platform      | KiwisIoT                          |
| Dashboard channel | Channel 0                         |
| Serial baud rate  | 115200                            |
| Update interval   | Approximately 2 seconds           |
| Output            | DETECTED / NOT DETECTED           |

## 💡 Why This Project?

Magnetic sensing is useful when a system needs to detect the presence or movement of a magnet without physical contact.

Combining a Hall Effect sensor with ESP8266 and KiwisIoT demonstrates how a simple digital sensor can be connected to an IoT dashboard for remote status monitoring.

This project is useful for understanding:

* Digital sensor interfacing with ESP8266
* Magnetic event detection
* GPIO input reading
* Wi-Fi-based IoT communication
* Dashboard-based status visualization

## 📚 What You'll Learn

* How a digital Hall Effect sensor works
* How to connect a Hall Effect sensor module to ESP8266
* How to read digital sensor output using `digitalRead()`
* How to interpret `HIGH` and `LOW` signals
* How to convert sensor readings into readable status messages
* How to send sensor data to KiwisIoT
* How to configure a dashboard widget to display text status
* How to monitor sensor activity using the Serial Monitor

## 🧰 Components Required

| Component                         |    Quantity | Purpose                                                 |
| --------------------------------- | ----------: | ------------------------------------------------------- |
| ESP8266 NodeMCU                   |           1 | Reads sensor output and sends data to the IoT dashboard |
| Digital Hall Effect sensor module |           1 | Detects magnetic fields                                 |
| Jumper wires                      | As required | Connect the sensor to the ESP8266                       |
| USB cable                         |           1 | Powers and programs the ESP8266                         |
| Magnet                            |           1 | Produces the magnetic field used to test the sensor     |

**Note:** The sensor module shown in the circuit is a digital-output Hall Effect module. Its detection behavior depends on the specific sensor and module configuration.

## 💻 Software Requirements

* **Arduino IDE** — to write and upload the program
* **ESP8266 board package** — to compile code for the NodeMCU
* **KiwisIoT Arduino library** — to communicate with the KiwisIoT platform
* **KiwisIoT account and dashboard** — to receive and display sensor status
* **Wi-Fi connection** — to connect the ESP8266 to KiwisIoT

### Common KiwisIoT Setup

If you are new to connecting ESP8266 projects to KiwisIoT, follow the common setup guide first.

[Open the KiwisIoT Arduino Setup Guide](../kiwisiot-arduino-setup/)

The guide covers the common Arduino and KiwisIoT setup required by these ESP8266 projects.

## 🛠️ Technologies Used

* **ESP8266 NodeMCU:** Reads the digital sensor signal and connects to Wi-Fi.
* **Hall Effect sensor:** Detects magnetic fields and provides a digital output.
* **Arduino IDE:** Used to write and upload the program.
* **KiwisIoT:** Receives sensor status and displays it on the dashboard.
* **Wi-Fi:** Enables communication between the ESP8266 and KiwisIoT.

## 🔌 Circuit Connection

Connect the digital Hall Effect sensor module to the ESP8266 NodeMCU according to the circuit diagram.

| Hall Effect Sensor Module | ESP8266 NodeMCU              |
| ------------------------- | ---------------------------- |
| VCC                       | VIN, as shown in the circuit |
| GND                       | GND                          |
| DO                        | D5                           |
| AO                        | Not connected                |

The program uses only the sensor's **digital output (DO)**. The analog output (AO), if present on your module, is not used in this project.

**Important:** Verify the module's permitted supply voltage before connecting VCC. Do not assume every Hall Effect module has the same voltage requirements.

### Circuit Diagram

![ESP8266 Hall Effect sensor circuit diagram](images/circuit.png)

The sensor's digital output connects to D5 on the ESP8266. The ESP8266 reads this signal and sends the resulting magnetic status to KiwisIoT.

## 🔬 How the Hall Effect Sensor Works

A Hall Effect sensor detects a magnetic field using the Hall effect. Depending on the sensor design and module configuration, its digital output changes state when the magnetic field reaches the module's switching threshold.

In this project, the ESP8266 reads the sensor's digital output and converts it into a status message.

| Digital Output | Program Status | Meaning                     |
| -------------- | -------------- | --------------------------- |
| `LOW`          | `DETECTED`     | Magnetic event detected     |
| `HIGH`         | `NOT DETECTED` | Magnetic event not detected |

These mappings follow the logic used in this project's Arduino code. Confirm the behavior of your particular module by testing it with a magnet.

## 🧠 Understanding the Detection Logic

The program uses the `digitalRead()` function to read the sensor output from pin D5.

```cpp
int sensorValue = digitalRead(HALL_SENSOR_PIN);

String magneticStatus;

if (sensorValue == LOW) {
  magneticStatus = "DETECTED";
} else {
  magneticStatus = "NOT DETECTED";
}
```

**How it works:**

1. The ESP8266 reads the digital signal from D5.
2. If the signal is `LOW`, the program sets the status to `DETECTED`.
3. If the signal is `HIGH`, the program sets the status to `NOT DETECTED`.
4. The status is printed in the Serial Monitor.
5. The status is sent to KiwisIoT through Channel 0.

This is digital status detection rather than an analog measurement of magnetic field strength.

## ☁️ KiwisIoT Dashboard

The KiwisIoT dashboard displays the magnetic event status received from the ESP8266.

The project uses **one channel — Channel 0** — to send the status as text.

### Dashboard Output

![KiwisIoT Hall Effect sensor dashboard displaying magnetic status](images/dashboard-output.png)

The dashboard widget displays the current status, such as `DETECTED`, when the sensor output is `LOW`.

When the sensor output becomes `HIGH`, the program sends `NOT DETECTED`.

### How Dashboard Data Is Sent

The following statement sends the magnetic status to KiwisIoT:

```cpp
kiwisiot.send("0", magneticStatus);
```

Here:

* `"0"` is the KiwisIoT channel used by this project.
* `magneticStatus` contains either `DETECTED` or `NOT DETECTED`.

## ⚙️ Dashboard Configuration

Configure your KiwisIoT dashboard to receive data from the same Topic ID used in the Arduino program.

| Setting         | Value                      |
| --------------- | -------------------------- |
| Dashboard name  | Hall Effect Monitoring     |
| Widget title    | MAGNETIC STATUS            |
| Data channel    | Channel 0                  |
| Data type       | Text status                |
| Possible values | `DETECTED`, `NOT DETECTED` |

### Configuration Steps

1. Open your KiwisIoT dashboard.
2. Create or open the Hall Effect Monitoring panel.
3. Add a widget that can display text values.
4. Configure the widget to read Channel 0.
5. Set the widget title to `MAGNETIC STATUS`.
6. Save the dashboard configuration.
7. Use the same Topic ID in the Arduino code.

The dashboard screenshot shows the status `DETECTED` when a magnetic event is detected.

## 💻 Arduino Code

The complete Arduino program for this project is available here:

[View the Arduino Code](code/esp8266-hall-effect-kiwisiot.ino)

The program reads the Hall Effect sensor's digital output, converts it to a status string, prints the result, and sends the status to KiwisIoT.

## 🔐 Configure Wi-Fi and KiwisIoT

Before uploading the program, update the Wi-Fi credentials and dashboard Topic ID.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";
```

Replace the placeholders with your actual Wi-Fi name, Wi-Fi password, and KiwisIoT dashboard Topic ID.

Keep your real Wi-Fi credentials and Topic ID private when publishing your code publicly.

## 📝 Complete Arduino Code

```cpp
/*
 * Project: Hall Effect Sensor Monitoring with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-017
 * Board: ESP8266 NodeMCU
 * Sensor: Digital Hall Effect Sensor Module
 */

#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";

#define HALL_SENSOR_PIN D5

KiwisIoT kiwisiot(ssid, pass, topic);

void sendHallSensorData() {

  int sensorValue = digitalRead(HALL_SENSOR_PIN);

  String magneticStatus;

  if (sensorValue == LOW) {
    magneticStatus = "DETECTED";
  } else {
    magneticStatus = "NOT DETECTED";
  }

  Serial.println();
  Serial.println("---------- HALL EFFECT MONITORING ----------");

  Serial.print("Digital Output: ");
  Serial.println(sensorValue == HIGH ? "HIGH" : "LOW");

  Serial.print("Magnetic Event: ");
  Serial.println(magneticStatus);

  kiwisiot.send("0", magneticStatus);

  Serial.print("Sent to KiwisIoT Channel 0: ");
  Serial.println(magneticStatus);
}

void setup() {
  Serial.begin(115200);

  Serial.println();
  Serial.println("===== HALL EFFECT SENSOR =====");

  pinMode(HALL_SENSOR_PIN, INPUT);

  Serial.println("Hall sensor initialized");
  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
  Serial.println("Starting magnetic event monitoring...");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendHallSensorData();
  }

  delay(100);
}
```

## ⬆️ Upload the Program

1. Connect the ESP8266 NodeMCU to your computer using a USB cable.
2. Open the project in Arduino IDE.
3. Install the ESP8266 board package and KiwisIoT Arduino library if they are not already installed.
4. Select the appropriate ESP8266 NodeMCU board and COM port.
5. Enter your Wi-Fi credentials and KiwisIoT Topic ID.
6. Click **Verify** to compile the program.
7. Click **Upload** to upload it to the ESP8266.
8. Open the Serial Monitor and select **115200 baud**.
9. Bring a magnet near the sensor and observe the output.
10. Open the KiwisIoT dashboard to confirm that the magnetic status updates.

## 🖥️ Serial Monitor Output

The program prints the digital output, magnetic event status, and data sent to KiwisIoT.

![Arduino Serial Monitor showing Hall Effect sensor output](images/serial-monitor.png)

### Example Output

```text
---------- HALL EFFECT MONITORING ----------
Digital Output: LOW
Magnetic Event: DETECTED
[TX] {"0":"DETECTED"}
Sent to KiwisIoT Channel 0: DETECTED

---------- HALL EFFECT MONITORING ----------
Digital Output: HIGH
Magnetic Event: NOT DETECTED
[TX] {"0":"NOT DETECTED"}
Sent to KiwisIoT Channel 0: NOT DETECTED
```

The example above illustrates the two status conditions. The actual Serial Monitor output may include additional library messages depending on the connection and library version.

## 🔄 Understanding the Data Flow

The project follows this sequence:

1. A magnetic field reaches the Hall Effect sensor.
2. The sensor changes its digital output according to its switching behavior.
3. The ESP8266 reads the signal from D5.
4. The program determines the magnetic status.
5. The status is printed in the Serial Monitor.
6. The ESP8266 sends the status to KiwisIoT through Channel 0.
7. The dashboard displays `DETECTED` or `NOT DETECTED`.

The program checks for new data approximately every 2 seconds.

## 🧪 Testing the Project

Use the following procedure to test the system:

1. Power the ESP8266 and Hall Effect sensor module.
2. Confirm that the ESP8266 starts the KiwisIoT initialization sequence.
3. Open the Serial Monitor at 115200 baud.
4. Observe the initial sensor status.
5. Bring a suitable magnet near the sensor.
6. Check whether the digital output changes.
7. Verify that the program reports the appropriate magnetic status.
8. Confirm that Channel 0 updates on the KiwisIoT dashboard.
9. Move the magnet away and observe whether the status returns to `NOT DETECTED`.

**Note:** The detection distance and switching behavior depend on the sensor type, magnet strength, polarity, orientation, and module design.

## 🛠️ Troubleshooting

| Problem                              | Possible Cause                                             | Solution                                                                   |
| ------------------------------------ | ---------------------------------------------------------- | -------------------------------------------------------------------------- |
| Sensor always shows `DETECTED`       | The sensor output remains LOW                              | Check the sensor orientation, magnet position, wiring, and module behavior |
| Sensor always shows `NOT DETECTED`   | The sensor output remains HIGH                             | Test with a suitable magnet and verify the connections                     |
| Status changes unexpectedly          | Magnet movement, electrical noise, or sensor sensitivity   | Secure the wiring and test at different magnet positions                   |
| Dashboard does not update            | Incorrect Topic ID or channel configuration                | Check the Topic ID and confirm that the widget reads Channel 0             |
| ESP8266 does not connect to KiwisIoT | Incorrect Wi-Fi credentials or network issue               | Verify the credentials and Wi-Fi availability                              |
| Program fails to compile             | Missing board package or library                           | Install the ESP8266 board package and KiwisIoT Arduino library             |
| Sensor output is unstable            | Incorrect supply, loose wires, or module-specific behavior | Verify the supply voltage and wiring against the module documentation      |

## 🔒 Security

Follow these practices when publishing or deploying the project:

* Do not publish actual Wi-Fi passwords in public repositories.
* Replace example credentials with your own local settings before uploading.
* Keep your KiwisIoT Topic ID private where appropriate.
* Use a stable power supply and secure sensor connections.
* Test the project before using it in a practical monitoring application.

## 🌱 Possible Applications

This project demonstrates magnetic event detection and can be adapted for applications such as:

* Detecting the presence of a magnet near a machine
* Monitoring magnetic switching events
* Demonstrating contactless sensing in educational projects
* Learning digital sensor monitoring with ESP8266
* Building prototypes for magnetic position or rotation detection
* Integrating magnetic event status into a broader IoT monitoring system

These are possible extensions. The current code reports only a digital magnetic status and does not measure magnetic field strength, rotation speed, or position.

## 📁 Project Structure

```text
017-hall-effect-kiwisiot/
│
├── README.md
│
├── code/
│   └── esp8266-hall-effect-kiwisiot.ino
│
└── images/
    ├── circuit.png
    ├── code.png
    ├── serial-monitor.png
    └── dashboard-output.png
```

Keep the filenames in the `images/` directory consistent with the image references in this README.

## 🔗 Related KiwisIoT ESP8266 Projects

Explore the other ESP8266 sensor projects in this repository:

* [ESP8266 LDR Sensor IoT Project](../001-ldr-kiwisiot/)
* [ESP8266 Sound Sensor IoT Project](../011-sound-sensor-kiwisiot/)
* [ESP8266 MPU6050 Motion Monitoring Project](../012-mpu6050-kiwisiot/)
* [ESP8266 Voltage Sensor IoT Project](../013-voltage-sensor-kiwisiot/)
* [ESP8266 Current Sensor IoT Project](../014-current-kiwisiot/)
* [ESP8266 Vibration Sensor IoT Project](../015-vibration-kiwisiot/)
* [ESP8266 Reed Switch IoT Project](../016-reed-switch-kiwisiot/)

Check the repository for additional ESP8266, sensor monitoring, and KiwisIoT projects.

## ❓ Frequently Asked Questions

### 1. What is a Hall Effect sensor?

A Hall Effect sensor detects the presence of a magnetic field and converts it into an electrical signal.

### 2. Which ESP8266 pin is used in this project?

The digital output of the Hall Effect sensor is connected to **D5** on the ESP8266 NodeMCU.

### 3. Which KiwisIoT channel is used?

This project uses **Channel 0** to send the magnetic status.

### 4. What does `DETECTED` mean?

In this program, `DETECTED` means that the digital sensor output is LOW.

### 5. What does `NOT DETECTED` mean?

In this program, `NOT DETECTED` means that the digital sensor output is HIGH.

### 6. Does this project measure magnetic field strength?

No. The current implementation reads the digital output and reports a status. It does not measure magnetic field strength.

### 7. How often is the status sent to KiwisIoT?

The program sends the status approximately every **2 seconds**.

### 8. Can this project be used for rotation monitoring?

It can serve as a starting point for a rotation-detection prototype using a magnet and suitable Hall sensor. Measuring rotation speed would require additional pulse counting and timing logic, which are not included in this code.

## 📌 Summary

This **ESP8266 Hall Effect Sensor IoT Project with KiwisIoT** demonstrates how to detect magnetic events, read digital sensor output, and send status updates to an IoT dashboard.

Using ESP8266 NodeMCU, a digital Hall Effect sensor module, Arduino IDE, and KiwisIoT, the project provides a practical introduction to contactless magnetic sensing and IoT-based status monitoring.

The same approach can be extended to more advanced sensor projects that combine multiple inputs and dashboard-based monitoring.

## 📄 License

This project is distributed under the license included in this repository. See the [LICENSE](LICENSE) file for details.
