#include "pyro.h"

#include "pins.h"
#include "flight_states.h"

bool drogueDeployed = false;
bool mainDeployed = false;

void initPyro() {

    pinMode(PYRO_DROGUE, OUTPUT);
    pinMode(PYRO_MAIN, OUTPUT);

    digitalWrite(PYRO_DROGUE, LOW);
    digitalWrite(PYRO_MAIN, LOW);
}

void handleRecovery(TelemetryData &data) {

    if(data.flightState == APOGEE &&
       !drogueDeployed) {

        digitalWrite(PYRO_DROGUE, HIGH);

        delay(1000);

        digitalWrite(PYRO_DROGUE, LOW);

        drogueDeployed = true;
    }
     if(data.altitude < 300 &&
       !mainDeployed) {

        digitalWrite(PYRO_MAIN, HIGH);

        delay(1000);

        digitalWrite(PYRO_MAIN, LOW);

        mainDeployed = true;
    }
}