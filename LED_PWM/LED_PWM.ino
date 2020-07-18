#include <Adafruit_Microbit.h>

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;
//0,1,2 unicamente

Adafruit_Microbit_Matrix microbit;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  microbit.begin();
}
void fadeInOut(int color) {
  for (int i = 0; i < 255; i++) {
    analogWrite(color, i);
    delay(1);
  }
  for (int i = 256; i >= 0 ; i--) {
    analogWrite(color, i);
    delay(1);
  }
}
void fadeInOut(int color,int color2) {
  for (int i = 0; i < 255; i++) {
    analogWrite(color, i);
    analogWrite(color2, i);
    delay(1);
  }
  for (int i = 256; i >= 0 ; i--) {
    analogWrite(color, i);
    analogWrite(color2, i);
    delay(1);
  }
}
void fadeInOut(int color,int color2,int color3) {
  for (int i = 0; i < 255; i++) {
    analogWrite(color, i);
    analogWrite(color2, i);
    analogWrite(color3, i);
    delay(1);
  }
  for (int i = 256; i >= 0 ; i--) {
    analogWrite(color, i);
    analogWrite(color2, i);
    analogWrite(color3, i);
    delay(1);
  }
}
void loop() {
  fadeInOut(RED);
  fadeInOut(RED,GREEN);
  fadeInOut(GREEN);
  fadeInOut(GREEN,BLUE);
  fadeInOut(BLUE);
  fadeInOut(BLUE,RED);
  fadeInOut(RED,GREEN,BLUE);
}
