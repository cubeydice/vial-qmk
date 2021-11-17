/* Copyright 2021 Kyle McCreery
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _UPPER,
  _LOWER,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(

    KC_GESC,                KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPACE,                                KC_MUTE,
    KC_TAB,                 KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,    KC_ENTER,                                 KC_HOME,
    MT(MOD_LSFT, KC_LPRN),  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,         MT(MOD_RSFT, KC_RPRN),  KC_UP,            KC_END,
    MT(MOD_LCTL, KC_LBRC),  KC_LGUI,  MO(_UPPER),            KC_SPACE,            MO(_LOWER), KC_RALT, MT(MOD_RCTL, KC_RBRC), KC_LEFT,   KC_DOWN,   KC_RIGHT
    ),

    [_UPPER] = LAYOUT(
    _______,                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,                         RESET,
    KC_CAPS,                KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,   _______,                                        _______,
    _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
    _______,                KC_LALT, _______,                   _______,          _______, _______, _______, _______, _______,                      _______
    ),

    [_LOWER] = LAYOUT(
    _______,                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,                         RESET,
    KC_CAPS,                KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,   _______,                                        _______,
    _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
    _______,                KC_LALT, _______,                   _______,          _______, _______, _______, _______, _______,                      _______
    ),

    [_FN] = LAYOUT(
    _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
    _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
    _______,                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
    _______,                _______, _______,                   _______,          _______, _______, _______, _______, _______,                      _______
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
		case 1:
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        break;
    }
    return true;
}
#endif
