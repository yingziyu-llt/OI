void setup() {
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
}
void loop() {
  digitalWrite(12,LOW);
  digitalWrite(8,HIGH);
  delay(2000);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  delay(2000);
}
