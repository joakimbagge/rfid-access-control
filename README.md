# RFID Access Control with Arduino

A basic RFID-based access control system using Arduino Uno, MFRC522 RFID reader, servo motor, LEDs, and piezo buzzer.

## Features
- Grants or denies access based on authorized RFID UIDs
- Visual and auditory feedback
- Servo-controlled lock mechanism
- Easy to expand with EEPROM or keypad

## Components
- Arduino Uno
- MFRC522 RFID Reader
- Servo (SM-S2309S)
- Red and Green LEDs
- Piezo buzzer
- Resistors (220Ω for LEDs)

## Wiring
See `/media/fritzing_wiring.png` for schematic.

## How to Use
1. Upload the code in `/src/`
2. Scan RFID cards
3. Modify `validCards` array to whitelist new UIDs

