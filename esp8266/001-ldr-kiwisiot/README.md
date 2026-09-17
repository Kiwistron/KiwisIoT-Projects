# LDR Light Sensor Module with ESP8266 and KiwisIoT

> **Project ID:** KIWISIOT-001
> **Category:** IoT / Sensors / Light Monitoring
> **Difficulty:** Beginner
> **Microcontroller:** ESP8266 NodeMCU
> **Sensor:** LDR Light Sensor Module
> **IoT Platform:** KiwisIoT
> **Programming:** Arduino C/C++
> **Communication:** Wi-Fi

An IoT-based **light monitoring project using an LDR sensor module, ESP8266, and KiwisIoT**. The ESP8266 reads the light-level signal from the LDR sensor module and sends the sensor data through Wi-Fi to KiwisIoT for real-time monitoring and visualization.

This project is suitable for **students, beginners, educators, makers, embedded developers, and IoT learners**.

---

## 📌 Project Overview

An **LDR (Light Dependent Resistor) sensor module** is an electronic sensor module that detects changes in surrounding light intensity.

The module typically provides:

* **AO (Analog Output)** — provides a variable analog signal related to the detected light level.
* **DO (Digital Output)** — provides a digital HIGH/LOW signal based on the adjustable threshold.
* **VCC** — power supply.
* **GND** — ground.

In this project, the **analog output (AO)** of the LDR sensor module is connected to the ESP8266 analog input.

The ESP8266 reads the sensor value and sends the data to KiwisIoT through Wi-Fi.

### System Flow

```text
       Light
         ↓
   LDR Sensor Module
         ↓
        AO
         ↓
      ESP8266
         ↓
       Wi-Fi
         ↓
     KiwisIoT
         ↓
   IoT Dashboard
         ↓
  Light Monitoring
```

---

# 🎯 What You Will Learn

By completing this project, you will learn:

* What an LDR sensor module is
* How an LDR sensor module detects light
* Difference between AO and DO
* How to connect an LDR module to ESP8266
* How to read analog sensor data
* How to program ESP8266 using Arduino IDE
* How to connect ESP8266 to Wi-Fi
* How to send sensor data to KiwisIoT
* How to create an IoT sensor dashboard
* How a sensor-to-cloud IoT system works

---

# ⭐ Key Features

* LDR sensor module based light detection
* Analog light-level monitoring
* ESP8266 Wi-Fi connectivity
* KiwisIoT integration
* Real-time IoT dashboard
* Arduino IDE compatible
* Beginner-friendly
* Low-cost IoT experiment
* Suitable for STEM and IoT education

---

# 🧰 Components Required

| Component         |    Quantity | Purpose                                |
| ----------------- | ----------: | -------------------------------------- |
| ESP8266 NodeMCU   |           1 | Microcontroller and Wi-Fi connectivity |
| LDR Sensor Module |           1 | Detects light intensity                |
| Breadboard        |           1 | Prototyping                            |
| Jumper Wires      | As required | Electrical connections                 |
| USB Cable         |           1 | Programming and power                  |
| Computer          |           1 | Arduino IDE programming                |
| Wi-Fi Network     |           1 | Internet connectivity                  |

---

# 🔌 Circuit Connection

The LDR sensor module is connected directly to the ESP8266.

## LDR Sensor Module → ESP8266

| LDR Module Pin | ESP8266 Pin   | Function                   |
| -------------- | ------------- | -------------------------- |
| VCC            | 3.3V          | Power                      |
| GND            | GND           | Ground                     |
| AO             | A0            | Analog light-level reading |
| DO             | Optional GPIO | Digital threshold output   |

### Recommended connection for this project

For KiwisIoT continuous light monitoring, use:

```text
LDR Module AO → ESP8266 A0
```

The **DO pin is optional** and is not required when using the analog light-level value.

> **Note:** LDR module pin labels and supply-voltage requirements can vary between module versions. Verify the labels printed on your specific module before powering it.

---

# 📐 Circuit Diagram

Place your actual circuit diagram in:

