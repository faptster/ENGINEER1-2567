int led1 = 9;
int led2 = 10;

void setup(){
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  int temp = analogRead(A0);
  Serial.println(temp);
  if (temp < 500)
  {
    digitalWrite(led1,1);
    digitalWrite(led2,0);
  }
  else
  {
    digitalWrite(led1,0);
    digitalWrite(led2,1);
  }
}
