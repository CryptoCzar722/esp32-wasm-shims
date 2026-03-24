#pragma once
#include "FS.h"
class SDMMCFS : public FS { public: bool begin(const char* mountpoint = "/sdcard", bool mode1bit = false) { (void)mountpoint;(void)mode1bit; return false; } void end() {} };
extern SDMMCFS SD_MMC;
