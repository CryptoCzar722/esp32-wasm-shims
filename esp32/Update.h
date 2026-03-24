#pragma once
#include "Arduino.h"

class UpdateClass {
public:
  bool begin(size_t size = 0, int command = 0) { (void)size;(void)command; return false; }
  size_t write(uint8_t* data, size_t len) { (void)data;(void)len; return 0; }
  bool end(bool evenIfRemaining = false) { (void)evenIfRemaining; return false; }
  bool hasError() { return true; }
  String errorString() { return String("sim-stub"); }
  bool isRunning() { return false; }
};

extern UpdateClass Update;
