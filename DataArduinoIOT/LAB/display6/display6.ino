#include "Arduino_LED_Matrix.h"  // Include the LED_Matrix library
ArduinoLEDMatrix matrix;         // Create an instance of the ArduinoLEDMatrix class
const uint32_t frames[][4] = {
  { 0x7c000, 0xc594485, 0x486c844f, 300 },
  { 0xf8000, 0x8b2891a, 0x91d9189f, 300 },
  { 0xf0100, 0x21641225, 0x22b2213f, 300 },
  { 0xe0200, 0x42c8244a, 0x4464427c, 300 },
  { 0xc0400, 0x85914884, 0x88c884f8, 300 },
  { 0x80801, 0x1b229109, 0x109109f0, 300 },
  { 0x1002, 0x36442202, 0x202203e0, 300 },
  { 0x2004, 0x7c884404, 0x404407c0, 300 },
  { 0x4008, 0xe9118818, 0x81881f81, 300 },
  
};
void setup() {
  matrix.loadSequence(frames);
  matrix.begin();
  matrix.play(true);
}
void loop() {
}