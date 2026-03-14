# Hardware Setup

## Components

ESP32 development board
MPU6050 inertial measurement unit

## Wiring

The MPU6050 communicates with the ESP32 using the I2C protocol.

Connections:

SDA → GPIO 21
SCL → GPIO 22
VCC → 3.3V
GND → GND

## Future Expansion

The controller design includes planned support for:

* trigger buttons
* button matrix
* vibration feedback

