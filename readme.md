````md
# RocketTelemetry

Professional ESP32-Based Rocket Telemetry and Flight Computer System

Developed by Shivam Singh — Founder of MathTech

---

#Overview

RocketTelemetry is a professional-grade modular avionics firmware system designed for high-power model rockets using ESP32.

The system supports:

- Real-time LoRa telemetry
- GPS tracking
- Flight-state detection
- SD card flight logging
- IMU orientation sensing
- Altitude calculation
- OLED telemetry display
- Dual pyro deployment
- Ground-station communication

---

#  Features

## Real-Time Telemetry

- Long-range LoRa communication
- Live telemetry transmission
- Ground-station compatible
- RSSI monitoring

## Flight Computer

- Launch detection
- Flight-state machine
- Apogee detection
- Main parachute deployment
- Altitude tracking
- Velocity calculation

## Flight Logging

- CSV data logging
- SD card storage
- Timestamped telemetry
- Blackbox-style recording

##Recovery System

- Drogue deployment
- Main parachute deployment
- MOSFET pyro control
- Safe deployment logic

---

# Hardware Components

| Component      | Description             |
| -------------- | ----------------------- |
| ESP32 DevKit   | Main flight computer    |
| BNO055         | IMU orientation sensor  |
| MS5611         | Precision altimeter     |
| NEO-M8N GPS    | GPS tracking module     |
| SX1278 LoRa    | Long-range telemetry    |
| SSD1306 OLED   | Telemetry display       |
| SD Card Module | Flight data logger      |
| LiPo Battery   | Power system            |
| MOSFET Drivers | Pyro deployment control |

---

# Project Structure

```text
RocketTelemetry/
│
├── platformio.ini
│
├── include/
│   ├── config.h
│   ├── pins.h
│   ├── telemetry.h
│   ├── flight_states.h
│   └── structs.h
│
├── src/
│   ├── main.cpp
│   │
│   ├── sensors/
│   │   ├── imu.cpp
│   │   ├── imu.h
│   │   ├── altimeter.cpp
│   │   ├── altimeter.h
│   │   ├── gps.cpp
│   │   ├── gps.h
│   │   ├── battery.cpp
│   │   └── battery.h
│   │
│   ├── telemetry/
│   │   ├── lora.cpp
│   │   ├── lora.h
│   │   ├── packet.cpp
│   │   └── packet.h
│   │
│   ├── storage/
│   │   ├── sdlogger.cpp
│   │   └── sdlogger.h
│   │
│   ├── flight/
│   │   ├── state_machine.cpp
│   │   ├── state_machine.h
│   │   ├── apogee.cpp
│   │   ├── apogee.h
│   │   ├── pyro.cpp
│   │   └── pyro.h
│   │
│   ├── utils/
│   │   ├── filters.cpp
│   │   ├── filters.h
│   │   ├── watchdog.cpp
│   │   └── watchdog.h
│   │
│   └── ui/
│       ├── oled.cpp
│       └── oled.h
│
└── data/
    └── calibration.json
```

---

# Pin Configuration

##LoRa SX1278

| SX1278 | ESP32  |
| ------ | ------ |
| NSS    | GPIO5  |
| RST    | GPIO14 |
| DIO0   | GPIO26 |
| SCK    | GPIO18 |
| MISO   | GPIO19 |
| MOSI   | GPIO23 |

---

##GPS NEO-M8N

| GPS | ESP32  |
| --- | ------ |
| TX  | GPIO16 |
| RX  | GPIO17 |

---

## I2C Sensors

| Device | ESP32  |
| ------ | ------ |
| SDA    | GPIO21 |
| SCL    | GPIO22 |

---

## Pyro Channels

| Function      | ESP32  |
| ------------- | ------ |
| Drogue Deploy | GPIO32 |
| Main Deploy   | GPIO33 |

---

# 📡 Telemetry Packet Structure

```cpp
struct TelemetryData {

    float altitude;
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
```

---

# 🚀 Flight States

```text
IDLE
ARMED
BOOST
COAST
APOGEE
DESCENT
LANDED
```

---

# 🛠️ Installation

## 1. Install PlatformIO

Install:

- VSCode
- PlatformIO Extension

---

## 2. Clone Repository

```bash
git clone https://github.com/ShivamMathtech/filght-telemtery-device
```

---

## 3. Open Project

Open the folder inside VSCode using PlatformIO.

---

## 4. Build Firmware

```bash
pio run
```

---

## 5. Upload Firmware

```bash
pio run --target upload
```

---

## 6. Open Serial Monitor

```bash
pio device monitor
```

---

# 📚 Required Libraries

```ini
adafruit/Adafruit BNO055
mikalhart/TinyGPSPlus
sandeepmistry/LoRa
adafruit/Adafruit SSD1306
adafruit/Adafruit GFX Library
```

---

# 🔋 Power System

Recommended Power Setup:

| Rail      | Purpose                |
| --------- | ---------------------- |
| 7.4V LiPo | Pyro channels          |
| 5V        | GPS module             |
| 3.3V      | ESP32 + Sensors + LoRa |

---

# 🧠 Future Upgrades

## Suggested Enhancements

- Kalman filtering
- FreeRTOS multitasking
- Redundant altimeters
- Flash blackbox
- Web telemetry dashboard
- Ground-station GUI
- CAN bus avionics
- OTA firmware updates

---

# 📈 Recommended Loop Rates

| System     | Rate   |
| ---------- | ------ |
| IMU        | 100 Hz |
| Altimeter  | 50 Hz  |
| GPS        | 10 Hz  |
| LoRa TX    | 5 Hz   |
| SD Logging | 20 Hz  |

---

# 🛡️ Safety Notes

⚠️ Important:

- Always test pyro outputs with LEDs before igniters
- Use proper MOSFET isolation
- Verify continuity before launch
- Never arm rocket indoors
- Test deployment systems separately

---

# 🧪 Testing Procedure

## Ground Test

- Sensor calibration
- GPS lock verification
- LoRa communication test
- SD card logging verification

## Static Test

- Launch detection simulation
- Pyro deployment simulation
- Recovery system verification

## Flight Test

- Low-altitude launch first
- Verify telemetry range
- Verify deployment logic

---

# 👨‍💻 Developed By

Shivam Singh  
Founder — MathTech

🚀 Innovating With Passion

---
````
