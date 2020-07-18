#include "imagenes.h"

const int buttonA = 5;
const int buttonB = 11;

void setup() {
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  beginOled();
}
void loop() {  
  if (!digitalRead(buttonA)) {
     blinkL();
  }
  if (! digitalRead(buttonB)) {
    blinkR();
  }

  if ( digitalRead(buttonB)  && digitalRead(buttonA)) {
    playOjos();
    //blinkBoth();
  }
}
