# ESP8266 LDR Sensor IoT Project with KiwisIoT

Monitor light intensity using an **LDR sensor**, **ESP8266 NodeMCU**, and the **KiwisIoT IoT platform**.

The ESP8266 reads the analog value from the LDR sensor, calculates a light level, determines the light status as **BRIGHT**, **MEDIUM**, or **DARK**, and sends the data to a KiwisIoT dashboard.

## Project Overview

This project demonstrates how to build a simple IoT-based light monitoring system using an ESP8266 and an LDR sensor.

The ESP8266:

* Reads the LDR sensor value
* Calculates the light level
* Determines the light condition
* Sends the light level to KiwisIoT
* Sends the light status to KiwisIoT
* Displays the data on a KiwisIoT dashboard

## Project Flow

```text
LDR Sensor
    ↓
ESP8266 NodeMCU
    ↓
Wi-Fi
    ↓
KiwisIoT
    ↓
Dashboard
```

## Features

* Light intensity monitoring
* Real-time sensor data
* Light status detection
* ESP8266 Wi-Fi connectivity
* KiwisIoT dashboard monitoring
* Simple beginner-friendly IoT project

## Hardware Required

* ESP8266 NodeMCU
* LDR Sensor Module
* Jumper wires
* USB cable
* Computer

## Software Required

* Arduino IDE
* ESP8266 board support
* KiwisIoT Arduino library
* KiwisIoT account

## KiwisIoT Setup

Before starting this project, complete the common KiwisIoT Arduino setup guide.

The setup guide covers:

* Arduino IDE setup
* ESP8266 board installation
* KiwisIoT Arduino library installation
* KiwisIoT account setup
* Dashboard/panel creation
* Topic ID
* Widget setup and configuration

👉 [ KiwisIoT Arduino Setup Guide](../kiwisiot-arduino-setup/README.md)

## Circuit

Connect the LDR sensor module to the ESP8266 NodeMCU.

[LDR Circuit](images/circuit.png)

### Connection

| LDR Sensor | ESP8266 NodeMCU |
| ---------- | --------------- |
| VCC        | 3.3V            |
| GND        | GND             |
| AO         | A0              |

> Use the analog output (AO) of the LDR sensor module for this project.

## Arduino Code

The complete Arduino code is available here:

[`code/esp8266-ldr-kiwisiot.ino`](https://chatgpt.com/c/code/esp8266-ldr-kiwisiot.ino)

The code uses:

* `ESP8266WiFi.h`
* `KiwisIoT.h`

### Code Configuration

Open the Arduino sketch and update the following values:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

const char* topic = "YOUR_DASHBOARD_TOPIC_ID";
```

Replace:

* `YOUR_WIFI_NAME` with your Wi-Fi network name
* `YOUR_WIFI_PASSWORD` with your Wi-Fi password
* `YOUR_DASHBOARD_TOPIC_ID` with the Topic ID from your KiwisIoT dashboard

Do not share your real Wi-Fi password or private credentials in a public GitHub repository.

### Channel Configuration

This project sends two values to KiwisIoT.

| Channel | Data         |
| ------- | ------------ |
| `0`     | Light Level  |
| `1`     | Light Status |

The code sends the light level using:

```cpp
kiwisiot.send("0", String(lightLevel));
```

The light status is sent using:

```cpp
kiwisiot.send("1", lightStatus);
```

Configure the corresponding dashboard widgets using these channel IDs.

## Arduino Code Screenshot

[Arduino Code](images/code.png)

## Upload the Code

After completing the configuration:

1. Open the `.ino` file in Arduino IDE.
2. Select the ESP8266 NodeMCU board.
3. Make sure the required ESP8266 and KiwisIoT setup has been completed.
4. Verify the code.
5. Upload the code to the ESP8266.

The common Arduino and KiwisIoT setup instructions are available in the:

[ KiwisIoT Arduino Setup Guide](../kiwisiot-arduino-setup/README.md)

## Serial Monitor

After uploading the program, open the Serial Monitor.

Set the baud rate to:

```text
115200
```

The ESP8266 displays:

* Raw LDR value
* Calculated light level
* Light status
* Data sent to KiwisIoT Channel 0
* Data sent to KiwisIoT Channel 1

Example output:

```text
---------- LIGHT MONITORING ----------

Raw LDR Value: 69
Light Level: 954
Light Status: BRIGHT

Sent to KiwisIoT Channel 0: 954
Sent to KiwisIoT Channel 1: BRIGHT
```

[Serial Monitor Output](images/serial-monitor.png)

## Light Level Calculation

The ESP8266 reads the LDR using its analog input:

```cpp
int rawValue = analogRead(LDR_PIN);
```

The project calculates the light level using:

```cpp
int lightLevel = 1023 - rawValue;
```

This reverses the raw ADC value so that a higher calculated value represents a higher light level for the LDR module used in this project.

The ESP8266 ADC reading is based on a range of:

```text
0 - 1023
```

## Light Status

The project classifies the calculated light level into three conditions:

| Light Level  | Status |
| ------------ | ------ |
| `700 - 1023` | BRIGHT |
| `300 - 699`  | MEDIUM |
| `0 - 299`    | DARK   |

The classification is implemented in the Arduino code:

```cpp
if (lightLevel >= 700) {
    lightStatus = "BRIGHT";
}
else if (lightLevel >= 300) {
    lightStatus = "MEDIUM";
}
else {
    lightStatus = "DARK";
}
```

These threshold values can be adjusted according to the LDR sensor, circuit, and lighting conditions.

## KiwisIoT Dashboard

The project sends two types of data to the KiwisIoT dashboard:

* Light level
* Light status

The dashboard can display the current light level and the corresponding light status.

[KiwisIoT Dashboard Output](images/dashboard-output.png)

## Data Flow

```text
LDR Sensor
    │
    │ Analog Value
    ↓
ESP8266 NodeMCU
    │
    ├── Light Level → Channel 0
    │
    └── Light Status → Channel 1
             │
             ↓
          KiwisIoT
             │
             ↓
         Dashboard
```

## Project Output

The final system provides:

* LDR sensor readings
* Calculated light level
* BRIGHT / MEDIUM / DARK status
* Real-time KiwisIoT monitoring

## Project Files

```text
esp8266-ldr-kiwisiot/
│
├── README.md
│
├── code/
│   └── esp8266-ldr-kiwisiot.ino
│
└── images/
    ├── circuit.png
    ├── code.png
    ├── serial-monitor.png
    └── dashboard-output.png
```

## Related Setup

For the complete Arduino, ESP8266, and KiwisIoT setup:

👉 [ KiwisIoT Arduino Setup Guide](../kiwisiot-arduino-setup/README.md)

## Conclusion

This project provides a simple way to monitor light intensity using an ESP8266 and LDR sensor and visualize the data through KiwisIoT.

It can also be used as a starting point for developing more advanced IoT monitoring projects with different sensors and devices.
