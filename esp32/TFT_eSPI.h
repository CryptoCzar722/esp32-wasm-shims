#pragma once
#include "Arduino.h"
#define TFT_BLACK 0x0000
#define TFT_WHITE 0xFFFF
#define TFT_RED 0xF800
#define TFT_GREEN 0x07E0
#define TFT_BLUE 0x001F
#define TFT_YELLOW 0xFFE0
#define MC_DATUM 4
class TFT_eSPI { public: void init() {} void begin() {} void fillScreen(uint32_t color) { (void)color; } void drawString(const char* s, int x, int y) { (void)s;(void)x;(void)y; } void drawString(const String& s, int x, int y) { (void)s;(void)x;(void)y; } void setTextColor(uint32_t fg, uint32_t bg = 0) { (void)fg;(void)bg; } void setTextSize(uint8_t sz) { (void)sz; } void setTextDatum(uint8_t d) { (void)d; } void setCursor(int16_t x, int16_t y) { (void)x;(void)y; } void print(const char* s) { (void)s; } void println(const char* s = "") { (void)s; } void drawPixel(int16_t x, int16_t y, uint16_t c) { (void)x;(void)y;(void)c; } void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t c) { (void)x0;(void)y0;(void)x1;(void)y1;(void)c; } void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c) { (void)x;(void)y;(void)w;(void)h;(void)c; } void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c) { (void)x;(void)y;(void)w;(void)h;(void)c; } void drawCircle(int16_t x, int16_t y, int16_t r, uint16_t c) { (void)x;(void)y;(void)r;(void)c; } void fillCircle(int16_t x, int16_t y, int16_t r, uint16_t c) { (void)x;(void)y;(void)r;(void)c; } void setRotation(uint8_t r) { (void)r; } int16_t width() { return 240; } int16_t height() { return 320; } void setSwapBytes(bool s) { (void)s; } void pushImage(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t* data) { (void)x;(void)y;(void)w;(void)h;(void)data; } };
