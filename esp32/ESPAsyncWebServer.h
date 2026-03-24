#pragma once
#include "Arduino.h"
class AsyncWebServerRequest { public: void send(int code, const char* type = "", const char* content = "") { (void)code;(void)type;(void)content; } void send(int code, const String& type, const String& content) { (void)code;(void)type;(void)content; } String arg(const char* name) { (void)name; return String(""); } bool hasArg(const char* name) { (void)name; return false; } String host() { return String(""); } };
class AsyncWebServer { public: AsyncWebServer(uint16_t port) { (void)port; } void begin() {} void on(const char* uri, int method, void (*handler)(AsyncWebServerRequest*)) { (void)uri;(void)method;(void)handler; } void onNotFound(void (*handler)(AsyncWebServerRequest*)) { (void)handler; } };
#define HTTP_GET 0
#define HTTP_POST 1
