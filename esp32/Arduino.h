#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif

// Pin modes
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2
#define INPUT_PULLDOWN 3

// Pin states
#define LOW 0
#define HIGH 1

// Math
#define PI 3.14159265358979323846
#define DEG_TO_RAD 0.017453292519943295
#define RAD_TO_DEG 57.29577951308232
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define map(x,in_min,in_max,out_min,out_max) (long)((x)-(in_min))*((out_max)-(out_min))/((in_max)-(in_min))+(out_min)

// Bit operations
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#define bit(b) (1UL << (b))
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

// Types
typedef bool boolean;
typedef uint8_t byte;
typedef uint16_t word;

// GPIO
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogWrite(uint8_t pin, int val);

// Timing
unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);

// Random — renamed to avoid POSIX random(void) conflict
long arduino_random(long max);
long arduino_random2(long min, long max);
void randomSeed(unsigned long seed);

// Interrupts (stubs)
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);
void interrupts(void);
void noInterrupts(void);
#define digitalPinToInterrupt(p) (p)
#define CHANGE 1
#define FALLING 2
#define RISING 3

// Tone
void tone(uint8_t pin, unsigned int frequency, unsigned long duration);
void noTone(uint8_t pin);

// Yield
void yield(void);

// ESP32 LEDC (PWM)
void ledcSetup(uint8_t channel, double freq, uint8_t resolution);
void ledcAttachPin(uint8_t pin, uint8_t channel);
void ledcWrite(uint8_t channel, uint32_t duty);
void ledcDetachPin(uint8_t pin);
double ledcReadFreq(uint8_t channel);
uint32_t ledcRead(uint8_t channel);

// ESP32 ADC
void analogReadResolution(int bits);
void analogSetAttenuation(int attenuation);
void analogSetPinAttenuation(uint8_t pin, int attenuation);
#define ADC_0db 0
#define ADC_2_5db 1
#define ADC_6db 2
#define ADC_11db 3

// ESP32 DAC
void dacWrite(uint8_t pin, uint8_t value);

// ESP32 touch
uint16_t touchRead(uint8_t pin);

// ESP32-specific GPIO numbers
#define LED_BUILTIN 2
#define A0 36
#define A3 39
#define A4 32
#define A5 33
#define A6 34
#define A7 35
#define A10 4
#define A11 0
#define A12 2
#define A13 15
#define A14 13
#define A15 12
#define A16 14
#define A17 27
#define A18 25
#define A19 26
#define DAC1 25
#define DAC2 26
#define SS 5
#define MOSI 23
#define MISO 19
#define SCK 18
#define SDA 21
#define SCL 22
#define TX 1
#define RX 3

