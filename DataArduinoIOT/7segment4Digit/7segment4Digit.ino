// กำหนดขาเชื่อมต่อของ segment และ digit บน 7-segment display
int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13; // จุดทศนิยม (Decimal Point)
int digit1 = 5;
int digit2 = 6;
int digit3 = 9;
int digit4 = 10;

void setup() {
  // ตั้งค่าให้ขาทั้งหมดเป็น output
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

// ฟังก์ชันปิดการแสดงผลของทั้ง 4 หลักบน 7-segment
void diactivepin() { 
  digitalWrite(digit1, 0);
  digitalWrite(digit2, 0);
  digitalWrite(digit3, 0);
  digitalWrite(digit4, 0);
}

// ฟังก์ชันเปิดการแสดงผลของหลักที่ระบุ (1-4)
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

// ฟังก์ชันควบคุมว่า segment ไหนจะติดหรือดับ โดยรับค่าทั้งหมด 8 ตัว (a-g และจุดทศนิยม)
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

// ฟังก์ชันแสดงตัวเลข (0-9) บน 7-segment โดยส่งค่าที่ต้องการแสดง และจุดทศนิยม (dp)
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
    case 10: // ใช้สำหรับเคลียร์จอ (ไม่แสดงอะไรเลย)
      Segment(0, 0, 0, 0, 0, 0, 0, dp);
      break;
  }
}

// ฟังก์ชันแสดงตัวเลข 4 หลัก โดยรับค่าของแต่ละ digit (temp1-temp4)
// ใช้เทคนิค multiplexing คือแสดงทีละหลักสลับกันเร็วๆ ให้ดูเหมือนแสดงพร้อมกัน
void tempout(int temp1, int temp2, int temp3, int temp4) {
  for (int num = 4; num > 0; num--) {
    activepin(num); // เปิดหลักที่ต้องการแสดง
    switch (num) {
      case 4:
        displaysegment(temp4, 0); // แสดงเลข temp4 ที่หลัก 4
        break;
      case 3:
        displaysegment(temp3, 0); // แสดงเลข temp3 ที่หลัก 3
        break;
      case 2:
        displaysegment(temp2, 0); // แสดงเลข temp2 ที่หลัก 2
        break;
      case 1:
        displaysegment(temp1, 0); // แสดงเลข temp1 ที่หลัก 1
        break;
    }
    delay(2); // หน่วงเวลาเล็กน้อยเพื่อให้มองเห็นการแสดงผล
    diactivepin(); // ปิดหลักปัจจุบันเพื่อเตรียมแสดงหลักถัดไป
  }
}

void loop() {
  // เรียกใช้ tempout เพื่อแสดงค่าบน 4 หลัก
  // ตัวอย่างเช่น: tempout(1, 2, 3, 4); แสดง 1234
  tempout( , , , ); // <<-- ต้องเติมค่าตัวเลขแต่ละหลักที่ต้องการแสดง
}
