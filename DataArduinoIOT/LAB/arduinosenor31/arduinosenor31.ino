#define THERMISTOR A5  // thermistor pin
#define R0 10000
#define B 3435  // B: 3435 K the beta coefficient of the thermistor
#define R1 10000
float T0 = 25;  // °C reference temp.
float R;
float T;
float averageTemp[5];

void setup() {
  T0 = T0 + 273.15;  // conversion from Celsius to kelvin
  Serial.begin(9600);
}
void loop() {
  int samples;
  samples = analogRead(THERMISTOR);  // read the input on analog pin 0
  R = R1 * (samples / (1023.0 - samples));
  T = (1.0 / ((1.0 / T0) + (1.0 / B) * log(R / R0))) - 273.15;
  Serial.print("Temp: ");  // print out the value
  Serial.println(T);
  delay(500);
}