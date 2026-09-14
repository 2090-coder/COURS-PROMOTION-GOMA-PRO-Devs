#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// ============================================================
// GPS NEO-8 / module compatible + Arduino UNO
// GOMA PRO Devs — Salomon BENGZ
// ============================================================
// Câblage :
// GPS TX  -> Arduino D4 (RX logiciel)
// GPS RX  -> Arduino D3 (TX logiciel)
// GPS GND -> Arduino GND
// GPS VCC -> alimentation adaptée au module
//
// IMPORTANT : le nom commercial « NEO-800L » peut désigner
// différents modules/clones. Vérifier la carte et sa tension
// d'alimentation avant le câblage.

#include <SoftwareSerial.h>   // Crée une liaison série sur D4/D3
#include <TinyGPS++.h>        // Décode les trames NMEA du GNSS

// D4 reçoit les données envoyées par le GPS.
// D3 peut envoyer des données vers le GPS.
static const int GPS_RX = 4;
static const int GPS_TX = 3;

// Débit de communication entre Arduino et le GPS.
static const uint32_t GPS_BAUD = 9600;

// SoftwareSerial(RX, TX)
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);

// Objet qui analyse les caractères NMEA reçus.
TinyGPSPlus gps;

// ------------------------------------------------------------
// Affiche toutes les informations actuellement disponibles.
// ------------------------------------------------------------
void afficherGPS() {
  Serial.println();
  Serial.println("===== DONNEES GPS =====");

  // Latitude + longitude = position géographique.
  if (gps.location.isValid()) {
    Serial.print("Latitude  : ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Longitude : ");
    Serial.println(gps.location.lng(), 6);

    // Création d'un lien Google Maps à partir des coordonnées.
    Serial.print("Maps      : https://www.google.com/maps?q=");
    Serial.print(gps.location.lat(), 6);
    Serial.print(",");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Position  : aucun fix valide pour le moment");
  }

  // Altitude estimée par le récepteur GNSS.
  if (gps.altitude.isValid()) {
    Serial.print("Altitude  : ");
    Serial.print(gps.altitude.meters());
    Serial.println(" m");
  }

  // Vitesse calculée par le récepteur.
  if (gps.speed.isValid()) {
    Serial.print("Vitesse   : ");
    Serial.print(gps.speed.kmph());
    Serial.println(" km/h");
  }

  // Nombre de satellites rapporté par la solution GNSS.
  if (gps.satellites.isValid()) {
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());
  }

  // HDOP : indicateur de géométrie/qualité du positionnement.
  // Plus il est faible, meilleure est généralement la géométrie.
  if (gps.hdop.isValid()) {
    Serial.print("HDOP      : ");
    Serial.println(gps.hdop.hdop());
  }

  // Date et heure reçues du GNSS sont généralement en UTC.
  if (gps.date.isValid() && gps.time.isValid()) {
    Serial.print("Date UTC  : ");
    if (gps.date.day() < 10) Serial.print('0');
    Serial.print(gps.date.day());
    Serial.print('/');
    if (gps.date.month() < 10) Serial.print('0');
    Serial.print(gps.date.month());
    Serial.print('/');
    Serial.println(gps.date.year());

    Serial.print("Heure UTC : ");
    if (gps.time.hour() < 10) Serial.print('0');
    Serial.print(gps.time.hour());
    Serial.print(':');
    if (gps.time.minute() < 10) Serial.print('0');
    Serial.print(gps.time.minute());
    Serial.print(':');
    if (gps.time.second() < 10) Serial.print('0');
    Serial.println(gps.time.second());
  }

  Serial.println("-----------------------");
}

void setup() {
  // Port série USB : communication avec le PC et moniteur série.
  Serial.begin(9600);

  // Port série logiciel : communication avec le GPS.
  gpsSerial.begin(GPS_BAUD);

  Serial.println("===============================================");
  Serial.println(" GPS + ARDUINO | GOMA PRO Devs");
  Serial.println(" Salomon BENGZ");
  Serial.println("===============================================");
  Serial.println("Lecture des trames NMEA...");
  Serial.println("Attente du fix satellite...");
}

void loop() {
  // Le GPS envoie continuellement des caractères.
  // On les lit un par un et TinyGPSPlus les analyse.
  while (gpsSerial.available() > 0) {
    char caractere = gpsSerial.read();
    gps.encode(caractere);
  }

  // isUpdated() signifie qu'une nouvelle position a été traitée.
  if (gps.location.isUpdated()) {
    afficherGPS();
  }

  // Diagnostic : si presque aucun caractère n'est reçu après 5 s,
  // il faut vérifier le câblage, le débit ou l'alimentation.
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println();
    Serial.println("ATTENTION : aucune donnee GPS recue.");
    Serial.println("Verifier TX/RX, GND, VCC et GPS_BAUD.");
    delay(1000);
  }
}
