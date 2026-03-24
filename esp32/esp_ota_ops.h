#pragma once
#include "esp_partition.h"

typedef void* esp_ota_handle_t;

inline esp_err_t esp_ota_begin(const esp_partition_t* p, size_t sz, esp_ota_handle_t* h) { (void)p; (void)sz; (void)h; return 0; }
inline esp_err_t esp_ota_write(esp_ota_handle_t h, const void* data, size_t sz) { (void)h; (void)data; (void)sz; return 0; }
inline esp_err_t esp_ota_end(esp_ota_handle_t h) { (void)h; return 0; }
inline esp_err_t esp_ota_set_boot_partition(const esp_partition_t* p) { (void)p; return 0; }
inline const esp_partition_t* esp_ota_get_running_partition() { return nullptr; }
inline const esp_partition_t* esp_ota_get_next_update_partition(const esp_partition_t* p) { (void)p; return nullptr; }
