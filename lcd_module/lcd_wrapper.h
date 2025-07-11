#ifndef LCD_WRAPPER_H
#define LCD_WRAPPER_H

#include <stdint.h>
#include <hardware/i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

// 📍 初始化 LCD（必須先呼叫）
void lcd_init(uint8_t address, uint8_t cols, uint8_t rows,
              i2c_inst_t* I2C, uint SDA, uint SCL);

// 🧹 清除顯示
void lcd_clear(void);

// 💡 背光控制
void lcd_backlight_on(void);
void lcd_backlight_off(void);

// 📐 設定游標位置
void lcd_set_cursor(uint8_t row, uint8_t col);

// 📺 印出字串（傳入 C 字串）
void lcd_print_string(const char* text);

// 💗 印出自訂符號
void lcd_print_custom_char(uint8_t location);

// 🧩 建立自訂符號（傳入 8-byte 陣列）
void lcd_create_custom_char(uint8_t location, const uint8_t* charmap);

void lcd_set_backlight(bool enable);
void lcd_set_display(bool enable);
void lcd_set_cursor_visible(bool enable);
void lcd_set_cursor_blink(bool enable);
void lcd_set_text_direction(bool left_to_right);  // true: LTR, false: RTL


#ifdef __cplusplus
}
#endif

#endif // LCD_WRAPPER_H
