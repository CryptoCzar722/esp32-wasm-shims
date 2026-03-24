#pragma once
#include "Arduino.h"

class MDNSResponder {
public:
  bool begin(const char* hostname) { (void)hostname; return true; }
  void end() {}
  void addService(const char* service, const char* proto, uint16_t port) { (void)service;(void)proto;(void)port; }
};

extern MDNSResponder MDNS;
