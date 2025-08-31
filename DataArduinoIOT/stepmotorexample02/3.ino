//declare variables for the motor pins
int motorPin1 = 8;    // Blue
int motorPin2 = 9;    // Pink
int motorPin3 = 10;   // Yellow
int motorPin4 = 11;   // Orange
                      // Red
int motorSpeed = 2;  //variable to set stepper speed
int stepCount = 0;    // number of steps the motor has taken
int sw = 12;

void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(sw,INPUT_PULLUP);
  Serial.begin(9600);  // initialize the serial port:
}
void re_wavedrive() {
  // 1
  digitalWrite(motorPin4, 1);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //2
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 1);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //3
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 1);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //4
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 1);
  delay(motorSpeed);
}
void wavedrive() {
  // 1
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 1);
  delay(motorSpeed);

  //2
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 1);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //3
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 1);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //4
  digitalWrite(motorPin4, 1);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);
}
void fullstep() {
  // 1
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);
  // 2
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motorSpeed);
  // 3
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
  // 4
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motorSpeed);
}
void halfstep(){
 // 1
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delay(motorSpeed);
 // 2
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delay (motorSpeed);
 // 3
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, LOW);
 delay(motorSpeed);
 // 4
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, HIGH);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, LOW);
 delay(motorSpeed);
 // 5
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, LOW);
 delay(motorSpeed);
 // 6
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, HIGH);
 digitalWrite(motorPin1, HIGH);
 delay (motorSpeed);
 // 7
 digitalWrite(motorPin4, LOW);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, HIGH);
 delay(motorSpeed);
 // 8
 digitalWrite(motorPin4, HIGH);
 digitalWrite(motorPin3, LOW);
 digitalWrite(motorPin2, LOW);
 digitalWrite(motorPin1, HIGH);
 delay(motorSpeed);
}

void countwavedrive(int k)
{
  int i = 0;
  while(i<k*512)
  {
    wavedrive();
    i++;
  }
}

void countre_wavedrive(int k)
{
  int i = 0;
  while(i<k*512)
  {
    re_wavedrive();
    i++;
  }
}

void loop() {
  int temp = analogRead(A5);
  Serial.println(temp);
  if(temp<150)
  {
    countwavedrive(4);
  }
  else if (temp>250)
  {
    countre_wavedrive(2);
  }

  /*fullstep();  // จ่ายไฟให ้ทํางานครั้งละ 2 ขด
  halfstep(); // ใชทั้งสองแบบรวมกันทําให ้หมุนได ้ครั้งละครึ่งเสตป ้
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;*/
}