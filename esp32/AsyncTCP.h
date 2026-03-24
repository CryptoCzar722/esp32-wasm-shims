#pragma once
#include "Arduino.h"
class AsyncClient { public: bool connect(const char* host, uint16_t port) { (void)host;(void)port; return false; } void close() {} bool connected() { return false; } void onData(void* handler, void* arg = nullptr) { (void)handler;(void)arg; } void onConnect(void* handler, void* arg = nullptr) { (void)handler;(void)arg; } void onDisconnect(void* handler, void* arg = nullptr) { (void)handler;(void)arg; } };
