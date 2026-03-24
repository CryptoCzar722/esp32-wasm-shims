#pragma once
/* ArduinoJson stub - provides minimal StaticJsonDocument/DynamicJsonDocument */
#include <string.h>
class JsonVariant { public: operator bool() const { return false; } operator int() const { return 0; } operator float() const { return 0; } operator const char*() const { return ""; } bool isNull() const { return true; } };
class JsonObject { public: JsonVariant operator[](const char* k) { (void)k; return JsonVariant(); } bool isNull() const { return true; } };
class JsonArray { public: int size() const { return 0; } JsonVariant operator[](int i) { (void)i; return JsonVariant(); } bool isNull() const { return true; } };
template<int N> class StaticJsonDocument { public: int deserializeJson(StaticJsonDocument&, const char*) { return 0; } JsonObject as() { return JsonObject(); } JsonVariant operator[](const char* k) { (void)k; return JsonVariant(); } void clear() {} };
class DynamicJsonDocument { int _cap; public: DynamicJsonDocument(int cap) : _cap(cap) {} JsonVariant operator[](const char* k) { (void)k; return JsonVariant(); } void clear() {} };
template<typename T> int deserializeJson(T& doc, const char* input) { (void)doc;(void)input; return 0; }
template<typename T> int serializeJson(T& doc, char* buf, size_t sz) { (void)doc;(void)buf;(void)sz; return 0; }