```text
circuit/circuit-diagram.png
```

Then display it in the README:

```markdown
![LDR sensor module connection with ESP8266](circuit/circuit-diagram.png)
```

Recommended diagram:

```text
       LDR SENSOR MODULE
       ┌───────────────┐
 VCC ──┤ VCC           │
 GND ──┤ GND           │
 AO  ──┤ AO            │
 DO  ──┤ DO            │
       └───────────────┘
          │
          │ AO
          ▼
       ESP8266
          │
          │ Wi-Fi
          ▼
       KiwisIoT
```

---

# ⚙️ How the LDR Sensor Module Works

The LDR inside the sensor module changes its electrical characteristics according to the amount of light falling on it.

The sensor module processes this change and provides an output signal.

### Analog Output — AO

The **AO pin** provides a variable analog signal.

This signal can be read by the ESP8266 analog input.

```text
Light Level
     ↓
LDR Sensor
     ↓
Analog Signal
     ↓
AO
     ↓
ESP8266 A0
     ↓
Sensor Value
     ↓
KiwisIoT
```

### Digital Output — DO

The **DO pin** can be used as a threshold-based digital output.

The onboard potentiometer can generally be adjusted to change the switching threshold.

```text
Light Level
     ↓
LDR Module
     ↓
Threshold Comparison
     ↓
DO
     ↓
HIGH / LOW
```

For this project, **AO is used because KiwisIoT can display the changing sensor value rather than only a HIGH/LOW state**.

---

# 🌐 IoT Data Flow

The complete system works as follows:

```text
LDR Sensor Module
       ↓
      AO
       ↓
ESP8266 Analog Input
       ↓
   Data Reading
       ↓
     Wi-Fi
       ↓
   KiwisIoT
       ↓
 Sensor Channel
       ↓
   Dashboard
```

---

# 💻 Software Requirements

Install:

* Arduino IDE
* ESP8266 board package
* KiwisIoT Arduino library
* Required ESP8266 libraries
* USB driver if required by your board
* Internet-connected Wi-Fi

---

# 🛠️ Installation and Setup

## Step 1 — Install Arduino IDE

Install Arduino IDE on your computer.

Open Arduino IDE after installation.

Add your screenshot:

```markdown
![Arduino IDE installation for ESP8266 IoT project](images/01-arduino-ide-installation.png)
```

---

## Step 2 — Install ESP8266 Board Support

Open:

```text
Arduino IDE
    ↓
File
    ↓
Preferences
```

Add the ESP8266 Board Manager URL.

Then open:

```text
Tools
    ↓
Board
    ↓
Boards Manager
```

Search for:

```text
ESP8266
```

Install the ESP8266 board package.

Screenshot:

```markdown
![ESP8266 board installation in Arduino IDE](images/02-esp8266-board-installation.png)
```

---

# 📡 Step 3 — Connect the LDR Sensor Module

Connect the module:

```text
LDR Module VCC → ESP8266 3.3V
LDR Module GND → ESP8266 GND
LDR Module AO  → ESP8266 A0
```

The DO connection is optional.

Add your actual hardware photograph:

```markdown
![LDR sensor module connected to ESP8266 NodeMCU](images/03-hardware-connection.jpg)
```

---

# 🌐 Step 4 — Configure KiwisIoT

Open your KiwisIoT account and create a new project.

Create a sensor/channel for the LDR value.

Recommended naming:

```text
Project:
LDR Light Monitoring

Sensor:
LDR

Data Field:
ldr_value
```

Add your actual KiwisIoT configuration screenshot:

```markdown
![KiwisIoT LDR sensor project configuration](images/04-kiwisiot-setup.png)
```

---

# 🔑 Step 5 — Configure Wi-Fi

Open:

```text
code/ldr_esp8266_kiwisiot.ino
```

Configure your Wi-Fi credentials.

Example:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

**Never publish your real Wi-Fi password, API key, device token, or private credentials on GitHub.**

Use placeholders in public source code.

---

# 📝 Arduino Code

