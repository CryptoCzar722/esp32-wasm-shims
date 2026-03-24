#pragma once
#include "Arduino.h"
class Client;
class PubSubClient { public: PubSubClient() {} PubSubClient(Client& client) { (void)client; } void setServer(const char* server, uint16_t port) { (void)server;(void)port; } void setCallback(void (*cb)(char*, uint8_t*, unsigned int)) { (void)cb; } bool connect(const char* id, const char* user = nullptr, const char* pass = nullptr) { (void)id;(void)user;(void)pass; return true; } bool connected() { return false; } bool loop() { return false; } bool publish(const char* topic, const char* payload) { (void)topic;(void)payload; return true; } bool subscribe(const char* topic) { (void)topic; return true; } void disconnect() {} int state() { return 0; } bool setBufferSize(uint16_t sz) { (void)sz; return true; } };
