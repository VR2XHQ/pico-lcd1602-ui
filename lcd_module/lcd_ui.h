#ifndef LCD_UI_H
#define LCD_UI_H

#include <stdbool.h>
#include <stdint.h>
#include "lcd_wrapper.h"
#include "lcd_icons.h"

// 🧩 UI 初始化：初始化 LCD + 圖示
static inline void lcd_ui_init(uint8_t address, uint8_t cols, uint8_t rows,
                               i2c_inst_t* I2C, uint SDA, uint SCL) {
    lcd_init(address, cols, rows, I2C, SDA, SCL);
    lcd_register_all_icons();
    lcd_set_backlight(true);
    lcd_set_display(true);
}

// 📺 顯示歡迎訊息
static inline void lcd_ui_show_welcome(void) {
    lcd_set_cursor(0, 0);
    lcd_print_string("Hello ");
    lcd_print_icon(ICON_HEART);
    lcd_print_icon(ICON_SMILE);
}

// 🔋 顯示狀態列（電池＋方向）
static inline void lcd_ui_show_status_bar(void) {
    lcd_set_cursor(1, 0);
    lcd_print_string("Power ");
    lcd_print_icon(ICON_BATTERY);
    lcd_print_string(" ");
    lcd_print_icon(ICON_ARROW_UP);
}

// 📋 顯示任意文字＋圖示
static inline void lcd_ui_show_message(const char* message, lcd_icon_t icon) {
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_print_string(message);
    lcd_print_string(" ");
    lcd_print_icon(icon);
}

#endif // LCD_UI_H
