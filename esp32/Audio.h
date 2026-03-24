#pragma once
#include "Arduino.h"
class Audio { public: Audio() {} bool connecttoFS(FS& fs, const char* path) { (void)fs;(void)path; return false; } bool connecttohost(const char* url) { (void)url; return false; } void loop() {} void setVolume(uint8_t vol) { (void)vol; } uint8_t getVolume() { return 0; } bool isRunning() { return false; } void stopSong() {} bool setPinout(uint8_t bclk, uint8_t lrc, uint8_t dout) { (void)bclk;(void)lrc;(void)dout; return true; } };
