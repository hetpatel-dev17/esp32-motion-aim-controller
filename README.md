# ESP32 Motion Aim Controller

An experimental motion-based aiming controller built using **ESP32 and the MPU6050 IMU**.

The system converts **gyroscope rotation into Bluetooth mouse movement**, allowing physical device motion to control a cursor.

This project explores **IMU-based human–machine interaction systems and motion filtering techniques**.

---

## 📺 Live Prototype Demonstration

To see the hardware in action, check out the demo video I’ve uploaded to Instagram. This reel demonstrates the current iteration of the project, focusing on real-world performance and functional testing.

[![Watch Prototype Demo](https://img.shields.io/badge/Instagram-Watch_Reel_Demo-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/reel/DV70GDGjGY7/?igsh=MWVnYmxyOWF6c2F0OA==)

> **Note:** The video covers the integration phase of the prototype. For detailed build logs and circuit diagrams, please refer to the `docs` folder in this repository.

Prototype demonstration of the motion controller.

![Prototype Demo](diagrams/demo.gif)

The video shows the ESP32 motion controller translating physical rotation into cursor movement through Bluetooth HID.

---

# Project Overview

The ESP32 reads angular velocity from the **MPU6050 gyroscope**, processes the signal, and sends movement commands as a **Bluetooth HID mouse**.

The goal of this prototype is to transform **noisy inertial sensor data into stable human-controlled input**.

---

# Hardware

• ESP32 development board
• MPU6050 inertial measurement unit

Future additions:

• trigger buttons
• vibration feedback

---

# System Pipeline

```
MPU6050 IMU
     │
     ▼
Gyroscope Data
     │
     ▼
Offset Calibration
     │
     ▼
Deadzone Filter
     │
     ▼
Axis Mapping
     │
     ▼
Sensitivity Scaling
     │
     ▼
Smoothing Filter
     │
     ▼
BLE Mouse Output
     │
     ▼
PC Cursor Movement
```

---

# Features

Current prototype includes:

* Bluetooth HID mouse interface
* Gyroscope offset calibration
* Deadzone filtering
* Adjustable sensitivity
* Motion smoothing filter
* Axis remapping system

---

# Motion Processing Logic

Raw gyroscope signals contain noise and drift.
The system processes the signal through multiple stages:

1. Sensor sampling
2. Offset calibration
3. Deadzone filtering
4. Axis remapping
5. Sensitivity scaling
6. Exponential smoothing
7. BLE mouse output

This pipeline converts **unstable physical signals into smooth cursor movement**.

---

# Prototype Result

The current system behaves as a **velocity-based motion controller**.

This means cursor movement depends on **how fast the device rotates**, not where it points.

This approach is similar to early motion systems such as the **Nintendo Wii Remote**.

---

# Future Improvements

Planned upgrades:

* Absolute orientation tracking (BNO055 / MPU9250)
* Button matrix for trigger input
* Advanced filtering algorithms
* Hybrid tracking using IMU + optical sensors

---

# Repository Structure

```
esp32-motion-aim-controller

firmware/
   motion_controller_v1.ino

docs/
   system_architecture.md
   hardware_setup.md
   debugging_journal.md

diagrams/
   demo.gif

experiments/
   prototype_v1.md

meta/
   ai_usage_disclosure.md
```

---

# Author

Het Patel
