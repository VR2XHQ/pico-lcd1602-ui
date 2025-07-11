#include "LCD_I2C.hpp"
#include <string.h>
#include "lcd_wrapper.h"

extern "C" {

// 🔐 內部 LCD 實例
static LCD_I2C* lcd_instance = nullptr;

// 🛠 初始化 LCD 實例
void lcd_init(uint8_t address, uint8_t cols, uint8_t rows,
              i2c_inst_t* I2C, uint SDA, uint SCL) {
    static LCD_I2C lcd(address, cols, rows, I2C, SDA, SCL);
    lcd_instance = &lcd;
}

// 🔲 清除螢幕
void lcd_clear() {
    if (lcd_instance) lcd_instance->Clear();
}

// 🔦 打開背光
void lcd_backlight_on() {
    if (lcd_instance) lcd_instance->BacklightOn();
}

// 💡 關閉背光
void lcd_backlight_off() {
    if (lcd_instance) lcd_instance->BacklightOff();
}

// ✍️ 印出字串（傳入 C-style 字串）
void lcd_print_string(const char* text) {
    if (lcd_instance && text) lcd_instance->PrintString(text);
}

// ➡️ 設定游標位置
void lcd_set_cursor(uint8_t row, uint8_t col) {
    if (lcd_instance) lcd_instance->SetCursor(row, col);
}

// 💗 顯示自定義符號
void lcd_print_custom_char(uint8_t location) {
    if (lcd_instance) lcd_instance->PrintCustomChar(location);
}

// 🧩 建立自定義符號（傳入 byte 陣列）
void lcd_create_custom_char(uint8_t location, const uint8_t* charmap) {
    if (lcd_instance && charmap) {
        LCD_I2C::array temp{};
        memcpy(temp.data(), charmap, LCD_I2C::CUSTOM_SYMBOL_SIZE);
        lcd_instance->CreateCustomChar(location, temp);
    }
}

void lcd_set_backlight(bool enable) {
    if (lcd_instance) lcd_instance->SetBacklight(enable);
}

void lcd_set_display(bool enable) {
    if (lcd_instance) {
        if (enable)
            lcd_instance->DisplayOn();
        else
            lcd_instance->DisplayOff();
    }
}

void lcd_set_cursor_visible(bool enable) {
    if (lcd_instance) {
        if (enable)
            lcd_instance->CursorOn();
        else
            lcd_instance->CursorOff();
    }
}

void lcd_set_cursor_blink(bool enable) {
    if (lcd_instance) {
        if (enable)
            lcd_instance->CursorBlinkOn();
        else
            lcd_instance->CursorBlinkOff();
    }
}

void lcd_set_text_direction(bool left_to_right) {
    if (lcd_instance) {
        if (left_to_right)
            lcd_instance->SetTextLeftToRight();
        else
            lcd_instance->SetTextRightToLeft();
    }
}

} // extern "C"
