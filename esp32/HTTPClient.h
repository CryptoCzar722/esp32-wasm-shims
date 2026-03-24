#pragma once
#include "Arduino.h"
#include "WiFiClient.h"

class HTTPClient {
public:
  bool begin(const char* url) { (void)url; return true; }
  bool begin(WiFiClient& client, const char* url) { (void)client;(void)url; return true; }
  void end() {}
  void addHeader(const char* name, const char* val) { (void)name;(void)val; }
  int GET() { return 200; }
  int POST(const char* payload) { (void)payload; return 200; }
  int PUT(const char* payload) { (void)payload; return 200; }
  String getString() { return String(""); }
  int getSize() { return 0; }
  void setTimeout(int t) { (void)t; }
  String errorToString(int e) { (void)e; return String("sim-stub"); }
};
