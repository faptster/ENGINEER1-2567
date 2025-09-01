int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int temp = analogRead(A0);
  Serial.println(temp);
  if (temp >= 900) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
  } else if (temp >= 800) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
  } else if (temp >= 700) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
  } else if (temp >= 600) {
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
  } else if (temp >= 500) {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  } else if (temp >= 400) {
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
  } else if (temp >= 300) {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
  }
}
