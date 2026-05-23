#include "imu.h"

#include <Wire.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055();

void initIMU() {

    if(!bno.begin()) {
        Serial.println("BNO055 Not Detected");
    }
}

void readIMU(TelemetryData &data) {

    imu::Vector<3> euler = bno.getVector(
        Adafruit_BNO055::VECTOR_EULER
    );

    data.yaw = euler.x();
    data.pitch = euler.y();
    data.roll = euler.z();
}