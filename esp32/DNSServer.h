#pragma once
#include "Arduino.h"
#include "WiFi.h"
class DNSServer { public: void start(uint16_t port, const char* domain, IPAddress ip) { (void)port;(void)domain;(void)ip; } void stop() {} void processNextRequest() {} void setErrorReplyCode(int code) { (void)code; } void setTTL(uint32_t ttl) { (void)ttl; } };
