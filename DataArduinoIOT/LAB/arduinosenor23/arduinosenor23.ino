void setup(){
  Serial.begin(115200);
}

void loop() {
  int temp = analogRead(A0);
  Serial.println(temp);
}
