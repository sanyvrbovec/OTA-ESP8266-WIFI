# OTA-ESP8266-WIFI by Nenad Dobrijevic - SanyVrbovec

# README.md (Croatian)

Ovaj program omogućava OTA (Over-The-Air) nadogradnju na ESP8266 mikrokontroleru uz podršku WiFi mreže i koristi se zajedno s OLED zaslonom i Rotary Encoderom.

## Biblioteke

Program koristi sljedeće biblioteke:

- ESP8266WiFi.h
- ESP8266mDNS.h
- WiFiUdp.h
- ArduinoOTA.h
- Wire.h
- Adafruit_GFX.h
- Adafruit_SSD1306.h
- RotaryEncoder.h

## Povezivanje

OLED povezivanje:

- RESET pin OLED zaslona je povezan na pin D4 (GPIO 4) na ESP8266.
- OLED I2C adresa je 0x3C.

Encoder povezivanje:

- Pin 1 (A) enkodera je povezan na pin D7 (GPIO 13) na ESP8266.
- Pin 2 (B) enkodera je povezan na pin D6 (GPIO 12) na ESP8266.
- Button enkodera je povezan na pin D5 (GPIO 14) na ESP8266.

## Postavljanje

U `setup()` funkciji programa obavljaju se sljedeće radnje:

1. Inicijalizacija serijske komunikacije na brzini 115200.
2. Inicijalizacija I2C veze za OLED zaslon.
3. Inicijalizacija OLED zaslona.
4. Postavljanje početnog položaja enkodera na 0.
5. Konfiguracija WiFi Managera.
6. Traženje dostupnih Wi-Fi mreža.
7. Povezivanje na WiFi mrežu ili pokretanje konfiguracijskog portala ako nije moguće uspostaviti vezu.
8. Postavljanje OTA nadogradnje.
9. Ispis informacija na OLED zaslonu.

## Glavna petlja

U `loop()` funkciji programa obavljaju se sljedeće radnje:

1. Provjera OTA nadogradnje.
2. Provjera stanja tipke enkodera.
3. Iscrtavanje informacija na OLED zaslonu.

## Contributing

Ako želite doprinijeti ovom projektu, slobodno otvorite "issue" ili pošaljite "pull request".

---

# README.md (English)

This program enables OTA (Over-The-Air) updates on the ESP8266 microcontroller with WiFi network support. It is designed to work with an OLED display and a Rotary Encoder.

## Libraries

The program utilizes the following libraries:

- ESP8266WiFi.h
- ESP8266mDNS.h
- WiFiUdp.h
- ArduinoOTA.h
- Wire.h
- Adafruit_GFX.h
- Adafruit_SSD1306.h
- RotaryEncoder.h

## Connections

OLED connections:

- The RESET pin of the OLED display is connected to pin D4 (GPIO 4) on the ESP8266.
- The OLED I2C address is 0x3C.

Encoder connections:

- Pin 1 (A) of the encoder is connected to pin D7 (GPIO 13) on the ESP8266.
- Pin 2 (B) of the encoder is connected to pin D6 (GPIO 12) on the ESP8266.
- The button of the encoder is connected to pin D5 (GPIO 14) on the ESP8266.

## Setup

In the `setup()` function of the program, the following actions are performed:

1. Serial communication is initialized at a baud rate of 115200.
2. I2C connection for the OLED display is established.
3. The OLED display is initialized.
4. The initial position of the encoder is set to 0.
5. WiFi Manager configuration is applied.
6. Available Wi-Fi networks are scanned.
7. If no Wi-Fi networks are found, a message is displayed on the OLED screen.
8. If Wi-Fi networks are found, their SSID names are displayed on the OLED screen.
9. WiFi connection is established or the configuration portal is started if connection fails.
10. OTA (Over-The-Air) update is set up.
11. Information is displayed on the OLED screen.

## Main Loop

In the `loop()` function of the program, the following actions are performed:

1. OTA update is checked.
2. Encoder button state is checked.
3. Information is displayed on the OLED screen.

## Contributing

If you would like to contribute to this project, feel free to open an issue or submit a pull request.
