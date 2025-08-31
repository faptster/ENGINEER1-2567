#define THERMISTOR A5  // thermistor pin
float R0 =  10000.0;
float B  = 3435.0;  // B: 3435 K the beta coefficient of the thermistor
float R1 =  10000.0; //ค่า R ที่เราใช้เทียบ ใข้ตัวต้านทานตัวไหน ใส่ค่านั้นเป็น Rref
float R;
void setup() {
  Serial.begin(9600);
}
void loop() {
  float samples;
  samples = analogRead(THERMISTOR);   // read the input on analog pin 0
  R = R1 * (samples / (1023.0 - samples)); //สูตรเทียบค่าความต้านทานจากค่า analog ที่อ่านได้
  Serial.print("Resistor : ");  // print out the value
  Serial.println(R);
  delay(1000);
}