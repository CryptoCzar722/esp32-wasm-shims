#pragma once
#include "Arduino.h"
#include <stdint.h>

typedef enum { WL_NO_SHIELD = 255, WL_IDLE_STATUS = 0, WL_NO_SSID_AVAIL = 1,
  WL_SCAN_COMPLETED = 2, WL_CONNECTED = 3, WL_CONNECT_FAILED = 4,
  WL_CONNECTION_LOST = 5, WL_DISCONNECTED = 6 } wl_status_t;

typedef enum { WIFI_MODE_NULL = 0, WIFI_STA = 1, WIFI_AP = 2, WIFI_AP_STA = 3 } wifi_mode_t;
typedef enum { WIFI_AUTH_OPEN = 0, WIFI_AUTH_WEP = 1, WIFI_AUTH_WPA_PSK = 2,
  WIFI_AUTH_WPA2_PSK = 3, WIFI_AUTH_WPA_WPA2_PSK = 4, WIFI_AUTH_WPA2_ENTERPRISE = 5,
  WIFI_AUTH_WPA3_PSK = 6, WIFI_AUTH_MAX = 7 } wifi_auth_mode_t;

#define WIFI_SCAN_RUNNING (-1)
#define WIFI_SCAN_FAILED  (-2)

class IPAddress {
  uint8_t _addr[4];
public:
  IPAddress() { memset(_addr, 0, 4); }
  IPAddress(uint8_t a, uint8_t b, uint8_t c, uint8_t d) { _addr[0]=a; _addr[1]=b; _addr[2]=c; _addr[3]=d; }
  IPAddress(uint32_t addr) { memcpy(_addr, &addr, 4); }
  String toString() const { char buf[16]; sprintf(buf, "%d.%d.%d.%d", _addr[0], _addr[1], _addr[2], _addr[3]); return String(buf); }
  uint8_t operator[](int i) const { return _addr[i]; }
  operator uint32_t() const { uint32_t r; memcpy(&r, _addr, 4); return r; }
  bool operator==(const IPAddress& o) const { return memcmp(_addr, o._addr, 4) == 0; }
  bool operator!=(const IPAddress& o) const { return memcmp(_addr, o._addr, 4) != 0; }
  bool fromString(const char* s) { (void)s; return false; }
};

class WiFiClass {
public:
  wl_status_t begin(const char* ssid, const char* pass = nullptr) { (void)ssid; (void)pass; return WL_CONNECTED; }
  void disconnect(bool wifioff = false) { (void)wifioff; }
  wl_status_t status() { return WL_CONNECTED; }
  IPAddress localIP() { return IPAddress(192,168,1,100); }
  IPAddress subnetMask() { return IPAddress(255,255,255,0); }
  IPAddress gatewayIP() { return IPAddress(192,168,1,1); }
  IPAddress dnsIP(uint8_t n = 0) { (void)n; return IPAddress(8,8,8,8); }
  String macAddress() { return String("AA:BB:CC:DD:EE:FF"); }
  String SSID() { return String("SimNetwork"); }
  int32_t RSSI() { return -50; }
  bool mode(wifi_mode_t m) { (void)m; return true; }
  bool softAP(const char* ssid, const char* pass = nullptr, int ch = 1, int hid = 0, int max = 4) {
    (void)ssid;(void)pass;(void)ch;(void)hid;(void)max; return true;
  }
  IPAddress softAPIP() { return IPAddress(192,168,4,1); }
  void setHostname(const char*) {}
  int16_t scanNetworks(bool async = false, bool showHidden = false, bool passive = false, uint32_t maxMs = 300) {
    (void)async;(void)showHidden;(void)passive;(void)maxMs; return 0;
  }
  int16_t scanComplete() { return 0; }
  void scanDelete() {}
  String BSSIDstr(int i = 0) { (void)i; return String("00:00:00:00:00:00"); }
  uint8_t* BSSID(int i = 0) { (void)i; static uint8_t b[6] = {0}; return b; }
  String SSID(int i) { (void)i; return String(""); }
  int32_t RSSI(int i) { (void)i; return 0; }
  int32_t channel(int i = 0) { (void)i; return 1; }
  wifi_auth_mode_t encryptionType(int i = 0) { (void)i; return WIFI_AUTH_OPEN; }
  bool isConnected() { return true; }
  bool setAutoReconnect(bool b) { (void)b; return true; }
  void persistent(bool b) { (void)b; }
  bool config(IPAddress local, IPAddress gateway, IPAddress subnet, IPAddress dns1 = IPAddress(), IPAddress dns2 = IPAddress()) {
    (void)local;(void)gateway;(void)subnet;(void)dns1;(void)dns2; return true;
  }
  bool enableSTA(bool en) { (void)en; return true; }
  bool enableAP(bool en) { (void)en; return true; }
  String softAPmacAddress() { return String("AA:BB:CC:DD:EE:00"); }
  uint8_t softAPgetStationNum() { return 0; }
  int hostByName(const char* host, IPAddress& ip) { (void)host;(void)ip; return 1; }
};

extern WiFiClass WiFi;
