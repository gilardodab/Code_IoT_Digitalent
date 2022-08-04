#define pinSwitch 2
#define pinRelay 3
void setup() {
  pinMode(pinSwitch, INPUT_PULLUP);
  pinMode(pinRelay, OUTPUT);
}

void loop() {
  int nilaiSwitch = digitalRead((pinSwitch));
  if(nilaiSwitch == 0){
    digitalWrite(pinRelay, HIGH);
  }
  else{
    digitalWrite(pinRelay, LOW);
  }
}