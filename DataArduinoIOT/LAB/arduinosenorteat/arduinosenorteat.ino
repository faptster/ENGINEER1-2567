int led;
int i;
void setup() {
  for(led=9;led<13;led++)
  {
    pinMode(led,OUTPUT);
  }
}
void loop() {
  for(led=9;led<=13;led++)
  {
    digitalWrite(led,HIGH);
    delay(1000);
  }
  for(led=13;led>=9;led--)
  {
    digitalWrite(led,LOW);
    delay(1000);
  }
}
