#pragma once
#include "Arduino.h"
#define NO_KEY 0
class Keypad { public: Keypad(char* userKeymap, uint8_t* row, uint8_t* col, uint8_t numRows, uint8_t numCols) { (void)userKeymap;(void)row;(void)col;(void)numRows;(void)numCols; } char getKey() { return NO_KEY; } void setDebounceTime(unsigned int t) { (void)t; } void setHoldTime(unsigned int t) { (void)t; } char waitForKey() { return NO_KEY; } bool keyStateChanged() { return false; } };
template<int R, int C> char* makeKeymap(char (&keys)[R][C]) { return &keys[0][0]; }
