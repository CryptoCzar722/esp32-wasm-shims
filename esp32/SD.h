#pragma once
#include "FS.h"
class SDFS : public FS { public: bool begin(uint8_t ss = 5) { (void)ss; return false; } };
extern SDFS SD;
