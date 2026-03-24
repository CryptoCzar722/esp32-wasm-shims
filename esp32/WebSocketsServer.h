#pragma once
#include "Arduino.h"
class WebSocketsServer { public: WebSocketsServer(uint16_t port) { (void)port; } void begin() {} void loop() {} void onEvent(void (*cb)(uint8_t, int, uint8_t*, size_t)) { (void)cb; } void broadcastTXT(const char* payload) { (void)payload; } void sendTXT(uint8_t num, const char* payload) { (void)num;(void)payload; } };
