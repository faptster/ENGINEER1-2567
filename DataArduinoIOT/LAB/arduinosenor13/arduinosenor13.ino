int led=9;
int i;
void setup() {
  for(i=0;i<5;i++)
  {
    pinMode(led+i,OUTPUT);
  }
}
void loop() {
  for(i=0;i<4;i++)
  {
    digitalWrite(led+i,HIGH);
    delay(1000);
    digitalWrite(led+i,LOW);
  }
  for(i=4;i>0;i--)
  {
    digitalWrite(led+i,HIGH);
    delay(1000);
    digitalWrite(led+i,LOW);
  }
}
