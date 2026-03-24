#pragma once
#include <stdint.h>
typedef long time_t;
struct tm { int tm_sec; int tm_min; int tm_hour; int tm_mday; int tm_mon; int tm_year; int tm_wday; int tm_yday; int tm_isdst; };
inline time_t time(time_t* t) { if(t) *t = 0; return 0; }
inline struct tm* localtime(const time_t* t) { (void)t; static struct tm tm0 = {0}; return &tm0; }
inline struct tm* gmtime(const time_t* t) { (void)t; static struct tm tm0 = {0}; return &tm0; }
inline size_t strftime(char* s, size_t max, const char* fmt, const struct tm* tm) { (void)s;(void)max;(void)fmt;(void)tm; if(max>0) s[0]=0; return 0; }
inline void configTime(long gmtOffset_sec, int daylightOffset_sec, const char* ntpServer) { (void)gmtOffset_sec;(void)daylightOffset_sec;(void)ntpServer; }
inline bool getLocalTime(struct tm* info) { (void)info; return false; }
