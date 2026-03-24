#pragma once
#include "freertos/FreeRTOS.h"

typedef void* TimerHandle_t;
typedef void (*TimerCallbackFunction_t)(TimerHandle_t);

inline TimerHandle_t xTimerCreate(const char* name, TickType_t period, int autoReload, void* id, TimerCallbackFunction_t callback) {
  (void)name; (void)period; (void)autoReload; (void)id; (void)callback;
  return (void*)1;
}
inline BaseType_t xTimerStart(TimerHandle_t timer, TickType_t blockTime) { (void)timer; (void)blockTime; return pdTRUE; }
inline BaseType_t xTimerStop(TimerHandle_t timer, TickType_t blockTime) { (void)timer; (void)blockTime; return pdTRUE; }
inline BaseType_t xTimerReset(TimerHandle_t timer, TickType_t blockTime) { (void)timer; (void)blockTime; return pdTRUE; }
inline BaseType_t xTimerChangePeriod(TimerHandle_t timer, TickType_t newPeriod, TickType_t blockTime) { (void)timer; (void)newPeriod; (void)blockTime; return pdTRUE; }
inline BaseType_t xTimerDelete(TimerHandle_t timer, TickType_t blockTime) { (void)timer; (void)blockTime; return pdTRUE; }
inline void* pvTimerGetTimerID(TimerHandle_t timer) { (void)timer; return nullptr; }
inline const char* pcTimerGetName(TimerHandle_t timer) { (void)timer; return "timer"; }
inline BaseType_t xTimerIsTimerActive(TimerHandle_t timer) { (void)timer; return pdFALSE; }
inline BaseType_t xTimerStartFromISR(TimerHandle_t timer, BaseType_t* higherPriorityTaskWoken) { (void)timer; (void)higherPriorityTaskWoken; return pdTRUE; }
inline BaseType_t xTimerStopFromISR(TimerHandle_t timer, BaseType_t* higherPriorityTaskWoken) { (void)timer; (void)higherPriorityTaskWoken; return pdTRUE; }
