/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define MT_HYP_EQ MT(MOD_HYPR, KC_EQUAL)
#define ACTIVE_STICKY_MOD_TIMEOUT 500
#define HYPER(kc) LALT(LCTL(LGUI(LSFT(kc))))
#define CALT(kc) LALT(LCTL(kc))

#define TMUX(kc) (K_TMUX | ((kc)&0xFF))
#define NTMUX(kc) (K_NTMUX | ((kc)&0xFF))

enum custom_keycodes {
    M_ALT_GRAVE = SAFE_RANGE,
    M_ALT_TAB,
    M_CTRL_TAB,
    M_MGC_B,
    M_MGC_E,
    M_MGC_I,
    M_MGC_R,
    M_MGC_S,
    M_MGC_U,
    RGB_SLD,

    // for these to work, the low order bits must be 0 so we can mask
    // another keycode into it; but the range of custom user keys is
    // only:
    //
    // QK_USER                        = 0x7E40,
    // QK_USER_MAX                    = 0x7FFF,
    //
    // so the only value that can do in the safe range this is this one
    K_TMUX     = 0x7F00,

    // this corresponds to this key, which we don't care about
    // QK_JOYSTICK_BUTTON_0 = 0x7400,
    K_NTMUX    = 0x7400,
};

enum tap_dance_codes {
    D_SYS,
    D_CAPS,
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
    C_L_TMUX_L,
    C_L_N_TMUX_L,
    C_L_TMUX_R,
    C_L_N_TMUX_R,
    C_L_NUMPAD,
    C_HYPER_L,
    C_HYPER_R,
    C_LENGTH,
};

// clang-format off

