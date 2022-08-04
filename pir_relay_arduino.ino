#define pinPIR 2
#define pinRelay 3
void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinRelay, OUTPUT);
}

void loop() {
  int nilaiSwitch = digitalRead((pinPIR));
  if(nilaiSwitch == 1){
    digitalWrite(pinRelay, HIGH);
  }
  else{
    digitalWrite(pinRelay, LOW);
  }
}