int led1=9;
int led2=10;
int sw = 11;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
}

// ใช้ switch กดกับปล่อย ไฟติดดับต่างกัน
void loop() {
  int temp = digitalRead(sw);
  if(temp == 1)
  {
    digitalWrite(led2,1);
    digitalWrite(led1,1);
    delay(1000);
    digitalWrite(led1,0);
    delay(1000);
    digitalWrite(led2,0);
    digitalWrite(led1,1);
    delay(1000);
    digitalWrite(led1,0);
    delay(1000);
  }
  else
  {
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    delay(2000);
    digitalWrite(led2,0);
    delay(2000);
  }
}
