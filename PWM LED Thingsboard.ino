int ledPin =8;
int potentiometerPin = A0;

void setup()
{
  pinMode (ledPin, OUTPUT);
}

void loop()
{
  int potValue = potentiometerValue();
  int fadeValue = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(ledPin, fadeValue);
  delay(30);
}

int potentiometerValue ()
{
  int val -analogRead(potentiometerPin);
  return val;
}
