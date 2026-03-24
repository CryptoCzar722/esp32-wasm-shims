#pragma once
#include "Arduino.h"

class Preferences {
public:
  bool begin(const char* name, bool readOnly = false) { (void)name;(void)readOnly; return true; }
  void end() {}
  size_t putString(const char* key, const char* val) { (void)key;(void)val; return 0; }
  size_t putInt(const char* key, int32_t val) { (void)key;(void)val; return 4; }
  size_t putUInt(const char* key, uint32_t val) { (void)key;(void)val; return 4; }
  size_t putFloat(const char* key, float val) { (void)key;(void)val; return 4; }
  size_t putBool(const char* key, bool val) { (void)key;(void)val; return 1; }
  size_t putBytes(const char* key, const void* buf, size_t len) { (void)key;(void)buf;(void)len; return len; }
  String getString(const char* key, const char* def = "") { (void)key; return String(def); }
  int32_t getInt(const char* key, int32_t def = 0) { (void)key; return def; }
  uint32_t getUInt(const char* key, uint32_t def = 0) { (void)key; return def; }
  float getFloat(const char* key, float def = 0) { (void)key; return def; }
  bool getBool(const char* key, bool def = false) { (void)key; return def; }
  size_t getBytes(const char* key, void* buf, size_t len) { (void)key;(void)buf;(void)len; return 0; }
  bool remove(const char* key) { (void)key; return true; }
  bool clear() { return true; }
  bool isKey(const char* key) { (void)key; return false; }
};
