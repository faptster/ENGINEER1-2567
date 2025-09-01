int led = 9 ;
int i;

void setup() 
{
  pinMode(led,OUTPUT);
}

void loop() 
{
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(1500);
  for(i=300;i<500;i=i+3)
  {
    digitalWrite(led,HIGH);
    delay(500-i);
    digitalWrite(led,LOW);
    delay(1500-(i*3));
  }

}
