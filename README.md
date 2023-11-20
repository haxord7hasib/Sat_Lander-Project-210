
# Wireless MPU6050 Data Transmission using Arduino and nRF24L01

This project demonstrates how to transmit MPU6050 sensor data wirelessly using Arduino Mega mini and nRF24L01 modules.

## Components
- 2x Arduino Mega mini
- 2x nRF24L01 Wireless Transceiver Modules
- 1x MPU6050 Gyroscope and Accelerometer Sensor
- Jumper Wires
- Voltage Regulator (for MPU6050)

## Circuit Connections

### Transmitter Setup
- **Arduino Mega mini to MPU6050:**
  - VCC to 5V (use a voltage regulator to step down to 3.3V)
  - GND to GND
  - SDA to SDA (Pin 20)
  - SCL to SCL (Pin 21)

- **Arduino Mega mini to nRF24L01:**
  - VCC to 3.3V
  - GND to GND
  - CE to Digital Pin 7
  - CSN to Digital Pin 8
  - SCK to SCK (Pin 52)
  - MOSI to MOSI (Pin 51)
  - MISO to MISO (Pin 50)
  - IRQ (not connected)

### Receiver Setup
- **Arduino Mega mini to nRF24L01:**
  - VCC to 3.3V
  - GND to GND
  - CE to Digital Pin 7
  - CSN to Digital Pin 8
  - SCK to SCK (Pin 52)
  - MOSI to MOSI (Pin 51)
  - MISO to MISO (Pin 50)
  - IRQ (not connected)

## Code
- The Arduino sketches for both the transmitter and receiver can be found in the repository.

## Setup and Testing
- Follow the circuit connections to set up the transmitter and receiver.
- Upload the respective Arduino sketches to each Arduino Mega mini.
- Power on the systems and open the Serial Monitor on the receiver's Arduino IDE to view the transmitted MPU6050 sensor data.
