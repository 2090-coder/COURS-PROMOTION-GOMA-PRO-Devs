// Exercices Arduino - Module 01
// Ce fichier peut être étudié comme code C++ avant téléversement.

#include <Arduino.h>

const int LED_PIN = LED_BUILTIN;
int compteur = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  compteur++;
  Serial.println(compteur);

  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(800);
}
