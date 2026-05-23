#include "gps.h"

#include <TinyGPSPlus.h>

HardwareSerial gpsSerial(1);
TinyGPSPlus gps;

void initGPS() {

    gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
}
void readGPS(TelemetryData &data) {

    while(gpsSerial.available()) {

        gps.encode(gpsSerial.read());
    }

    if(gps.location.isValid()) {

        data.latitude = gps.location.lat();
        data.longitude = gps.location.lng();
    }

    data.satellites = gps.satellites.value();
}