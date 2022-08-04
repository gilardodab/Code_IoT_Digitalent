#define ECHO_PIN 3
#define TRIG_PIN 2
#define pinBuzzer 5

#include <Servo.h>

Servo myservo;  

int potpin = 0;  
int val;    

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115200);
  pinMode(pinBuzzer, OUTPUT);
  myservo.attach(9);  
}

void loop() {
  float distance = readDistanceCM();
  Serial.print("Measured distance: ");
  Serial.println(readDistanceCM());

  if(distance <= 200){    
    myservo.write(90);                  
    delay(15);
   tone(pinBuzzer, 1000);
    delay(200);     
    tone(pinBuzzer, 500);
    delay(200);
  }
  else{
    myservo.write(0);
    noTone(pinBuzzer); 
  }                           
}