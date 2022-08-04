void setup() {
  //put your code here, to run once
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  //put your code here, to run repeatedly
  if(digitalWrite(7) == HIGH){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}