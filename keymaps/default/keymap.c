// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later



#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_joined_14x5(
  //,-----------------------------------------------------|                                |-----------------------------------------------------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                                |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------------|        |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, LT(3,KC_LBRC),    LT(3,KC_RBRC),    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------------|        |--------+--------+--------+--------+--------+--------+--------|
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC,   MO(1), MO(2),            LT(2,KC_PSCR),  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
            //|-------------------------------------------|                                |-----------------------------------------------------|
  ),

    [1] = LAYOUT_joined_14x5(
  //,-----------------------------------------------------|                    |-----------------------------------------------------|
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
       KC_TAB, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
      KC_CAPS, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
      KC_LSFT, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC, _______,   MO(2),      MO(2),  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  ),

    [2] = LAYOUT_joined_14x5(
  //,-----------------------------------------------------|                    |-----------------------------------------------------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
       KC_TAB, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP, XXXXXXX,
      KC_CAPS, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, XXXXXXX,
      KC_LSFT,   KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC,   MO(1), _______,    _______,  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  ),

    [3] = LAYOUT_joined_14x5(
  //,--------------------------------------------------------|                    |-----------------------------------------------------|
      RGB_TOG,  RGB_M_P, RGB_M_B, RGB_M_R,  RGB_M_G, RGB_M_TW,                     RGB_M_SW, RGB_M_K, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      VK_TOGG,  XXXXXXX, RGB_SAD, RGB_VAI,  RGB_SAI,  RGB_SPI,                      XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,
      XXXXXXX,  XXXXXXX, RGB_HUD, RGB_VAD,  RGB_HUI,  RGB_SPD,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, _______,    _______, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, XXXXXXX,
                KC_LCTL, KC_LGUI, KC_LALT,   KC_SPC,    MO(1),   MO(2),      MO(2),  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
  //|--------+--------+--------+--------+----------+---------|                    |--------+--------+--------+--------+--------+--------|
  )
};


#ifdef OLED_ENABLE

static void oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    char * text;
    switch (get_highest_layer(layer_state)) {
        case 0:
            // oled_write_P(PSTR("QWERTY\n"), false);
            text = "- QWERTY -";
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        case 1:
            text = "- SYMBOL -";
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        case 2:
            text = " - FUNC - ";
            // oled_clear();
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        case 3:
            text = "- ADJUST -";
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
}

const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {0, 64, 85, 127, 170};
static void oled_render_led_mode(void) {
    int speed = 0;
    char* mode;
    if (rgblight_get_mode() == 1){
        speed = 0;
        mode = "   SOLID   ";
        }
    if (rgblight_get_mode() > 1){
        speed = rgblight_get_mode()-1;
        mode = "   BREATH  ";
        }
    if (rgblight_get_mode() > 5){
        speed = rgblight_get_mode()-5;
        mode = "   CYCLE   ";
        }
    if (rgblight_get_mode() > 8){
        speed = rgblight_get_mode()-8;
        mode = "   RAINBOW ";
        }
    if (rgblight_get_mode() > 14){
        speed = rgblight_get_mode()-14;
        mode = "   SNAKE   ";
        }
    if (rgblight_get_mode() > 17){
        speed = rgblight_get_mode()-17;
        mode = "   GRADIENT";
        }
    if (rgblight_get_mode() > 27){
        speed = rgblight_get_mode()-27;
        mode = "   WAVES   ";
        }
    oled_set_cursor(1, 2);
    oled_write(mode, false);
    oled_write_ln(get_u8_str(speed, ' '), false);
}

static void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

// ------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// ---------------------------------------------------------------------------------------------
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_led_mode();
        // oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);

            // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(1, 0);
    oled_write(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // snprintf(temp, sizeof(temp) + 1, "M:%3dH:%3dS:%3dV:%3d", rgb_config.mode, rgb_config.hsv.h, rgb_config.hsv.s, rgb_config.hsv.v);

        // oled_set_cursor(0, 5);
        // oled_render_logo();

    } else {
        // oled_render_layer_state();
        // oled_set_cursor(1, 5);
        oled_render_logo();
    }
    return false;
}

// Render a message before booting into bootloader mode -------------------------------------
// void oled_render_boot(bool bootloader) {
//     oled_clear();
//     for (int i = 0; i < 16; i++) {
//         oled_set_cursor(0, i);
//         if (bootloader) {
//             oled_write_P(PSTR("Awaiting New Firmware "), false);
//         } else {
//             oled_write_P(PSTR("Rebooting "), false);
//         }
//     }
//     oled_render_dirty(true);
// }
// bool shutdown_user(bool jump_to_bootloader) {
//     render_logo();
//         return false;
// }

#endif
