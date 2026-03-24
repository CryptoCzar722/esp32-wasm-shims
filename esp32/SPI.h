#pragma once
#include "Arduino.h"

#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 3
#define MSBFIRST 1
#define LSBFIRST 0

class SPISettings {
public:
  SPISettings() {}
  SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) { (void)clock;(void)bitOrder;(void)dataMode; }
};

class SPIClass {
public:
  SPIClass(uint8_t bus = 0) { (void)bus; }
  void begin(int8_t sck = -1, int8_t miso = -1, int8_t mosi = -1, int8_t ss = -1) { (void)sck;(void)miso;(void)mosi;(void)ss; }
  void end() {}
  void beginTransaction(SPISettings settings) { (void)settings; }
  void endTransaction() {}
  uint8_t transfer(uint8_t data) { (void)data; return 0; }
  void transfer(void* buf, size_t count) { (void)buf;(void)count; }
  void setBitOrder(uint8_t order) { (void)order; }
  void setDataMode(uint8_t mode) { (void)mode; }
  void setFrequency(uint32_t freq) { (void)freq; }
};

extern SPIClass SPI;
