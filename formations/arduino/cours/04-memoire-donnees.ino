// GOMA PRO Devs — Arduino 04 — Mémoire et données
struct Configuration {
  int identifiant;
  int seuil;
};

Configuration config = {1, 500};

void setup() {
  Serial.begin(115200);
  Serial.print("Taille int: ");
  Serial.println(sizeof(int));
  Serial.print("Taille long: ");
  Serial.println(sizeof(long));
  Serial.print("Seuil: ");
  Serial.println(config.seuil);
}

void loop() {
  byte masque = 0b00000100;
  bool bit2 = (masque & 0b00000100) != 0;
  Serial.print("Bit 2 = ");
  Serial.println(bit2);
  delay(2000);
}
