#include QMK_KEYBOARD_H
#include "version.h"

#define MT_HYP_EQ MT(MOD_HYPR, KC_EQUAL)

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3,
    ST_MACRO_4,
    ST_MACRO_5,
    ST_MACRO_6,
    ST_MACRO_7,
    ST_MACRO_8,
    ST_MACRO_9,
    ST_MACRO_10,
    ST_MACRO_11,
    ST_MACRO_12,
    ST_MACRO_13,
    ST_MACRO_14,
    ST_MACRO_15,
    ST_MACRO_16,
    ST_MACRO_17,
    ST_MACRO_18,
    ST_MACRO_19,
    ST_MACRO_20,
    ST_MACRO_21,
    ST_MACRO_22,
    ST_MACRO_23,
    ST_MACRO_24,
    ST_MACRO_25,
    ST_MACRO_26,
    ST_MACRO_27,
    ST_MACRO_28,
    ST_MACRO_29,
    ST_MACRO_30,
    ST_MACRO_31,
    ST_MACRO_32,
    ST_MACRO_33,
    ST_MACRO_34,
    ST_MACRO_35,
    ST_MACRO_36,
    ST_MACRO_37,
    ST_MACRO_38,
    ST_MACRO_39,
    ST_MACRO_40,
    ST_MACRO_41,
    ST_MACRO_42,
    ST_MACRO_43,
    ST_MACRO_44,
    ST_MACRO_45,
    ST_MACRO_46,
    ST_MACRO_47,
    ST_MACRO_48,
    ST_MACRO_49,
    ST_MACRO_50,
    ST_MACRO_51,
    ST_MACRO_52,
    ST_MACRO_53,
    ST_MACRO_54,
    ST_MACRO_55,
    ST_MACRO_56,
    ST_MACRO_57,
    ST_MACRO_58,
    ST_MACRO_59,
    ST_MACRO_60,
    ST_MACRO_61,
    ST_MACRO_62,
    ST_MACRO_63,
    ST_MACRO_64,
    ST_MACRO_65,
    ST_MACRO_66,
    ALT_TAB,
};

