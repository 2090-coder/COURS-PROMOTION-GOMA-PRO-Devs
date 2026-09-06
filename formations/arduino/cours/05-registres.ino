// GOMA PRO Devs — Arduino 05 — Registres
// Exemple destiné aux cartes AVR compatibles avec ces registres.

void setup() {
  DDRB |= (1 << PB5);       // PB5 en sortie
  PORTB |= (1 << PB5);      // sortie à 1
  delay(500);
  PORTB &= ~(1 << PB5);     // sortie à 0
}

void loop() {
  PORTB ^= (1 << PB5);      // inverser PB5
  delay(500);
}
