#pragma once
#include "Arduino.h"

class WiFiUDP {
public:
  uint8_t begin(uint16_t port) { (void)port; return 1; }
  void stop() {}
  int parsePacket() { return 0; }
  int read(unsigned char* buf, size_t sz) { (void)buf;(void)sz; return 0; }
  int beginPacket(const char* host, uint16_t port) { (void)host;(void)port; return 1; }
  size_t write(const uint8_t* buf, size_t sz) { (void)buf;(void)sz; return sz; }
  int endPacket() { return 1; }
};
