#pragma once
#include "WiFi.h"
class WiFiMulti { public: void addAP(const char* s, const char* p) {(void)s;(void)p;} uint8_t run() { return 3; } };
