#pragma once
#include "Arduino.h"

class EEPROMClass {
  uint8_t _data[4096];
public:
  EEPROMClass() { memset(_data, 0xFF, sizeof(_data)); }
  bool begin(size_t size) { (void)size; return true; }
  uint8_t read(int addr) { return (addr >= 0 && addr < 4096) ? _data[addr] : 0xFF; }
  void write(int addr, uint8_t val) { if (addr >= 0 && addr < 4096) _data[addr] = val; }
  bool commit() { return true; }
  void end() {}
  uint8_t& operator[](int addr) { return _data[addr]; }
  template<typename T> T get(int addr, T& val) { memcpy(&val, _data + addr, sizeof(T)); return val; }
  template<typename T> void put(int addr, const T& val) { memcpy(_data + addr, &val, sizeof(T)); }
};

extern EEPROMClass EEPROM;
