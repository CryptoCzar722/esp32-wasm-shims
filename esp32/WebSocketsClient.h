#pragma once
#include "Arduino.h"
class WebSocketsClient { public: void begin(const char* host, uint16_t port, const char* url = "/") { (void)host;(void)port;(void)url; } void loop() {} void onEvent(void (*cb)(int, uint8_t*, size_t)) { (void)cb; } void sendTXT(const char* payload) { (void)payload; } void disconnect() {} bool isConnected() { return false; } };
