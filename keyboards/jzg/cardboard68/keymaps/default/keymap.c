/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _DEFAULT = 0,
    _NUM,
    _SYM,
    _NAV,
    _MOUSE,
    _FPS
};

// Aliases for readability
#define QWERTY   DF(_DEFAULT)
#define FPS      DF(_FPS)

#define BASE     TO(_DEFAULT)
#define NUM      TT(_NUM)
#define SYM      TT(_SYM)
#define NAV      TT(_NAV)
#define MOUSE    TT(_MOUSE)

#define SFT_CAPS MT(MOD_LSFT, KC_CAPS)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT(
        KC_F12,   KC_1, KC_2, KC_3, KC_4,  KC_5,  KC_F5,                           KC_F6,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
        KC_TAB,   KC_Q, KC_W, KC_E, KC_R,  KC_T, MOUSE,                           MOUSE,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC, 
        KC_ESC,   KC_A, KC_S, KC_D, KC_F,  KC_G, BASE,                            BASE,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT, 
        SFT_CAPS, KC_Z, KC_X, KC_C, KC_V,  KC_B,    NUM,    KC_LGUI,      KC_RGUI, NUM,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
                                  BASE, KC_LALT, KC_LCTL, KC_SPC, SYM,      NAV,     KC_SPC, KC_RCTL, KC_RALT, MOUSE
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______,_______, _______, _______, _______, _______, _______,
        _______, KC_F15, KC_F9, KC_F8, KC_F7, KC_F12,_______,                       _______, KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, _______,
        _______, KC_F14, KC_F6, KC_F5, KC_F4, KC_F11,_______,                       _______, KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, _______,
        _______, KC_F13, KC_F3, KC_F2, KC_F1, KC_F10, _______, _______,    _______, _______, KC_0,    KC_1, KC_2, KC_3, KC_PDOT, _______,
                           _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______,_______, _______, _______, _______, _______, _______,
        _______, KC_EXLM,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC,_______,                       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_DQUO, RSFT(KC_3), _______, 
        _______, RALT(KC_4), KC_TILD, KC_PLUS,  KC_LBRC, KC_RBRC,_______,                       _______, KC_LPRN, KC_RPRN, KC_MINS, KC_QUOT, KC_PSTE, _______, 
        _______, KC_BSLS,    KC_PIPE,  KC_UNDS, KC_LCBR, KC_RCBR, _______, _______,     _______, _______, KC_LT, KC_GT, KC_EQL, KC_GRV, KC_QUES, _______, 
                                   _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______
    ), 

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______,_______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_SLCK,_______,                       _______, KC_DEL, KC_HOME, KC_END, KC_MPLY, KC_VOLU, KC_MPRV, 
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NLCK,_______,                       _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_MNXT, 
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_INS, KC_PGUP, KC_PGDN, KC_PAUS, KC_MUTE, KC_PSCR, 
                               _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______
    ), 

    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______,_______, _______, _______, _______, _______, _______,
        _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_VOLU, _______,                       _______, FPS, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______, 
        _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, _______,                       _______, QWERTY, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, _______, 
        _______, _______, KC_WBAK, KC_WREF, KC_WFWD, KC_MUTE,  _______, _______,     _______, _______, _______, _______, _______, _______, RGB_TOG, 
                          _______, _______, _______, KC_MS_R, KC_MS_L, _______,     _______, _______, _______, _______, _______
    ), 

    [_FPS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,_______,                       _______,_______, _______, _______, _______, _______, _______,
        KC_T, KC_TAB, KC_Q, KC_X, KC_E, KC_R,_______,                       _______, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
        KC_G, KC_LSFT, KC_A, KC_W, KC_D, KC_F,_______,                       _______, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
        KC_B, KC_NUBS, KC_Z, KC_S, KC_C, KC_V, KC_ESC, KC_5,    MO(_MOUSE), NUM,    KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
                       BASE, KC_LALT, KC_LCTL, KC_SPC, KC_4,    SYM,        KC_SPC, KC_RCTL, KC_RALT, KC_LGUI
    )


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
