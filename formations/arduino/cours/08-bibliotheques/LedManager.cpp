#include "LedManager.h"

LedManager::LedManager(int pin) : _pin(pin) {}

void LedManager::begin() {
  pinMode(_pin, OUTPUT);
}

void LedManager::on() {
  digitalWrite(_pin, HIGH);
}

void LedManager::off() {
  digitalWrite(_pin, LOW);
}
