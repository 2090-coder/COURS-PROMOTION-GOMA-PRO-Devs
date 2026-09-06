// GOMA PRO Devs — Arduino 06 — Interruptions et timers
volatile bool evenement = false;
unsigned long precedent = 0;
const unsigned long periode = 1000;
const int bouton = 2;
const int led = 13;

void ISR_bouton() {
  evenement = true;
}

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(bouton), ISR_bouton, FALLING);
  Serial.begin(115200);
}

void loop() {
  unsigned long maintenant = millis();

  if (evenement) {
    evenement = false;
    digitalWrite(led, !digitalRead(led));
    Serial.println("Evenement bouton");
  }

  if (maintenant - precedent >= periode) {
    precedent = maintenant;
    Serial.println("Tache periodique");
  }
}
