/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12         Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)         BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;                         Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [0] = LAYOUT(
        KC_ESC,       KC_F1,   KC_F2,   KC_F3,         KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SLEP, KC_MUTE,
        KC_GRV,       KC_1,    KC_2,    KC_3,          KC_4,          KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,       KC_Q,    KC_W,    KC_E,          KC_R,          KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        LT(2,KC_ESC), KC_A,    KC_S,    KC_D,          KC_F,          KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,               KC_Z,    KC_X,          KC_C,          KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,      KC_LALT, KC_LGUI,                                        KC_SPC,                             KC_RGUI, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_TRNS,      KC_F1,   KC_F2,   KC_F3,         KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS,      RGB_M_P, RGB_M_B, RGB_M_R,       RGB_M_SW,      RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS,      RGB_TOG, RGB_MOD, RGB_HUI,       RGB_SAI,       RGB_VAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS,      KC_TRNS, RGB_RMOD,RGB_HUD,       RGB_SAD,       RGB_VAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,               KC_CAPS, KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS,                                        KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,      KC_SLCK, KC_PAUS, LCTL(KC_UP),   LCTL(KC_DOWN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,          KC_TRNS,
        KC_TRNS,      KC_HOME, KC_UP,   KC_END,        KC_PGUP,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS,      KC_LEFT, KC_DOWN, KC_RGHT,       KC_PGDN,       KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_MUTE,               KC_VOLD, KC_VOLU,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_PGUP, KC_TRNS,
        KC_TRNS,      KC_TRNS, KC_TRNS,                                        KC_ENT,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    )
};


void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      if (get_mods() & MOD_MASK_GUI) {
        tap_code(KC_PAUS);
      } else {
        tap_code(KC_VOLU);
      }
    } else {
      if (get_mods() & MOD_MASK_GUI) {
        tap_code(KC_SLCK);
      } else {
        tap_code(KC_VOLD);
      }
    }
}
