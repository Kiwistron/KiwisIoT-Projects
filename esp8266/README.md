# ESP8266 IoT Projects with KiwisIoT | Arduino, Sensors and Cloud Dashboard

Explore hands-on **ESP8266 IoT projects using KiwisIoT, Arduino IDE, NodeMCU, and electronic sensors**. This collection includes sensor-monitoring projects, wireless data visualization, automation experiments, and practical embedded systems examples.

Each project has its own folder with documentation and source code to help students, educators, electronics enthusiasts, and developers learn how to connect sensors to an ESP8266 and visualize sensor data on an IoT dashboard.

- **IoT platform:** [KiwisIoT](https://kiwisiot.in/)
- **Repository:** [KiwisIoT Projects on GitHub](https://github.com/Kiwistron/KiwisIoT-Projects)
- **Controller:** ESP8266 NodeMCU
- **Development environment:** Arduino IDE
- **Topics:** IoT, embedded systems, sensor monitoring, and electronics education

## Table of Contents

- [Getting Started](#getting-started)
- [ESP8266 Sensor Projects](#esp8266-sensor-projects)
- [What You Will Learn](#what-you-will-learn)
- [Who Can Use These Projects](#who-can-use-these-projects)
- [About KiwisIoT](#about-kiwisiot)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

To start building an ESP8266 IoT project:

1. Install the Arduino IDE.
2. Configure the ESP8266 board package and select your NodeMCU board.
3. Follow the [KiwisIoT Arduino Setup Guide](./kiwisiot-arduino-setup/).
4. Connect the sensor according to the selected project's wiring instructions.
5. Configure your Wi-Fi credentials and KiwisIoT dashboard settings in the example code.
6. Upload the sketch, open the Serial Monitor, and check the readings on your dashboard.

Review the individual project's README for its components, pin connections, library requirements, configuration, and testing procedure.

## ESP8266 Sensor Projects

These projects demonstrate how to interface sensors and electronic modules with an ESP8266 and monitor readings or status information through a KiwisIoT dashboard.

| No. | Project | Description |
|---|---|---|
| 001 | [ESP8266 LDR Sensor IoT Project](./001-ldr-kiwisiot/) | Measure light intensity using an LDR sensor and monitor light levels on an IoT dashboard. |
| 002 | [ESP8266 IR Sensor IoT Project](./002-ir-kiwisiot/) | Detect nearby objects using an infrared sensor module and display its status. |
| 003 | [ESP8266 Ultrasonic Sensor IoT Project](./003-ultrasonic-kiwisiot/) | Measure distance using an ultrasonic sensor and visualize the readings. |
| 004 | [ESP8266 DHT11 Temperature and Humidity Project](./004-dht11-kiwisiot/) | Read temperature and humidity using a DHT11 sensor. |
| 005 | [ESP8266 PIR Motion Sensor IoT Project](./005-pir-kiwisiot/) | Detect motion and monitor movement status remotely. |
| 006 | [ESP8266 Gas Sensor IoT Project](./006-gas-kiwisiot/) | Monitor the output of a gas sensor module and display sensor status. |
| 007 | [ESP8266 Flame Sensor IoT Project](./007-flame-kiwisiot/) | Detect flame sensor output and monitor alert status. |
| 008 | [ESP8266 Soil Moisture Sensor IoT Project](./008-soil-moisture-kiwisiot/) | Monitor soil moisture readings for plant and irrigation experiments. |
| 009 | [ESP8266 Water Level Monitoring Project](./009-water-level-kiwisiot/) | Monitor water level using a compatible water-level sensor. |
| 010 | [ESP8266 Rain Sensor IoT Project](./010-rain-sensor-kiwisiot/) | Detect rain or water on a raindrop sensor module. |
| 011 | [ESP8266 Sound Sensor IoT Project](./011-sound-kiwisiot/) | Monitor sound sensor output and observe changes in sound activity. |
| 012 | [ESP8266 MPU6050 IoT Project](./012-mpu6050-kiwisiot/) | Read motion and orientation-related measurements from an MPU6050 sensor. |
| 013 | [ESP8266 Voltage Monitoring IoT Project](./013-voltage-kiwisiot/) | Measure voltage through a suitable, correctly scaled voltage-sensor circuit. |
| 014 | [ESP8266 Current Monitoring IoT Project](./014-current-kiwisiot/) | Monitor current using an ACS712 current sensor module. |
| 015 | [ESP8266 Vibration Sensor IoT Project](./015-vibration-kiwisiot/) | Detect vibration events using an SW-420 vibration sensor module. |
| 016 | [ESP8266 Reed Switch IoT Project](./016-reed-switch-kiwisiot/) | Detect magnetic switching events using a reed switch. |
| 017 | [ESP8266 Hall Effect Sensor IoT Project](./017-hall-effect-kiwisiot/) | Detect magnetic fields using a Hall effect sensor module. |
| 018 | [ESP8266 Capacitive Touch Sensor IoT Project](./018-touch-kiwisiot/) | Detect touch input using a capacitive touch sensor module. |
| 019 | [ESP8266 BMP180 Pressure and Temperature IoT Project](./019-bmp180-kiwisiot/) | Read atmospheric pressure and temperature using a BMP180 barometric sensor. |
| 020 | [ESP8266 DS18B20 Temperature Monitoring IoT Project](./020-DS18B20-kiwisiot/) | Measure temperature using a DS18B20 digital temperature sensor. |

## What You Will Learn

By exploring these ESP8266 projects, you can gain practical experience with:

- Interfacing sensors and electronic modules with an ESP8266 NodeMCU.
- Writing and uploading Arduino sketches.
- Reading analog and digital sensor outputs.
- Using sensor libraries and communication interfaces such as I²C and OneWire where required.
- Sending sensor readings and device status to an IoT dashboard.
- Visualizing measurements and status information using suitable dashboard widgets.
- Testing, troubleshooting, and extending embedded systems projects.

## Who Can Use These Projects?

These projects are suitable for:

- Engineering students working on IoT and embedded systems experiments.
- Beginners learning ESP8266 and Arduino programming.
- Educators preparing sensor-based demonstrations.
- Electronics hobbyists building connected devices.
- Developers exploring sensor monitoring and IoT dashboard integration.

Component requirements, circuit connections, code, and difficulty vary by project. Follow the individual project documentation before assembling a circuit.

## About KiwisIoT

[KiwisIoT](https://kiwisiot.in/) is an IoT platform for connecting devices, sending data, and visualizing information through dashboards. These examples demonstrate ways to use KiwisIoT with ESP8266-based sensor projects for learning, prototyping, and monitoring applications.

Visit the [KiwisIoT website](https://kiwisiot.in/) to learn more about the platform.

## Contributing

Suggestions, corrections, and improvements are welcome. When reporting an issue, include the project name and relevant hardware configuration, and describe the steps needed to reproduce the problem.

## License

Refer to the repository's [LICENSE](../LICENSE) file for the applicable terms of use and distribution.
