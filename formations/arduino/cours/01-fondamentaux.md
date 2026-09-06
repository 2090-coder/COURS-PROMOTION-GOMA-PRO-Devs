# Arduino — Module 01 : Fondamentaux

## Objectifs

À la fin de ce module, l'apprenant doit pouvoir expliquer ce qu'est un microcontrôleur, identifier les principales parties d'une carte Arduino, préparer un environnement de développement, compiler un programme et comprendre la structure d'un sketch.

## 1. Microcontrôleur et carte Arduino

Un microcontrôleur est un circuit intégré qui regroupe notamment un processeur, de la mémoire et des périphériques d'entrée/sortie. Une carte Arduino fournit autour du microcontrôleur une alimentation, une interface de programmation et des connecteurs facilitant l'expérimentation.

Il faut distinguer la carte et le microcontrôleur : la carte est le système matériel complet ; le microcontrôleur est le composant programmable au centre du système.

## 2. Chaîne de développement

Le cycle de base est :

1. écrire le programme ;
2. compiler ;
3. corriger les erreurs éventuelles ;
4. téléverser le programme ;
5. exécuter et observer le comportement ;
6. mesurer, diagnostiquer et améliorer.

## 3. Structure minimale d'un programme

```cpp
void setup() {
  // Initialisation exécutée au démarrage.
}

void loop() {
  // Instructions répétées.
}
```

`setup()` sert à initialiser les périphériques et les paramètres nécessaires. `loop()` contient la logique répétitive de l'application.

## 4. Variables et types

```cpp
int compteur = 0;
float tension = 3.3;
bool actif = true;
char lettre = 'A';
```

Le choix du type influence la mémoire utilisée et les valeurs représentables. Dans un système embarqué, il faut éviter de choisir les types sans réfléchir aux contraintes de mémoire, de précision et de performance.

## 5. Entrées et sorties

La logique Arduino classique utilise des broches numériques ou analogiques. Exemple conceptuel :

```cpp
const int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
```

Cet exemple permet de comprendre la chaîne : configuration d'une broche, écriture d'un niveau logique et répétition.

## 6. Pourquoi aller plus loin que les fonctions Arduino ?

Les fonctions de haut niveau simplifient le développement, mais elles masquent une partie du fonctionnement matériel. La formation poursuivra donc vers :

- représentation binaire et hexadécimale ;
- opérations bit à bit ;
- architecture mémoire ;
- registres matériels ;
- ports et GPIO ;
- interruptions ;
- timers et compteurs ;
- ADC et PWM ;
- UART, I2C et SPI ;
- pointeurs et gestion de la mémoire ;
- structures, unions et énumérations ;
- classes et programmation orientée objet ;
- création de bibliothèques `.h` et `.cpp`.

## Exercices

### Exercice 1
Expliquer avec ses propres mots la différence entre une carte Arduino et son microcontrôleur.

### Exercice 2
Modifier le programme LED pour obtenir un temps d'allumage de 200 ms et un temps d'extinction de 800 ms.

### Exercice 3
Créer un programme contenant une variable `compteur`, l'incrémenter à chaque passage dans `loop()` et expliquer pourquoi sa valeur évolue.

### Exercice 4
Identifier dans un programme Arduino les parties d'initialisation et les parties répétitives.

## Travaux pratiques

Réaliser un premier montage de sortie numérique dans un environnement de laboratoire autorisé. Documenter : matériel utilisé, schéma, code, résultat observé et difficultés rencontrées.

## Suite du parcours

Le prochain module introduira les entrées/sorties de manière approfondie, puis la formation abordera progressivement le C/C++ et enfin la programmation des registres et du matériel au niveau bas.