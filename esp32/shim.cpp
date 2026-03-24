#include "Arduino.h"
#include <stdio.h>
#include <stdarg.h>

// ============================================================
// EM_JS bridges: these define JS functions callable from C/C++
// ============================================================

EM_JS(void, js_pin_mode, (int pin, int mode), {
  if (Module.onPinMode) Module.onPinMode(pin, mode);
});

EM_JS(void, js_digital_write, (int pin, int val), {
  if (Module.onDigitalWrite) Module.onDigitalWrite(pin, val);
});

EM_JS(int, js_digital_read, (int pin), {
  return Module.digitalPinStates ? (Module.digitalPinStates[pin] || 0) : 0;
});

EM_JS(int, js_analog_read, (int pin), {
  return Module.analogPinValues ? (Module.analogPinValues[pin] || 0) : 0;
});

EM_JS(double, js_millis_f, (), {
  var start = Module.simStartTime || 0;
  return performance.now() - start;
});

EM_JS(void, js_serial_print, (const char* str), {
  if (Module.onSerialData) Module.onSerialData(UTF8ToString(str));
});

EM_JS(int, js_should_stop, (), {
  return Module.shouldStop ? 1 : 0;
});

// ============================================================
// Arduino API implementations
// ============================================================

extern "C" {

void pinMode(uint8_t pin, uint8_t mode) {
  js_pin_mode(pin, mode);
}

void digitalWrite(uint8_t pin, uint8_t val) {
  js_digital_write(pin, val ? 1 : 0);
}

int digitalRead(uint8_t pin) {
  return js_digital_read(pin);
}

int analogRead(uint8_t pin) {
  return js_analog_read(pin);
}

void analogWrite(uint8_t pin, int val) {
  // ESP32 uses LEDC for PWM - bridge as digital for now
  js_digital_write(pin, val > 127 ? 1 : 0);
}

unsigned long millis(void) {
  return (unsigned long)js_millis_f();
}

unsigned long micros(void) {
  return (unsigned long)(js_millis_f() * 1000.0);
}

void delay(unsigned long ms) {
  emscripten_sleep(ms);
}

void delayMicroseconds(unsigned int us) {
  if (us >= 1000) {
    emscripten_sleep(us / 1000);
  }
  // Sub-ms delays are no-ops in WASM
}

static unsigned long _random_seed = 1;

long arduino_random(long max) {
  if (max <= 0) return 0;
  _random_seed = _random_seed * 1103515245 + 12345;
  return (long)((_random_seed / 65536) % max);
}

long arduino_random2(long mn, long mx) {
  if (mn >= mx) return mn;
  return arduino_random(mx - mn) + mn;
}

void randomSeed(unsigned long seed) {
  if (seed != 0) _random_seed = seed;
}

void attachInterrupt(uint8_t, void (*)(void), int) { /* stub */ }
void detachInterrupt(uint8_t) { /* stub */ }
void interrupts(void) { /* stub */ }
void noInterrupts(void) { /* stub */ }

void tone(uint8_t, unsigned int, unsigned long) { /* stub */ }
void noTone(uint8_t) { /* stub */ }

void yield(void) {
  emscripten_sleep(0);
}

} // extern "C"

// ============================================================
// HardwareSerial implementation
// ============================================================

HardwareSerial Serial;

void HardwareSerial::begin(unsigned long) {
  // No-op: serial is always available in sim
}

void HardwareSerial::end() {}

int HardwareSerial::available() {
  return 0; // TODO: serial input buffering
}

int HardwareSerial::read() {
  return -1;
}

int HardwareSerial::peek() {
  return -1;
}

size_t HardwareSerial::write(uint8_t byte) {
  char buf[2] = { (char)byte, 0 };
  js_serial_print(buf);
  return 1;
}

size_t HardwareSerial::write(const uint8_t* buf, size_t size) {
  for (size_t i = 0; i < size; i++) write(buf[i]);
  return size;
}

