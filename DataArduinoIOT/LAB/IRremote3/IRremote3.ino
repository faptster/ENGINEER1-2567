#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11

void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData)  // Remote IR codes
    {
      case 0xF906FE01: Serial.println("OK "); break;
      case 0xB34CFE01: Serial.println("LEFT "); break;
      case 0xBF40FE01: Serial.println("RIGHT "); break;
      case 0xBB44FE01: Serial.println("FORWARD "); break;
      case 0xB748FE01: Serial.println("REVERSE "); break;
      case 0xB04FFE01: Serial.println("1 "); break;
      case 0xB44BFE01: Serial.println("2 "); break;
      case 0xB847FE01: Serial.println("3 "); break;
      case 0xB14EFE01: Serial.println("4 "); break;
      case 0xB54AFE01: Serial.println("5 "); break;
      case 0xB946FE01: Serial.println("6 "); break;
      case 0xB24DFE01: Serial.println("7 "); break;
      case 0xB649FE01: Serial.println("8 "); break;
      case 0xBA45FE01: Serial.println("9 "); break;
      case 0xBE41FE01: Serial.println("0 "); break;
      //case 0xFF42BD: Serial.print("* "); break;
      //case 0xFF52AD: Serial.print("# "); break;
      //case 0xFFFFFFFF: Serial.print("REPEAT ");break;
      //default: Serial.println("other button ");
    }
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}
