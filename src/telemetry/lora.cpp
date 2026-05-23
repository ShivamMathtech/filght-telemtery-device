#include "lora.h"

#include <SPI.h>
#include <LoRa.h>

#include "pins.h"
#include "config.h"

void initLoRa() {

    LoRa.setPins(
        LORA_CS,
        LORA_RST,
        LORA_DIO0
    );
     if(!LoRa.begin(LORA_FREQUENCY)) {

        Serial.println("LoRa Init Failed");
    }
}
void sendTelemetry(TelemetryData &data) {

    LoRa.beginPacket();

    LoRa.write((uint8_t*)&data,
                sizeof(data));

    LoRa.endPacket();
}