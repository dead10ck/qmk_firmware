// vim: nowrap

#include QMK_KEYBOARD_H
#include "version.h"

#define MT_HYP_EQ MT(MOD_HYPR, KC_EQUAL)
#define ACTIVE_STICKY_MOD_TIMEOUT 500
#define HYPER(kc) LALT(LCTL(LGUI(LSFT(kc))))
#define CALT(kc) LALT(LCTL(kc))

enum custom_keycodes {
    M_ALT_GRAVE = ML_SAFE_RANGE,
    M_ALT_TAB,
    M_CTRL_TAB,
    M_MGC_B,
    M_MGC_E,
    M_MGC_I,
    M_MGC_R,
    M_MGC_S,
    M_MGC_U,
    M_NTM_0,
    M_NTM_1,
    M_NTM_2,
    M_NTM_3,
    M_NTM_4,
    M_NTM_5,
    M_NTM_6,
    M_NTM_7,
    M_NTM_8,
    M_NTM_9,
    M_NTM_AST,
    M_NTM_C,
    M_NTM_CDOWN,
    M_NTM_CLEFT,
    M_NTM_COLON,
    M_NTM_CRIGHT,
    M_NTM_CUP,
    M_NTM_D,
    M_NTM_DOWN,
    M_NTM_LBRKT,
    M_NTM_LEFT,
    M_NTM_LPRN,
    M_NTM_N,
    M_NTM_P,
    M_NTM_PCNT,
    M_NTM_QUOT,
    M_NTM_RIGHT,
    M_NTM_SPC,
    M_NTM_UP,
    M_NTM_X,
    M_PARENS,
    M_TM_0,
    M_TM_1,
    M_TM_2,
    M_TM_3,
    M_TM_4,
    M_TM_5,
    M_TM_6,
    M_TM_7,
    M_TM_8,
    M_TM_9,
    M_TM_AST,
    M_TM_C,
    M_TM_CDOWN,
    M_TM_CLEFT,
    M_TM_COLON,
    M_TM_CRIGHT,
    M_TM_CUP,
    M_TM_D,
    M_TM_DOWN,
    M_TM_LBRKT,
    M_TM_LEFT,
    M_TM_LPRN,
    M_TM_N,
    M_TM_P,
    M_TM_PCNT,
    M_TM_QUOT,
    M_TM_RIGHT,
    M_TM_SPC,
    M_TM_UP,
    M_TM_X,
    RGB_SLD,
};

enum tap_dance_codes {
    D_SYS,
    D_CAPS,
    D_ALT_BACKTICK,
    D_WKSP_L,
    D_WKSP_R,
    D_TMUX,
};

enum layers {
    L_BASE,
    L_NAV,
    L_SYMB,
    L_MEDIA,
    L_TMUX,
    L_N_TMUX,
    L_NUMPAD,
    L_SYS,
};

enum combos {
    C_L_N_TMUX,
    C_RALT,
    C_LENGTH,
};

// necessary to tell it how many combos there are
uint16_t COMBO_LEN = C_LENGTH;
const uint16_t PROGMEM c_nested_tmux_layer[] = { OSL(L_TMUX), OSL(L_NAV), COMBO_END };
const uint16_t PROGMEM c_right_alt[] = { OSL(L_SYMB), KC_LGUI, COMBO_END };

