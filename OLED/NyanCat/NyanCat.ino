#include "imagenes.h"

void setup() {
  beginOLED();
}
void loop() {
  
  for (int i = -80; i < 80; i=i+3) {
    playNyanCat(i);
    //playFireWorcks(i,0,50);
  }
  
}
