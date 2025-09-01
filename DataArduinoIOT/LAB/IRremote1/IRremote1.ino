#include <IRremote.h>  // Include the library
#define RECV 11        // IR receiver pin 11
IRrecv irrecv(RECV);
decode_results results;
void setup() {
  Serial.begin(9600);    // Message will be sent to PC
  irrecv.enableIRIn();   // Start the receiver
  irrecv.blink13(true);  // pin 13 blink
}
void loop() {
  if (irrecv.decode(&results))  // Received IR signal
  {
    switch (results.decode_type) {
      case NEC: Serial.print("NEC: "); break;
      case SONY: Serial.print("SONY: "); break;
      case SHARP: Serial.print("SHARP: "); break;
      case PANASONIC: Serial.print("PANASONIC: "); break;
      case JVC: Serial.print("JVC: "); break;
      //case SANYO: Serial.print("SANYO: "); break;
      //case MITSUBISHI: Serial.print("MITSUBISHI: "); break;
      case RC5: Serial.print("Philips RC5: "); break;
      case RC6: Serial.print("Philips RC6: "); break;
      //case DISH: Serial.print("DISH: "); break;
      case DENON: Serial.print("DENON: "); break;
      case SAMSUNG: Serial.print("SAMSUNG: "); break;
      case LG: Serial.print("LG: "); break;
      case UNKNOWN: Serial.print("UNKNOWN: "); break;
    }
    Serial.println(results.value, HEX);  // Print raw data
    irrecv.resume();                     // Enable receiving of the next value
  }
}
