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

enum layers {
    _CHARS,
    _UTILS,
    _MATH,
};

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CHARS] = LAYOUT_split_3x5_3(
  // gotta figure out how to use home row mods...
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,   KC_W,    KC_F,    KC_P,     KC_B,                                   KC_J,   KC_L,   KC_U,     KC_Y,   KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,                KC_M, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| 
      KC_Z,     KC_X,    KC_C,     KC_D,   KC_V,                                  KC_K,   KC_H,   KC_DOT,   KC_SLSH, KC_QUES,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TAB, KC_SPC, KC_BSPC, KC_ENT, TO(_UTILS), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),

    [_UTILS] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,--------------------------------------+---------------.
              KC_TILD, KC_LT, KC_GT, KC_LBRC, KC_RBRC,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
              KC_AT, KC_DQT, KC_QUOT, KC_LPRN, KC_RPRN,                         KC_GRV, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
              KC_DLR, KC_PERC, KC_HASH, KC_LCBR, KC_RCBR,                       XXXXXXX, XXXXXXX, KC_COMM, KC_UNDS, KC_EXLM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB, TO(_CHARS), KC_BSPC, KC_ENT, TO(_MATH), KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

    [_MATH] = LAYOUT_split_3x5_3(
  //                                                                            right hand side is "numpad"
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_F1, KC_F9, KC_AMPR, KC_EQL, KC_EXLM,                                KC_PLUS, KC_7, KC_8, KC_9, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F2, KC_F10, KC_PIPE, KC_CIRC, XXXXXXX,                              KC_ASTR, KC_4, KC_5, KC_6, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F3, KC_F11, KC_COMM, KC_DOT, XXXXXXX,                               KC_0, KC_1, KC_2, KC_3, KC_PERC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TAB, TO(_CHARS), KC_BSPC, KC_ENT, XXXXXXX, KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("my@mail.com");
      }
      return false;
  }
  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
