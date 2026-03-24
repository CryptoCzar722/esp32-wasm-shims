#pragma once
#include "Arduino.h"

class BluetoothSerial : public Stream {
public:
  bool begin(const char* name = "ESP32", bool isMaster = false) { (void)name;(void)isMaster; return true; }
  void end() {}
  int available() { return 0; }
  int read() { return -1; }
  int peek() { return -1; }
  size_t write(uint8_t val) { (void)val; return 1; }
  size_t write(const uint8_t* buf, size_t sz) { (void)buf;(void)sz; return sz; }
  void print(const char* s) { (void)s; }
  void println(const char* s = "") { (void)s; }
  void flush() {}
  bool connected() { return false; }
  bool hasClient() { return false; }
  bool connect(const char* remoteName) { (void)remoteName; return false; }
  bool connect(uint8_t remoteAddress[]) { (void)remoteAddress; return false; }
  bool disconnect() { return true; }
  void setPin(const char* pin, uint8_t pinLen = 0) { (void)pin;(void)pinLen; }
  bool isReady() { return true; }
  void enableSSP() {}
};
