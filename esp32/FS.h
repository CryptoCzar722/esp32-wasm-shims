#pragma once
#include "Arduino.h"

class File {
public:
  operator bool() const { return false; }
  size_t write(uint8_t b) { (void)b; return 0; }
  size_t write(const uint8_t* buf, size_t sz) { (void)buf;(void)sz; return 0; }
  int available() { return 0; }
  int read() { return -1; }
  size_t read(uint8_t* buf, size_t sz) { (void)buf;(void)sz; return 0; }
  String readString() { return String(""); }
  String name() const { return String(""); }
  size_t size() const { return 0; }
  void close() {}
  bool isDirectory() { return false; }
  File openNextFile() { return File(); }
  size_t print(const char* s) { (void)s; return 0; }
  size_t println(const char* s = "") { (void)s; return 0; }
  bool seek(uint32_t pos) { (void)pos; return false; }
  uint32_t position() { return 0; }
};

class FS {
public:
  File open(const char* path, const char* mode = "r") { (void)path;(void)mode; return File(); }
  bool exists(const char* path) { (void)path; return false; }
  bool remove(const char* path) { (void)path; return false; }
  bool rename(const char* from, const char* to) { (void)from;(void)to; return false; }
  bool mkdir(const char* path) { (void)path; return false; }
  bool rmdir(const char* path) { (void)path; return false; }
};
