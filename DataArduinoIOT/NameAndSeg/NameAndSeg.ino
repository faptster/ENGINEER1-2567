#include "Arduino_LED_Matrix.h"  // Include the LED_Matrix library
ArduinoLEDMatrix matrix;         // Create an instance of the ArduinoLEDMatrix class

int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

const uint32_t name[][4] = {
  { 0x0, 0x10000, 0x0, 300 },
  { 0x100, 0x30010, 0x1001001, 300 },
  { 0x300, 0x60020, 0x2002002, 300 },
  { 0x700, 0xc0040, 0x5006004, 300 },
  { 0xf00, 0x180080, 0xa00d008, 300 },
  { 0x1f00, 0x310110, 0x1501b011, 300 },
  { 0x3e00, 0x620220, 0x2a036022, 300 },
  { 0x7c00, 0xc50440, 0x5406c044, 300 },
  { 0xf800, 0x18b0890, 0xa90d9089, 300 },
  { 0x1f000, 0x3161121, 0x521b2113, 300 },
  { 0x3e000, 0x62d2242, 0x84364227, 300 },
  { 0x7c000, 0x1c5a4495, 0x496c944f, 300 },
  { 0xf8100, 0x28b4892a, 0x92d9289e, 300 },
  { 0xf0200, 0x41681255, 0x24b2413c, 300 },
  { 0xe0400, 0x82d124aa, 0x48648278, 300 },
  { 0xc0801, 0x5a34944, 0x90c904f0, 300 },
  { 0x81002, 0xb469299, 0x219219e1, 300 },
  { 0x2004, 0x68c2522, 0x422423c2, 300 },
  { 0x4008, 0xd194a44, 0x84484784, 300 },
  { 0x8010, 0xa339499, 0x9909f09, 300 },
  { 0x10020, 0x4662922, 0x12213e12, 300 },
  { 0x20040, 0x8cc5244, 0x25426c24, 300 },
  { 0x40080, 0x198a488, 0x4a84d848, 300 },
  { 0x80000, 0x3314910, 0x9509b091, 300 },
  { 0x0, 0x6629221, 0x2a136122, 300 },
  { 0x0, 0xcc42452, 0x5426c244, 300 },
  { 0x0, 0x98848a4, 0xa94d8488, 300 },
  { 0x0, 0x3109149, 0x529b1910, 300 },
  { 0x0, 0x6212282, 0xa4362221, 300 },
  { 0x0, 0xc434515, 0x496c5443, 300 },
  { 0x0, 0x8868a2a, 0x92d8a886, 300 },
  { 0x0, 0x10c1455, 0x25b1510d, 300 },
  { 0x0, 0x21928aa, 0x4a62b21a, 300 },
  { 0x100, 0x4335144, 0x95c56434, 300 },
  { 0x100200, 0x867a289, 0x2a8ac868, 300 },
  { 0x300400, 0xcf4512, 0x551590d1, 300 },
  { 0x600800, 0x119e8a24, 0xaa2b21a2, 300 },
  { 0xc01100, 0x233c1449, 0x54564344, 300 },
  { 0x1802200, 0x46782882, 0xa8ac8688, 300 },
  { 0x3004400, 0x8cf05105, 0x50590d10, 300 },
  { 0x6008801, 0x9e0a20a, 0xa0b20a20, 300 },
  { 0xc011002, 0x3c04405, 0x40640440, 300 },
  { 0x18022004, 0x780880a, 0x80c80880, 300 },
  { 0x30044008, 0xf001005, 0x900100, 300 },
  { 0x60088010, 0xe00200a, 0x200200, 300 },
  { 0xc0010020, 0xc004004, 0x400400, 300 },
  { 0x80020040, 0x8008008, 0x800800, 300 },
  { 0x40080, 0x0, 0x0, 300 },
  { 0x80000, 0x0, 0x0, 300 },
  { 0x0, 0x0, 0x0, 300 },
};
void setup() {
  matrix.loadSequence(name);
  matrix.begin();
  matrix.play(true);
  Serial.begin(9600);
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);

}

void displayNumber() {
  for (int digit = 1; digit <= 6; digit++) {
    displaysegment(digit,0);  // แสดงผลบน 7-Segment ขนาด 1 หลัก
    delay(400);             // หน่วงเวลา 0.6 วินาที
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
  displayNumber();
}