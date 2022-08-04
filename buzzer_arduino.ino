
int buzzerPin = 7;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 150);
  delay(1000);

  noTone(buzzerPin);

  delay(1000);

  tone(buzzerPin, 100, 1000);
  delay(2000);
}