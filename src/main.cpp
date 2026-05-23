#include<Aduino.h>
#include "structs.h"
#include "flight_states.h"

#include "imu.h"
#include "altimeter.h"

#include "gps.h"
#include "battery.h"

#include "lora.h"
#include "packet.h"

#include "sdlogger.h"

#include "state_machine.h"
#include "pyro.h"

#include "oled.h"
TelemetryData telemetry;

void setup() {

    Serial.begin(115200);

    Wire.begin(21, 22);

    initIMU();
    initAltimeter();
    initGPS();
    initBattery();

    initLoRa();
    initSD();

    initOLED();

    initPyro();
        telemetry.flightState = IDLE;

    Serial.println("Rocket Telemetry System Started");
}

void loop() {

    telemetry.timestamp = millis();

    readIMU(telemetry);

    readAltimeter(telemetry);

    readGPS(telemetry);

    readBattery(telemetry);
    updateFlightState(telemetry);

    handleRecovery(telemetry);

    logTelemetry(telemetry);

    sendTelemetry(telemetry);

    updateOLED(telemetry);

    delay(50);
}