#pragma once
#include "Arduino.h"

class Ticker {
public:
  void attach(float seconds, void (*callback)()) { (void)seconds;(void)callback; }
  void attach_ms(uint32_t ms, void (*callback)()) { (void)ms;(void)callback; }
  void once(float seconds, void (*callback)()) { (void)seconds;(void)callback; }
  void once_ms(uint32_t ms, void (*callback)()) { (void)ms;(void)callback; }
  void detach() {}
  bool active() { return false; }
};
