#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
  matrix.begin();
}
const uint32_t smile[] = {
  0xfff80199,
  0x99998018,
  0x91861fff
};
const uint32_t dead[] = {
  0x39c39,
  0xc39c0000,
  0xf00f0000
};

void loop() {
  matrix.loadFrame(smile);
  delay(500);
  matrix.loadFrame(dead);
  delay(500);
}