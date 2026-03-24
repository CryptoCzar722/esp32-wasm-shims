#pragma once
#include "FS.h"

class SPIFFSFS : public FS {
public:
  bool begin(bool formatOnFail = false) { (void)formatOnFail; return true; }
  void end() {}
  bool format() { return true; }
  size_t totalBytes() { return 1048576; }
  size_t usedBytes() { return 0; }
};

extern SPIFFSFS SPIFFS;