The complete tested source code should be stored here:

```text
code/
└── ldr_esp8266_kiwisiot.ino
```

Basic project logic:

```cpp
/*
 * Project: LDR Light Sensor Module with ESP8266 and KiwisIoT
 * Project ID: KIWISIOT-001
 * Board: ESP8266 NodeMCU
 * Sensor: LDR Sensor Module
 */

#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const int LDR_PIN = A0;

void setup() {
    Serial.begin(115200);

    // Connect ESP8266 to Wi-Fi

    // Initialize KiwisIoT
}

void loop() {

    // Read analog value from LDR module
    int ldrValue = analogRead(LDR_PIN);

    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    // Send ldrValue to KiwisIoT

    delay(5000);
}
```

> Replace the abbreviated KiwisIoT section with the actual tested KiwisIoT Arduino library/API code used by this project.

---

# ⬆️ Step 6 — Upload the Program

Connect the ESP8266 to your computer.

Select:

```text
Tools → Board → ESP8266 NodeMCU
```

Select the correct COM port:

```text
Tools → Port
```

Then:

1. Verify the code.
2. Upload the program.
3. Wait for the upload to finish.
4. Open Serial Monitor.

Screenshot:

```markdown
![Uploading LDR ESP8266 KiwisIoT Arduino code](images/05-upload-code.png)
```

---

# 🖥️ Step 7 — Check Serial Monitor

Open:

```text
Tools → Serial Monitor
```

Use the baud rate configured in the program.

Example output:

```text
Connecting to WiFi...
WiFi connected

LDR Value: 356
LDR Value: 412
LDR Value: 528
LDR Value: 641
```

The actual values depend on the sensor module, lighting conditions, board, and module design.

Screenshot:

```markdown
![ESP8266 LDR sensor module readings in Serial Monitor](images/06-serial-monitor.png)
```

---

# 📊 Step 8 — Monitor the Sensor on KiwisIoT

Open your KiwisIoT dashboard.

Add a suitable widget for the LDR sensor data.

The final data flow is:

```text
LDR Module
    ↓
ESP8266
    ↓
Wi-Fi
    ↓
KiwisIoT
    ↓
LDR Sensor Channel
    ↓
Dashboard Widget
```

Add your dashboard screenshot:

```markdown
![KiwisIoT dashboard displaying LDR sensor data from ESP8266](images/07-kiwisiot-dashboard.png)
```

---

# 📷 Installation Screenshots

For a professional project guide, include screenshots for each important stage:

```text
images/
│
├── 01-arduino-ide-installation.png
├── 02-esp8266-board-installation.png
├── 03-hardware-connection.jpg
├── 04-kiwisiot-setup.png
├── 05-upload-code.png
├── 06-serial-monitor.png
├── 07-kiwisiot-dashboard.png
└── 08-final-project.jpg
```

Use descriptive filenames instead of:

```text
IMG_1234.jpg
Screenshot1.png
image.png
```

---

# 📈 Expected Output

When the project is working correctly:

```text
LDR Sensor Module
        ↓
     ESP8266
        ↓
     Wi-Fi
        ↓
    KiwisIoT
        ↓
    Dashboard
```

The sensor reading should change when the amount of light falling on the LDR changes.

For example:

```text
Normal Light  → Sensor Value
Low Light     → Sensor Value
Bright Light  → Sensor Value
```

> Do not assume that a higher ADC value always means brighter light. The direction depends on the particular LDR module's circuit design. Determine the relationship experimentally for your module.

---

# 🧪 Experiments

Try these experiments after completing the basic project.

### Experiment 1 — Normal Room Light

Observe the LDR sensor value under normal room lighting.

### Experiment 2 — Cover the Sensor

Cover the LDR sensor and observe how the reading changes.

### Experiment 3 — Use a Flashlight

Point a flashlight toward the LDR module and observe the sensor value.

### Experiment 4 — Change Distance

Move the flashlight closer and farther from the sensor.

### Experiment 5 — Digital Threshold

