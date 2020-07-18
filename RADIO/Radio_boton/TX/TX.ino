/*
 * https://github.com/tipih/NRF51_Radio_library
 * nesesario: NRF51_Radio_library
*/
#include "NRF51_Radio_library.h"
#include <Adafruit_Microbit.h>
Adafruit_Microbit_Matrix microbit;
NRF51_Radio MicrobitRadio = NRF51_Radio();

const int buttonA = 5; 
const int buttonB = 11; 

FrameBuffer* myDataSendData;
FrameBuffer* myData;

void setup() {
  Serial.begin(115200);

  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);

  microbit.begin();
  MicrobitRadio.enable();
  MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);

  myDataSendData = new FrameBuffer();
}

void loop() {

  myDataSendData->length = 3;
  myDataSendData->version = 10;
  myDataSendData->protocol = 10;

  if (! digitalRead(buttonA)) {
    microbit.print("A");
    myDataSendData->group = 1;
    MicrobitRadio.send(myDataSendData);
    delay(100);
  }

  if (! digitalRead(buttonB)) {
    microbit.clear();
    myDataSendData->group = 0;
    MicrobitRadio.send(myDataSendData);
    delay(100);
  }
  

  delay(1);

}
