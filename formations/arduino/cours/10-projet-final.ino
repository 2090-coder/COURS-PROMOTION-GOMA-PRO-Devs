const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  Serial.println("Systeme actif");
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
