//declare variables for the motor pins
int motorPin1 = 9;    // Blue
int motorPin2 = 10;    // Pink
int motorPin3 = 11;   // Yellow
int motorPin4 = 12;   // Orange
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
void wavedrive() {
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
void re_wavedrive() {
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
void loop() {
  // จ่ายไฟให ้ทํางานครั้งละ 1 ขด
  //wavedrive();
  fullstep();  // จ่ายไฟให ้ทํางานครั้งละ 2 ขด
  halfstep(); // ใชทั้งสองแบบรวมกันทําให ้หมุนได ้ครั้งละครึ่งเสตป ้
  Serial.print("steps:");
  Serial.println(stepCount); //ขยับไปกี่ step 1 step คือ ทำงานครบ func. นั้น ๆ
  stepCount++;
}