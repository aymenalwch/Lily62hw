// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#ifdef OLED_ENABLE
#include "oled.c"
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_7x5(
  //,-----------------------------------------------------|                                |-----------------------------------------------------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
      KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, LT(3,KC_LBRC),    LT(3,KC_RBRC),    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC,   MO(2),         MO(1),    LT(1,KC_PSCR),  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
            //|-------------------------------------------|                                |-----------------------------------------------------|
  ),
    [1] = LAYOUT_7x5(
//,-----------------------------------------------------|                    |-----------------------------------------------------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
       KC_TAB, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,                      KC_PGUP, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_CAPS, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
      KC_LSFT, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, _______,    _______, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC, _______, _______,    _______,  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  ),
    [2] = LAYOUT_7x5(
  //,-----------------------------------------------------|                    |-----------------------------------------------------|
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
       KC_TAB, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PPLS,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
      KC_CAPS, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
      KC_LSFT,   KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS,
               KC_LCTL, KC_LGUI, KC_LALT,  KC_SPC, _______, _______,    _______,  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  ),
    [3] = LAYOUT_7x5(
  //,--------------------------------------------------------|                    |-----------------------------------------------------|
      RGB_TOG,  XXXXXXX, RGB_M_B, RGB_M_R,  RGB_M_G, RGB_M_TW,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      VK_TOGG,  XXXXXXX, RGB_SAD, RGB_VAI,  RGB_SAI,  XXXXXXX,                      XXXXXXX, UG_SATD, UG_VALU, UG_SATU, XXXXXXX, XXXXXXX,
      XXXXXXX,  XXXXXXX, RGB_HUD, RGB_VAD,  RGB_HUI,  XXXXXXX,                      XXXXXXX, UG_HUED, UG_VALD, UG_HUEU, XXXXXXX, XXXXXXX,
      XXXXXXX,  XXXXXXX, UG_PREV, XXXXXXX,  UG_NEXT,  XXXXXXX, _______,    _______, XXXXXXX, UG_SPDD, XXXXXXX, UG_SPDU, XXXXXXX, XXXXXXX,
                KC_LCTL, KC_LGUI, KC_LALT,   KC_SPC,  _______, _______,    _______,  KC_ENT, KC_BSPC,  KC_DEL, KC_RGUI, KC_LCTL
  //|--------+--------+--------+--------+----------+---------|                    |--------+--------+--------+--------+--------+--------|
  )
};