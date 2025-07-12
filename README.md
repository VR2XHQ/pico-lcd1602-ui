<p align="center">
  <img src="assets/banner.png" alt="Pico LCD UI Banner" width="80%">
</p>

<p align="center">
  <img src="https://img.shields.io/github/license/VR2XHQ/pico-lcd1602-ui" />
  <img src="https://img.shields.io/github/last-commit/VR2XHQ/pico-lcd1602-ui" />
</p>


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


## 📺 Demo

<img src="assets/lcd_demo.png" alt="LCD demo image" width="70%">

