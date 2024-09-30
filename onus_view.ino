#include "utils.h"

void setup() {
  Serial.begin(115200);
  EEPROM.begin(sizeof(Config));
  Wire.begin(0, 2);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  // Load configuration
  loadConfig();
  // Set up Access Point
  WiFi.softAP("ESP8266-Config", "12345678az");
  server.on("/", handleRoot);
  server.on("/save", handleSave);
  server.begin();

  display.setCursor(0, 0);
  display.println("AP: ESP8266-Config");
  display.println("IP: 192.168.4.1");
  display.display();
}

void loop() {
  server.handleClient();
  if (WiFi.status() == WL_CONNECTED) {
    webSocket.loop();
  }
}