#include "battery.h"

void initBattery() {

    pinMode(34, INPUT);
}

void readBattery(TelemetryData &data) {

    int raw = analogRead(34);

    float voltage = (raw / 4095.0) * 3.3 * 3.127;

    data.batteryVoltage = voltage;
}