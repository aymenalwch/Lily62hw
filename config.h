// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define USB_VBUS_PIN GP19

#define SPLIT_USB_DETECT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_HAND_PIN GP20
#define SOFT_SERIAL_PIN GP9


#include_next <mcuconf.h>
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE
#define HAL_USE_I2C TRUE
#include_next <halconf.h>
#undef I2C_DRIVER
#define I2C_DRIVER I2CD0
#undef I2C1_SCL_PIN
#define I2C1_SCL_PIN GP1
#undef I2C1_SDA_PIN
#define I2C1_SDA_PIN GP0


#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H "./lib/glcdfont.c"
#    define OLED_DISPLAY_WIDTH 128
#    define OLED_DISPLAY_HEIGHT 64
#    define OLED_TIMEOUT 10000
// #    define OLED_FADE_OUT
// #    define OLED_FADE_OUT_INTERVAL 5
#endif // OLED_ENABLE


#ifdef RGBLIGHT_ENABLE
#   define WS2812_DI_PIN GP14
#   define RGBLIGHT_LED_COUNT 16   // Number of LEDs
#   define RGBLED_SPLIT {8, 8}
#   define RGBLIGHT_SPLIT         // sync split halfs
#   define RGBLIGHT_SLEEP      //  the RGB lighting will be switched off when the host goes to sleep
#   define RGBLIGHT_MODE_PLAIN
#   define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_EFFECT_RAINBOW_MOOD
#   define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#   define RGBLIGHT_EFFECT_SNAKE
#   define RGBLIGHT_EFFECT_STATIC_GRADIENT
#   define RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_LAYERS

#endif
// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow mood
// 9-14 = Rainbow WAVES
// 15-17 = Snake
// 18-27 = Static Gradient
// 28-33 = Waves

#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 51
#define RGBLIGHT_VAL_STEP 51
// #define RGBLIGHT_DEFAULT_MODE RGB_MODE_RGBTEST
#define RGBLIGHT_DEFAULT_ON false
#define RGBLIGHT_TIMEOUT 10000  // 10 seconds