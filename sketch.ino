#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic sensor pins
#define TRIG_PIN 2
#define ECHO_PIN 3

// Servo
Servo lidServo;

// Bin parameters
#define BIN_EMPTY_DIST 30   // cm
#define BIN_FULL_DIST 5     // cm

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(10);
  lidServo.write(0);  // Start closed

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Dustbin");
  lcd.setCursor(0, 1);
  lcd.print("Using IoT");

  Serial.begin(9600);
  delay(2000);
  lcd.clear();
}

void loop() {
  long distance = getDistance();
  Serial.print("Hand Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Lid open/close based on hand detection
  if (distance < 15) {
    lidServo.write(90); // Open lid
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lid Open");
    delay(3000);
    lidServo.write(0);  // Close lid
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lid Closed");
    delay(1000);
  }

  // Measure bin fill level
  long levelDistance = getDistance();
  Serial.print("Level Distance: ");
  Serial.print(levelDistance);
  Serial.println(" cm");

  int fillPercent;
  if (levelDistance <= BIN_FULL_DIST) {
    fillPercent = 100;
  } else if (levelDistance >= BIN_EMPTY_DIST) {
    fillPercent = 0;
  } else {
    fillPercent = map(BIN_EMPTY_DIST - levelDistance, 0, BIN_EMPTY_DIST - BIN_FULL_DIST, 0, 100);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bin Fill Level:");
  lcd.setCursor(0, 1);
  lcd.print(fillPercent);
  lcd.print("%");

  delay(1000);
}
