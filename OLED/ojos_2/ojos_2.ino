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
  for (int j = 0; j < 1; j++) {
    for (int i = 0; i < 10; i++) {
      display.clearDisplay();
      display.drawBitmap(0, 0, uno, 128, 64, WHITE);
      display.display();
      delay(20);

      display.clearDisplay();
      display.drawBitmap(0, 0, dos, 128, 64, WHITE);
      display.display();
      delay(20);

      display.clearDisplay();
      display.drawBitmap(0, 0, tres, 128, 64, WHITE);
      display.display();
      delay(20);
    }

    display.clearDisplay();
    display.drawBitmap(0, 0, blinky, 128, 64, WHITE);
    display.display();
    delay(100);
  }
  display.clearDisplay();
  display.drawBitmap(0, 0, sonr, 128, 64, WHITE);
  display.display();
  delay(2000);
}
