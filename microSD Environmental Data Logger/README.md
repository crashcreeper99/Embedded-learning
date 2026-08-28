# microSD Environmental Data Logger

## Overview
This project uses an ESP32, DHT22 sensor, and microSD storage to record temperature and humidity measurements over time. Instead of measurements disappearing after they are displayed, the ESP32 saves them to a file that can be reviewed later.

## Components
- ESP32 DevKit V1
- DHT22 temperature/humidity sensor
- microSD card module
- microSD card
- Breadboard
- Jumper wires

## Core Concepts
- Environmental sensing
- SPI communication
- File creation and appending
- Persistent storage
- CSV/data logging
- Periodic sampling

## How It Works
1. The ESP32 initializes the DHT22 and microSD card.
2. Temperature and humidity are measured at a fixed interval.
3. The ESP32 opens or creates a log file on the card.
4. Each reading is appended as a new line.
5. The file can later be opened on a computer for analysis.

## Suggested Data Format
`sample,temperature_c,humidity_percent`

## Testing
- Verify that the microSD card initializes.
- Confirm valid DHT22 readings in Serial Monitor.
- Allow several samples to be recorded.
- Remove the card after safely powering down the circuit.
- Open the log file and confirm that multiple readings were saved.

## What I Learned
This project introduced persistent data acquisition. It connects sensor reading with storage, which is an important step toward real monitoring and engineering data-collection systems.

## Future Improvements
- Add DS1307 timestamps.
- Add soil moisture or light measurements.
- Create downloadable logs over Wi-Fi.
- Graph the stored data.
- Add automatic file rotation.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
