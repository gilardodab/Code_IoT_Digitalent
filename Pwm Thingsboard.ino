void setup(){
 //put your setup code here, to run once;
 Serial.begin(9600);
}

void loop()
  //put your setup code here, to run once;
  int output = analogRead(A0);
  int nilai_pwm = map(output, 0, 1023, 0, 255);
  Serial.print("Nilai PWM: ");
  Serial.println (nilai_pwm);
  delay(100);
}