#pragma once
#include "Arduino.h"
class WiFiUDP;
class NTPClient { public: NTPClient(WiFiUDP& udp, const char* server = "pool.ntp.org", long offset = 0, unsigned long interval = 60000) { (void)udp;(void)server;(void)offset;(void)interval; } void begin() {} bool update() { return true; } bool forceUpdate() { return true; } String getFormattedTime() { return String("00:00:00"); } unsigned long getEpochTime() { return 0; } int getDay() { return 0; } int getHours() { return 0; } int getMinutes() { return 0; } int getSeconds() { return 0; } void setTimeOffset(long offset) { (void)offset; } void setUpdateInterval(unsigned long interval) { (void)interval; } };
