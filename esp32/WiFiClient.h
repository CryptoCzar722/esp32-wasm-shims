#pragma once
#include "Arduino.h"
#include "WiFi.h"

class WiFiClient {
public:
  int connect(const char* host, uint16_t port) { (void)host;(void)port; return 1; }
  int connect(IPAddress ip, uint16_t port) { (void)ip;(void)port; return 1; }
  size_t write(uint8_t b) { (void)b; return 1; }
  size_t write(const uint8_t* buf, size_t sz) { (void)buf;(void)sz; return sz; }
  int available() { return 0; }
  int read() { return -1; }
  int read(uint8_t* buf, size_t sz) { (void)buf;(void)sz; return 0; }
  int peek() { return -1; }
  void flush() {}
  void stop() {}
  bool connected() { return false; }
  operator bool() { return false; }
  void setTimeout(int t) { (void)t; }
  size_t print(const char* s) { (void)s; return 0; }
  size_t print(const String& s) { (void)s; return 0; }
  size_t println(const char* s = "") { (void)s; return 0; }
  size_t println(const String& s) { (void)s; return 0; }
  IPAddress remoteIP() { return IPAddress(0,0,0,0); }
  uint16_t remotePort() { return 0; }
  IPAddress localIP() { return IPAddress(0,0,0,0); }
  uint16_t localPort() { return 0; }
};

class WiFiClientSecure : public WiFiClient {
public:
  void setInsecure() {}
  void setCACert(const char* rootCA) { (void)rootCA; }
  void setCertificate(const char* cert) { (void)cert; }
  void setPrivateKey(const char* key) { (void)key; }
};
