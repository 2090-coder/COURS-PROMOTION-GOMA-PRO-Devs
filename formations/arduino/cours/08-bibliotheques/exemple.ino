// GOMA PRO Devs — Arduino 08 — Exemple d'utilisation
#include "LedManager.h"

LedManager led(13);

void setup() {
  led.begin();
}

void loop() {
  led.on();
  delay(500);
  led.off();
  delay(500);
}
