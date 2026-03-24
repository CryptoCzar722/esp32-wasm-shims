#pragma once
#include "freertos/FreeRTOS.h"

typedef void* StreamBufferHandle_t;
typedef void* MessageBufferHandle_t;

inline StreamBufferHandle_t xStreamBufferCreate(size_t sz, size_t trigger) { (void)sz; (void)trigger; return (void*)1; }
inline size_t xStreamBufferSend(StreamBufferHandle_t buf, const void* data, size_t len, TickType_t timeout) { (void)buf; (void)data; (void)timeout; return len; }
inline size_t xStreamBufferReceive(StreamBufferHandle_t buf, void* data, size_t len, TickType_t timeout) { (void)buf; (void)data; (void)len; (void)timeout; return 0; }
inline void vStreamBufferDelete(StreamBufferHandle_t buf) { (void)buf; }
inline BaseType_t xStreamBufferReset(StreamBufferHandle_t buf) { (void)buf; return pdTRUE; }
inline size_t xStreamBufferBytesAvailable(StreamBufferHandle_t buf) { (void)buf; return 0; }

inline MessageBufferHandle_t xMessageBufferCreate(size_t sz) { (void)sz; return (void*)1; }
inline size_t xMessageBufferSend(MessageBufferHandle_t buf, const void* data, size_t len, TickType_t timeout) { (void)buf; (void)data; (void)timeout; return len; }
inline size_t xMessageBufferReceive(MessageBufferHandle_t buf, void* data, size_t len, TickType_t timeout) { (void)buf; (void)data; (void)len; (void)timeout; return 0; }
inline void vMessageBufferDelete(MessageBufferHandle_t buf) { (void)buf; }
