# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(lcd1602 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(lcd1602 main.c)

pico_set_program_name(lcd1602 "lcd1602")
pico_set_program_version(lcd1602 "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(lcd1602 1)
pico_enable_stdio_usb(lcd1602 0)

# Add the standard library to the build
target_link_libraries(lcd1602
    pico_stdlib
    hardware_i2c
    lcd_module
)

# Add the standard include files to the build
target_include_directories(lcd1602 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/lcd_module
)

pico_add_extra_outputs(lcd1602)

target_compile_definitions(lcd1602 PRIVATE
    PICO_DEFAULT_I2C_INSTANCE=i2c0
    #PICO_DEFAULT_I2C_SDA_PIN=4
    #PICO_DEFAULT_I2C_SCL_PIN=5
)

add_subdirectory(lcd_module)