enum tap_dance_codes {
    D_SYS,
    D_CAPS,
    D_ALT_BACKTICK,
    D_WKSP_L,
    D_WKSP_R,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    //              |              |              |                  |                |              |           ||        |         |        |          |             |             |
    KC_DELETE,        KC_1,          KC_2,          KC_3,              KC_4,            KC_5,          KC_HOME,     KC_END,  KC_6,     KC_7,     KC_8,      KC_9,         KC_0,         KC_MINUS,
    KC_AMPR,          KC_Q,          KC_W,          KC_E,              KC_R,            KC_T,          KC_PIPE,     TO(2),   KC_Y,     KC_U,     KC_I,      KC_O,         KC_P,         KC_BSLASH,
    LT(2,KC_ESCAPE),  KC_A,          KC_S,          KC_D,              KC_F,            KC_G,          MT_HYP_EQ,   TO(1),   KC_H,     KC_J,     KC_K,      KC_L,         KC_SCOLON,    KC_QUOTE,
    KC_LSHIFT,        LCTL_T(KC_Z),  LSFT_T(KC_X),  KC_C,              KC_V,            KC_B,                                KC_N,     KC_M,     KC_COMMA,  KC_DOT,       KC_SLASH,     KC_LEAD,
    TD(D_SYS),        TD(D_CAPS),    KC_LGUI,       OSL(5),            OSL(4),          LALT(KC_TAB),                        TG(6),    KC_LGUI,  KC_RALT,   TD(D_WKSP_L), TD(D_WKSP_R), MO(3),
                                                    LCTL_T(KC_ENTER),  LSFT_T(KC_TAB),  TD(D_ALT_BACKTICK),                         KC_LALT,  LSFT_T(KC_BSPACE), LCTL_T(KC_SPACE)
  ),
  [1] = LAYOUT_moonlander(
    _______,          _______,       _______,       _______,           _______,         _______,       _______,     _______, _______,  _______,  _______,   _______,      _______,      _______, 
    _______,          _______,       _______,       KC_F,              KC_P,            KC_G,          _______,     _______, KC_J,     KC_L,     KC_U,      KC_Y,         KC_SCOLON,    _______, 
    _______,          _______,       KC_R,          KC_S,              KC_T,            KC_D,          _______,     TO(0),   _______,  KC_N,     KC_E,      KC_I,         KC_O,         _______, 
    _______,          _______,       _______,       _______,           _______,         _______,                             KC_K,     _______,  _______,   _______,      _______,      _______, 
    _______,          _______,       _______,       _______,           _______,         _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
                                                    _______,           _______,         _______,                             _______,  _______,  _______
  ),
  [2] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                                 _______, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    _______, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_AMPR,        KC_PIPE,                                        TO(3),          KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         _______, KC_F12,         
    _______, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_HOME,                                                                        KC_END,         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______, 
    _______, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        _______, _______, _______, _______, KC_RCTRL,       KC_RSHIFT,      
    _______, KC_COMMA,       KC_LGUI,        KC_LABK,        KC_RABK,        _______,                                                                                                 _______, KC_LGUI,        _______, _______, _______, _______, 
    _______, _______, _______,                 _______, _______, _______
  ),
  [3] = LAYOUT_moonlander(
    AU_TOG,         _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______, 
    MU_TOG,         _______, _______, KC_MS_UP,       _______, _______, _______,                                 TO(0),          _______, _______, _______, _______, _______, _______, 
    MU_MOD,         _______, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______, _______, 
    RGB_SPD,        RGB_SPI,        _______, KC_MS_BTN1,     KC_MS_BTN2,     RGB_MOD,                                                                                                        RGB_TOG,        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  LALT(LCTL(LGUI(LSFT(KC_M)))),_______, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [4] = LAYOUT_moonlander(
    _______, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     _______,                                 _______, ST_MACRO_13,    ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    _______, 
    _______, ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     _______, _______,                                 _______, ST_MACRO_18,    ST_MACRO_19,    ST_MACRO_20,    ST_MACRO_21,    ST_MACRO_22,    _______, 
    _______, _______, ST_MACRO_9,     ST_MACRO_10,    _______, _______, _______,                                                                 _______, ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,    ST_MACRO_27,    _______, 
    _______, _______, ST_MACRO_11,    ST_MACRO_12,    _______, _______,                                 ST_MACRO_28,    _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______,                 _______, _______, ST_MACRO_29
  ),
  [5] = LAYOUT_moonlander(
    _______, ST_MACRO_30,    ST_MACRO_31,    ST_MACRO_32,    ST_MACRO_33,    ST_MACRO_34,    _______,                                 _______, ST_MACRO_43,    ST_MACRO_44,    ST_MACRO_45,    ST_MACRO_46,    ST_MACRO_47,    _______, 
    _______, ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    ST_MACRO_38,    _______, _______,                                 _______, ST_MACRO_48,    ST_MACRO_49,    ST_MACRO_50,    ST_MACRO_51,    ST_MACRO_52,    _______, 
    _______, _______, ST_MACRO_39,    ST_MACRO_40,    _______, _______, _______,                                                                 _______, ST_MACRO_53,    ST_MACRO_54,    ST_MACRO_55,    ST_MACRO_56,    ST_MACRO_57,    _______, 
    _______, _______, ST_MACRO_41,    ST_MACRO_42,    _______, _______,                                 ST_MACRO_58,    _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______,                 _______, _______, ST_MACRO_59
  ),
  [6] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, ST_MACRO_60,    KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    _______, 
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     _______, 
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    _______, 
    _______, _______, _______,                 _______, KC_BSPACE,      KC_KP_ENTER
  ),
  [7] = LAYOUT_moonlander(
    LALT(LCTL(KC_DELETE)),LALT(LCTL(KC_F1)),LALT(LCTL(KC_F2)),LALT(LCTL(KC_F3)),_______, _______, _______,                                 _______, _______, _______, _______, _______, _______, RESET,          
    _______, _______, _______, _______, _______, _______, _______,                                 TO(0),          _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______,                                                                 ST_MACRO_61,    ST_MACRO_62,    ST_MACRO_63,    ST_MACRO_64,    ST_MACRO_65,    ST_MACRO_66,    _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______,                 _______, _______, _______
  ),
};
// clang-format on

uint16_t active_sticky_mod = 0;
uint16_t sticky_mod_timer  = 0;

