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
See `/media/wiring.png` for schematic.

## Pinout table
| Component    | Function                 | Arduino Pin          | Notes                                     |
| ------------ | ------------------------ | -------------------- | ----------------------------------------- |
| RC522 RFID   | RST (Reset)              | 9                    | Defined as `RST_PIN`                      |
| RC522 RFID   | SDA (SS/CS)              | 10                   | Defined as `SS_PIN` – Chip Select         |
| RC522 RFID   | MOSI                     | 11 (Uno) / 51 (Mega) | SPI communication      |
| RC522 RFID   | MISO                     | 12 (Uno) / 50 (Mega) | SPI communication      |
| RC522 RFID   | SCK                      | 13 (Uno) / 52 (Mega) | SPI communication      |
| Servo Motor  | PWM Signal               | 6                    | Defined as `SERVO_PIN`                    |
| Green LED    | Access granted indicator | 4                    | Defined as `GREEN_LED`                    |
| Red LED      | Access denied indicator  | 5                    | Defined as `RED_LED`                      |
| Piezo Buzzer | Audio feedback           | 3                    | Defined as `PIEZO_PIN`                    |
| Power        | VCC and GND              | 5V / GND             | Ground for components |

## How to Use
1. Upload the code in `/src/`
2. Scan RFID cards
3. Modify `validCards` array to whitelist new UIDs

