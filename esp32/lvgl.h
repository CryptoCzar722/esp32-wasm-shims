#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
/* Minimal LVGL stub for WASM compilation */
typedef void* lv_obj_t;
typedef void* lv_disp_t;
typedef void* lv_indev_t;
typedef void* lv_disp_drv_t;
typedef void* lv_indev_drv_t;
typedef void* lv_disp_draw_buf_t;
typedef void* lv_event_t;
typedef void* lv_style_t;
typedef struct { uint16_t full; } lv_color_t;
typedef struct { uint8_t _dummy; } lv_font_t;
typedef void* lv_img_dsc_t;
typedef void* lv_group_t;
typedef void* lv_theme_t;
typedef void* lv_chart_series_t;
typedef int16_t lv_coord_t;
typedef uint8_t lv_opa_t;
typedef uint32_t lv_color32_t;
typedef void (*lv_event_cb_t)(lv_event_t*);
#define LV_HOR_RES_MAX 320
#define LV_VER_RES_MAX 240
#define LV_COLOR_DEPTH 16
#define LV_ALIGN_CENTER 0
#define LV_ALIGN_TOP_LEFT 1
#define LV_ALIGN_TOP_MID 2
#define LV_ALIGN_TOP_RIGHT 3
#define LV_ALIGN_BOTTOM_LEFT 4
#define LV_ALIGN_BOTTOM_MID 5
#define LV_ALIGN_BOTTOM_RIGHT 6
#define LV_ALIGN_LEFT_MID 7
#define LV_ALIGN_RIGHT_MID 8
#define LV_EVENT_CLICKED 0
#define LV_EVENT_PRESSED 1
#define LV_EVENT_VALUE_CHANGED 2
#define LV_SIZE_CONTENT 0
#define LV_PCT(x) (x)
#define LV_FLEX_FLOW_ROW 0
#define LV_FLEX_FLOW_COLUMN 1
#define LV_FLEX_ALIGN_CENTER 0
#define LV_FLEX_ALIGN_START 1
#define LV_FLEX_ALIGN_END 2
#define LV_FLEX_ALIGN_SPACE_BETWEEN 3
#define LV_PALETTE_BLUE 0
#define LV_PALETTE_RED 1
#define LV_PALETTE_GREEN 2
#define LV_STATE_DEFAULT 0
#define LV_PART_MAIN 0
#define LV_OPA_COVER 255
#define LV_CHART_TYPE_LINE 0
inline void lv_init() {}
inline void lv_tick_inc(uint32_t t) { (void)t; }
inline void lv_timer_handler() {}
inline void lv_task_handler() {}
inline lv_obj_t* lv_scr_act() { return nullptr; }
inline lv_obj_t* lv_obj_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_label_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_btn_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_slider_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_switch_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_textarea_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_dropdown_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_chart_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_bar_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_arc_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_spinner_create(lv_obj_t* parent, uint32_t t, uint32_t a) { (void)parent;(void)t;(void)a; return nullptr; }
inline lv_obj_t* lv_img_create(lv_obj_t* parent) { (void)parent; return nullptr; }
inline lv_obj_t* lv_tabview_create(lv_obj_t* parent, uint8_t dir, lv_coord_t sz) { (void)parent;(void)dir;(void)sz; return nullptr; }
inline lv_obj_t* lv_tabview_add_tab(lv_obj_t* tv, const char* name) { (void)tv;(void)name; return nullptr; }
inline void lv_label_set_text(lv_obj_t* obj, const char* txt) { (void)obj;(void)txt; }
inline void lv_label_set_text_fmt(lv_obj_t* obj, const char* fmt, ...) { (void)obj;(void)fmt; }
inline void lv_obj_set_size(lv_obj_t* obj, lv_coord_t w, lv_coord_t h) { (void)obj;(void)w;(void)h; }
inline void lv_obj_set_width(lv_obj_t* obj, lv_coord_t w) { (void)obj;(void)w; }
inline void lv_obj_set_height(lv_obj_t* obj, lv_coord_t h) { (void)obj;(void)h; }
inline void lv_obj_set_pos(lv_obj_t* obj, lv_coord_t x, lv_coord_t y) { (void)obj;(void)x;(void)y; }
inline void lv_obj_align(lv_obj_t* obj, uint8_t align, lv_coord_t x, lv_coord_t y) { (void)obj;(void)align;(void)x;(void)y; }
inline void lv_obj_set_style_text_font(lv_obj_t* obj, const lv_font_t* font, uint32_t sel) { (void)obj;(void)font;(void)sel; }
inline void lv_obj_set_style_text_color(lv_obj_t* obj, lv_color_t color, uint32_t sel) { (void)obj;(void)color;(void)sel; }
inline void lv_obj_set_style_bg_color(lv_obj_t* obj, lv_color_t color, uint32_t sel) { (void)obj;(void)color;(void)sel; }
inline void lv_obj_set_style_bg_opa(lv_obj_t* obj, lv_opa_t opa, uint32_t sel) { (void)obj;(void)opa;(void)sel; }
inline void lv_obj_set_style_pad_all(lv_obj_t* obj, lv_coord_t pad, uint32_t sel) { (void)obj;(void)pad;(void)sel; }
inline void lv_obj_set_style_radius(lv_obj_t* obj, lv_coord_t r, uint32_t sel) { (void)obj;(void)r;(void)sel; }
inline void lv_obj_set_style_border_width(lv_obj_t* obj, lv_coord_t w, uint32_t sel) { (void)obj;(void)w;(void)sel; }
inline void lv_obj_add_event_cb(lv_obj_t* obj, lv_event_cb_t cb, uint8_t filter, void* ud) { (void)obj;(void)cb;(void)filter;(void)ud; }
inline void lv_obj_add_flag(lv_obj_t* obj, uint32_t f) { (void)obj;(void)f; }
inline void lv_obj_clear_flag(lv_obj_t* obj, uint32_t f) { (void)obj;(void)f; }
inline void lv_obj_add_state(lv_obj_t* obj, uint32_t s) { (void)obj;(void)s; }
inline void lv_obj_clear_state(lv_obj_t* obj, uint32_t s) { (void)obj;(void)s; }
inline bool lv_obj_has_state(lv_obj_t* obj, uint32_t s) { (void)obj;(void)s; return false; }
inline void lv_obj_del(lv_obj_t* obj) { (void)obj; }
inline void lv_obj_clean(lv_obj_t* obj) { (void)obj; }
inline void lv_obj_set_flex_flow(lv_obj_t* obj, uint8_t flow) { (void)obj;(void)flow; }
inline void lv_obj_set_flex_align(lv_obj_t* obj, uint8_t main, uint8_t cross, uint8_t track) { (void)obj;(void)main;(void)cross;(void)track; }
inline lv_color_t lv_color_make(uint8_t r, uint8_t g, uint8_t b) { (void)r;(void)g;(void)b; lv_color_t c = {0}; return c; }
inline lv_color_t lv_color_hex(uint32_t c) { (void)c; lv_color_t col = {0}; return col; }
inline lv_color_t lv_color_white() { lv_color_t c = {0xFFFF}; return c; }
inline lv_color_t lv_color_black() { lv_color_t c = {0}; return c; }
inline lv_color_t lv_palette_main(int p) { (void)p; lv_color_t c = {0}; return c; }
inline lv_color_t lv_palette_lighten(int p, uint8_t l) { (void)p;(void)l; lv_color_t c = {0}; return c; }
inline lv_color_t lv_palette_darken(int p, uint8_t l) { (void)p;(void)l; lv_color_t c = {0}; return c; }
inline int32_t lv_slider_get_value(lv_obj_t* obj) { (void)obj; return 0; }
inline void lv_slider_set_value(lv_obj_t* obj, int32_t val, uint8_t anim) { (void)obj;(void)val;(void)anim; }
inline void lv_slider_set_range(lv_obj_t* obj, int32_t min, int32_t max) { (void)obj;(void)min;(void)max; }
inline void lv_bar_set_value(lv_obj_t* obj, int32_t val, uint8_t anim) { (void)obj;(void)val;(void)anim; }
inline void lv_bar_set_range(lv_obj_t* obj, int32_t min, int32_t max) { (void)obj;(void)min;(void)max; }
inline void lv_arc_set_value(lv_obj_t* obj, int16_t val) { (void)obj;(void)val; }
inline void lv_arc_set_range(lv_obj_t* obj, uint16_t min, uint16_t max) { (void)obj;(void)min;(void)max; }
inline lv_chart_series_t* lv_chart_add_series(lv_obj_t* obj, lv_color_t color, uint8_t axis) { (void)obj;(void)color;(void)axis; return nullptr; }
inline void lv_chart_set_next_value(lv_obj_t* obj, lv_chart_series_t* ser, lv_coord_t val) { (void)obj;(void)ser;(void)val; }
inline void lv_chart_set_point_count(lv_obj_t* obj, uint16_t cnt) { (void)obj;(void)cnt; }
inline void lv_chart_set_type(lv_obj_t* obj, uint8_t type) { (void)obj;(void)type; }
inline void lv_chart_refresh(lv_obj_t* obj) { (void)obj; }
inline void lv_img_set_src(lv_obj_t* obj, const void* src) { (void)obj;(void)src; }
inline void lv_textarea_set_text(lv_obj_t* obj, const char* txt) { (void)obj;(void)txt; }
inline const char* lv_textarea_get_text(lv_obj_t* obj) { (void)obj; return ""; }
inline void lv_dropdown_set_options(lv_obj_t* obj, const char* opts) { (void)obj;(void)opts; }
inline uint16_t lv_dropdown_get_selected(lv_obj_t* obj) { (void)obj; return 0; }
inline const lv_font_t lv_font_montserrat_14 = {0};
inline const lv_font_t lv_font_montserrat_16 = {0};
inline const lv_font_t lv_font_montserrat_20 = {0};
inline const lv_font_t lv_font_montserrat_24 = {0};
inline const lv_font_t lv_font_montserrat_28 = {0};
inline const lv_font_t lv_font_montserrat_36 = {0};
inline const lv_font_t lv_font_montserrat_48 = {0};
#define LV_FONT_DEFAULT &lv_font_montserrat_14
#define LV_OBJ_FLAG_HIDDEN 1
#define LV_OBJ_FLAG_CLICKABLE 2
#define LV_OBJ_FLAG_SCROLLABLE 4