// necessary to tell it how many combos there are
const uint16_t         COMBO_LEN               = C_LENGTH;
const uint16_t PROGMEM c_layer_tmux_left[]     = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM c_layer_tmux_right[]    = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM c_layer_ntmux_left[]    = {KC_R, KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM c_layer_ntmux_right[]   = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM c_hyper_left[]          = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM c_hyper_right[]         = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM c_numpad[]              = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    [C_L_TMUX_L]   = COMBO(c_layer_tmux_left,   TT(L_TMUX)),
    [C_L_TMUX_R]   = COMBO(c_layer_tmux_right,  TT(L_TMUX)),
    [C_L_N_TMUX_L] = COMBO(c_layer_ntmux_left,  TT(L_N_TMUX)),
    [C_L_N_TMUX_R] = COMBO(c_layer_ntmux_right, TT(L_N_TMUX)),
    [C_L_NUMPAD]   = COMBO(c_numpad,            TT(L_NUMPAD)),
    [C_HYPER_L]    = COMBO(c_hyper_left,        KC_HYPR),
    [C_HYPER_R]    = COMBO(c_hyper_right,       KC_HYPR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
       TT(L_SYS),        KC_Q,          KC_W,         KC_E,         KC_R,         KC_T,                                                  KC_Y,         KC_U,        KC_I,        KC_O,        KC_P,     KC_MINUS,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
 LT(L_SYMB, KC_ESC),     KC_A,          KC_S,         KC_D,         KC_F,         KC_G,                                                  KC_H,         KC_J,        KC_K,        KC_L,       KC_SCLN,  LT(L_MEDIA, KC_QUOT),
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
      KC_LEFT_GUI,       KC_Z,          KC_X,         KC_C,         KC_V,         KC_B,                                                  KC_N,         KC_M,       KC_COMM,     KC_DOT,      KC_SLSH,    QK_LEAD,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                              TT(L_NAV),   LCTL_T(KC_ENTER), LSFT_T(KC_TAB),      LSFT_T(KC_BACKSPACE),  LCTL_T(KC_SPACE),   KC_LEFT_ALT
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_NAV] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                               KC_HOME,    KC_PAGE_UP,    KC_PGDN,     KC_END,     _______,     _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       KC_PGDN,      _______,      _______,                                               KC_LEFT,      KC_DOWN,      KC_UP,     KC_RIGHT,    _______,     _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                               _______,      _______,     _______,     _______,    _______,     _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                                _______,        _______,         _______,              _______,              _______,            _______
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_SYMB] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       KC_LCBR,     KC_RCBR,      KC_EQUAL,                                               KC_GRAVE,     KC_EXLM,      KC_AT,      KC_BSLS,    KC_CIRC,     _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       KC_LPRN,     KC_RPRN,      KC_TILD,                                                KC_PERC,      KC_AMPR,     KC_PIPE,     KC_MINUS,   KC_DLR,      _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       KC_LBRC,     KC_RBRC,      KC_PLUS,                                                KC_HASH,      KC_ASTR,     _______,     _______,    _______,     _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                             M_ALT_GRAVE,     M_ALT_TAB,       M_CTRL_TAB,             _______,             _______,             _______
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_MEDIA] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                              TO(L_BASE),    KC_MPLY,     KC_MPRV,     KC_MNXT,     _______,    _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       RGB_MOD,      RGB_RMOD,     _______,                                               _______,      KC_VOLD,    KC_VOLU,  KC_AUDIO_MUTE,HYPER(KC_M),   _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       RGB_SPD,      RGB_SPI,      _______,                                               _______,      _______,     _______,     _______,     _______,    _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                               RGB_VAD,        RGB_VAI,          _______,              _______,              RGB_HUD,            RGB_HUI
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_TMUX] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,    TMUX(KC_QUOT), TMUX(KC_PERC), TMUX(KC_ASTR), TMUX(KC_LPRN),   _______,                                               _______,     _______,     _______,     _______,    TMUX(KC_P),  _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,   TMUX(KC_LBRC),  TMUX(KC_D),     _______,      _______,                                           TMUX(KC_LEFT),TMUX(KC_DOWN),TMUX(KC_UP),TMUX(KC_RIGHT),TMUX(KC_COLON),_______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,    TMUX(KC_X),    TMUX(KC_C),     _______,      _______,                                             TMUX(KC_N),    _______,     _______,     _______,     _______,      _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                                _______,        _______,         _______,              _______,              _______,            _______
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_N_TMUX] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,    NTMUX(KC_QUOT),NTMUX(KC_PERC),NTMUX(KC_ASTR),NTMUX(KC_LPRN),  _______,                                              _______,      _______,    _______,     _______,     NTMUX(KC_P), _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,   NTMUX(KC_LBRC), NTMUX(KC_D),    _______,      _______,                                          NTMUX(KC_LEFT),NTMUX(KC_DOWN),NTMUX(KC_UP),NTMUX(KC_RIGHT),NTMUX(KC_COLON),_______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,    NTMUX(KC_X),   NTMUX(KC_C),    _______,      _______,                                             NTMUX(KC_N),    _______,     _______,     _______,     _______,      _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                                _______,        _______,         _______,              _______,              _______,            _______
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_NUMPAD] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,         KC_1,         KC_2,          KC_3,          KC_4,        KC_5,                                                  KC_6,         KC_7,        KC_8,        KC_9,       KC_0,       _______,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                             KC_ASTERISK,     KC_4,        KC_5,        KC_6,      KC_PLUS,    KC_SLASH,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                                KC_DOT,       KC_1,        KC_2,        KC_3,      KC_MINUS,    _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                                _______,        _______,         _______,              _______,           KC_BACKSPACE,         KC_ENTER
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

    [L_SYS] = LAYOUT_split_3x6_3(
  // _______________________________________________________________________________________                                         _____________________________________________________________________________
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
    CALT(KC_DELETE),  CALT(KC_F1),  CALT(KC_F2),   CALT(KC_F3),    _______,      _______,                                               _______,      _______,     _______,     _______,     _______,    QK_BOOT,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                               M_MGC_R,      M_MGC_E,     M_MGC_I,     M_MGC_S,     M_MGC_U,    M_MGC_B,
  //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
        _______,        _______,      _______,       _______,      _______,      _______,                                               _______,      _______,     _______,     _______,     _______,    _______,
  //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  //                                                       |              |                |                 |   |                  |                      |                |
                                                                _______,        _______,         _______,              _______,              _______,            _______
  //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  ),

  //   [L_BLANK] = LAYOUT_split_3x6_3(
  // // _______________________________________________________________________________________                                         _____________________________________________________________________________
  // //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
  //       _______,        _______,      _______,       _______,      _______,      _______,                                               _______,      _______,     _______,     _______,     _______,    _______,
  // //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  // //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
  //       _______,        _______,      _______,       _______,      _______,      _______,                                               _______,      _______,     _______,     _______,     _______,    _______,
  // //|______________|______________|______________|_____________|_____________|_____________|                                        |_____________|____________|____________|____________|____________|___________|
  // //|              |              |              |             |             |             |                                        |             |            |            |            |            |           |
  //       _______,        _______,      _______,       _______,      _______,      _______,                                               _______,      _______,     _______,     _______,     _______,    _______,
  // //|______________|______________|______________|_____________|_____________|_____________|_________________     __________________|_____________|____________|____________|____________|____________|___________|
  // //                                                       |              |                |                 |   |                  |                      |                |
  //                                                               _______,        _______,         _______,              _______,              _______,            _______
  // //                                                       |______________|________________|_________________|   |__________________|______________________|________________|
  // ),
};
// clang-format on

