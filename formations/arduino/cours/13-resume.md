# Arduino 13 — GPS et localisation

## Objectif

À la fin du chapitre, l'apprenant doit pouvoir :

- expliquer le rôle d'un récepteur GPS/GNSS ;
- câbler un module série avec Arduino en respectant TX/RX ;
- comprendre le rôle des trames NMEA ;
- installer et utiliser TinyGPSPlus ;
- lire latitude, longitude, altitude, vitesse, heure, satellites et HDOP ;
- diagnostiquer une absence de données ou de fix.

## Principe

Un récepteur GNSS reçoit les signaux de plusieurs satellites et calcule une solution de position et de temps. Le terme GNSS est plus général que GPS : GPS désigne une constellation particulière, tandis que GNSS peut regrouper plusieurs constellations selon le récepteur.

## Communication UART

Pour une liaison série classique :

- TX du GPS -> RX de l'Arduino ;
- RX du GPS -> TX de l'Arduino ;
- GND du GPS -> GND Arduino ;
- VCC -> alimentation adaptée au module.

Ne pas supposer que tous les modules GPS acceptent la même tension. Vérifier la documentation ou les marquages de la carte utilisée.

## NMEA

De nombreux récepteurs transmettent des trames NMEA. Elles contiennent des informations structurées que la bibliothèque TinyGPSPlus peut analyser.

Exemples de familles de données : position, heure, date, vitesse, cap et satellites.

## TinyGPSPlus

La bibliothèque TinyGPSPlus permet de parser les données NMEA et d'accéder simplement à la position, à l'heure, à l'altitude, à la vitesse et à d'autres informations.

Le programme doit lire les caractères reçus un par un :

```cpp
while (gpsSerial.available() > 0) {
  gps.encode(gpsSerial.read());
}
```

Puis on teste les données :

```cpp
if (gps.location.isUpdated()) {
  Serial.println(gps.location.lat(), 6);
  Serial.println(gps.location.lng(), 6);
}
```

## `isValid()` et `isUpdated()`

- `isValid()` indique qu'une valeur disponible est valide.
- `isUpdated()` indique qu'une nouvelle valeur vient d'être reçue et traitée.

## Première mise en service

À l'extérieur ou près d'une zone avec une bonne visibilité du ciel, le récepteur peut avoir besoin de temps pour obtenir un fix. Pendant cette phase, le programme peut recevoir des trames sans encore disposer d'une position valide.

## TP

1. Faire le câblage UART.
2. Installer TinyGPSPlus depuis le gestionnaire de bibliothèques Arduino.
3. Téléverser `13-gps.ino`.
4. Ouvrir le moniteur série à 9600 bauds.
5. Observer satellites, latitude et longitude.
6. Comparer les valeurs après déplacement du module.
7. Ajouter ensuite un écran OLED ou une carte SD.

## Diagnostic

Si aucune donnée n'arrive :

- vérifier GND ;
- vérifier que TX et RX sont croisés ;
- vérifier le débit série ;
- vérifier l'alimentation adaptée au module ;
- vérifier le choix des broches Arduino ;
- tester d'abord la réception série avant d'ajouter OLED ou SD.

## Résultat attendu

L'apprenant doit être capable d'expliquer le chemin complet :

**satellites → récepteur GNSS → trames NMEA → UART → Arduino → TinyGPSPlus → latitude/longitude/heure/etc.**
