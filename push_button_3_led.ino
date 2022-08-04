
#define LED_hijau 13
#define LED_biru 12
#define LED_merah 11
#define tombol 7

int status = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_hijau, OUTPUT);
  pinMode(tombol, INPUT);
  pinMode(LED_biru, OUTPUT);
  pinMode(LED_merah, OUTPUT);
  digitalWrite(LED_hijau, LOW);
  digitalWrite(LED_biru, LOW);
  digitalWrite(LED_merah, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(tombol) == HIGH){
    status++;
    delay(100);
  } 
  
  if(status == 1){
    digitalWrite(LED_hijau, HIGH);
  }
  else if (status == 2){
    digitalWrite(LED_biru, HIGH);
  }
  else if(status == 3){
   digitalWrite(LED_merah, HIGH);
  }
  else if(status == 4){
   status = 0;
  }
  else{
    digitalWrite(LED_hijau, LOW);
    digitalWrite(LED_biru, LOW);
    digitalWrite(LED_merah, LOW);
  }

}