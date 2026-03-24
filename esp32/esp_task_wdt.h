#pragma once
inline void esp_task_wdt_init(uint32_t t, bool p) { (void)t;(void)p; }
inline void esp_task_wdt_add(void* h) { (void)h; }
inline void esp_task_wdt_reset() {}
