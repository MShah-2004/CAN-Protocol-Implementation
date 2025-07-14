# CAN-Protocol-Implementation
This project demonstrates the implementation of the Controller Area Network (CAN) protocol using two Arduino Uno boards. It allows serial data transmission from a transmitter Arduino and displays the received data on a 16x2 LCD at the receiver end.

# Overview
The CAN protocol is widely used in automotive and industrial embedded systems for robust, reliable, and fault-tolerant communication. Here, we use:  
  * Arduino Uno boards as controllers  
  * MCP2515 CAN controllers and MCP2551 transceivers for CAN communication  
  * A 16x2 LCD display for output at the receiver

This repository contains:  
  * Arduino code for Transmitter and Receiver  
  * Circuit diagrams and connection details  
  * A PDF report explaining the implementation

# Components Used
  * Arduino Uno (x2)  
  * MCP2515 CAN module (x2)  
  * 16x2 LCD Display (non-I2C)
  * Jumper wires and breadboard
  * 5V power supply

# How It Works
  The Transmitter Arduino takes data from the serial monitor and sends it over the CAN bus using the MCP2515 module.
  The Receiver Arduino receives the CAN message and displays it on the 16x2 LCD.

# Connections
  * Transmitter Arduino ↔ MCP2515: SPI communication (CS, MOSI, MISO, SCK)
  * Receiver Arduino ↔ MCP2515: Same as above
  * Receiver Arduino ↔ LCD: Parallel communication (RS, EN, D4–D7 pins)

# How to Run
  * Upload transmitter.ino to the Transmitter Arduino.
  * Upload receiver.ino to the Receiver Arduino.
  * Open the Serial Monitor for the transmitter and send a message.
  * The message appears on the LCD connected to the receiver.
