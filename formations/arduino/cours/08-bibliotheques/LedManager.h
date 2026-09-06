#ifndef LED_MANAGER_H
#define LED_MANAGER_H

class LedManager {
public:
  LedManager(int pin);
  void begin();
  void on();
  void off();
private:
  int _pin;
};

#endif
