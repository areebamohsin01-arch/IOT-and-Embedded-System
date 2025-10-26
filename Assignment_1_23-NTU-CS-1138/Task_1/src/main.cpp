/*
  Project Title: OLED + LED + Buzzer Mode Controller
  Author: Areeba Mohsin | Reg: 23-NTU-CS-1138 (CS-5th B)
  Date: 26-Oct-2025
*/

#include <Arduino.h>
#include <Wire.hp
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- Pin Configuration ----------
#define LED_ONE   2
#define LED_TWO   4
#define LED_FADE  5
#define BTN_MODE  25
#define BTN_CLR   27
#define BUZZER    15

// ---------- OLED Setup ----------
Adafruit_SSD1306 oled(128, 64, &Wire, -1);

// ---------- Global Variables ----------
int currentMode = 0;         
unsigned long lastBlink = 0;
bool toggleLED = false;

// ---------- OLED Text Function ----------
void displayMode(String text) {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(10, 25);
  oled.print("Mode :  ");
  oled.println(text);
  oled.display();
}

// ---------- Buzzer Tone Function ----------
void buzz(int freq, int dur) {
  tone(BUZZER, freq, dur);
  delay(dur + 40);
  noTone(BUZZER);
}

// ---------- Setup ----------
void setup() {
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(LED_FADE, OUTPUT);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_CLR, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.display();

  displayMode("Start | LEDs OFF");
}

// ---------- Main Loop ----------
void loop() {
  // --- Mode Button Logic ---
  if (digitalRead(BTN_MODE) == LOW) {
    delay(200);
    currentMode++;
    if (currentMode > 4) currentMode = 1;

    switch (currentMode) {
      case 1:
        digitalWrite(LED_ONE, LOW);
        digitalWrite(LED_TWO, LOW);
        displayMode("All OFF");
        buzz(800, 100);
        break;

      case 2:
        displayMode("Alternate Blink");
        buzz(950, 100);
        break;

      case 3:
        digitalWrite(LED_ONE, HIGH);
        digitalWrite(LED_TWO, HIGH);
        displayMode("All ON");
        buzz(1150, 100);
        break;

      case 4:
        displayMode("PWM Fade Mode");
        buzz(1400, 100);
        break;
    }
  }

  // --- Reset Button Logic ---
  if (digitalRead(BTN_CLR) == LOW) {
    delay(200);
    currentMode = 1;
    digitalWrite(LED_ONE, LOW);
    digitalWrite(LED_TWO, LOW);
    analogWrite(LED_FADE, 0);
    displayMode("Reset → OFF");
    buzz(500, 200);
  }

  // --- Alternate Blink ---
  if (currentMode == 2) {
    if (millis() - lastBlink >= 500) {
      lastBlink = millis();
      toggleLED = !toggleLED;
      digitalWrite(LED_ONE, toggleLED);
      digitalWrite(LED_TWO, !toggleLED);
    }
  }

  // --- PWM Fade Effect ---
  if (currentMode == 4) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(LED_FADE, i);
      delay(5);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(LED_FADE, i);
      delay(5);
    }
  }
}
