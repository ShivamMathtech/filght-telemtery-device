#include "sdlogger.h"

#include <SPI.h>
#include <SD.h>

#include "pins.h"

File logFile;

void initSD() {

    if(!SD.begin(SD_CS)) {

        Serial.println("SD Init Failed");
    }
}

void logTelemetry(TelemetryData &data) {

    logFile = SD.open("/flight.csv", FILE_APPEND);

    if(logFile) {

        logFile.print(data.timestamp);
        logFile.print(",");

        logFile.print(data.altitude);
        logFile.print(",");

        logFile.print(data.velocity);
        logFile.print(",");

        logFile.print(data.latitude, 6);
        logFile.print(",");

        logFile.print(data.longitude, 6);
        logFile.print(",");

        logFile.print(data.batteryVoltage);
        logFile.print(",");
        logFile.println(data.flightState);

        logFile.close();
    }
}