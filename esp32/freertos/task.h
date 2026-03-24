#pragma once
#include "freertos/FreeRTOS.h"
#include <stddef.h>
inline void vTaskDelay(uint32_t t) { (void)t; }
inline void vTaskDelete(TaskHandle_t h) { (void)h; }
inline void taskYIELD() {}
inline BaseType_t xTaskCreate(void(*f)(void*), const char* n, uint32_t s, void* p, int pr, TaskHandle_t* h) { (void)f;(void)n;(void)s;(void)p;(void)pr;(void)h; return 1; }
inline BaseType_t xTaskCreatePinnedToCore(void(*f)(void*), const char* n, uint32_t s, void* p, int pr, TaskHandle_t* h, int core) { (void)f;(void)n;(void)s;(void)p;(void)pr;(void)h;(void)core; return 1; }
inline TaskHandle_t xTaskGetCurrentTaskHandle() { return NULL; }
inline void vTaskSuspend(TaskHandle_t h) { (void)h; }
inline void vTaskResume(TaskHandle_t h) { (void)h; }
