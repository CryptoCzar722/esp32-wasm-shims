#pragma once
#include "Arduino.h"
#define ELM_SUCCESS 0
#define ELM_NO_RESPONSE 1
#define ELM_BUFFER_OVERFLOW 2
#define ELM_GARBAGE 3
#define ELM_UNABLE_TO_CONNECT 4
#define ELM_NO_DATA 5
#define ELM_STOPPED 6
#define ELM_TIMEOUT 7
#define ELM_GETTING_MSG 8
#define ELM_MSG_RXD 9
#define ELM_GENERAL_ERROR -1
class ELM327 { public: bool begin(Stream& stream, bool debug = false, uint16_t timeout = 1000) { (void)stream;(void)debug;(void)timeout; return true; } float rpm() { return 0; } float kph() { return 0; } float mph() { return 0; } float engineLoad() { return 0; } float coolantTemp() { return 0; } float oilTemp() { return 0; } float voltage() { return 12.6f; } float throttle() { return 0; } float engineCoolantTemp() { return 0; } float intakeAirTemp() { return 0; } float batteryVoltage() { return 12.6f; } float manifoldPressure() { return 0; } float fuelLevel() { return 0; } float timingAdvance() { return 0; } float ctrlModVoltage() { return 0; } float absLoad() { return 0; } float ambientAirTemp() { return 0; } uint32_t freqPID; int8_t nb_rx_state; bool connected; String payload; int8_t status() { return ELM_SUCCESS; } bool queryPID(uint8_t service, uint16_t pid) { (void)service;(void)pid; return true; } bool queryPID(const char* header, uint8_t service, uint16_t pid) { (void)header;(void)service;(void)pid; return true; } float processPID(uint8_t service, uint16_t pid, uint8_t numResponses = 1, uint8_t numExpectedBytes = 0, float scaleFactor = 1.0f, float bias = 0.0f) { (void)service;(void)pid;(void)numResponses;(void)numExpectedBytes;(void)scaleFactor;(void)bias; return 0; } };
