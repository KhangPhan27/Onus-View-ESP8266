#ifndef UTILS_H
#define UTILS_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
struct Config {
  char ssid[32];
  char password[32];
  char wsParam[32];
};

extern Adafruit_SSD1306 display;
extern WebSocketsClient webSocket;
extern ESP8266WebServer server;
extern Config config;

void loadConfig();
void saveConfig();
void connectToWiFi();
void setupWebSocket();
void handleRoot();
void handleSave();
void showBitmap();
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

#endif 