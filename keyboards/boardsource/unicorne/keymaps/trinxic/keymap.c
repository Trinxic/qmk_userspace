#pragma once
#include "keyboard.h"
#include "layers/layers.h"

#if __has_include("features/features.h")
#    include "features/features.h"
#endif

// NOTE: These aren't proper 3x5 layouts, they're just `XXXXXX`ed on the outer columns
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "layers/dvorak5.h"
#include "layers/qwerty5.h"
#include "layers/navigation5.h"
#include "layers/symbols5.h"
#include "layers/game1.h"
#include "layers/game2.h"
#include "layers/function5.h"
#include "layers/system.h"
};

// don't touch.. idk what this does at the moment
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif

// Layer Timeout -- NOTE: this may be moved eventually...
void matrix_scan_user(void) {
    mod_timeout_reached = last_input_activity_elapsed() >= last_mod_timeout;
    if (get_highest_layer(layer_state) == _FUNC || get_highest_layer(layer_state) == _SYS && last_input_activity_elapsed() >= 10000) { // 10 seconds
        layer_move(_DVRK);
        oled_off(); // not working...
    }
}
