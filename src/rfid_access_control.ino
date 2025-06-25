#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define GREEN_LED 4
#define RED_LED 5
#define PIEZO_PIN 3
#define SERVO_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servo;

// List of valid UIDs
byte validCards[][4] = {
  {0xDE, 0xAD, 0xBE, 0xEF},
  {0x12, 0x34, 0x56, 0x78},
  {0xCA, 0x19, 0xD9, 0x05}
};
const int numValidCards = sizeof(validCards) / sizeof(validCards[0]);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0);

  Serial.println("System ready. Scan your card.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("Card UID: ");

  if (isAuthorized(mfrc522.uid.uidByte)) {
    grantAccess();
  } else {
    denyAccess();
  }

  mfrc522.PICC_HaltA();
  delay(1000); 
}

bool isAuthorized(byte *uid) {
  for (int i = 0; i < numValidCards; i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (validCards[i][j] != uid[j]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  return false;
}

void grantAccess() {
  Serial.println("Access granted.");
  digitalWrite(GREEN_LED, HIGH);
  tone(PIEZO_PIN, 1000, 200);
  servo.write(90);
  delay(3000);
  servo.write(0); 
  digitalWrite(GREEN_LED, LOW);
}

void denyAccess() {
  Serial.println("Access denied.");
  digitalWrite(RED_LED, HIGH);
  tone(PIEZO_PIN, 300, 500);
  delay(500);
  digitalWrite(RED_LED, LOW);
}
