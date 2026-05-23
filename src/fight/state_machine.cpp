#include "state_machine.h"

#include "flight_states.h"

void updateFlightState(TelemetryData &data) {

    switch(data.flightState) {

        case IDLE:

            if(data.velocity > 15) {
                data.flightState = BOOST;
            }
             break;

        case BOOST:

            if(data.velocity < 0) {
                data.flightState = APOGEE;
            }

        break; 

        case APOGEE:

            data.flightState = DESCENT;

        break;

        case DESCENT:

            if(data.altitude < 5) {
                data.flightState = LANDED;
            }

        break;
    }
}