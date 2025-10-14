
#include <Arduino.h>

#define LED1_PIN 18
#define LED2_PIN 19
#define PWM_CH1  0
#define PWM_CH2  1
#define FREQ     5000
#define RES      8

void setup() {
  // Setup both PWM channels
  ledcSetup(PWM_CH1, FREQ, RES);
  ledcSetup(PWM_CH2, FREQ, RES);

  // Attach pins to channels
  ledcAttachPin(LED1_PIN, PWM_CH1);
  ledcAttachPin(LED2_PIN, PWM_CH2);
}

void loop() {
  // Fade In
  for (int d = 0; d <= 255; d++) {
    ledcWrite(PWM_CH1, d);
    ledcWrite(PWM_CH2, d);
    delay(10);
  }

  // Fade Out
  for (int d = 255; d >= 0; d--) {
    ledcWrite(PWM_CH1, d);
    ledcWrite(PWM_CH2, d);
    delay(10);
  }
}
