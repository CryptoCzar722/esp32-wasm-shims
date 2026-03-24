#pragma once
#include "freertos/FreeRTOS.h"
inline QueueHandle_t xQueueCreate(int len, int sz) { (void)len;(void)sz; return (void*)1; }
inline BaseType_t xQueueSend(QueueHandle_t q, const void* item, TickType_t t) { (void)q;(void)item;(void)t; return 1; }
inline BaseType_t xQueueReceive(QueueHandle_t q, void* buf, TickType_t t) { (void)q;(void)buf;(void)t; return 0; }