Connect the DO output to an ESP8266 GPIO and adjust the module's potentiometer to experiment with threshold detection.

---

# 🚀 Project Extensions

The basic project can be extended into more advanced IoT applications.

## Smart Lighting

Use the LDR reading to automatically control an LED or relay.

```text
LDR
 ↓
ESP8266
 ↓
Threshold
 ↓
Relay
 ↓
Light
```

## Remote Light Monitoring

Monitor light levels remotely using KiwisIoT.

## Automated Classroom Lighting

Use light measurements to create an automated classroom lighting system.

## Smart Home

Use LDR data as part of a smart-home automation system.

## Data Analytics

Store historical sensor data and analyze light-level patterns.

## AI + IoT

Historical sensor data can be used for anomaly detection and intelligent automation experiments.

---

# 🔧 Troubleshooting

## 1. LDR value does not change

Check:

* LDR module connection
* VCC connection
* GND connection
* AO → A0 connection
* Sensor surface
* Lighting conditions
* Serial Monitor

Try covering the sensor and shining a flashlight on it.

---

## 2. ESP8266 is not detected

Check:

* USB cable
* USB driver
* COM port
* ESP8266 board selection
* USB connection

---

## 3. ESP8266 cannot connect to Wi-Fi

Check:

* Wi-Fi SSID
* Wi-Fi password
* Network availability
* Signal strength
* ESP8266 power supply

---

## 4. KiwisIoT does not receive data

Check:

* KiwisIoT project configuration
* Device credentials
* Sensor/channel configuration
* Wi-Fi connection
* MQTT/API configuration
* Serial Monitor
* KiwisIoT dashboard widget

---

## 5. DO output is not changing

Check:

* DO connection
* Module power
* Potentiometer adjustment
* Light level
* ESP8266 GPIO configuration

Remember that DO is a **threshold output**, while AO provides the changing analog signal.

---

# 📋 Project Specifications

| Specification           | Details                 |
| ----------------------- | ----------------------- |
| Project ID              | KIWISIOT-001            |
| Project Name            | LDR Light Sensor Module |
| Microcontroller         | ESP8266                 |
| Board                   | ESP8266 NodeMCU         |
| Sensor                  | LDR Sensor Module       |
| Sensor Type             | Light Sensor            |
| Analog Input            | A0                      |
| Analog Output           | AO                      |
| Digital Output          | DO                      |
| Communication           | Wi-Fi                   |
| IoT Platform            | KiwisIoT                |
| Programming Language    | Arduino C/C++           |
| Development Environment | Arduino IDE             |
| Difficulty              | Beginner                |
| Category                | IoT / Sensor Monitoring |

---

# 🎓 Learning Outcomes

After completing this project, learners should be able to:

* Explain the purpose of an LDR sensor module.
* Identify AO and DO outputs.
* Connect an LDR sensor module to ESP8266.
* Read analog sensor values.
* Understand threshold-based digital output.
* Program ESP8266 using Arduino IDE.
* Connect ESP8266 to Wi-Fi.
* Send sensor data to KiwisIoT.
* Create a basic IoT dashboard.
* Understand the sensor-to-cloud data flow.

---

# ❓ Frequently Asked Questions

## What is an LDR sensor module?

An LDR sensor module is an electronic module that detects changes in light intensity using a light-dependent resistor and provides electrical output signals.

## What is AO on an LDR sensor module?

AO means **Analog Output**. It provides a variable signal that can be read by an analog input such as the ESP8266 A0 pin.

## What is DO on an LDR sensor module?

DO means **Digital Output**. It generally provides a HIGH/LOW signal according to a configurable light threshold.

## Which LDR output should be used for KiwisIoT?

For continuous light-level monitoring, **AO is normally the appropriate output** because it provides a variable sensor reading.

## Can an LDR sensor module work with ESP8266?

Yes. An LDR sensor module can be interfaced with an ESP8266 using its analog output, provided the module's supply and output voltage are compatible with the ESP8266 board.

## Can LDR data be monitored remotely?

