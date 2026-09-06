// GOMA PRO Devs — Arduino 02 — Entrées, sorties et PWM
const int bouton = 2;
const int led = 9;
const int potentiometre = A0;

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int valeur = analogRead(potentiometre);
  int luminosite = map(valeur, 0, 1023, 0, 255);
  bool appuye = digitalRead(bouton) == LOW;

  if (appuye) {
    analogWrite(led, luminosite);
  } else {
    analogWrite(led, 0);
  }

  Serial.println(valeur);
  delay(50);
}
