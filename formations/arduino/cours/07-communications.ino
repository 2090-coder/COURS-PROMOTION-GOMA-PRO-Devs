// GOMA PRO Devs — Arduino 07 — UART, I2C et SPI
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Communication Arduino");
}

void loop() {
  Serial.println("Message UART");

  // Exemple de début de transaction I2C.
  // Adapter l'adresse au périphérique réellement utilisé.
  Wire.beginTransmission(0x3C);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(1000);
}
