
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID   "TMPLimhA6O7T"
#define LED 2

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHTesp.h"

const int DHT_PIN = 15;
DHTesp dhtSensor;

char auth[] = "zcxwMjTazluDxNzJHLKWqAfgAJ8KqgNF";

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
 int pinValue = param.asInt();
 digitalWrite(LED,pinValue);
}

void sendSensor()
{
 TempAndHumidity  data = dhtSensor.getTempAndHumidity();
 Serial.println("Temp: " + String(data.temperature, 2) + "°C");
 Serial.println("Humidity: " + String(data.humidity, 1) + "%");
 Serial.println("---");
 Blynk.virtualWrite(V1, data.temperature); //mengirimkan data ke Virtual pin di Blynk Cloud
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(LED, OUTPUT);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}