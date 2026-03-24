#pragma once
#include "Arduino.h"
class SoftwareSerial { public: SoftwareSerial(uint8_t rx, uint8_t tx, bool inverse = false) { (void)rx;(void)tx;(void)inverse; } void begin(unsigned long baud) { (void)baud; } void end() {} int available() { return 0; } int read() { return -1; } size_t write(uint8_t b) { (void)b; return 1; } void print(const char* s) { (void)s; } void println(const char* s = "") { (void)s; } void listen() {} bool isListening() { return false; } int peek() { return -1; } };
