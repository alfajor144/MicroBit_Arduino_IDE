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
  for(int i = 0; i>-126;i=i-3){
    display.clearDisplay();
    display.drawBitmap(i, 0, nuves, 256, 32, WHITE);
    display.drawBitmap(40, 0, avion, 32, 32, WHITE);
    display.drawBitmap(0, 0, cuadro, 128, 32, WHITE);
    display.display();
    delay(1);
  }
}
