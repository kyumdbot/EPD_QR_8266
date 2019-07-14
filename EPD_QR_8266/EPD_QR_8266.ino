#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LOLIN_EPD.h>
#include <Adafruit_GFX.h>
#include <qrcode.h>
#include "html_str.h"

const char* ssid     = "EPD_SETUP_AP_8266";
const char* password = "pw112233";

ESP8266WebServer server(80);

/*D1 mini*/
#define EPD_CS D0
#define EPD_DC D8
#define EPD_RST -1  // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY -1 // can set to -1 to not use a pin (will wait a fixed delay)

LOLIN_IL3897 EPD(250, 122, EPD_DC, EPD_RST, EPD_CS, EPD_BUSY); //hardware SPI



void setup(void) {
  Serial.begin(115200);
  Serial.print("Hello! EPD");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.println(IP);

  
  server.on("/", []() {
    server.send(200, "text/html", homepage_html);
  });
  
  server.on("/website", []() {
    String qr_str = server.arg("url");
    String displaytype_str = server.arg("displaytype");
    bool isDisplaytype = displaytype_str.equals("yes") ? true : false;
    
    draw_qrcode(EPD_BLACK, EPD_WHITE, qr_str, isDisplaytype, "Link");
    server.send(200, "text/plain", "ok");
  });

  server.on("/wifi", []() {
    String qr_str = "WIFI:T:" + server.arg("auth_type") + ";S:" + server.arg("ssid") + ";P:" + server.arg("passwd") + ";;";
    String displaytype_str = server.arg("displaytype");
    bool isDisplaytype = displaytype_str.equals("yes") ? true : false;
    
    draw_qrcode(EPD_BLACK, EPD_WHITE, qr_str, isDisplaytype, "Wifi");
    server.send(200, "text/plain", "ok");
  });

  server.on("/plaintext", []() {
    String qr_str = server.arg("content");
    String displaytype_str = server.arg("displaytype");
    bool isDisplaytype = displaytype_str.equals("yes") ? true : false;
    
    draw_qrcode(EPD_BLACK, EPD_WHITE, qr_str, isDisplaytype, "Text");
    server.send(200, "text/plain", "ok");
  });
  
  server.begin();
  
  
  EPD.begin();
  Serial.println("Initialized");

  draw_text(IP.toString());
  Serial.println("done");
}

void loop() {
  server.handleClient();
}

// Draw Text
void draw_text(String text) {
  EPD.clearBuffer();
  EPD.fillScreen(EPD_WHITE);
  EPD.setTextColor(EPD_BLACK);
  EPD.setTextSize(2);
  EPD.print(text);
  EPD.display();
}

// Draw QRCode
void draw_qrcode(uint16_t color1, uint16_t color2, String qr_string, bool isDisplayType, String type_string) {
  EPD.clearBuffer();
  EPD.fillScreen(EPD_WHITE);
  
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(4)];
  qrcode_initText(&qrcode, qrcodeData, 4, ECC_MEDIUM, qr_string.c_str());

  int offset_x = 74;
  int offset_y = 11;
  int p_width  = 3;
  
  if (isDisplayType) {
    offset_x = 20;
  }

  for (int y = 0; y < qrcode.size; y++) {
    for (int x = 0; x < qrcode.size; x++) {
      int new_x = offset_x + (x * p_width);
      int new_y = offset_y + (y * p_width);
      
      if (qrcode_getModule(&qrcode, x, y)) {
          EPD.fillRect( new_x, new_y, p_width, p_width, color1);
      } else {
          EPD.fillRect( new_x, new_y, p_width, p_width, color2);
      }
    }
  }

  if (isDisplayType) {
    EPD.setTextColor(color1);
    EPD.setTextSize(2);
    EPD.setCursor(165, 52);
    EPD.print(type_string);
  }
  
  EPD.display();
}
