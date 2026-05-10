#if __has_include("../features/shortcuts.h")
#    include "../features/shortcuts.h"
#endif

[_NAV] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------,                    ,-----------------------------------------------------,
    XXXXXXX,TO(_FUNC),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_END, KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,  W_UNDO,   W_CUT,  W_COPY, W_PASTE,  W_BOLD,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______,  M_UNDO,   M_CUT,  M_COPY, M_PASTE,  M_BOLD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                        KC_LGUI, XXXXXXX, XXXXXXX,  MO(_SYMB), _______, _______
                                    //'--------------------------'  '--------------------------'
),
