#pragma once

#include <Arduino.h>

struct TelemetryData {

    float altitude;
    float maxAltitude;
    float velocity;

    float pitch;
    float roll;
    float yaw;

    float latitude;
    float longitude;

    float batteryVoltage;

    int satellites;
    int flightState;

    unsigned long timestamp;
};