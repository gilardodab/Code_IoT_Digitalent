// Lampu LED Berjalan Menggunakan Arduino UNO
// Menyalakan LED dengan Aktif HIGH
 
void setup() 
{
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);// menjadikan PIN 0, 1, 2, dan 3 sebagai OUTPUT
}
 
void loop() 
{
//menyala secara bergilir
 
digitalWrite(0, HIGH);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
delay(1000);
digitalWrite(0, LOW);
digitalWrite(1, HIGH);
digitalWrite(2, LOW);
delay(1000);
digitalWrite(0, LOW);
digitalWrite(1, LOW);
digitalWrite(2, HIGH);
delay(1000);
}