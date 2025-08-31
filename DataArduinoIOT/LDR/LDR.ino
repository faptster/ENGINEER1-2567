void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp = analogRead(A5);
  int v = map(temp,1023,0,0,100); //เทียบค่า analog เป็นความสว่าง 1 - 100
  Serial.println(v);
}