# 建立模組庫
add_library(lcd_module STATIC
    LCD_I2C.cpp
    lcd_wrapper.cpp
)

# 模組內部標頭，其他 target 也可見
target_include_directories(lcd_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 啟用 C++20 特性
#arget_compile_features(lcd_module PRIVATE cxx_std_20)

# 模組需要用到 Pico 的 I2C 等庫
target_link_libraries(lcd_module
    pico_stdlib
    hardware_i2c
)

# 傳遞預設 I2C 設定
target_compile_definitions(lcd_module PRIVATE
    PICO_DEFAULT_I2C_INSTANCE=i2c0
    #PICO_DEFAULT_I2C_SDA_PIN=4
    #PICO_DEFAULT_I2C_SCL_PIN=5
)
