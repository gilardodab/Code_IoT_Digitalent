#define ledMerah 13
#define ledKuning 12
#define ledHijau 14

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);
}

void loop() {
  digitalWrite(ledMerah, HIGH);
  delay(500);
  digitalWrite(ledMerah, LOW);
  digitalWrite(ledKuning, HIGH);
  delay(500);
  digitalWrite(ledKuning, LOW);
  digitalWrite(ledHijau, HIGH);
  delay(500);
  digitalWrite(ledHijau, LOW);
  digitalWrite(ledKuning, HIGH);
  delay(500);
  digitalWrite(ledKuning, LOW);
}