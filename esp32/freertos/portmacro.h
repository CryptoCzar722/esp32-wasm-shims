#pragma once
#include <stdint.h>

typedef uint32_t StackType_t;
typedef int32_t BaseType_t;
typedef uint32_t UBaseType_t;
typedef uint32_t TickType_t;

#define portMAX_DELAY 0xFFFFFFFF
#define portTICK_PERIOD_MS 1
#define portTICK_RATE_MS 1
#define portNUM_PROCESSORS 2
#define portMUX_INITIALIZER_UNLOCKED {}
#define portENTER_CRITICAL(mux) (void)(mux)
#define portEXIT_CRITICAL(mux) (void)(mux)
#define portENTER_CRITICAL_ISR(mux) (void)(mux)
#define portEXIT_CRITICAL_ISR(mux) (void)(mux)
#define portYIELD()
#define portYIELD_FROM_ISR(x) (void)(x)
#define portDISABLE_INTERRUPTS()
#define portENABLE_INTERRUPTS()

typedef struct { } portMUX_TYPE;
