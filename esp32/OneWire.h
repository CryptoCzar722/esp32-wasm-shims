#pragma once
#include "Arduino.h"
class OneWire { public: OneWire() {} OneWire(uint8_t pin) { (void)pin; } void begin(uint8_t pin) { (void)pin; } bool search(uint8_t* addr) { (void)addr; return false; } void reset_search() {} bool reset() { return true; } void select(const uint8_t* addr) { (void)addr; } void write(uint8_t v, uint8_t power = 0) { (void)v;(void)power; } uint8_t read() { return 0; } };
