
#include <Arduino.h>
#include <BleMouse.h>
#include <Wire.h>
#include <MPU6050.h>

BleMouse bleMouse("ESP32 Motion Gun");
MPU6050 mpu;

float sensitivity = 0.008;
int deadzone = 1200;

bool firstConnect = true;

// gyro offsets
long offsetX = 0;
long offsetY = 0;
long offsetZ = 0;

// smoothing values
float smoothX = 0;
float smoothY = 0;


/*
AXIS MAPPING SYSTEM

Change these values if direction becomes wrong

1  = normal
-1 = inverted
*/

int mapMouseX_from = 1;   // 1 = GX , 2 = GY
int mapMouseY_from = 2;

int invertX = -1;   // change to 1 if direction wrong
int invertY = 1;



void calibrateGyro() {

    Serial.println("Calibrating gyro... keep gun still");

    long sumX = 0;
    long sumY = 0;
    long sumZ = 0;

    for(int i=0;i<1000;i++){

        int16_t gx,gy,gz;
        mpu.getRotation(&gx,&gy,&gz);

        sumX += gx;
        sumY += gy;
        sumZ += gz;

        delay(3);
    }

    offsetX = sumX / 1000;
    offsetY = sumY / 1000;
    offsetZ = sumZ / 1000;

    Serial.println("Calibration complete");
}



void setup(){

    Serial.begin(115200);

    Wire.begin(21,22);

    mpu.initialize();

    calibrateGyro();

    bleMouse.begin();
}



void loop(){

    if(!bleMouse.isConnected()){
        firstConnect = true;
        delay(10);
        return;
    }

    if(firstConnect){
        delay(500);
        bleMouse.click(MOUSE_LEFT);
        firstConnect = false;
    }


    int16_t gx,gy,gz;

    mpu.getRotation(&gx,&gy,&gz);


    // remove offsets
    gx -= offsetX;
    gy -= offsetY;
    gz -= offsetZ;


    if(abs(gx) < deadzone) gx = 0;
    if(abs(gy) < deadzone) gy = 0;



    float axisX;
    float axisY;


    if(mapMouseX_from == 1) axisX = gx;
    else axisX = gy;

    if(mapMouseY_from == 1) axisY = gx;
    else axisY = gy;


    float rawX = axisX * sensitivity * invertX;
    float rawY = axisY * sensitivity * invertY;



    // smoothing filter
    smoothX = 0.85 * smoothX + 0.15 * rawX;
    smoothY = 0.85 * smoothY + 0.15 * rawY;



    bleMouse.move(smoothX, smoothY);

    delay(5);
}
