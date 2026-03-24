#pragma once
#include "freertos/FreeRTOS.h"
inline SemaphoreHandle_t xSemaphoreCreateMutex() { return (void*)1; }
inline BaseType_t xSemaphoreTake(SemaphoreHandle_t s, TickType_t t) { (void)s;(void)t; return 1; }
inline BaseType_t xSemaphoreGive(SemaphoreHandle_t s) { (void)s; return 1; }