uint16_t get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_TAB):
        case LSFT_T(KC_BSPACE):
            return true;
        default:
            return false;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (active_sticky_mod && timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(active_sticky_mod);
        active_sticky_mod = 0;
    }

    LEADER_DICTIONARY() {
        leading = false;
        SEQ_THREE_KEYS(KC_L, KC_S, KC_L) { SEND_STRING("ls -alh\n"); }
        SEQ_TWO_KEYS(KC_C, KC_B) { SEND_STRING("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP)); }
        leader_end();
    }
}

// --- generated by oryx ---

void sticky_mod(uint16_t mod_key, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (active_sticky_mod && active_sticky_mod != mod_key) {
            unregister_code(active_sticky_mod);
            active_sticky_mod = 0;
        }

        if (!active_sticky_mod) {
            register_code(mod_key);
            active_sticky_mod = mod_key;
        }

        sticky_mod_timer = timer_read();
        register_code(keycode);
    } else {
        unregister_code(keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB:
            sticky_mod(KC_ALT, KC_TAB);
            break;

        // Macros
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_QUOTE)));
            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_5)));
            }
            break;
        case ST_MACRO_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_8)));
            }
            break;
        case ST_MACRO_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LBRACKET));
            }
            break;
        case ST_MACRO_10:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_11:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_X));
            }
            break;
        case ST_MACRO_12:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_13:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_14:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_15:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_16:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_17:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_18:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
        case ST_MACRO_19:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_DOWN)));
            }
            break;
        case ST_MACRO_20:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_UP)));
            }
            break;
        case ST_MACRO_21:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_RIGHT)));
            }
            break;
        case ST_MACRO_22:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_P));
            }
            break;
        case ST_MACRO_23:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LEFT));
            }
            break;
        case ST_MACRO_24:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_DOWN));
            }
            break;
        case ST_MACRO_25:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_UP));
            }
            break;
        case ST_MACRO_26:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_RIGHT));
            }
            break;
        case ST_MACRO_27:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)));
            }
            break;
        case ST_MACRO_28:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_N));
            }
            break;
        case ST_MACRO_29:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_SPACE));
            }
            break;
        case ST_MACRO_30:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_1));
            }
            break;
        case ST_MACRO_31:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_2));
            }
            break;
        case ST_MACRO_32:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_3));
            }
            break;
        case ST_MACRO_33:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_4));
            }
            break;
        case ST_MACRO_34:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_5));
            }
            break;
        case ST_MACRO_35:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_QUOTE)));
            }
            break;
        case ST_MACRO_36:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_5)));
            }
            break;
        case ST_MACRO_37:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_8)));
            }
            break;
        case ST_MACRO_38:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_39:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LBRACKET));
            }
            break;
        case ST_MACRO_40:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_D));
            }
            break;
        case ST_MACRO_41:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_X));
            }
            break;
        case ST_MACRO_42:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_C));
            }
            break;
        case ST_MACRO_43:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_6));
            }
            break;
        case ST_MACRO_44:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_7));
            }
            break;
        case ST_MACRO_45:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_8));
            }
            break;
        case ST_MACRO_46:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_9));
            }
            break;
        case ST_MACRO_47:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_0));
            }
            break;
        case ST_MACRO_48:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
        case ST_MACRO_49:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_DOWN)));
            }
            break;
        case ST_MACRO_50:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_UP)));
            }
            break;
        case ST_MACRO_51:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_RIGHT)));
            }
            break;
        case ST_MACRO_52:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_P));
            }
            break;
        case ST_MACRO_53:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LEFT));
            }
            break;
        case ST_MACRO_54:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_DOWN));
            }
            break;
        case ST_MACRO_55:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_UP));
            }
            break;
        case ST_MACRO_56:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_RIGHT));
            }
            break;
        case ST_MACRO_57:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)));
            }
            break;
        case ST_MACRO_58:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_N));
            }
            break;
        case ST_MACRO_59:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_SPACE));
            }
            break;
        case ST_MACRO_60:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_8)) SS_DELAY(100) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case ST_MACRO_61:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_R));
            }
            break;
        case ST_MACRO_62:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_63:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_I));
            }
            break;
        case ST_MACRO_64:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_S));
            }
            break;
        case ST_MACRO_65:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_U));
            }
            break;
        case ST_MACRO_66:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_B));
            }
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 6:
            set_layer_color(6);
            break;
        case 7:
            set_layer_color(7);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [6] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 97, 236}, {27, 126, 255}, {27, 126, 255}, {254, 198, 190}, {254, 198, 190}, {15, 176, 169}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {146, 224, 255}, {169, 120, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {233, 218, 217}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {254, 198, 190}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}},
    [7] = {{0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245},
           {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[5];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP:
            layer_move(7);
            break;
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {}
    dance_state[0].step = 0;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            register_code16(KC_CAPSLOCK);
            break;
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            unregister_code16(KC_CAPSLOCK);
            break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if (state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
            break;
        case DOUBLE_HOLD:
            register_code16(LSFT(KC_GRAVE));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case DOUBLE_HOLD:
            unregister_code16(LSFT(KC_GRAVE));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_PGUP));
        tap_code16(LGUI(KC_PGUP));
        tap_code16(LGUI(KC_PGUP));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_PGUP));
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PGUP));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PGUP)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PGUP));
            register_code16(LGUI(KC_PGUP));
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PGUP));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PGUP)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PGUP));
            break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_PGDOWN));
        tap_code16(LGUI(KC_PGDOWN));
        tap_code16(LGUI(KC_PGDOWN));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_PGDOWN));
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PGDOWN));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PGDOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PGDOWN));
            register_code16(LGUI(KC_PGDOWN));
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PGDOWN));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PGDOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PGDOWN));
            break;
    }
    dance_state[4].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [D_SYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset), [D_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset), [D_ALT_BACKTICK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset), [D_WKSP_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset), [D_WKSP_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
