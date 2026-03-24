#pragma once
#include "Arduino.h"
class OneWire;
typedef uint8_t DeviceAddress[8];
class DallasTemperature { public: DallasTemperature() {} DallasTemperature(OneWire* ow) { (void)ow; } void begin() {} void requestTemperatures() {} float getTempCByIndex(uint8_t i) { (void)i; return 25.0f; } float getTempFByIndex(uint8_t i) { (void)i; return 77.0f; } int getDeviceCount() { return 0; } bool getAddress(uint8_t* addr, uint8_t idx) { (void)addr;(void)idx; return false; } void setResolution(uint8_t bits) { (void)bits; } void setWaitForConversion(bool b) { (void)b; } };
