#pragma once
#include "Arduino.h"
#include "WiFiClient.h"

class WebServer {
public:
  WebServer(int port = 80) { (void)port; }
  void begin() {}
  void handleClient() {}
  void on(const char* uri, void (*handler)()) { (void)uri;(void)handler; }
  void on(const char* uri, int method, void (*handler)()) { (void)uri;(void)method;(void)handler; }
  void onNotFound(void (*handler)()) { (void)handler; }
  void send(int code, const char* type = "", const char* content = "") { (void)code;(void)type;(void)content; }
  void send(int code, const String& type, const String& content) { (void)code;(void)type;(void)content; }
  void sendContent(const char* content) { (void)content; }
  void sendContent(const String& content) { (void)content; }
  void sendHeader(const char* name, const char* val, bool first = false) { (void)name;(void)val;(void)first; }
  void sendHeader(const String& name, const String& val, bool first = false) { (void)name;(void)val;(void)first; }
  void setContentLength(size_t len) { (void)len; }
  String arg(const char* name) { (void)name; return String(""); }
  String arg(const String& name) { return arg(name.c_str()); }
  String arg(int i) { (void)i; return String(""); }
  String argName(int i) { (void)i; return String(""); }
  int args() { return 0; }
  bool hasArg(const char* name) { (void)name; return false; }
  bool hasArg(const String& name) { return hasArg(name.c_str()); }
  String uri() { return String("/"); }
  int method() { return 0; }
  WiFiClient client() { return WiFiClient(); }
  String hostHeader() { return String(""); }
  void close() {}
  void stop() {}
};

#define HTTP_GET 0
#define HTTP_POST 1
#define HTTP_PUT 2
#define HTTP_DELETE 3
