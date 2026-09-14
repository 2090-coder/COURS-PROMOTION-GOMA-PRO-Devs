#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Arduino UNO :
// GPS TX -> D4 (Arduino RX)
// GPS RX -> D3 (Arduino TX)
// GPS GND -> Arduino GND
// GPS VCC -> alimentation adaptee a votre module

static const int GPS_RX = 4;
static const int GPS_TX = 3;
static const uint32_t GPS_BAUD = 9600;

SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

void afficherGPS() {
  Serial.println("\n===== POSITION GPS =====");

  if (gps.location.isValid()) {
    Serial.print("Latitude  : ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude : ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Position : recherche d'un fix satellite...");
  }

  if (gps.altitude.isValid()) {
    Serial.print("Altitude  : ");
    Serial.print(gps.altitude.meters());
    Serial.println(" m");
  }

  if (gps.speed.isValid()) {
    Serial.print("Vitesse   : ");
    Serial.print(gps.speed.kmph());
    Serial.println(" km/h");
  }

  if (gps.satellites.isValid()) {
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());
  }

  if (gps.hdop.isValid()) {
    Serial.print("HDOP      : ");
    Serial.println(gps.hdop.hdop());
  }

  if (gps.date.isValid() && gps.time.isValid()) {
    Serial.print("UTC       : ");
    if (gps.time.hour() < 10) Serial.print('0');
    Serial.print(gps.time.hour());
    Serial.print(':');
    if (gps.time.minute() < 10) Serial.print('0');
    Serial.print(gps.time.minute());
    Serial.print(':');
    if (gps.time.second() < 10) Serial.print('0');
    Serial.println(gps.time.second());
  }
}

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPS_BAUD);
  Serial.println("Demarrage du GPS...");
  Serial.println("Attente des trames NMEA et du fix satellite...");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  // On affiche uniquement lorsqu'une nouvelle position est disponible.
  if (gps.location.isUpdated()) {
    afficherGPS();
  }

  // Diagnostic : permet de detecter un mauvais cablage ou un mauvais debit serie.
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("ATTENTION : aucune donnee GPS recue. Verifiez TX/RX, GND et le debit serie.");
    delay(1000);
  }
}
