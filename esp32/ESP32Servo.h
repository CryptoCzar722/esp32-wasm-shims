#pragma once
#include "Arduino.h"
class Servo { public: uint8_t attach(int pin, int min = 544, int max = 2400) { (void)pin;(void)min;(void)max; return 0; } void write(int val) { (void)val; } int read() { return 90; } void writeMicroseconds(int us) { (void)us; } int readMicroseconds() { return 1500; } void detach() {} bool attached() { return false; } };
