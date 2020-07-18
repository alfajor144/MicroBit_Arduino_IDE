const int buttonA = 5; // the number of the pushbutton pin
const int buttonB = 11; // the number of the pushbutton pin
void setup() {
  Serial.begin(9600);
  Serial.println("microbit is ready!");
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}
void loop() {
  if (! digitalRead(buttonA)) {
    Serial.println("Button A pressed");
  }
  if (! digitalRead(buttonB)) {
    Serial.println("Button B pressed");
  }
  delay(10);
}
