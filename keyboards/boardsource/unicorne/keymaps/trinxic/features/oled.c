#include QMK_KEYBOARD_H
#include "layers/layers.h"

// NOTE:
// - `features/features.h` already considers if oled is enabled
// - `oled_init_kb` -> `oled_init_user` since now using "Userspace"

// Rotate Screens
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    bool vertical_text = false;
    if (vertical_text) { // vertical
        if (!is_keyboard_left()) {
            return OLED_ROTATION_180;
        }
        return rotation;
    } else { // horizontal
        return OLED_ROTATION_270;
    }
}

// Layer Status
void render_current_layer(void) {
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
        case _DVRK:
            oled_write_P(PSTR(" DVRK\n"), false);
            break;
        case _QWRT:
            oled_write_P(PSTR(" QWRT\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR(" SYMB\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR(" NAV \n"), false);
            break;
        case _GAM1:
            oled_write_P(PSTR("GAME1\n"), false);
            break;
        case _GAM2:
            oled_write_P(PSTR("GAME2\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR(" FUNC\n"), false);
            break;
        case _SYS:
            oled_write_P(PSTR(" SYS \n"), false);
            break;
        default:
            oled_write_P(PSTR("ERROR\n"), false);
            break;
    }
}

static void render_os_logo(int os_int) {
    static const char PROGMEM raw_os_logo[3][128] = {{
                                                         // Apple Logo
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 0, 0, 0, 112, 124, 62, 62, 159, 135, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 248, 252, 254, 255, 255, 255, 255, 255, 255, 255, 255, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 31, 15, 6, 0, 0, 0, 0, 0, 0, 0, 31, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 248, 224, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, 15, 31, 63, 127, 127, 127, 63, 63, 31, 31, 31, 31, 63, 63, 127, 127, 63, 63, 31, 15, 3, 0, 0, 0, 0,
                                                     },
                                                     {
                                                         // Archlinux Logo
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 240, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 248, 242, 247, 239, 255, 255, 255, 252, 240, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 240, 252, 254, 255, 255, 127, 7, 3, 1, 1, 3, 7, 127, 255, 255, 255, 252, 184, 160, 128, 0, 0, 0, 0, 0, 0, 0, 0, 8, 12, 7, 7, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 3, 7, 14, 8, 0, 0, 0,
                                                     },
                                                     {
                                                         // Windows Logo
                                                         0, 0, 0, 128, 128, 128, 128, 192, 192, 192, 192, 192, 192, 224, 0, 224, 224, 224, 224, 224, 240, 240, 240, 240, 240, 240, 248, 248, 248, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 0, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 7, 7, 7, 7, 7, 0, 7, 15, 15, 15, 15, 15, 15, 15, 15, 31, 31, 31, 31, 31, 0, 0, 0,
                                                     }};
    oled_set_cursor(0, 5);
    oled_write_raw_P(raw_os_logo[os_int], sizeof(raw_os_logo[os_int]));
}

static int os_num;

// Display Current OS on start-up
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    if (is_keyboard_master()) {
        switch (detected_os) {
            case OS_MACOS:
            case OS_IOS:
                os_num = 1;
                break;
            case OS_WINDOWS:
                os_num = 2;
                break;
            case OS_LINUX:
                os_num = 0;
                break;
            case OS_UNSURE:
                os_num = 0;
            default:
                // oled_write(PSTR("OS: ?"), false);
                break;
        }
    }
    return true;
}

// Mod Key Icons (Paired)
static const char PROGMEM mod_icons[4][4][64] = { // '1' = pressed
    {
        // ctl | shft
        /*0 0*/ {0, 240, 248, 4, 2, 130, 194, 98, 50, 98, 194, 130, 2, 4, 248, 0, 0, 240, 248, 4, 2, 66, 98, 242, 250, 242, 98, 66, 2, 4, 248, 0, 0, 31, 63, 112, 96, 97, 96, 96, 96, 96, 96, 97, 32, 16, 15, 0, 0, 31, 63, 112, 96, 96, 96, 111, 111, 111, 96, 96, 32, 16, 15, 0},
        /*0 1*/ {0, 240, 248, 4, 2, 130, 194, 98, 50, 98, 194, 130, 2, 4, 248, 0, 0, 240, 248, 252, 124, 60, 28, 12, 28, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 112, 96, 97, 96, 96, 96, 96, 96, 97, 32, 16, 15, 0, 0, 31, 63, 127, 127, 127, 96, 96, 96, 127, 127, 127, 63, 31, 0, 0},
        /*1 0*/ {0, 240, 248, 252, 252, 124, 60, 156, 60, 124, 252, 252, 248, 240, 0, 0, 0, 240, 248, 4, 2, 66, 98, 242, 250, 242, 98, 66, 2, 4, 248, 0, 0, 31, 63, 127, 124, 126, 127, 127, 127, 126, 124, 127, 63, 31, 0, 0, 0, 31, 63, 112, 96, 96, 96, 111, 111, 111, 96, 96, 32, 16, 15, 0},
        /*1 1*/ {0, 240, 248, 252, 252, 124, 60, 156, 60, 124, 252, 252, 248, 240, 0, 0, 0, 240, 248, 252, 124, 60, 28, 12, 28, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 127, 124, 126, 127, 127, 127, 126, 124, 127, 63, 31, 0, 0, 0, 31, 63, 127, 127, 127, 96, 96, 96, 127, 127, 127, 63, 31, 0, 0},
    },
    {
        // gui | alt (linux/unknown)
        /*0 0*/ {0, 240, 248, 4, 114, 250, 154, 154, 154, 154, 154, 186, 50, 4, 248, 0, 0, 240, 248, 4, 2, 194, 226, 50, 50, 50, 226, 194, 2, 4, 248, 0, 0, 31, 63, 112, 102, 110, 108, 108, 108, 108, 108, 111, 39, 16, 15, 0, 0, 31, 63, 112, 96, 103, 103, 97, 97, 97, 103, 103, 32, 16, 15, 0},
        /*0 1*/ {0, 240, 248, 4, 114, 250, 154, 154, 154, 154, 154, 186, 50, 4, 248, 0, 0, 240, 248, 252, 124, 60, 156, 156, 156, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 112, 102, 110, 108, 108, 108, 108, 108, 111, 39, 16, 15, 0, 0, 31, 63, 127, 112, 112, 125, 125, 125, 112, 112, 127, 63, 31, 0, 0},
        /*1 0*/ {0, 240, 248, 28, 12, 204, 204, 204, 204, 204, 140, 156, 248, 240, 0, 0, 0, 240, 248, 4, 2, 194, 226, 50, 50, 50, 226, 194, 2, 4, 248, 0, 0, 31, 63, 115, 98, 102, 102, 102, 102, 102, 96, 113, 63, 31, 0, 0, 0, 31, 63, 112, 96, 103, 103, 97, 97, 97, 103, 103, 32, 16, 15, 0},
        /*1 1*/ {0, 240, 248, 28, 12, 204, 204, 204, 204, 204, 140, 156, 248, 240, 0, 0, 0, 240, 248, 252, 124, 60, 156, 156, 156, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 115, 98, 102, 102, 102, 102, 102, 96, 113, 63, 31, 0, 0, 0, 31, 63, 127, 112, 112, 125, 125, 125, 112, 112, 127, 63, 31, 0, 0},
    },
    {
        // gui | alt (mac/ios)
        /*0 0*/ {0, 240, 248, 4, 18, 42, 242, 34, 34, 34, 242, 42, 18, 4, 248, 0, 0, 240, 248, 4, 2, 18, 18, 34, 194, 2, 18, 18, 2, 4, 248, 0, 0, 31, 63, 112, 100, 106, 103, 98, 98, 98, 103, 106, 36, 16, 15, 0, 0, 31, 63, 112, 96, 96, 96, 96, 97, 98, 100, 100, 32, 16, 15, 0},
        /*0 1*/ {0, 240, 248, 4, 18, 42, 242, 34, 34, 34, 242, 42, 18, 4, 248, 0, 0, 240, 248, 252, 220, 220, 188, 124, 252, 220, 220, 252, 248, 240, 0, 0, 0, 31, 63, 112, 100, 106, 103, 98, 98, 98, 103, 106, 36, 16, 15, 0, 0, 31, 63, 127, 127, 127, 127, 124, 123, 119, 119, 127, 63, 31, 0, 0},
        /*1 0*/ {0, 240, 248, 220, 172, 28, 188, 188, 188, 28, 172, 220, 248, 240, 0, 0, 0, 240, 248, 4, 2, 18, 18, 34, 194, 2, 18, 18, 2, 4, 248, 0, 0, 31, 63, 119, 107, 112, 123, 123, 123, 112, 107, 119, 63, 31, 0, 0, 0, 31, 63, 112, 96, 96, 96, 96, 97, 98, 100, 100, 32, 16, 15, 0},
        /*1 1*/ {0, 240, 248, 220, 172, 28, 188, 188, 188, 28, 172, 220, 248, 240, 0, 0, 0, 240, 248, 252, 220, 220, 188, 124, 252, 220, 220, 252, 248, 240, 0, 0, 0, 31, 63, 119, 107, 112, 123, 123, 123, 112, 107, 119, 63, 31, 0, 0, 0, 31, 63, 127, 127, 127, 127, 124, 123, 119, 119, 127, 63, 31, 0, 0},
    },
    {
        // gui | alt (windows)
        /*0 0*/ {0, 240, 248, 4, 2, 114, 114, 114, 2, 114, 114, 114, 2, 4, 248, 0, 0, 240, 248, 4, 2, 194, 226, 50, 50, 50, 226, 194, 2, 4, 248, 0, 0, 31, 63, 112, 96, 103, 103, 103, 96, 103, 103, 103, 32, 16, 15, 0, 0, 31, 63, 112, 96, 103, 103, 97, 97, 97, 103, 103, 32, 16, 15, 0},
        /*0 1*/ {0, 240, 248, 4, 2, 114, 114, 114, 2, 114, 114, 114, 2, 4, 248, 0, 0, 240, 248, 252, 124, 60, 156, 156, 156, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 112, 96, 103, 103, 103, 96, 103, 103, 103, 32, 16, 15, 0, 0, 31, 63, 127, 112, 112, 125, 125, 125, 112, 112, 127, 63, 31, 0, 0},
        /*1 0*/ {0, 240, 248, 252, 28, 28, 28, 252, 28, 28, 28, 252, 248, 240, 0, 0, 0, 240, 248, 4, 2, 194, 226, 50, 50, 50, 226, 194, 2, 4, 248, 0, 0, 31, 63, 127, 113, 113, 113, 127, 113, 113, 113, 127, 63, 31, 0, 0, 0, 31, 63, 112, 96, 103, 103, 97, 97, 97, 103, 103, 32, 16, 15, 0},
        /*1 1*/ {0, 240, 248, 252, 28, 28, 28, 252, 28, 28, 28, 252, 248, 240, 0, 0, 0, 240, 248, 252, 124, 60, 156, 156, 156, 60, 124, 252, 248, 240, 0, 0, 0, 31, 63, 127, 113, 113, 113, 127, 113, 113, 113, 127, 63, 31, 0, 0, 0, 31, 63, 127, 112, 112, 125, 125, 125, 112, 112, 127, 63, 31, 0, 0},
    }};

static void render_ctl_shift(int ctl, int shft) {
    oled_set_cursor(0, 5);
    oled_write_raw_P( // [2] and [3] have ctrl so 0|2 + 0|1 can produce all for 4 combinations.. so smart
        mod_icons[0][2 * ctl + shft], sizeof(mod_icons[0][2 * ctl + shft]));
}

static void render_gui_alt(int gui, int alt) {
    oled_set_cursor(0, 7);
    oled_write_raw_P(mod_icons[1 + os_num][2 * gui + alt], sizeof(mod_icons[1 + os_num][2 * gui + alt]));
}

/**
 * Render OS logo if all 4 mod keys are pressed simultaniously.
 * Render active mod keys
 * If no mod keys are active, clear area to reduce oled burn-in
 */
void render_mod_status(uint8_t mod_status) {
    if ((mod_status & MOD_MASK_CTRL) && (mod_status & MOD_MASK_SHIFT) && (mod_status & MOD_MASK_GUI) && (mod_status & MOD_MASK_ALT)) {
        render_os_logo(os_num);
        return;
    } else if (!((mod_status & MOD_MASK_CTRL) || (mod_status & MOD_MASK_SHIFT) || (mod_status & MOD_MASK_GUI) || (mod_status & MOD_MASK_ALT))) {
        for (int i = 0; i < 4; i++) {
            oled_set_cursor(0, 5 + i);
            oled_write_P(PSTR("      "), false);
        }
        return;
    }

    render_ctl_shift((mod_status & MOD_MASK_CTRL) ? 1 : 0, ((mod_status & MOD_MASK_SHIFT) || host_keyboard_led_state().caps_lock) ? 1 : 0);
    render_gui_alt((mod_status & MOD_MASK_GUI) ? 1 : 0, (mod_status & MOD_MASK_ALT) ? 1 : 0);
}

void render_master_oled(void) {
    render_current_layer();
    render_mod_status(get_mods() | get_oneshot_mods());
    // render_wpm();
}

void render_slave_oled(void) {
    render_current_layer();
    // render_mod_status(get_mods() | get_oneshot_mods());
}

bool oled_task_user() {
    if (is_keyboard_master())
        render_master_oled();
    else
        render_slave_oled();

    return false;
}

/*
// Display Words-per-minute | toggle by appending/removing 1 '/' to the line above
int peak_wpm, curr_wpm;
void render_wpm(void) {  // eventually replace with Luna?
    curr_wpm = get_current_wpm();

    // get WPM Peak | reset if wpm is 0
    oled_set_cursor(1, 12);
    if (curr_wpm == 0) { peak_wpm = 0; }
    if (curr_wpm > peak_wpm || last_input_activity_elapsed() > 3500) {
        peak_wpm = curr_wpm;
    }
    oled_write(get_u8_str(peak_wpm, '0'), false);

    oled_set_cursor(0, 13);
    oled_write(PSTR("-----"), false);
    oled_set_cursor(1, 14);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    oled_set_cursor(1, 15);
    oled_write(PSTR("WPM"), false);
}
//*/
