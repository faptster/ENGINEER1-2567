void setup(){
  Serial.begin(115200);
}

void loop() {
  int temp = analogRead(A1);
  Serial.println(temp);
}
