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
    _WIN_DFLT = 0,
    _WIN_SYM,
    _WIN_NUM,
    _WIN_NAV,
    _MAC_DFLT,
    _MAC_SYM,
    _MAC_NUM,
    _MAC_NAV,
    _MOUSE,
    _FPS
};

// Aliases for readability
#define MT_LSFT  MT(MOD_LSFT, KC_CAPS)
#define MT_RSFT  MT(MOD_RSFT, KC_CAPS)

#define WIN_DFLT TO(_WIN_DFLT)
#define MAC_DFLT TO(_MAC_DFLT)
#define FPS      TO(_FPS)

#define WIN_SYM  TT(_WIN_SYM)
#define MAC_SYM  TT(_MAC_SYM)
#define WIN_NUM  TT(_WIN_NUM)
#define MAC_NUM  TT(_MAC_NUM)
#define WIN_NAV  TT(_WIN_NAV)
#define MAC_NAV  TT(_MAC_NAV)
#define TT_MOUSE TT(_MOUSE)
#define TG_MOUSE TG(_MOUSE)

#define UK_BSLS  KC_NUBS
#define UK_PIPE  LSFT(KC_NUBS)
#define UK_DQUO  LSFT(KC_2)
#define UK_AT    LSFT(KC_QUOT)
#define UK_HASH  KC_NUHS
#define UK_TILD  LSFT(KC_NUHS)
#define UK_TAIL  LSFT(KC_GRV)

#define MAC_DQUO  LSFT(KC_QUOT)
#define MAC_AT    LSFT(KC_2)
#define MAC_HASH  LALT(KC_3)
#define MAC_GRV   KC_GRV
#define MAC_TILD  LSFT(KC_GRV)
#define MAC_BSLS  KC_NUHS
#define MAC_PIPE  LSFT(KC_NUHS)
#define MAC_DBLS  KC_NUBS // Section symbol, double S

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN_DFLT] = LAYOUT(
          KC_F12, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_BSPC,                       KC_PSCR,   KC_F6,    KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
          KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,   KC_DEL,                      WIN_DFLT,    KC_Y,     KC_U,    KC_I,   KC_O,    KC_P, KC_BSPC,
          KC_ESC,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,   KC_ENT,                      TG_MOUSE,    KC_H,     KC_J,    KC_K,   KC_L, KC_SCLN,  KC_ENT,
         KC_LSFT,  KC_Z,  KC_X,    KC_C,    KC_V,    KC_B, TG_MOUSE, KC_LGUI,    KC_RGUI,  KC_CAPS,    KC_N,     KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                               WIN_DFLT, KC_LALT, KC_LCTL,   KC_SPC, WIN_NUM,    WIN_NAV,  WIN_SYM,  KC_SPC,  KC_RCTL, KC_RALT
    ),

    [_WIN_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM,   UK_AT, UK_HASH,  KC_DLR, KC_PERC, _______,                      _______, KC_CIRC, KC_AMPR, KC_ASTR, UK_DQUO, XXXXXXX, _______, 
        _______, UK_TAIL, UK_TILD, KC_PLUS, KC_LCBR, KC_RCBR, _______,                      _______, KC_LPRN, KC_RPRN,  KC_EQL, KC_QUOT, KC_QUES, _______, 
        _______, UK_BSLS, UK_PIPE, KC_UNDS, KC_LBRC, KC_RBRC, _______, _______,    _______, _______,   KC_LT,   KC_GT, KC_MINS, KC_GRV,  KC_SLSH, _______, 
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_WIN_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PMNS, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX, _______,                      _______, KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, _______,    KC_0,    KC_1,    KC_2,    KC_3, KC_PDOT, _______,
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_WIN_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, _______,                      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, _______, 
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_NLCK, _______,                      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______, 
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, _______,  KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MAC_DFLT] = LAYOUT(
          KC_F12, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_BSPC,                       KC_PSCR,   KC_F6,    KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
          KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,   KC_DEL,                      MAC_DFLT,    KC_Y,     KC_U,    KC_I,   KC_O,    KC_P, KC_BSPC,
          KC_ESC,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,   KC_ENT,                      TG_MOUSE,    KC_H,     KC_J,    KC_K,   KC_L, KC_SCLN,  KC_ENT,
         KC_LSFT,  KC_Z,  KC_X,    KC_C,    KC_V,    KC_B, TG_MOUSE, KC_LCTL,    KC_RCTL,  KC_CAPS,    KC_N,     KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                               MAC_DFLT, KC_LOPT, KC_LCMD,   KC_SPC, MAC_NUM,    MAC_NAV,  MAC_SYM,  KC_SPC,  KC_RCMD, KC_ROPT
    ),

    [_MAC_SYM] = LAYOUT(
        _______,  _______,  _______,  _______, _______, _______, _______,                      _______, _______, _______, _______,  _______, _______, _______,
        _______,  KC_EXLM,   MAC_AT, MAC_HASH,  KC_DLR, KC_PERC, _______,                      _______, KC_CIRC, KC_AMPR, KC_ASTR, MAC_DQUO, XXXXXXX, _______, 
        _______, MAC_DBLS, MAC_TILD,  KC_PLUS, KC_LCBR, KC_RCBR, _______,                      _______, KC_LPRN, KC_RPRN,  KC_EQL,  KC_QUOT, KC_QUES, _______, 
        _______, MAC_BSLS, MAC_PIPE,  KC_UNDS, KC_LBRC, KC_RBRC, _______, _______,    _______, _______,   KC_LT,   KC_GT, KC_MINS, MAC_GRV,  KC_SLSH, _______, 
                                      _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MAC_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______, KC_PSLS,    KC_7,    KC_8,    KC_9, KC_PMNS, _______,
        _______, KC_LCTL, KC_LCMD, KC_LSFT, KC_LOPT, XXXXXXX, _______,                      _______, KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, _______,    KC_0,    KC_1,    KC_2,    KC_3, KC_PDOT, _______,
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MAC_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, _______,                      _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, _______, 
        _______, KC_LCTL, KC_LCMD, KC_LSFT, KC_LOPT, KC_NLCK, _______,                      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, _______,  KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                      _______,  _______, _______, _______, _______, _______, _______,
        _______, KC_VOLU, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,                      _______,      FPS, KC_VOLU, KC_PAUS, KC_MPRV, XXXXXXX, _______,
        _______, KC_VOLD, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,                      _______, MAC_DFLT, KC_VOLD, KC_MPLY, KC_MNXT, XXXXXXX, _______,
        _______, KC_MUTE, KC_WBAK, KC_WREF, KC_WFWD, XXXXXXX, _______, _______,    _______, _______, WIN_DFLT, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                   _______, _______, KC_BTN2, KC_BTN1, _______,    _______, _______,  _______, _______, _______
    ),

    [_FPS] = LAYOUT(
         KC_F12,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_F5,                      KC_PSCR,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
         KC_TAB,    KC_T,    KC_Q,    KC_X,    KC_E,    KC_R, _______,                      _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_NUBS,    KC_A,    KC_W,    KC_D,    KC_F, _______,                      _______, _______, _______, _______, _______, _______, _______,
           KC_B,    KC_G,    KC_Z,    KC_S,    KC_C,    KC_V,    KC_5,  KC_ESC,    _______, _______, _______, _______, _______, _______, _______, _______,
                                  WIN_DFLT, KC_LALT, KC_LCTL,  KC_SPC,    KC_4,    _______, _______, _______, _______, _______
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
