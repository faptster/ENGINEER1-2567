#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>  // Include the library
//#define IR_SEND_PIN 

uint16_t sAddress = 0x635;     //613f
uint16_t sCommand_1 = 0x7A;  //FE01613f
uint16_t sCommand_2 = 0x64;
uint16_t commands[] = {
  sCommand_1,
  sCommand_2
};
uint8_t sRepeats = 0;

int key_1 = 10;  // KEY pin
int key_2 = 11;

int led1 = 8;  // LED pin
int led2 = 9;   // LED pin

void setup() {
  Serial.begin(9600);
  IrSender.begin();  // Start with IR_SEND_PIN
  disableLEDFeedback();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(key_1, INPUT_PULLUP);
  pinMode(key_2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);  // LED pin Serial.begin(9600); IrSender.begin(); // Start with IR_SEND_PIN disableLEDFeedback(); // Disable feedback LED at default feedback LED pin
}
void loop() {
  IR_send(digitalRead(key_1), 0);
  IR_send(digitalRead(key_2), 1);
  if(digitalRead(key_1)==0)
  {
    digitalWrite(led1,1);
    delay(200);
    digitalWrite(led1,0);
  }
  if(digitalRead(key_2)==0)
  {
    digitalWrite(led2,1);
    delay(200);
    digitalWrite(led2,0);
  }
}
void IR_send(int button_val, int command) {
  if (button_val == 0) {
    Serial.println();
    Serial.print("Send IR signals at pin ");
    Serial.println(IR_SEND_PIN);
    Serial.print("Send Protocol=NEC : address=");
    Serial.print(sAddress, HEX);
    Serial.print("command= ");
    Serial.print(commands[command], HEX);
    Serial.print(", repeats=");
    Serial.println(sRepeats);
    IrSender.sendNEC(commands[command], sRepeats);
    delay(100);
  }
}