#pragma once
#include <stdint.h>
typedef enum { ESP_SLEEP_WAKEUP_UNDEFINED=0, ESP_SLEEP_WAKEUP_EXT0=2, ESP_SLEEP_WAKEUP_EXT1=3, ESP_SLEEP_WAKEUP_TIMER=4, ESP_SLEEP_WAKEUP_TOUCHPAD=5, ESP_SLEEP_WAKEUP_ULP=6 } esp_sleep_wakeup_cause_t;
inline esp_sleep_wakeup_cause_t esp_sleep_get_wakeup_cause() { return ESP_SLEEP_WAKEUP_UNDEFINED; }
inline void esp_sleep_enable_timer_wakeup(uint64_t us) { (void)us; }
inline void esp_deep_sleep_start() {}
inline void esp_light_sleep_start() {}
