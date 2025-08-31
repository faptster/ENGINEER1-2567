//declare variables for the motor pins
int motorPin1 = 8;    // Blue
int motorPin2 = 9;    // Pink
int motorPin3 = 10;   // Yellow
int motorPin4 = 11;   // Orange
                      // Red
int motorSpeed = 2;  //variable to set stepper speed
int stepCount = 0;    // number of steps the motor has taken

void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);  // initialize the serial port:
}
void wavedrive() { //หมุน motor แบบ wavedrive
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
void re_wavedrive() { //หมุน motor แบบ wavedrive เปลี่ยนทิศทาง
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
void fullstep() { //หมุน motor แบบ fullstep
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
void halfstep(){ //หมุน motor แบบ halfstep
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
void stopwavedrive() { //หยุดหมุน motor
  // 1
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //2
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //3
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);

  //4
  digitalWrite(motorPin4, 0);
  digitalWrite(motorPin3, 0);
  digitalWrite(motorPin2, 0);
  digitalWrite(motorPin1, 0);
  delay(motorSpeed);
}

void loop() {
  int temp = analogRead(A5);
  Serial.println(temp);
  // จ่ายไฟให ้ทํางานครั้งละ 1 ขด
  //wavedrive();
  if(temp<200)
  {
    stopwavedrive();
  }
  else if(temp < 100)
  {
    stepCount = 0;
    while(stepCount < 512)
    {
      wavedrive();
      stepCount++;
    }
  }
  else
  {
    stepCount = 0;
    for(int n = 0;n<3;n++);
    {
      for(int i = 0;i<512;i++)
      {
        re_wavedrive();
      }
    }
  }
  fullstep();  // จ่ายไฟให ้ทํางานครั้งละ 2 ขด
  halfstep(); // ใชทั้งสองแบบรวมกันทําให ้หมุนได ้ครั้งละครึ่งเสตป ้
  //Serial.print("steps:");
  //Serial.println(stepCount);
  stepCount++;
}