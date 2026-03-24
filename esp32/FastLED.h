#pragma once
#include "Arduino.h"
struct CRGB { uint8_t r,g,b; CRGB() : r(0),g(0),b(0) {} CRGB(uint8_t r, uint8_t g, uint8_t b) : r(r),g(g),b(b) {} static CRGB Black; static CRGB Red; static CRGB Green; static CRGB Blue; static CRGB White; };
inline CRGB CRGB::Black = {0,0,0};
inline CRGB CRGB::Red = {255,0,0};
inline CRGB CRGB::Green = {0,255,0};
inline CRGB CRGB::Blue = {0,0,255};
inline CRGB CRGB::White = {255,255,255};
struct CHSV { uint8_t h,s,v; CHSV(uint8_t h=0,uint8_t s=0,uint8_t v=0) : h(h),s(s),v(v) {} };
class CFastLED { public: template<int CHIPSET, int DATA_PIN, int CLOCK_ORDER> CFastLED& addLeds(CRGB* leds, int num) { (void)leds;(void)num; return *this; } template<int CHIPSET, int DATA_PIN> CFastLED& addLeds(CRGB* leds, int num) { (void)leds;(void)num; return *this; } void show() {} void setBrightness(uint8_t b) { (void)b; } void clear() {} };
extern CFastLED FastLED;
#define WS2812B 1
#define WS2811 2
#define NEOPIXEL 3
#define GRB 0
#define NUM_LEDS 1
