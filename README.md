# ESP32 Motion Aim Controller

An experimental motion-based aiming controller built with **ESP32 and MPU6050**.
The device converts **gyroscope rotation into Bluetooth mouse movement**, allowing physical motion to control a cursor.

This project explores **IMU-based human–machine interaction systems**.

---

# Overview

The system reads **angular velocity from the MPU6050 gyroscope**, processes the signal using filtering techniques, and sends movement data to a computer as a **Bluetooth HID mouse**.

The project focuses on **signal processing, sensor calibration, and motion filtering**.

---

# Hardware

* ESP32 development board
* MPU6050 IMU sensor
* push buttons (planned trigger system)

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

* Bluetooth HID mouse
* Gyroscope offset calibration
* Deadzone filtering
* Adjustable sensitivity
* Motion smoothing filter
* Axis remapping system

---

# Motion Processing Logic

Raw gyroscope signals contain noise and drift.
The system processes motion using several stages:

1. Gyroscope sampling
2. Offset calibration
3. Deadzone filtering
4. Axis remapping
5. Sensitivity scaling
6. Exponential smoothing
7. BLE mouse output

This pipeline converts **unstable physical sensor signals into stable cursor movement**.

---

# Prototype Result

The controller currently operates as a **velocity-based motion controller**.

This means cursor movement depends on **how fast the device rotates**, rather than the exact direction the device points.

This behavior is similar to early motion controllers like the Nintendo Wii Remote.

---

# Future Improvements

Planned upgrades include:

* Absolute orientation tracking (BNO055 / MPU9250)
* 3×3 trigger button matrix
* improved motion filtering
* hybrid IMU + optical tracking

---

# Repository Structure

```
esp32-motion-aim-controller
│
├── firmware
│   └── motion_controller_v1.ino
│
├── docs
│   ├── system_architecture.md
│   ├── hardware_setup.md
│   └── debugging_journal.md
│
├── diagrams
│   └── system_pipeline.png
│
└── meta
    └── ai_usage_disclosure.md
```

---

# Author

Het Patel
