#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("RTC: installer la bibliotheque du module choisi, puis initialiser l'horloge.");
}

void loop() {
  // Avec la bibliotheque du RTC choisi : lire date et heure ici.
  delay(1000);
}
