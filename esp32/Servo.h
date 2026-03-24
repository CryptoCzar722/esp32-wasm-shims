#pragma once
class Servo { public: uint8_t attach(int pin) { (void)pin; return 0; } void write(int val) { (void)val; } int read() { return 90; } void detach() {} bool attached() { return false; } };