uint16_t active_sticky_mod         = 0;
uint16_t sticky_mod_timer          = 0;
bool     active_sticky_mod_pressed = false;
int      ss_waitms                 = 20;

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_TAB):
        case LSFT_T(KC_BACKSPACE):
            return true;
        default:
            return false;
    }
}

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

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_C, KC_B)) {
        SEND_STRING_DELAY("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP), ss_waitms);

    } else if (leader_sequence_four_keys(KC_C, KC_B, KC_P, KC_P)) {
        SEND_STRING_DELAY(SS_LSFT("\n\n") "```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V)), ss_waitms);

    } else if (leader_sequence_three_keys(KC_C, KC_B, KC_P)) {
        SEND_STRING_DELAY("```" SS_LSFT("\n\n") "```" SS_TAP(X_UP) SS_LCTL(SS_TAP(X_V)), ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_L, KC_S, KC_L)) {
        SEND_STRING_DELAY("ls -alh\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_A, KC_L, KC_S)) {
        SEND_STRING_DELAY("aws s3 ls --human ", ss_waitms);

    } else if (leader_sequence_two_keys(KC_T, KC_M)) {
        SEND_STRING_DELAY("tmux a || tmux\n", ss_waitms);
    }

    // disable bracketed paste
    else if (leader_sequence_two_keys(KC_B, KC_P)) {
        SEND_STRING_DELAY("printf \"\\e[?2004l\"\n", ss_waitms);
    }

    // enable bracketed paste
    else if (leader_sequence_three_keys(KC_B, KC_P, KC_P)) {
        SEND_STRING_DELAY("printf \"\\e[?2004h\"\n", ss_waitms);
    }

    else if (leader_sequence_two_keys(KC_S, KC_U)) {
        SEND_STRING_DELAY("sudo -i\n", ss_waitms);

    } else if (leader_sequence_two_keys(KC_P, KC_S)) {
        SEND_STRING_DELAY("ps -aefH", ss_waitms);

    } else if (leader_sequence_three_keys(KC_P, KC_S, KC_L)) {
        SEND_STRING_DELAY("ps -aefH | less\n", ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_T, KC_A, KC_I)) {
        SEND_STRING_DELAY("tai64nlocal", ss_waitms);

    } else if (leader_sequence_two_keys(KC_T, KC_A)) {
        SEND_STRING_DELAY("tail -F  | tai64nlocal" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), ss_waitms);

    } else if (leader_sequence_two_keys(KC_P, KC_U)) {
        SEND_STRING_DELAY("/etc/puppet/bin/puppet", ss_waitms);
    }

    else if (leader_sequence_two_keys(KC_O, KC_S)) {
        SEND_STRING_DELAY("source /opt/SGraph/scripts/oozie-env.sh\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_O, KC_J, KC_I)) {
        SEND_STRING_DELAY("oozie job -info '" SS_LSFT(SS_LCTL("v")) "'\n", ss_waitms);

    } else if (leader_sequence_three_keys(KC_O, KC_J, KC_S)) {
        SEND_STRING_DELAY("oozie jobs -jobtype ", ss_waitms);

    } else if (leader_sequence_two_keys(KC_Y, KC_L)) {
        SEND_STRING_DELAY("yarn logs -applicationId '" SS_LSFT(SS_LCTL("v")) "'\n", ss_waitms);
    }

    else if (leader_sequence_three_keys(KC_J, KC_Q, KC_L)) {
        SEND_STRING_DELAY("jq -C '.' | less -R\n", ss_waitms);

    } else if (leader_sequence_two_keys(KC_E, KC_M)) {
        SEND_STRING_DELAY("skyler@dead10ck.dev", ss_waitms);
    } else if (leader_sequence_three_keys(KC_E, KC_M, KC_C)) {
        SEND_STRING_DELAY("skhawtho@cisco.com", ss_waitms);
    }
}

// must hold all combos to fire
bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    return true;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t high_code = (keycode & 0xFF00);

    switch(high_code) {
        case K_TMUX:
        case K_NTMUX:
            uint16_t kc = (keycode & 0xFF);

            if (record->event.pressed) {
                if (high_code == K_TMUX) {
                    SEND_STRING_DELAY(SS_LCTL("b"), ss_waitms);
                } else {
                    SEND_STRING_DELAY(SS_LCTL("bb"), ss_waitms);
                }

                tap_code_delay(kc, ss_waitms);
            }

            return false;
    }

    switch (keycode) {
        case M_ALT_TAB:
            sticky_mod(KC_LEFT_ALT, KC_TAB, record);
            return false;

        case M_CTRL_TAB:
            sticky_mod(KC_LEFT_CTRL, KC_TAB, record);
            return false;

        case M_ALT_GRAVE:
            sticky_mod(KC_LEFT_ALT, KC_GRAVE, record);
            return false;

        // Macros
        case M_MGC_R:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_R) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
            }
            break;
        case M_MGC_E:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_E) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
            }
            break;
        case M_MGC_I:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_I) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
            }
            break;
        case M_MGC_S:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_S) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
            }
            break;
        case M_MGC_U:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_U) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
            }
            break;
        case M_MGC_B:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LALT(SS_DOWN(X_SYSTEM_REQUEST) SS_TAP(X_B) SS_UP(X_SYSTEM_REQUEST)), ss_waitms);
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