combo_t key_combos[] = {
    [C_L_N_TMUX] = COMBO(c_nested_tmux_layer, OSL(L_N_TMUX)),
    [C_RALT]     = COMBO(c_right_alt, KC_RALT),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
         KC_DELETE,       KC_1,          KC_2,        KC_3,    KC_4,       KC_5,       KC_HOME,       KC_END,      KC_6,     KC_7,     KC_8,       KC_9,         KC_0,       KC_MINUS,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          KC_AMPR,        KC_Q,          KC_W,        KC_E,    KC_R,       KC_T,       KC_PIPE,     TO(L_SYMB),    KC_Y,     KC_U,     KC_I,       KC_O,         KC_P,       KC_BSLASH,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
      LT(L_SYMB,KC_ESC),  KC_A,          KC_S,        KC_D,    KC_F,       KC_G,      MT_HYP_EQ,     TG(L_NAV),    KC_H,     KC_J,     KC_K,       KC_L,       KC_SCOLON,    KC_QUOTE,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
         KC_LSHIFT,    LCTL_T(KC_Z),  LSFT_T(KC_X),   KC_C,    KC_V,       KC_B,                                   KC_N,     KC_M,   KC_COMMA,    KC_DOT,       KC_SLASH,    KC_LEAD,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
         TD(D_SYS),     TD(D_CAPS),     KC_LGUI,OSL(L_TMUX),OSL(L_NAV),LALT(KC_TAB),                           TG(L_NUMPAD),OSL(L_SYMB),KC_LGUI, TD(D_WKSP_L), TD(D_WKSP_R), MO(L_MEDIA),
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                       LCTL_T(KC_ENTER),  LSFT_T(KC_TAB),  TD(D_ALT_BACKTICK),         KC_LALT,  LSFT_T(KC_BSPACE), LCTL_T(KC_SPACE)
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),

  [L_NAV] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,      _______,     _______, _______,  _______,     _______,     _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        KC_HOME,   KC_PGDN, KC_PGUP,    KC_END,       _______,      _______,     KC_HOME, KC_PGDN,  KC_PGUP,     KC_END,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        KC_LEFT,   KC_DOWN,  KC_UP,     KC_RIGHT,     _______,      _______,     KC_LEFT, KC_DOWN,   KC_UP,     KC_RIGHT,     _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,  _______,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______, _______,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,           _______,          _______,              _______,       _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_SYMB] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          KC_ESC,         KC_F1,         KC_F2,      KC_F3,   KC_F4,      KC_F5,       _______,       _______,     KC_F6,   KC_F7,    KC_F8,      KC_F9,        KC_F10,       KC_F11,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LCBR, KC_RCBR,    KC_HASH,      _______,     TO(L_MEDIA), KC_GRAVE, KC_EXLM,   KC_AT,     KC_CIRC,      _______,       KC_F12,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LPRN, KC_RPRN,    KC_TILD,      _______,       _______,    KC_PERC, KC_AMPR,  KC_PIPE,     KC_DLR,      _______,       KC_DQUO,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LBRC, KC_RBRC,    _______,                                 _______, KC_ASTR,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    KC_LABK, KC_RABK,    _______,                                 _______, _______,  _______,    _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            M_ALT_TAB,      M_ALT_GRAVE,       M_CTRL_TAB,             _______,       _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_MEDIA] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           AU_TOG,        _______,       _______,   _______, _______,    _______,      _______,       _______,    _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           MU_TOG,        _______,       _______,   _______, _______,    _______,      _______,     TO(L_BASE),   _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
           MU_MOD,        _______,       _______,   _______, _______,    _______,      _______,       _______,    _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
           _______,       _______,       _______,   _______, _______,    _______,                                 _______, KC_MPLY,  KC_MPRV,     KC_MNXT,     _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
           RGB_SPD,       RGB_SPI,       _______,   _______, _______,    RGB_MOD,                                 RGB_TOG, KC_VOLD,  KC_VOLU,  KC_AUDIO_MUTE, HYPER(KC_M),   _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            RGB_VAD,          RGB_VAI,     TOGGLE_LAYER_COLOR,         RGB_SLD,        RGB_HUD,          RGB_HUI
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_TMUX] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        M_TM_1,       M_TM_2,      M_TM_3,  M_TM_4,     M_TM_5,      _______,       _______,    M_TM_6,   M_TM_7,   M_TM_8,    M_TM_9,        M_TM_0,       _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,      M_TM_QUOT,     M_TM_PCNT,   M_TM_AST,M_TM_LPRN,  _______,      _______,       _______, M_TM_CLEFT,M_TM_CDOWN,M_TM_CUP,  M_TM_CRIGHT,    M_TM_P,       _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        _______,     M_TM_LBRKT,   M_TM_D, _______,    _______,      _______,       _______,  M_TM_LEFT,M_TM_DOWN, M_TM_UP,   M_TM_RIGHT,    M_TM_COLON,    _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,        _______,      M_TM_X,      M_TM_C, _______,    _______,                                 M_TM_N,  _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,        _______,       _______,   _______, _______,    _______,                                 _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                             _______,         _______,           _______,              _______,       _______,          M_TM_SPC
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_N_TMUX] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,        M_NTM_1,       M_NTM_2,   M_NTM_3, M_NTM_4,    M_NTM_5,      _______,       _______,    M_NTM_6, M_NTM_7,  M_NTM_8,     M_NTM_9,      M_NTM_0,     _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,      M_NTM_QUOT,    M_NTM_PCNT, M_NTM_AST,M_NTM_LPRN, _______,      _______,       _______,M_NTM_CLEFT,M_NTM_CDOWN,M_NTM_CUP,M_NTM_CRIGHT,   M_NTM_P,     _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,     M_NTM_LBRKT,  M_NTM_D, _______,    _______,      _______,       _______, M_NTM_LEFT,M_NTM_DOWN,M_NTM_UP,  M_NTM_RIGHT,  M_NTM_COLON,   _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       M_NTM_X,    M_NTM_C, _______,    _______,                                 M_NTM_N, _______,  _______,     _______,      _______,     _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,    _______,                                 _______, _______,  _______,     _______,      _______,     _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                             _______,         _______,           _______,              _______,       _______,         M_NTM_SPC
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_NUMPAD] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______, M_PARENS, KC_SLASH,  KC_ASTERISK,   KC_MINUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______,   KC_7,     KC_8,       KC_9,        KC_PLUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,      _______,       _______,    _______,   KC_4,     KC_5,       KC_6,        KC_PLUS,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,   KC_1,     KC_2,       KC_3,       KC_ENTER,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,        _______,   _______, _______,    _______,                                 _______,   KC_0,     KC_0,      KC_DOT,      KC_ENTER,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,         _______,           _______,               _______,     KC_BSPACE,          KC_ENTER
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
  [L_SYS] = LAYOUT_moonlander(
    // _________________________________________________________________________________________________________________________________________________________________________________
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
      CALT(KC_DELETE),  CALT(KC_F1), CALT(KC_F2),CALT(KC_F3),_______,     _______,     _______,       _______,    _______, _______,  _______,     _______,      _______,       RESET,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,     _______,     TO(L_BASE),   _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |           | |             |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,     _______,       M_MGC_R,    M_MGC_E, M_MGC_I,  M_MGC_S,    M_MGC_U,       M_MGC_B,      _______,
    //|______________|______________|______________|________|________|______________|___________| |_____________|_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,                                _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|                           |_________|________|__________|_____________|_____________|_____________|
    //|              |              |              |        |        |              |                           |         |        |          |             |             |             |
          _______,       _______,       _______,    _______, _______,     _______,                                _______, _______,  _______,     _______,      _______,      _______,
    //|______________|______________|______________|________|________|______________|_________       ___________|_________|________|__________|_____________|_____________|_____________|
    //                                |                  |                |                   |     |           |                  |                |
                                            _______,           _______,          _______,              _______,      _______,           _______
    //                                |__________________|________________|___________________|     |___________|__________________|________________|
  ),
};
// clang-format on

