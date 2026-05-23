#include "altimeter.h"

#include <Wire.h>

float previousAltitude = 0;
unsigned long previousTime = 0;

void initAltimeter() {

    Serial.println("MS5611 Initialized");
}
void readAltimeter(TelemetryData &data) {

    // Replace with real sensor code
    float altitude = analogRead(35) * 0.1;

    unsigned long now = millis();

    float dt = (now - previousTime) / 1000.0;

    if(dt > 0) {
        data.velocity = (altitude - previousAltitude) / dt;
    }
        data.altitude = altitude;

    if(altitude > data.maxAltitude) {
        data.maxAltitude = altitude;
    }

    previousAltitude = altitude;
    previousTime = now;
}