int i ;
int led = 9 ;

void setup() 
{
  for(i=9;i<13;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() 
{
  //for(i=9;i<13;i++)
  for(i=0;i<4;i++)
  {
    digitalWrite(led+i,HIGH);
    delay(50);
    digitalWrite(led+i,LOW);
    delay(50);
  }
  //for(i=13;i>9;i--,led--)
  for(i=4;i>0;i--)
  {
    digitalWrite(led+i,HIGH);
    delay(50);
    digitalWrite(led+i,LOW);
    delay(50);
  }
}
