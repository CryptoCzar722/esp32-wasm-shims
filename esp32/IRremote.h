#pragma once
#include "Arduino.h"
struct decode_results { unsigned long value; int bits; int decode_type; };
class IRrecv { public: IRrecv(uint8_t pin) { (void)pin; } void enableIRIn() {} bool decode(decode_results* results) { (void)results; return false; } void resume() {} };
class IRsend { public: IRsend(uint8_t pin) { (void)pin; } void begin() {} void sendNEC(unsigned long data, int nbits = 32) { (void)data;(void)nbits; } void sendSony(unsigned long data, int nbits = 12) { (void)data;(void)nbits; } void sendRaw(const unsigned int buf[], unsigned int len, unsigned int hz) { (void)buf;(void)len;(void)hz; } };
