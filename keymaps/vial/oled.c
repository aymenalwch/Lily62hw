
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

// const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {0, 64, 85, 127, 170};
// static void oled_render_led_mode(void) {
//     int speed = 0;
//     char* mode;
//     if (rgblight_get_mode() == 1){
//         speed = 0;
//         mode = "   SOLID   ";
//         }
//     if (rgblight_get_mode() > 1){
//         speed = rgblight_get_mode()-1;
//         mode = "   BREATH  ";
//         }
//     if (rgblight_get_mode() > 5){
//         speed = rgblight_get_mode()-5;
//         mode = "   CYCLE   ";
//         }
//     if (rgblight_get_mode() > 8){
//         speed = rgblight_get_mode()-8;
//         mode = "   RAINBOW ";
//         }
//     if (rgblight_get_mode() > 14){
//         speed = rgblight_get_mode()-14;
//         mode = "   SNAKE   ";
//         }
//     if (rgblight_get_mode() > 17){
//         speed = rgblight_get_mode()-17;
//         mode = "   GRADIENT";
//         }
//     if (rgblight_get_mode() > 27){
//         speed = rgblight_get_mode()-27;
//         mode = "   WAVES   ";
//         }
//     oled_set_cursor(1, 2);
//     oled_write(mode, false);
//     oled_write_ln(get_u8_str(speed, ' '), false);
//     oled_write("    HUE  :  ", false);
//     oled_write_ln(get_u8_str(rgblight_get_hue(), ' '), false);
// }

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
        oled_render_logo();
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
        // oled_render_led_mode();

        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(1, 0);
        oled_write(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

        oled_set_cursor(1, 5);
        oled_write_ln(read_keylog(), false);
        // oled_write_ln(read_keylogs(), false);
        // oled_set_cursor(0, 5);
        // oled_render_logo();
    } else {
        oled_render_layer_state();
        // oled_render_led_mode();

        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(1, 0);
        oled_write(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

        oled_set_cursor(15, 7);
        oled_write_ln(PSTR("SLAVE"), false);
    }

    // snprintf(temp, sizeof(temp) + 1, "M:%3dH:%3dS:%3dV:%3d", rgb_config.mode, rgb_config.hsv.h, rgb_config.hsv.s, rgb_config.hsv.v);
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
