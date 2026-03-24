#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct { uint32_t type; uint32_t subtype; uint32_t address; uint32_t size; char label[17]; } esp_partition_t;
typedef int esp_err_t;

inline const esp_partition_t* esp_partition_find_first(int type, int subtype, const char* label) { (void)type; (void)subtype; (void)label; return nullptr; }
inline esp_err_t esp_partition_read(const esp_partition_t* p, size_t off, void* dst, size_t sz) { (void)p; (void)off; (void)dst; (void)sz; return -1; }
inline esp_err_t esp_partition_write(const esp_partition_t* p, size_t off, const void* src, size_t sz) { (void)p; (void)off; (void)src; (void)sz; return -1; }
inline esp_err_t esp_partition_erase_range(const esp_partition_t* p, size_t off, size_t sz) { (void)p; (void)off; (void)sz; return -1; }
