#pragma once
#include "WiFiClient.h"

class WiFiServer {
public:
  WiFiServer(uint16_t port = 80) { (void)port; }
  void begin() {}
  WiFiClient available() { return WiFiClient(); }
};
