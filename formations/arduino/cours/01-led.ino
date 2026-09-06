// GOMA PRO Devs — Arduino 01 — TP LED
// TP 01 : faire clignoter la LED intégrée

const int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
