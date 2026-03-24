#pragma once
#include "Arduino.h"

class TwoWire {
public:
  void begin(int sda = -1, int scl = -1, uint32_t freq = 0) { (void)sda;(void)scl;(void)freq; }
  void beginTransmission(uint8_t addr) { (void)addr; }
  uint8_t endTransmission(bool stop = true) { (void)stop; return 0; }
  size_t write(uint8_t val) { (void)val; return 1; }
  size_t write(const uint8_t* buf, size_t len) { (void)buf;(void)len; return len; }
  uint8_t requestFrom(uint8_t addr, uint8_t qty, bool stop = true) { (void)addr;(void)qty;(void)stop; return 0; }
  int available() { return 0; }
  int read() { return 0; }
  void setClock(uint32_t freq) { (void)freq; }
  void setTimeOut(uint16_t t) { (void)t; }
};

extern TwoWire Wire;
extern TwoWire Wire1;
