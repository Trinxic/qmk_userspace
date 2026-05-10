#pragma once
#include "layers/layers.h"
#include QMK_KEYBOARD_H

// ------------------- Combos ------------------- //
// NOTE: All combos resolve to the first layer (_DVRK). Write any combos with respect to said layer.
enum combos {
    CHORD_CAPS,
    TAB,
    ESC,
    ENTER,
    LEFT_FUNC,
    RIGHT_FUNC,
    LEFT_ALT,
    LEFT_ALT_SHIFT,
    LEFT_ALT_SHIFT_CTRL,
    LEFT_SHIFT,
    LEFT_CTRL,
    LEFT_CTRL_ALT,
    LEFT_CTRL_SHIFT,
    RIGHT_ALT,
    RIGHT_ALT_SHIFT,
    RIGHT_ALT_SHIFT_CTRL,
    RIGHT_SHIFT,
    RIGHT_CTRL,
    RIGHT_CTRL_ALT,
    RIGHT_CTRL_SHIFT,
};

const uint16_t PROGMEM chord_caps[]           = {KC_Q, KC_J, KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM tab[]                  = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM esc[]                  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM enter[]                = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM left_func[]            = {KC_SCLN, KC_COMM, COMBO_END};
const uint16_t PROGMEM right_func[]           = {KC_R, KC_L, COMBO_END};
const uint16_t PROGMEM left_alt[]             = {KC_QUOTE, KC_Q, COMBO_END};
const uint16_t PROGMEM left_alt_shift[]       = {KC_QUOT, KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM left_alt_shift_ctrl[]  = {KC_QUOT, KC_Q, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_shift[]           = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM left_ctrl[]            = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_ctrl_alt[]        = {KC_QUOT, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_ctrl_shift[]      = {KC_Q, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM right_alt[]            = {KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM right_alt_shift[]      = {KC_W, KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM right_alt_shift_ctrl[] = {KC_M, KC_W, KC_V, KC_Z, COMBO_END};
const uint16_t PROGMEM right_shift[]          = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM right_ctrl[]           = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM right_ctrl_alt[]       = {KC_M, KC_W, KC_Z, COMBO_END};
const uint16_t PROGMEM right_ctrl_shift[]     = {KC_M, KC_W, KC_V, COMBO_END};

combo_t                key_combos[]           = {
    [CHORD_CAPS]           = COMBO(chord_caps, KC_CAPS),
    [TAB]                  = COMBO(tab, KC_TAB),
    [ESC]                  = COMBO(esc, KC_ESC),
    [ENTER]                = COMBO(enter, KC_ENT),
    [LEFT_FUNC]            = COMBO(left_func, TO(_FUNC)),
    [RIGHT_FUNC]           = COMBO(right_func, TO(_FUNC)),
    [LEFT_ALT]             = COMBO(left_alt, KC_LALT),
    [LEFT_ALT_SHIFT]       = COMBO(left_alt_shift, LALT(KC_LSFT)),
    [LEFT_ALT_SHIFT_CTRL]  = COMBO(left_alt_shift_ctrl, LALT(LCTL(KC_LSFT))),
    [LEFT_SHIFT]           = COMBO(left_shift, KC_LSFT),
    [LEFT_CTRL]            = COMBO(left_ctrl, KC_LCTL),
    [LEFT_CTRL_ALT]        = COMBO(left_ctrl_alt, LCTL(KC_LALT)),
    [LEFT_CTRL_SHIFT]      = COMBO(left_ctrl_shift, LCTL(KC_LSFT)),
    [RIGHT_ALT]            = COMBO(right_alt, KC_RALT),
    [RIGHT_ALT_SHIFT]      = COMBO(right_alt_shift, RALT(KC_RSFT)),
    [RIGHT_ALT_SHIFT_CTRL] = COMBO(right_alt_shift_ctrl, RALT(RCTL(KC_RSFT))),
    [RIGHT_SHIFT]          = COMBO(right_shift, KC_RSFT),
    [RIGHT_CTRL]           = COMBO(right_ctrl, KC_RCTL),
    [RIGHT_CTRL_ALT]       = COMBO(right_ctrl_alt, RCTL(KC_RALT)),
    [RIGHT_CTRL_SHIFT]     = COMBO(right_ctrl_shift, RCTL(KC_RSFT)),
};
