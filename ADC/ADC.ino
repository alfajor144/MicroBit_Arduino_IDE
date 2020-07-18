
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("A0: ");
  Serial.println(analogRead(A0));
  delay(1000);

  Serial.print("A1: ");
  Serial.println(analogRead(A1));
  delay(1000);

  Serial.print("A2: ");
  Serial.println(analogRead(A2));
  delay(1000);

  Serial.print("A3: ");
  Serial.println(analogRead(A3));
  delay(1000);

  Serial.print("A4: ");
  Serial.println(analogRead(A4));
  delay(1000);
  
}
