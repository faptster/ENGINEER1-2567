#define THERMISTOR A5  // thermistor pin
#define R0 10000
#define B 3435  // B: 3435 K the beta coefficient of the thermistor
#define R1 10000
#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11

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

int i = 10;
float averageTemp[5];

void setup() {
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
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
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
    case 11://a
      Segment(1, 1, 1, 0, 1, 1, 1, dp);
      break;
    case 12://b
      Segment(1, 1, 1, 1, 1, 1, 1, dp);
      break;
    case 13://c
      Segment(1, 0, 0, 1, 1, 1, 0, dp);
      break;
    case 14://d
      Segment(1, 1, 1, 1, 1, 1, 0, dp);
      break;
    case 15://e
      Segment(1, 0, 0, 1, 1, 1, 1, dp);
      break;
    case 16://f
      Segment(1, 0, 0, 0, 1, 1, 1, dp);
      break;
  }
}

void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData)  // Remote IR codes
    {
      case 0xB04FFE01:
        Serial.println("1 ");
        i = 1;
        break;

      case 0xB44BFE01:
        Serial.println("2 ");
        i = 2;
        break;

      case 0xB847FE01:
        Serial.println("3 ");
        i = 3;        break;

      case 0xB14EFE01:
        Serial.println("4 ");
        i = 4;
        break;

      case 0xB54AFE01:
        Serial.println("5 ");
        i = 5;
        break;

      case 0xB946FE01:
        Serial.println("6 ");
        i = 6;        break;

      case 0xB24DFE01:
        Serial.println("7 ");
        i = 7;
        break;

      case 0xB649FE01:
        Serial.println("8 ");
        i = 8;        break;

      case 0xBA45FE01:
        Serial.println("9 ");
        i = 9;
        break;

      case 0xBE41FE01:
        Serial.println("0 ");
        i = 0;
        break;
        
    }
    IrReceiver.resume();
  }
  tempout(i,10,10,10);
}