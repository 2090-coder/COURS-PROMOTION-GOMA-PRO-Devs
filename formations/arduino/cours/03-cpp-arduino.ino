// GOMA PRO Devs — Arduino 03 — C/C++
const int leds[] = {3, 5, 6, 9};
const int nombreLeds = 4;

int addition(int a, int b) {
  return a + b;
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < nombreLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.println(addition(10, 5));
}

void loop() {
  for (int i = 0; i < nombreLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }
}