Yes. The ESP8266 can read the LDR module and transmit the data over Wi-Fi to KiwisIoT for remote monitoring.

## Can this project be used for automatic lighting?

Yes. The LDR reading can be used to control an LED, relay, or other output device according to a defined light-level condition.

## Is this project suitable for beginners?

Yes. This project introduces sensor interfacing, analog input, ESP8266 programming, Wi-Fi connectivity, and IoT dashboard monitoring.

---

# 🔗 Related KiwisIoT Projects

This project is part of the KiwisIoT project collection.

### Sensor Projects

* [002 — DHT11 Temperature and Humidity with ESP8266](../002-dht11-esp8266-kiwisiot/)
* [003 — DHT22 Temperature and Humidity with ESP8266](../003-dht22-esp8266-kiwisiot/)
* [004 — BMP180 Pressure Sensor with ESP8266](../004-bmp180-esp8266-kiwisiot/)
* [005 — DS18B20 Temperature Sensor with ESP8266](../005-ds18b20-esp8266-kiwisiot/)
* [006 — MQ2 Gas Sensor with ESP8266](../006-mq2-esp8266-kiwisiot/)

---

# 🗂️ KiwisIoT 200+ Project Collection

This project is **Project 001** in the KiwisIoT project library.

The collection is organized into progressive categories:

```text
001–050
Sensors
    ↓
051–080
Output Devices
    ↓
081–120
Modules & Communication
    ↓
121–160
IoT Applications
    ↓
161–200+
Advanced IoT / AI + IoT
```

The goal is to provide a structured collection of practical IoT experiments for learners, educators, makers, and developers.

---

# 🔑 SEO Keywords

LDR sensor module ESP8266, LDR light sensor module project, ESP8266 LDR project, ESP8266 light sensor, LDR module Arduino, LDR sensor Arduino project, ESP8266 IoT project, KiwisIoT ESP8266, KiwisIoT LDR project, IoT light monitoring, light sensor IoT project, NodeMCU LDR project, ESP8266 analog sensor, LDR AO DO sensor module, Arduino IoT project, beginner IoT project, IoT sensor monitoring, smart lighting project, IoT education project.

---

# 🏷️ Suggested GitHub Topics

```text
kiwisiot
iot
esp8266
nodemcu
ldr
ldr-sensor
ldr-module
light-sensor
arduino
arduino-ide
iot-project
esp8266-project
iot-dashboard
sensor-monitoring
wifi
mqtt
embedded
stem-education
iot-education
```

---

# 📁 Project Structure

```text
001-ldr-light-sensor-esp8266-kiwisiot/
│
├── README.md
│
├── code/
│   └── ldr_esp8266_kiwisiot.ino
│
├── circuit/
│   └── circuit-diagram.png
│
├── images/
│   ├── 01-arduino-ide-installation.png
│   ├── 02-esp8266-board-installation.png
│   ├── 03-hardware-connection.jpg
│   ├── 04-kiwisiot-setup.png
│   ├── 05-upload-code.png
│   ├── 06-serial-monitor.png
│   ├── 07-kiwisiot-dashboard.png
│   └── 08-final-project.jpg
│
└── docs/
    └── troubleshooting.md
```

---

# 📜 License

This project is provided for educational and development purposes.

See the repository license for the applicable terms.

---

# 🌐 KiwisIoT

**KiwisIoT is an IoT platform for connecting devices, collecting sensor data, creating dashboards, and developing IoT applications.**

```text
Learn
  ↓
Build
  ↓
Connect
  ↓
Monitor
  ↓
Analyze
  ↓
Create
```

---

# ⭐ Support the Project

If this project helped you:

* ⭐ Star the repository
* 🔧 Build the experiment
* 📚 Explore other KiwisIoT projects
* 💡 Create your own modification
* 🤝 Contribute improvements
* 📢 Share the project with other learners

---

**Project ID:** KIWISIOT-001
**Project:** LDR Light Sensor Module + ESP8266 + KiwisIoT
**Collection:** KiwisIoT 200+ IoT Projects
