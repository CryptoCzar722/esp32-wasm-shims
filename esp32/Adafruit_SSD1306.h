#pragma once
#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Wire.h"
#define SSD1306_SWITCHCAPVCC 0x02
#define WHITE 1
#define BLACK 0
class Adafruit_SSD1306 : public Adafruit_GFX { public: Adafruit_SSD1306(int16_t w, int16_t h, TwoWire* wire = &Wire, int8_t rst = -1) : Adafruit_GFX(w, h) { (void)wire;(void)rst; } bool begin(uint8_t vcs = SSD1306_SWITCHCAPVCC, uint8_t addr = 0x3C) { (void)vcs;(void)addr; return true; } void display() {} void clearDisplay() {} void drawPixel(int16_t x, int16_t y, uint16_t color) override { (void)x;(void)y;(void)color; } void setTextSize(uint8_t s) { (void)s; } void setTextColor(uint16_t c) { (void)c; } void setTextColor(uint16_t c, uint16_t bg) { (void)c;(void)bg; } void setCursor(int16_t x, int16_t y) { (void)x;(void)y; } void print(const char* s) { (void)s; } void println(const char* s = "") { (void)s; } void invertDisplay(bool i) { (void)i; } };
