int ir =9;
void setup(){
  Serial.begin(115200);
}

void loop() {
  int temp = analogRead(A3);
  Serial.println(temp);
  if(temp<800)
  {
    digitalWrite(ir,1)
  }
  else
  {
    digitalWrite(ir,0)
  }
}
