#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Settings ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "192.168.1.11"; // Apna IP yahan likhein

const int DHT_PIN = 23; // Aapke JSON ke mutabiq D23
const int BTN_PIN = 5;  // Aapke JSON ke mutabiq D5

DHTesp dht;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
    pinMode(BTN_PIN, INPUT_PULLUP);

    // OLED Setup
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
    }
    display.clearDisplay();
    display.setTextColor(WHITE);

    // Sensor & WiFi Setup
    dht.setup(DHT_PIN, DHTesp::DHT22);
    WiFi.begin(ssid, password);
    client.setServer(mqtt_server, 1883);
}

void loop() {
    if (!client.connected()) {
        if (client.connect("esp32_lab1_001")) {
            Serial.println("MQTT Connected");
        }
    }
    client.loop();

    TempAndHumidity data = dht.getTempAndHumidity();

    // MQTT Publish
    client.publish("home/lab1/temp", String(data.temperature).c_str());
    
    // OLED Display
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("MQTT Lab 1");
    display.printf("Temp: %.1f C\n", data.temperature);
    display.printf("Hum: %.1f %%\n", data.humidity);
    
    // Button Check
    if(digitalRead(BTN_PIN) == LOW) {
        display.println("Button: Pressed!");
        client.publish("home/lab1/button", "Pressed");
    }
    
    display.display();
    delay(2000);
}