uint16_t active_sticky_mod         = 0;
uint16_t sticky_mod_timer          = 0;
bool     active_sticky_mod_pressed = false;

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
    if (active_sticky_mod && timer_elapsed(sticky_mod_timer) > ACTIVE_STICKY_MOD_TIMEOUT) {
        // if we're still holding the key, reset the timer to give more time
        if (active_sticky_mod_pressed) {
            sticky_mod_timer = timer_read();
        } else {
            unregister_code(active_sticky_mod);
            active_sticky_mod = 0;
        }
    }

    LEADER_DICTIONARY() {
        leading = false;
        SEQ_TWO_KEYS(KC_C, KC_B) { SEND_STRING("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP)); }
        SEQ_FOUR_KEYS(KC_C, KC_B, KC_P, KC_P) { SEND_STRING(SS_LSFT("\n\n") "```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V))); }
        SEQ_THREE_KEYS(KC_C, KC_B, KC_P) { SEND_STRING("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V))); }

        SEQ_THREE_KEYS(KC_L, KC_S, KC_L) { SEND_STRING("ls -alh\n"); }
        SEQ_THREE_KEYS(KC_A, KC_L, KC_S) { SEND_STRING("aws s3 ls --human "); }
        SEQ_TWO_KEYS(KC_T, KC_M) { SEND_STRING("tmux a || tmux\n"); }
        SEQ_TWO_KEYS(KC_S, KC_U) { SEND_STRING("sudo -i\n"); }
        SEQ_TWO_KEYS(KC_P, KC_S) { SEND_STRING("ps -aefH"); }
        SEQ_THREE_KEYS(KC_P, KC_S, KC_L) { SEND_STRING("ps -aefH | less\n"); }

        SEQ_THREE_KEYS(KC_T, KC_A, KC_I) { SEND_STRING("tai64nlocal"); }
        SEQ_TWO_KEYS(KC_T, KC_A) { SEND_STRING("tail -F  | tai64nlocal" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)); }

        SEQ_TWO_KEYS(KC_O, KC_S) { SEND_STRING("source /opt/SGraph/scripts/oozie-env.sh\n"); }
        SEQ_THREE_KEYS(KC_O, KC_J, KC_I) { SEND_STRING("oozie job -info '" SS_DELAY(300) SS_LSFT(SS_LCTL("v")) SS_DELAY(300) "'\n"); }
        SEQ_THREE_KEYS(KC_O, KC_J, KC_S) { SEND_STRING("oozie jobs -jobtype "); }

        leader_end();
    }
}

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
        tap_code(keycode);
        active_sticky_mod_pressed = true;
    } else {
        // start the timer again when we release
        sticky_mod_timer = timer_read();

        // we've already released it
        active_sticky_mod_pressed = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_ALT_TAB:
            sticky_mod(KC_LALT, KC_TAB, record);
            return false;

        case M_CTRL_TAB:
            sticky_mod(KC_LCTRL, KC_TAB, record);
            return false;

        case M_ALT_GRAVE:
            sticky_mod(KC_LALT, KC_GRAVE, record);
            return false;

        // Macros
        case M_TM_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_1));
            }
            break;
        case M_TM_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_2));
            }
            break;
        case M_TM_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_3));
            }
            break;
        case M_TM_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_4));
            }
            break;
        case M_TM_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_5));
            }
            break;
        case M_TM_QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_QUOTE)));
            }
            break;
        case M_TM_PCNT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_5)));
            }
            break;
        case M_TM_AST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_8)));
            }
            break;
        case M_TM_LPRN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case M_TM_LBRKT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LBRACKET));
            }
            break;
        case M_TM_D:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_D));
            }
            break;
        case M_TM_X:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_X));
            }
            break;
        case M_TM_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_C));
            }
            break;
        case M_TM_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_6));
            }
            break;
        case M_TM_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_7));
            }
            break;
        case M_TM_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_8));
            }
            break;
        case M_TM_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_9));
            }
            break;
        case M_TM_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_0));
            }
            break;
        case M_TM_CLEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
        case M_TM_CDOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_DOWN)));
            }
            break;
        case M_TM_CUP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_UP)));
            }
            break;
        case M_TM_CRIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_RIGHT)));
            }
            break;
        case M_TM_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_P));
            }
            break;
        case M_TM_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT));
            }
            break;
        case M_TM_DOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_DOWN));
            }
            break;
        case M_TM_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_UP));
            }
            break;
        case M_TM_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_RIGHT));
            }
            break;
        case M_TM_COLON:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_SCOLON)));
            }
            break;
        case M_TM_N:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_N));
            }
            break;
        case M_TM_SPC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_TAP(X_SPACE));
            }
            break;
        case M_NTM_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_1));
            }
            break;
        case M_NTM_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_2));
            }
            break;
        case M_NTM_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_3));
            }
            break;
        case M_NTM_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_4));
            }
            break;
        case M_NTM_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_5));
            }
            break;
        case M_NTM_QUOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_QUOTE)));
            }
            break;
        case M_NTM_PCNT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_5)));
            }
            break;
        case M_NTM_AST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_8)));
            }
            break;
        case M_NTM_LPRN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case M_NTM_LBRKT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LBRACKET));
            }
            break;
        case M_NTM_D:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_D));
            }
            break;
        case M_NTM_X:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_X));
            }
            break;
        case M_NTM_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_C));
            }
            break;
        case M_NTM_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_6));
            }
            break;
        case M_NTM_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_7));
            }
            break;
        case M_NTM_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_8));
            }
            break;
        case M_NTM_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_9));
            }
            break;
        case M_NTM_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_0));
            }
            break;
        case M_NTM_CLEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
        case M_NTM_CDOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_DOWN)));
            }
            break;
        case M_NTM_CUP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_UP)));
            }
            break;
        case M_NTM_CRIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_RIGHT)));
            }
            break;
        case M_NTM_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_P));
            }
            break;
        case M_NTM_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_LEFT));
            }
            break;
        case M_NTM_DOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_DOWN));
            }
            break;
        case M_NTM_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_UP));
            }
            break;
        case M_NTM_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_RIGHT));
            }
            break;
        case M_NTM_COLON:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_LSFT(SS_TAP(X_SCOLON)));
            }
            break;
        case M_NTM_N:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_N));
            }
            break;
        case M_NTM_SPC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_LCTL(SS_TAP(X_B)) SS_TAP(X_SPACE));
            }
            break;
        case M_PARENS:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_8)) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case M_MGC_R:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_R));
            }
            break;
        case M_MGC_E:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_E));
            }
            break;
        case M_MGC_I:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_I));
            }
            break;
        case M_MGC_S:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_S));
            }
            break;
        case M_MGC_U:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_PSCREEN)) SS_DELAY(100) SS_TAP(X_U));
            }
            break;
        case M_MGC_B:
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

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [L_NUMPAD] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 97, 236}, {27, 126, 255}, {27, 126, 255}, {254, 198, 190}, {254, 198, 190}, {15, 176, 169}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {146, 224, 255}, {169, 120, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {233, 218, 217}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {254, 198, 190}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}},
    [L_SYS] = {{0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245},
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

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case L_NUMPAD:
            set_layer_color(L_NUMPAD);
            break;
        case L_SYS:
            set_layer_color(L_SYS);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
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
            layer_move(L_SYS);
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

// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [D_SYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
    [D_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
    [D_ALT_BACKTICK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [D_WKSP_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [D_WKSP_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
