const int TRIG = 9;
const int ECHO = 10;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  unsigned long duree = pulseIn(ECHO, HIGH, 30000);
  if (duree == 0) {
    Serial.println("Aucune mesure");
  } else {
    float distance = duree * 0.0343 / 2.0;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(200);
}
