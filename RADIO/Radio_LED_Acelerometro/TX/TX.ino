/*
   https://github.com/tipih/NRF51_Radio_library
   nesesario: NRF51_Radio_library
*/
#include "NRF51_Radio_library.h"
#include <Adafruit_Microbit.h>
#include <LSM303AGR_ACC_Sensor.h>
#include <LSM303AGR_MAG_Sensor.h>
#if defined(ARDUINO_SAM_DUE)
#define DEV_I2C Wire1   //Define which I2C bus is used. Wire1 for the Arduino Due
#define SerialPort Serial
#else
#define DEV_I2C Wire    //Or Wire
#define SerialPort Serial
#endif
Adafruit_Microbit_Matrix microbit;
NRF51_Radio MicrobitRadio = NRF51_Radio();

LSM303AGR_ACC_Sensor *Acc;
LSM303AGR_MAG_Sensor *Mag;
FrameBuffer* myDataSendData;
FrameBuffer* myData;

void setup() {
  Serial.begin(115200);
  DEV_I2C.begin();
  microbit.begin();
  MicrobitRadio.enable();
  MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);
  Acc = new LSM303AGR_ACC_Sensor(&DEV_I2C);
  Acc->Enable();
  Acc->EnableTemperatureSensor();
  Mag = new LSM303AGR_MAG_Sensor(&DEV_I2C);
  Mag->Enable();
  myDataSendData = new FrameBuffer();
}

void loop() {
  
  int32_t accelerometer[3];
  Acc->GetAxes(accelerometer);
  float temperature;
  Acc->GetTemperature(&temperature);
  int32_t magnetometer[3];
  Mag->GetAxes(magnetometer);
/*
  SerialPort.print("| Acc[mg]: ");
  SerialPort.print(accelerometer[0]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[1]);
  SerialPort.print(" ");
  SerialPort.print(accelerometer[2]);
  SerialPort.print(" | Mag[mGauss]: ");
  SerialPort.print(magnetometer[0]);
  SerialPort.print(" ");
  SerialPort.print(magnetometer[1]);
  SerialPort.print(" ");
  SerialPort.print(magnetometer[2]);
  SerialPort.print(" | Temp[C]: ");
  SerialPort.print(temperature, 2);
  SerialPort.println(" |");
*/
  myDataSendData->length = 3;
  myDataSendData->version = map(accelerometer[0],-1040,1040,0,255);
  myDataSendData->protocol = map(accelerometer[1],-1040,1040,0,255);
  myDataSendData->group = map(accelerometer[2],-1040,1040,0,255);
  
  MicrobitRadio.send(myDataSendData);
  
  delay(100);

}
