#pragma once
#define pdMS_TO_TICKS(ms) (ms)
#define portMAX_DELAY 0xFFFFFFFF
typedef void* TaskHandle_t;
typedef void* SemaphoreHandle_t;
typedef void* QueueHandle_t;
typedef uint32_t TickType_t;
typedef int BaseType_t;
#define pdTRUE 1
#define pdFALSE 0
