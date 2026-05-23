#include "oled.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"

Adafruit_SSD1306 display(
    OLED_WIDTH,
    OLED_HEIGHT,
    &Wire,
    -1
);
void initOLED() {

    display.begin(
        SSD1306_SWITCHCAPVCC,
        0x3C
    );

    display.clearDisplay();
}

void updateOLED(TelemetryData &data) {

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setCursor(0,0);
    display.print("ALT: ");
    display.println(data.altitude);

    display.print("VEL: ");
    display.println(data.velocity);

    display.print("BAT: ");
    display.println(data.batteryVoltage);

    display.print("SAT: ");
    display.println(data.satellites);

    display.display();
}