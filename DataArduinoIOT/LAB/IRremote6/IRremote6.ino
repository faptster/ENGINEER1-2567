#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>  // Include the library
uint16_t sAddress = 0x1578;
uint16_t sCommand = 0x1578;
uint8_t sRepeats = 0;
int led = 1;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // LED pin
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  IrSender.begin();      // Start with IR_SEND_PIN
  disableLEDFeedback();  // Disable feedback LED at default feedback LED pin
}
void loop() {
  int temp; 
  temp = analogRead(A5);
  Serial.println(temp);
  if (temp < 600) {
    sCommand = 0x0001;
    digitalWrite(led,1);
    Serial.println();
    Serial.print("Send IR signals at pin ");
    Serial.println(IR_SEND_PIN);
    Serial.print("Send Protocol=NEC : address=");
    Serial.print(sAddress, HEX);
    Serial.print(", command=");
    Serial.print(sCommand, HEX);
    Serial.print(", repeats=");
    Serial.println(sRepeats);
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    delay(100);
  }
  else if(temp < 700){
    sCommand = 0x0002;
    digitalWrite(led,1);
    Serial.println();
    Serial.print("Send IR signals at pin ");
    Serial.println(IR_SEND_PIN);
    Serial.print("Send Protocol=NEC : address=");
    Serial.print(sAddress, HEX);
    Serial.print(", command=");
    Serial.print(sCommand, HEX);
    Serial.print(", repeats=");
    Serial.println(sRepeats);
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    delay(100);
  }
  else if(temp < 800){
    sCommand = 0x0003;
    digitalWrite(led,1);
    Serial.println();
    Serial.print("Send IR signals at pin ");
    Serial.println(IR_SEND_PIN);
    Serial.print("Send Protocol=NEC : address=");
    Serial.print(sAddress, HEX);
    Serial.print(", command=");
    Serial.print(sCommand, HEX);
    Serial.print(", repeats=");
    Serial.println(sRepeats);
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    delay(100);
  }
  else{
    sCommand = 0x0000;
    digitalWrite(led,LOW);
    Serial.println();
    Serial.print("Send IR signals at pin ");
    Serial.println(IR_SEND_PIN);
    Serial.print("Send Protocol=NEC : address=");
    Serial.print(sAddress, HEX);
    Serial.print(", command=");
    Serial.print(sCommand, HEX);
    Serial.print(", repeats=");
    Serial.println(sRepeats);
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    delay(50);
  }
}