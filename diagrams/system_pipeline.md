# System Pipeline Diagram

The motion controller processes IMU data through several stages before sending mouse commands.

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

This diagram represents the internal data pipeline of the system.

