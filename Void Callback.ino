void callback(char* topic, byte* payload, unsigned int length) {
  // variable StringPayload untuk menyimpan konten paket data yang diterima
  String StringPayload = "";

  // Menjadikan setiap character yang diterima menjadi string utuh
  // melalui proses penggabungan character
  for (int i = 0; i < length; i++) {
    StringPayload += (char)payload[i];
  }

  Serial.println("TOPIC: " + String(topic));
  Serial.println("PAYLOAD: " + String(StringPayload));

  // Mem-filter data berdasarkan nama topic nya masing-masing
  if (strcmp(topic, inTopicFAN) == 0) {
    // Topic: "/fanpwm"
    SpeedFANSub(StringPayload.toInt());
  } else if (strcmp(topic, inTopicRelay) == 0) {
    // Topic: "/relay"
    if (StringPayload == "ON") {
      // Mengaktifkan Relay jika StringPayload = "ON"
      srChannel.set(pinRelay, HIGH);
    } else {
      // Menonaktifkan Relay jika StringPayload = "OFF"
      srChannel.set(pinRelay, LOW);
    }
  } else if (strcmp(topic, inTopicPiezo) == 0) {
    // Topic: "/piezo"
    if (StringPayload == "ON") {
      // Mengaktifkan Buzz jika StringPayload = "ON"
      srChannel.set(pinBuzz, HIGH);
    } else {
      // Menonaktifkan Buzz jika StringPayload = "OFF"
      srChannel.set(pinBuzz, LOW);
    }
  } else if (strcmp(topic, inTopicLED) == 0) {
    // Topic: "/ledanim"
    for (int i = 0; i <= 8; i++) {
      // Menset status channel shift register mulai dari 0-8 menjadi LOW
      srChannel.set(i, LOW);
    }

    for (int i = 1; i <= StringPayload.toInt(); i++) {
      // Menset status channel shift register mulai dari 0
      // sampai nilai maks yang diterima dari payload menjadi HIGH
      srChannel.set(i - 1, HIGH);
    }
  }
}
