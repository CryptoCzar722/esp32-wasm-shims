#pragma once
#include "freertos/FreeRTOS.h"

typedef void* EventGroupHandle_t;
typedef uint32_t EventBits_t;

inline EventGroupHandle_t xEventGroupCreate() { return (void*)1; }
inline void vEventGroupDelete(EventGroupHandle_t g) { (void)g; }
inline EventBits_t xEventGroupSetBits(EventGroupHandle_t g, EventBits_t bits) { (void)g; return bits; }
inline EventBits_t xEventGroupClearBits(EventGroupHandle_t g, EventBits_t bits) { (void)g; (void)bits; return 0; }
inline EventBits_t xEventGroupGetBits(EventGroupHandle_t g) { (void)g; return 0; }
inline EventBits_t xEventGroupWaitBits(EventGroupHandle_t g, EventBits_t bitsToWaitFor, int clearOnExit, int waitForAll, TickType_t timeout) {
  (void)g; (void)bitsToWaitFor; (void)clearOnExit; (void)waitForAll; (void)timeout;
  return bitsToWaitFor;
}
inline BaseType_t xEventGroupSetBitsFromISR(EventGroupHandle_t g, EventBits_t bits, BaseType_t* higherPriorityTaskWoken) {
  (void)g; (void)bits; (void)higherPriorityTaskWoken;
  return pdTRUE;
}
