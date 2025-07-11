# Pico LCD1602 UI Module

🧩 A modular LCD control system for Raspberry Pi Pico, written in C/C++ with support for custom icons, semantic UI functions, and mixed-style API.

## Features

- ✅ C-style fallback functions for pure-C usage
- 🌈 `lcd_icons.h` with custom 5x8 CGRAM symbols
- 🎛️ `lcd_ui.h` semantic API like `lcd_ui_show_status_bar()`
- 🧵 CMake modular structure (`lcd_module/`)

## Getting Started

```c
lcd_ui_init(0x27, 16, 2, i2c0, 4, 5);
lcd_ui_show_welcome();
