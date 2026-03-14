
# Prototype v1 Experiment Log

## Objective

Test whether gyroscope motion can control mouse movement via Bluetooth.

## Hardware

ESP32
MPU6050

## Observations

Initial motion data caused unstable cursor movement due to sensor noise.

## Improvements Implemented

* Gyroscope offset calibration
* Deadzone filtering
* Sensitivity adjustment
* Motion smoothing filter

## Result

Cursor movement became stable enough for basic aiming control.

## Limitation

The current system uses **angular velocity**, meaning the cursor moves based on motion speed rather than absolute orientation.
