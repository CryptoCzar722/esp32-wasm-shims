#pragma once
#include "Arduino.h"
#define NEO_GRB 0x01
#define NEO_KHZ800 0x02
class Adafruit_NeoPixel { public: Adafruit_NeoPixel(uint16_t n = 0, int16_t pin = -1, uint8_t type = NEO_GRB + NEO_KHZ800) { (void)n;(void)pin;(void)type; } void begin() {} void show() {} void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) { (void)n;(void)r;(void)g;(void)b; } void setPixelColor(uint16_t n, uint32_t c) { (void)n;(void)c; } void setBrightness(uint8_t b) { (void)b; } void clear() {} uint16_t numPixels() { return 0; } static uint32_t Color(uint8_t r, uint8_t g, uint8_t b) { return ((uint32_t)r<<16)|((uint32_t)g<<8)|b; } uint32_t getPixelColor(uint16_t n) { (void)n; return 0; } void fill(uint32_t c = 0, uint16_t first = 0, uint16_t count = 0) { (void)c;(void)first;(void)count; } };
