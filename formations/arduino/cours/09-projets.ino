// GOMA PRO Devs — Arduino 09 — Projet feu tricolore
const int ROUGE = 8;
const int ORANGE = 9;
const int VERT = 10;
const int BOUTON = 2;

void setup() {
  pinMode(ROUGE, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(VERT, OUTPUT);
  pinMode(BOUTON, INPUT_PULLUP);
}

void eteindreTout() {
  digitalWrite(ROUGE, LOW);
  digitalWrite(ORANGE, LOW);
  digitalWrite(VERT, LOW);
}

void loop() {
  eteindreTout();
  digitalWrite(VERT, HIGH);
  delay(3000);

  eteindreTout();
  digitalWrite(ORANGE, HIGH);
  delay(1000);

  eteindreTout();
  digitalWrite(ROUGE, HIGH);
  delay(3000);
}
