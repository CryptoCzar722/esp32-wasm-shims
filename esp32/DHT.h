#pragma once
#include "Arduino.h"
#define DHT11 11
#define DHT22 22
#define DHT21 21
class DHT { public: DHT(uint8_t pin, uint8_t type) { (void)pin;(void)type; } void begin() {} float readTemperature(bool isFahrenheit = false) { (void)isFahrenheit; return 25.0f; } float readHumidity() { return 50.0f; } float computeHeatIndex(float temp, float hum, bool isFahrenheit = true) { (void)temp;(void)hum;(void)isFahrenheit; return 25.0f; } bool read(bool force = false) { (void)force; return true; } };