void HardwareSerial::print(const char* s) { js_serial_print(s); }
void HardwareSerial::print(char c) { char buf[2] = {c, 0}; js_serial_print(buf); }
void HardwareSerial::print(int val, int base) {
  char buf[34]; // enough for binary
  if (base == 16) sprintf(buf, "%X", val);
  else if (base == 8) sprintf(buf, "%o", val);
  else if (base == 2) {
    int pos = 0;
    if (val == 0) { buf[pos++] = '0'; }
    else { unsigned int v = (unsigned int)val; for (int i = 31; i >= 0; i--) { if (v & (1u << i)) { for (; i >= 0; i--) buf[pos++] = (v & (1u << i)) ? '1' : '0'; } } }
    buf[pos] = 0;
  }
  else sprintf(buf, "%d", val);
  js_serial_print(buf);
}
void HardwareSerial::print(unsigned int val, int base) { print((int)val, base); }
void HardwareSerial::print(long val, int base) { print((int)val, base); }
void HardwareSerial::print(unsigned long val, int base) { print((int)val, base); }
void HardwareSerial::print(float val, int decimals) { char buf[32]; sprintf(buf, "%.*f", decimals, val); js_serial_print(buf); }
void HardwareSerial::print(double val, int decimals) { print((float)val, decimals); }
void HardwareSerial::print(const String& s) { js_serial_print(s.c_str()); }

void HardwareSerial::println(const char* s) { js_serial_print(s); js_serial_print("\n"); }
void HardwareSerial::println(char c) { print(c); js_serial_print("\n"); }
void HardwareSerial::println(int val, int base) { print(val, base); js_serial_print("\n"); }
void HardwareSerial::println(unsigned int val, int base) { print(val, base); js_serial_print("\n"); }
void HardwareSerial::println(long val, int base) { print(val, base); js_serial_print("\n"); }
void HardwareSerial::println(unsigned long val, int base) { print(val, base); js_serial_print("\n"); }
void HardwareSerial::println(float val, int decimals) { print(val, decimals); js_serial_print("\n"); }
void HardwareSerial::println(double val, int decimals) { print(val, decimals); js_serial_print("\n"); }
void HardwareSerial::println(const String& s) { print(s); js_serial_print("\n"); }

void HardwareSerial::flush() {}

void HardwareSerial::printf(const char* fmt, ...) {
  char buf[256];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);
  js_serial_print(buf);
}

EspClass ESP;

// ============================================================
// Serial1 / Serial2 instances
// ============================================================

HardwareSerial Serial1;
HardwareSerial Serial2;

// ============================================================
// ESP32 LEDC / ADC / DAC / Touch stub implementations
// ============================================================

extern "C" {

void ledcSetup(uint8_t channel, double freq, uint8_t resolution) {
  (void)channel; (void)freq; (void)resolution;
}
void ledcAttachPin(uint8_t pin, uint8_t channel) {
  js_pin_mode(pin, 1); (void)channel;
}
void ledcWrite(uint8_t channel, uint32_t duty) {
  (void)channel; (void)duty;
}
void ledcDetachPin(uint8_t pin) { (void)pin; }
double ledcReadFreq(uint8_t channel) { (void)channel; return 0; }
uint32_t ledcRead(uint8_t channel) { (void)channel; return 0; }

void analogReadResolution(int bits) { (void)bits; }
void analogSetAttenuation(int atten) { (void)atten; }
void analogSetPinAttenuation(uint8_t pin, int atten) { (void)pin; (void)atten; }

void dacWrite(uint8_t pin, uint8_t value) {
  (void)pin; (void)value;
}

uint16_t touchRead(uint8_t pin) { (void)pin; return 0; }

} // extern "C"

// ESP32 library extern instances
#include "WiFi.h"
WiFiClass WiFi;

#include "Wire.h"
TwoWire Wire;
TwoWire Wire1;

#include "SPI.h"
SPIClass SPI;

#include "SPIFFS.h"
SPIFFSFS SPIFFS;

#include "EEPROM.h"
EEPROMClass EEPROM;

#include "ESPmDNS.h"
MDNSResponder MDNS;

#include "Update.h"
UpdateClass Update;

#include "SD.h"
SDFS SD;

#include "LittleFS.h"
LittleFSFS LittleFS;

#include "ArduinoOTA.h"
ArduinoOTAClass ArduinoOTA;

#include "FastLED.h"
CFastLED FastLED;
