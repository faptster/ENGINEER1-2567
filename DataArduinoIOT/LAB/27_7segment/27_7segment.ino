#define THERMISTOR A5  // thermistor pin
#define R0 10000
#define B 3435  // B: 3435 K the beta coefficient of the thermistor
#define R1 10000
float T0 = 25;  // °C reference temp.
float R;
float T;
int Ta;
int T1;
int T2;
int T3;
int T4;

int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;
int digit1 = 5;
int digit2 = 6;
int digit3 = 9;
int digit4 = 10;

float averageTemp[5];

void average(float temp) {
  for (int num = 0; num <= 5; num++) {
    averageTemp[num] = temp;
  }
  temp = (averageTemp[0] + averageTemp[1] + averageTemp[2] + averageTemp[3] + averageTemp[4]) / 5;
  Serial.print("Temp: ");  // print out the value
  Serial.println(temp);
}

void setup() {
  T0 = T0 + 273.15;  // conversion from Celsius to kelvin
  Serial.begin(9600);
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
}

void diactivepin() {
  digitalWrite(digit1, 0);
  digitalWrite(digit2, 0);
  digitalWrite(digit3, 0);
  digitalWrite(digit4, 0);
}

void activepin(int digit) {
  switch (digit) {
    case 1:
      digitalWrite(digit1, 1);
      break;
    case 2:
      digitalWrite(digit2, 1);
      break;
    case 3:
      digitalWrite(digit3, 1);
      break;
    case 4:
      digitalWrite(digit4, 1);
      break;
  }
}

void tempout(int temp1, int temp2, int temp3, int temp4) {
  for (int num = 4; num >= 1; num--) {
    activepin(num);
    switch (num) {
      case 4:
        displaysegment(temp4, 0);

        break;
      case 3:
        displaysegment(temp3, 0);

        break;
      case 2:
        displaysegment(temp2, 0);

        break;
      case 1:
        displaysegment(temp1, 0);

        break;
    }
    delay(2);
    diactivepin();
  }
}

void Segment(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte dp) {
  digitalWrite(segmentA, a);
  digitalWrite(segmentB, b);
  digitalWrite(segmentC, c);
  digitalWrite(segmentD, d);
  digitalWrite(segmentE, e);
  digitalWrite(segmentF, f);
  digitalWrite(segmentG, g);
  digitalWrite(segmentDP, dp);
}

void displaysegment(int digit, int dp) {
  switch (digit) {
    case 0:
      Segment(1, 1, 1, 1, 1, 1, 0, dp);
      break;
    case 1:
      Segment(0, 1, 1, 0, 0, 0, 0, dp);
      break;
    case 2:
      Segment(1, 1, 0, 1, 1, 0, 1, dp);
      break;
    case 3:
      Segment(1, 1, 1, 1, 0, 0, 1, dp);
      break;
    case 4:
      Segment(0, 1, 1, 0, 0, 1, 1, dp);
      break;
    case 5:
      Segment(1, 0, 1, 1, 0, 1, 1, dp);
      break;
    case 6:
      Segment(1, 0, 1, 1, 1, 1, 1, dp);
      break;
    case 7:
      Segment(1, 1, 1, 0, 0, 0, 0, dp);
      break;
    case 8:
      Segment(1, 1, 1, 1, 1, 1, 1, dp);
      break;
    case 9:
      Segment(1, 1, 1, 1, 0, 1, 1, dp);
      break;
    case 10:
      Segment(0, 0, 0, 0, 0, 0, 0, dp);
      break;
  }
}

void loop() {
  /*int samples;
    samples = analogRead(THERMISTOR);  // read the input on analog pin 0
    R = R1 * (samples / (1023.0 - samples));
    T = (1.0 / ((1.0 / T0) + (1.0 / B) * log(R / R0))) - 273.15;
    average(T);*/
  int c = analogRead(A3);
  Serial.println(c);

  Ta = c;
  T1 = Ta % 10;
  T2 = (Ta % 100) / 10;
  T3 = (Ta % 1000) / 100;
  T4 = (Ta % 10000) / 1000;
  tempout(T1, T2, T3, T4);
  /*if (T4 == 0 && T3 == 0 && T2 == 0 && T1 == 0)
    tempout(10, 10, 10, 10);
  else if (T4 == 0 && T3 == 0 && T2 == 0 && T1 != 0)
    tempout(T1, 10, 10, 10);
  else if (T4 == 0 && T3 == 0 && T2 != 0 && T1 == 0)
    tempout(T1, T2, 10, 10);
  else if (T4 == 0 && T3 != 0 && T2 == 0 && T1 == 0)
    tempout(T1, T2, T3, 10);
  else if (T4 != 0 && T3 == 0 && T2 == 0 && T1 == 0)
    tempout(T1, T2, T3, T4);*/
}
