#pragma once
#include "Arduino.h"
#include "SPI.h"
class TS_Point { public: int16_t x, y, z; TS_Point() : x(0), y(0), z(0) {} TS_Point(int16_t x, int16_t y, int16_t z) : x(x), y(y), z(z) {} };
class XPT2046_Touchscreen { public: XPT2046_Touchscreen(uint8_t cs, uint8_t irq = 255) { (void)cs;(void)irq; } bool begin() { return true; } bool begin(SPIClass& spi) { (void)spi; return true; } bool touched() { return false; } TS_Point getPoint() { return TS_Point(0,0,0); } void setRotation(uint8_t r) { (void)r; } uint8_t tirqTouched() { return 0; } };
