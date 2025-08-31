void setup(){
  Serial.begin(9600);
}

void loop() {
  int temp = analogRead(A5); //อ่านค่า analog ตรง photo transistor
  Serial.println(temp);
}
