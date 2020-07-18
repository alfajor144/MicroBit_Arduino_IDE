#include "imagenes.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
//Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.setTextColor(WHITE);
}
void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.drawBitmap(0, 0, ojos, 128, 64, WHITE);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.drawBitmap(0, 0, blinky, 128, 64, WHITE);
  display.display();
  delay(100);
}
