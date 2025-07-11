#ifndef LCD_ICONS_H
#define LCD_ICONS_H

#include <stdint.h>
#include "lcd_wrapper.h"

// 🎯 圖示索引列舉
typedef enum {
    ICON_HEART = 0,
    ICON_SMILE,
    ICON_BATTERY,
    ICON_ARROW_UP,
    ICON_ARROW_DOWN,
    ICON_COUNT  // 圖示總數（自動計算）
} lcd_icon_t;

// 📦 所有圖示的 CGRAM 字形資料（ICON_COUNT x 8）
static const uint8_t LCD_ICON_MAP[ICON_COUNT][8] = {
    // ICON_HEART
    {0x00, 0x0A, 0x1F, 0x1F, 0x1F, 0x0E, 0x04, 0x00},

    // ICON_SMILE
    {0x00, 0x0A, 0x00, 0x00, 0x11, 0x0E, 0x00, 0x00},

    // ICON_BATTERY
    {0x0E, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F},

    // ICON_ARROW_UP
    {0x04, 0x0E, 0x15, 0x04, 0x04, 0x00, 0x00, 0x00},

    // ICON_ARROW_DOWN
    {0x00, 0x00, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00},
};

// 🧩 一次註冊所有圖示進 CGRAM
static inline void lcd_register_all_icons(void) {
    for (uint8_t i = 0; i < ICON_COUNT; ++i) {
        lcd_create_custom_char(i, LCD_ICON_MAP[i]);
    }
}

// 📺 顯示指定圖示
static inline void lcd_print_icon(lcd_icon_t icon) {
    if (icon < ICON_COUNT) {
        lcd_print_custom_char((uint8_t)icon);
    }
}

#endif // LCD_ICONS_H