// Forward declarations for user sketch
void setup(void);
void loop(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

// C++ random() wrappers — Arduino overloads random(max) and random(min,max)
inline long random(long maxVal) { return arduino_random(maxVal); }
inline long random(long minVal, long maxVal) { return arduino_random2(minVal, maxVal); }

// String class
class String {
  char* buffer;
  unsigned int len;
public:
  String() : buffer(nullptr), len(0) { buffer = (char*)malloc(1); buffer[0] = 0; }
  String(const char* s) { len = strlen(s); buffer = (char*)malloc(len+1); strcpy(buffer, s); }
  String(char c) { buffer = (char*)malloc(2); buffer[0] = c; buffer[1] = 0; len = 1; }
  String(int val) { buffer = (char*)malloc(12); len = sprintf(buffer, "%d", val); }
  String(unsigned int val) { buffer = (char*)malloc(12); len = sprintf(buffer, "%u", val); }
  String(long val) { buffer = (char*)malloc(12); len = sprintf(buffer, "%ld", val); }
  String(unsigned long val) { buffer = (char*)malloc(12); len = sprintf(buffer, "%lu", val); }
  String(float val, int dec = 2) { buffer = (char*)malloc(32); len = sprintf(buffer, "%.*f", dec, val); }
  String(double val, int dec = 2) { buffer = (char*)malloc(32); len = sprintf(buffer, "%.*f", dec, val); }
  String(const String& s) { len = s.len; buffer = (char*)malloc(len+1); strcpy(buffer, s.buffer); }
  ~String() { if (buffer) free(buffer); }
  String& operator=(const String& s) { if (this != &s) { free(buffer); len = s.len; buffer = (char*)malloc(len+1); strcpy(buffer, s.buffer); } return *this; }
  String& operator=(const char* s) { free(buffer); len = strlen(s); buffer = (char*)malloc(len+1); strcpy(buffer, s); return *this; }
  String operator+(const String& s) const { String r; free(r.buffer); r.len = len + s.len; r.buffer = (char*)malloc(r.len+1); strcpy(r.buffer, buffer); strcat(r.buffer, s.buffer); return r; }
  String operator+(const char* s) const { return *this + String(s); }
  String operator+(char c) const { return *this + String(c); }
  friend String operator+(const char* lhs, const String& rhs) { return String(lhs) + rhs; }
  String& operator+=(const String& s) { *this = *this + s; return *this; }
  String& operator+=(const char* s) { *this = *this + String(s); return *this; }
  String& operator+=(char c) { *this = *this + String(c); return *this; }
  bool operator==(const String& s) const { return strcmp(buffer, s.buffer) == 0; }
  bool operator==(const char* s) const { return strcmp(buffer, s) == 0; }
  bool operator!=(const String& s) const { return strcmp(buffer, s.buffer) != 0; }
  bool operator!=(const char* s) const { return strcmp(buffer, s) != 0; }
  bool operator<(const String& s) const { return strcmp(buffer, s.buffer) < 0; }
  bool operator>(const String& s) const { return strcmp(buffer, s.buffer) > 0; }
  bool operator<=(const String& s) const { return strcmp(buffer, s.buffer) <= 0; }
  bool operator>=(const String& s) const { return strcmp(buffer, s.buffer) >= 0; }
  char operator[](unsigned int i) const { return i < len ? buffer[i] : 0; }
  char& operator[](unsigned int i) { return buffer[i]; }
  unsigned int length() const { return len; }
  const char* c_str() const { return buffer; }
  char charAt(unsigned int i) const { return i < len ? buffer[i] : 0; }
  void setCharAt(unsigned int i, char c) { if (i < len) buffer[i] = c; }
  int indexOf(char c, unsigned int from = 0) const { for (unsigned int i = from; i < len; i++) if (buffer[i] == c) return i; return -1; }
  int indexOf(const String& s, unsigned int from = 0) const { if (from >= len) return -1; char* p = strstr(buffer + from, s.buffer); return p ? (int)(p - buffer) : -1; }
  int indexOf(const char* s, unsigned int from = 0) const { if (from >= len) return -1; char* p = strstr(buffer + from, s); return p ? (int)(p - buffer) : -1; }
  int lastIndexOf(char c) const { for (int i = len - 1; i >= 0; i--) if (buffer[i] == c) return i; return -1; }
  int lastIndexOf(const String& s) const { /* simple */ for (int i = len - s.len; i >= 0; i--) if (strncmp(buffer + i, s.buffer, s.len) == 0) return i; return -1; }
  String substring(unsigned int from, unsigned int to = 0xFFFFFFFF) const {
    if (to > len) to = len; if (from >= to) return String();
    char* s = (char*)malloc(to-from+1); memcpy(s, buffer+from, to-from); s[to-from] = 0;
    String r(s); free(s); return r;
  }
  bool startsWith(const String& prefix) const { return len >= prefix.len && strncmp(buffer, prefix.buffer, prefix.len) == 0; }
  bool startsWith(const char* prefix) const { size_t pl = strlen(prefix); return len >= pl && strncmp(buffer, prefix, pl) == 0; }
  bool endsWith(const String& suffix) const { return len >= suffix.len && strcmp(buffer + len - suffix.len, suffix.buffer) == 0; }
  bool endsWith(const char* suffix) const { size_t sl = strlen(suffix); return len >= sl && strcmp(buffer + len - sl, suffix) == 0; }
  void replace(const String& from, const String& to) { replace(from.c_str(), to.c_str()); }
  void replace(const char* from, const char* to) {
    size_t fl = strlen(from), tl = strlen(to);
    if (fl == 0) return;
    // Count occurrences
    int count = 0; char* p = buffer; while ((p = strstr(p, from))) { count++; p += fl; }
    if (count == 0) return;
    size_t newLen = len + count * ((int)tl - (int)fl);
    char* nb = (char*)malloc(newLen + 1); nb[0] = 0;
    char* src = buffer; char* dst = nb;
    while ((p = strstr(src, from))) { memcpy(dst, src, p - src); dst += (p - src); memcpy(dst, to, tl); dst += tl; src = p + fl; }
    strcpy(dst, src); free(buffer); buffer = nb; len = newLen;
  }
  void remove(unsigned int idx, unsigned int count = 1) { if (idx >= len) return; if (idx + count > len) count = len - idx; memmove(buffer + idx, buffer + idx + count, len - idx - count + 1); len -= count; }
  void trim() {
    unsigned int s = 0, e = len;
    while (s < e && (buffer[s] == ' ' || buffer[s] == '\t' || buffer[s] == '\r' || buffer[s] == '\n')) s++;
    while (e > s && (buffer[e-1] == ' ' || buffer[e-1] == '\t' || buffer[e-1] == '\r' || buffer[e-1] == '\n')) e--;
    if (s > 0 || e < len) { memmove(buffer, buffer + s, e - s); len = e - s; buffer[len] = 0; }
  }
  void toLowerCase() { for (unsigned int i = 0; i < len; i++) if (buffer[i] >= 'A' && buffer[i] <= 'Z') buffer[i] += 32; }
  void toUpperCase() { for (unsigned int i = 0; i < len; i++) if (buffer[i] >= 'a' && buffer[i] <= 'z') buffer[i] -= 32; }
  int toInt() const { return atoi(buffer); }
  long toLong() const { return atol(buffer); }
  float toFloat() const { return atof(buffer); }
  double toDouble() const { return atof(buffer); }
  bool isEmpty() const { return len == 0; }
  bool equals(const String& s) const { return strcmp(buffer, s.buffer) == 0; }
  bool equalsIgnoreCase(const String& s) const { if (len != s.len) return false; for (unsigned int i = 0; i < len; i++) { char a = buffer[i], b = s.buffer[i]; if (a >= 'A' && a <= 'Z') a += 32; if (b >= 'A' && b <= 'Z') b += 32; if (a != b) return false; } return true; }
  void reserve(unsigned int size) { if (size > len) { buffer = (char*)realloc(buffer, size + 1); } }
  void concat(const char* s) { *this += s; }
  void concat(char c) { *this += c; }
  int compareTo(const String& s) const { return strcmp(buffer, s.buffer); }
  void getBytes(unsigned char* buf, unsigned int bufsize, unsigned int index = 0) const { if (index >= len) return; unsigned int n = len - index; if (n > bufsize - 1) n = bufsize - 1; memcpy(buf, buffer + index, n); buf[n] = 0; }
  void toCharArray(char* buf, unsigned int bufsize, unsigned int index = 0) const { getBytes((unsigned char*)buf, bufsize, index); }
};

// Stream base class (Arduino core)
class Stream {
public:
  virtual int available() { return 0; }
  virtual int read() { return -1; }
  virtual int peek() { return -1; }
  virtual size_t write(uint8_t) { return 0; }
  virtual void flush() {}
  void setTimeout(unsigned long timeout) { (void)timeout; }
  String readString() { return String(""); }
  String readStringUntil(char terminator) { (void)terminator; return String(""); }
  int readBytes(char* buffer, int length) { (void)buffer;(void)length; return 0; }
  int readBytesUntil(char terminator, char* buffer, int length) { (void)terminator;(void)buffer;(void)length; return 0; }
  bool find(const char* target) { (void)target; return false; }
  long parseInt() { return 0; }
  float parseFloat() { return 0; }
  virtual ~Stream() {}
};

// HardwareSerial
class HardwareSerial : public Stream {
public:
  void begin(unsigned long baud);
  void end();
  int available();
  int read();
  int peek();
  size_t write(uint8_t byte);
  size_t write(const uint8_t* buf, size_t size);
  void print(const char* s);
  void print(char c);
  void print(int val, int base = 10);
  void print(unsigned int val, int base = 10);
  void print(long val, int base = 10);
  void print(unsigned long val, int base = 10);
  void print(float val, int decimals = 2);
  void print(double val, int decimals = 2);
  void print(const String& s);
  void println(const char* s = "");
  void println(char c);
  void println(int val, int base = 10);
  void println(unsigned int val, int base = 10);
  void println(long val, int base = 10);
  void println(unsigned long val, int base = 10);
  void println(float val, int decimals = 2);
  void println(double val, int decimals = 2);
  void println(const String& s);
  void flush();
  // printf — ESP32 extension, variadic
  void printf(const char* fmt, ...) __attribute__((format(printf, 2, 3)));
  operator bool() const { return true; }
};

extern HardwareSerial Serial;
extern HardwareSerial Serial1;
extern HardwareSerial Serial2;

// Base number formatters
#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

// ESP32 system stub
class EspClass {
public:
  uint32_t getFreeHeap() { return 262144; }
  uint32_t getHeapSize() { return 327680; }
  uint32_t getMinFreeHeap() { return 200000; }
  uint32_t getMaxAllocHeap() { return 110000; }
  uint8_t getChipRevision() { return 1; }
  uint32_t getCpuFreqMHz() { return 240; }
  uint32_t getFlashChipSize() { return 4194304; }
  uint32_t getFlashChipSpeed() { return 40000000; }
  uint32_t getSketchSize() { return 131072; }
  uint32_t getFreeSketchSpace() { return 1048576; }
  uint64_t getEfuseMac() { return 0x112233445566ULL; }
  const char* getSdkVersion() { return "sim"; }
  const char* getChipModel() { return "ESP32-SIM"; }
  uint8_t getChipCores() { return 2; }
  uint32_t getFlashChipMode() { return 0; }
  void restart() {}
  void deepSleep(uint64_t us) {}
};

// ESP32 standalone functions
inline float temperatureRead() { return 42.0f; }
inline long hallRead() { return 0; }

extern EspClass ESP;

#endif // __cplusplus
