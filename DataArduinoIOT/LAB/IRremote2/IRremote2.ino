#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 10  // IR receiver pin 11
int i;

void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.protocol) {
      case NEC: Serial.print("NEC: "); break;
      case SONY: Serial.print("SONY: "); break;
      case SHARP: Serial.print("SHARP: "); break;
      case PANASONIC: Serial.print("PANASONIC: "); break;
      case JVC: Serial.print("JVC: "); break;
      case RC5: Serial.print("Philips RC5: "); break;
      case RC6: Serial.print("Philips RC6: "); break;
      case DENON: Serial.print("DENON: "); break;
      case SAMSUNG: Serial.print("SAMSUNG: "); break;
      case LG: Serial.print("LG: "); break;
      case UNKNOWN: Serial.print("UNKNOWN: "); break;
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}
