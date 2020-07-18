/*
 * https://github.com/tipih/NRF51_Radio_library
 * nesesario: NRF51_Radio_library
*/
#include "NRF51_Radio_library.h"
#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix microbit;
NRF51_Radio MicrobitRadio = NRF51_Radio();

FrameBuffer* myDataSendData;
FrameBuffer* myData;

void setup() {
  Serial.begin(115200);
  
  microbit.begin();
  MicrobitRadio.enable();
  MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);

  myDataSendData = new FrameBuffer();

}

void loop() {
  if (MicrobitRadio.dataReady() > 0) {
    myData = MicrobitRadio.recv();

    if (myData->group == 1) {
      microbit.print("A");
      delay(100);
    }
    if (myData->group == 0) {
      microbit.clear();
      delay(100);
    }
    delete myData;
  }
}
