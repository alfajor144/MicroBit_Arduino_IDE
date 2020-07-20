/*
   https://github.com/tipih/NRF51_Radio_library
   nesesario: NRF51_Radio_library
*/
#include "NRF51_Radio_library.h"
#include <Adafruit_Microbit.h>
const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
Adafruit_Microbit_Matrix microbit;
NRF51_Radio MicrobitRadio = NRF51_Radio();

FrameBuffer* myDataSendData;
FrameBuffer* myData;

void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  analogWrite(RED,0);
  analogWrite(GREEN,0);
  analogWrite(BLUE,0);
  
  microbit.begin();
  MicrobitRadio.enable();
  MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);

  myDataSendData = new FrameBuffer();

}

void loop() {
  if (MicrobitRadio.dataReady() > 0) {
    myData = MicrobitRadio.recv();
    analogWrite(RED, myData->version);
    analogWrite(GREEN, myData->protocol);
    analogWrite(BLUE, myData->group);
    delay(10);
    delete myData;
  }
}
