#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RotaryEncoder.h>

// OLED povezivanje
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

// Encoder povezivanje
#define ENCODER_PIN1 D7
#define ENCODER_PIN2 D6
#define ENCODER_BUTTON D5
RotaryEncoder encoder(ENCODER_PIN1, ENCODER_PIN2);

// WiFi višestruki pristup
ESP8266WiFiMulti wifiMulti;

void setup() {
  Serial.begin(115200);
  Wire.begin(D2, D1); // Inicijalizacija I2C veze za OLED zaslon

  // OLED inicijalizacija
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP8266 OTA");
  display.display();

  // Encoder inicijalizacija
  encoder.setPosition(0);

  // WiFi Manager konfiguracija
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Traženje dostupnih Wi-Fi mreža
  Serial.println("Traženje dostupnih Wi-Fi mreža...");
  display.setCursor(0, 10);
  display.println("Dostupne mreže:");
  display.display();
  int numSsid = WiFi.scanNetworks();
  if (numSsid <= 0) {
    Serial.println("Nema dostupnih Wi-Fi mreža");
    display.setCursor(0, 20);
    display.println("Nema dostupnih mreža");
    display.display();
  } else {
    for (int i = 0; i < numSsid; i++) {
      String ssid = WiFi.SSID(i);
      display.setCursor(0, (i + 2) * 10);
      display.println(ssid);
      display.display();
      Serial.println(ssid);
      delay(10);
    }
  }

  // WiFi Manager konfiguracija
  wifiMulti.addAP("SSID", "PASSWORD");
  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout(60);
  if (!wifiManager.autoConnect("ESP8266 OTA")) {
    Serial.println("WiFi povezivanje nije uspjelo");
    delay(1000);
    ESP.reset();
    delay(5000);
  }
  Serial.println("WiFi povezan");

  // OTA nadogradnja
  ArduinoOTA.setHostname("ESP8266-OTA");
  ArduinoOTA.setPassword("PASSWORD");
  ArduinoOTA.begin();

  // OLED ispis
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("ESP OTA ready");
  display.setCursor(0, 10)
    
    display.println("IP address: ");
  display.println(WiFi.localIP());
  display.display();
}

void loop() {
  ArduinoOTA.handle();

  // Provjera encodera
  encoder.tick();
  int16_t position = encoder.getPosition();

  // Provjera stanja tipke encodera
  if (digitalRead(ENCODER_BUTTON) == LOW) {
    Serial.println("Encoder button pressed");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("ESP OTA update");
    display.display();
    delay(1000);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("ESP OTA running");
    display.display();
    delay(1000);
    ESP.restart();
  }

  // Iscrtavanje na OLED zaslon
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("ESP OTA ready");
  display.setCursor(0, 10);
  display.println("IP address: ");
  display.println(WiFi.localIP());
  display.setCursor(0, 30);
  display.println("Encoder position: ");
  display.println(position);
  display.display();

  delay(10);
}
