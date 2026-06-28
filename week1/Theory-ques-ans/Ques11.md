# IoT Architecture
 
A typical IoT system is organized into **4 layers**, with data flowing upward from physical sensors to the end-user application.
 
```
 ┌─────────────────────────────────────┐
 │          Application Layer          │  <- Mobile app / dashboard
 └───────────────────▲───────────────────┘
                      │
 ┌───────────────────┴───────────────────┐
 │          Processing Layer           │  <- Cloud server (AWS IoT)
 └───────────────────▲───────────────────┘
                      │
 ┌───────────────────┴───────────────────┐
 │           Network Layer             │  <- Wi-Fi module (ESP8266)
 └───────────────────▲───────────────────┘
                      │
 ┌───────────────────┴───────────────────┐
 │          Perception Layer           │  <- DHT11 temperature sensor
 └─────────────────────────────────────┘
```
 
## Layer descriptions
 
| Layer | Function | Example device/technology |
|---|---|---|
| **Perception Layer** | Senses the physical world and collects raw data (temperature, motion, light, etc.) | DHT11 temperature & humidity sensor |
| **Network Layer** | Transmits collected data from devices to processing systems | Wi-Fi module (ESP8266) using MQTT/HTTP |
| **Processing Layer** | Stores, analyzes, and processes the incoming data | Cloud server (e.g. AWS IoT Core) |
| **Application Layer** | Presents processed data/insights to the end user and enables control | Mobile app / web dashboard |
 
**Data flow:** Perception → Network → Processing → Application
