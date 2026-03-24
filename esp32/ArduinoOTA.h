#pragma once
#include "Arduino.h"
class ArduinoOTAClass { public: void setHostname(const char* h) { (void)h; } void setPassword(const char* p) { (void)p; } void setPort(uint16_t p) { (void)p; } void begin() {} void handle() {} void onStart(void (*fn)()) { (void)fn; } void onEnd(void (*fn)()) { (void)fn; } void onProgress(void (*fn)(unsigned int, unsigned int)) { (void)fn; } void onError(void (*fn)(int)) { (void)fn; } };
extern ArduinoOTAClass ArduinoOTA;
