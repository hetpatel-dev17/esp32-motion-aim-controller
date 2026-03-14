# System Architecture

The ESP32 Motion Aim Controller converts rotational motion into mouse movement.

The system reads gyroscope data from the MPU6050 and processes it through a filtering pipeline before sending movement commands via Bluetooth.

## Processing Pipeline

MPU6050 → Calibration → Deadzone Filter → Axis Mapping → Sensitivity Scaling → Smoothing Filter → BLE Mouse Output

## Sensor Role

The MPU6050 provides:

* Gyroscope (angular velocity)
* Accelerometer (not used in current prototype)

The current prototype uses **gyroscope velocity** to move the cursor.

This means the cursor moves based on **how fast the controller rotates**, not the direction it points.

## Key System Components

* ESP32 microcontroller
* MPU6050 inertial sensor
* Bluetooth HID interface

The ESP32 processes the IMU signal and sends mouse movement packets to the host device.

