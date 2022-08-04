#include <wifi.h>
#include <esp_wifi.h>

//Set your new MAC Address
uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66};

void setup () {
  Serial.begin(115200);
  Serial.println();

  Wifi.mode(WIFI_STA);

  Serial.print("[OLD] ESP32 Board MAC Address: ");
  Serial.println(wifi.macAddress());

  //ESP Board add-on before version < 1.0.5
  //esp_wifi_set_mac (ESP_IF_WIFI_STA, &newMACAddress [0]);

  //ESP Board add-on before version < 1.0.5
  //esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress [0]);

  Serial.print("[NEW] ESP32 Board MAC Address: ");
  Serial.println(Wifi.macAddress());
}
void loop (){
  
}