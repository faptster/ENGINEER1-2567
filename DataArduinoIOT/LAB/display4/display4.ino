#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
  matrix.begin();
}
const uint32_t smile[] = {
  0x3fc606d9,
  0xb801909c,
  0xf36063fc
};
const uint32_t happy[] = {
  0x19819,
  0x80000001,
  0x81f8000
};

void loop() {
  matrix.loadFrame(smile);
  delay(500);
  matrix.loadFrame(happy);
  delay(500);
}