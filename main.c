#include "lcd_ui.h"
#include <pico/binary_info.h>

#define I2C PICO_DEFAULT_I2C_INSTANCE
#define SDA PICO_DEFAULT_I2C_SDA_PIN
#define SCL PICO_DEFAULT_I2C_SCL_PIN
#define I2C_ADDRESS 0x26
#define LCD_COLUMNS 20
#define LCD_ROWS 4

int main() {

    bi_decl(bi_program_feature_group(0x1000, 0, "I2C configuration"));
    bi_decl(bi_program_feature_group(0x1000, 1, "LCD configuration"));
    bi_decl(bi_ptr_int32(0x1000, 0, i2c_address, I2C_ADDRESS));
    bi_decl(bi_ptr_int32(0x1000, 1, lcd_columns, LCD_COLUMNS));
    bi_decl(bi_ptr_int32(0x1000, 1, lcd_rows, LCD_ROWS));

    bi_decl(bi_1pin_with_name(SDA, "[SDA] LCD screen serial data pin"));
    bi_decl(bi_1pin_with_name(SCL, "[SCL] LCD screen serial clock pin"));
    
    // lcd_init(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS, I2C, SDA, SCL);
    lcd_ui_init(I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS, I2C, SDA, SCL);

    lcd_ui_show_welcome();

    sleep_ms(2000);
    lcd_ui_show_status_bar();

    sleep_ms(2000);
    lcd_ui_show_message("Charging", ICON_BATTERY);
    
    return 0;
}