/*
extern rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [L_NUMPAD] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {15, 97, 236}, {27, 126, 255}, {27, 126, 255}, {254, 198, 190}, {254, 198, 190}, {15, 176, 169}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {146, 224, 255}, {169, 120, 255}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {233, 218, 217}, {250, 159, 255}, {250, 159, 255}, {250, 159, 255}, {254, 198, 190}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {254, 198, 190}, {205, 255, 255}, {0, 0, 0}, {0, 0, 0}},
    [L_SYS]    = {{0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245},
                  {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}, {0, 172, 245}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
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

    return false;
}
*/

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[5];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
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

void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP:
            layer_move(L_SYS);
            break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {}
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            register_code16(KC_CAPS_LOCK);
            break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case DOUBLE_TAP:
            unregister_code16(KC_CAPS_LOCK);
            break;
    }
    dance_state[1].step = 0;
}

void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        for(int i = 0; i < state->count; i++) {      
            tap_code16(LGUI(KC_PAGE_UP));
        }
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PAGE_UP));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PAGE_UP)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PAGE_UP));
            register_code16(LGUI(KC_PAGE_UP));
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_UP));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PAGE_UP)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_UP));
            break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        for(int i = 0; i < state->count; i++) {      
            tap_code16(LGUI(KC_PAGE_DOWN));
        }
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_PAGE_DOWN));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(LSFT(KC_PAGE_DOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_PAGE_DOWN));
            register_code16(LGUI(KC_PAGE_DOWN));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_DOWN));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(LSFT(KC_PAGE_DOWN)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_PAGE_DOWN));
            break;
    }
    dance_state[4].step = 0;
}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [D_SYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
    [D_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
    [D_WKSP_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [D_WKSP_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};

// overriding some magic key code functions to cut down on firmware size
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
