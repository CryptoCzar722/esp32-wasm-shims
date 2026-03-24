#pragma once
#include "Arduino.h"
namespace websockets { class WebsocketsClient { public: bool connect(const char* url) { (void)url; return false; } void poll() {} bool available() { return false; } void send(const char* msg) { (void)msg; } void close() {} void onMessage(void (*cb)(WebsocketsClient&, const char*, size_t)) { (void)cb; } bool connected() { return false; } }; }
using namespace websockets;
