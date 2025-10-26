#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("OLED init failed"));
    for (;;);
  }

  oled.clearDisplay();

  // --------- Simple Emoji (Smiley Face) ---------

  // Head (big circle)
  oled.drawCircle(64, 32, 20, SSD1306_WHITE); // face circle

  // Eyes (filled small circles)
  oled.fillCircle(56, 26, 2, SSD1306_WHITE); // left eye
  oled.fillCircle(72, 26, 2, SSD1306_WHITE); // right eye

  // Smile (arc made with pixels)
  oled.drawPixel(54, 36, SSD1306_WHITE);
  oled.drawPixel(56, 38, SSD1306_WHITE);
  oled.drawPixel(58, 39, SSD1306_WHITE);
  oled.drawPixel(60, 40, SSD1306_WHITE);
  oled.drawPixel(62, 40, SSD1306_WHITE);
  oled.drawPixel(64, 40, SSD1306_WHITE);
  oled.drawPixel(66, 39, SSD1306_WHITE);
  oled.drawPixel(68, 38, SSD1306_WHITE);
  oled.drawPixel(70, 36, SSD1306_WHITE);

  // Optional: Add caption
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(40, 56);
  oled.println(":)");

  oled.display();
}

void loop() {
  // static emoji
}