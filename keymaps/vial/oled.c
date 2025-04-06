#include <stdio.h>

#ifdef OLED_ENABLE

static void oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    char * text;
    switch (get_highest_layer(layer_state)) {
        case 0:
            text = "- QWERTY -";
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        case 1:
            text = " - FUNC - ";
            oled_set_cursor((oled_max_chars() - strlen(text))/2+1, 0);
            oled_write_ln_P(PSTR(text), false);
            break;
        case 2:
            text = "- SYMBOL -";
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
    if (rgblight_get_mode() > 20){
        speed = rgblight_get_mode()-20;
        mode = "   GRADIENT";
        }
    if (rgblight_get_mode() > 30){
        speed = rgblight_get_mode()-30;
        mode = "   WAVES   ";
        }
    oled_set_cursor(1, 2);
    oled_write(mode, false);
    oled_write_ln(get_u8_str(speed, ' '), false);
    oled_write("    SAT  :  ", false);
    oled_write_ln(get_u8_str(rgblight_get_sat(), ' '), false);
    oled_write("    HUE  :  ", false);
    oled_write_ln(get_u8_str(rgblight_get_hue(), ' '), false);
}


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
        
        // led_t led_state = host_keyboard_led_state();
        // oled_set_cursor(1, 0);
        // oled_write(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        // oled_set_cursor(15, 7);
        // oled_write_ln(PSTR(" MTR "), false);


        oled_set_cursor(0, 6);
        // oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_set_cursor(0, 5);
        // oled_write_P(read_logo(), false);
    } else {
        oled_render_layer_state();
        oled_render_led_mode();

        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(1, 0);
        oled_write(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_set_cursor(15, 7);

        oled_write_ln(PSTR("SLAVE"), false);
        oled_set_cursor(0, 4);
        oled_write_P(read_logo(), false);
    }
    return false;
}

// Render a message before booting into bootloader mode -------------------------------------
void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }
    oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
    oled_write_P(read_logo(), false);
        return false;
}

#endif // OLED_ENABLE