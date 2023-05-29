/* Copyright 2020 globalista-dev
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
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _DEBUG,
  _GAME
};

#define LOWER OSL(_LOWER)
#define RAISE OSL(_RAISE)
#define FN TT (_FUNCTION)
#define DBLY TG (_DEBUG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ç  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ;  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Fn   |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, FN, LOWER,   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  '   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ´`  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ |   -  |   =  |      |      |      |      |      |      |  [   |   ]  |  ~^  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Prev | Next | Play |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute |      |      |      |      |             |ALTGR |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
	KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_LBRC,
    KC_VOLU, KC_MINS, KC_EQL, _______, _______,  _______, _______, _______, _______,    KC_RBRC, KC_BSLS, KC_QUOT,
    KC_VOLD, KC_MPRV, KC_MNXT, KC_MPLY,  _______, _______, _______, _______, _______, _______, _______,  _______,
    KC_MUTE, _______, _______, _______, _______, _______, KC_RALT,  _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  /   |  ?   |   A  |   B  |  C   |   F1  |  F2  |  F3  |  F4  |  F5  | F6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |   D  |   H  |   P  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |      |   T  |   S  |   Q  |      | Del  | Ins  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |ALTGR |      |      |             |      | Home | PUp  | PDw  | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    _______, KC_RO, S(KC_RO),  _______, _______, _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,
    KC_CAPS, _______, _______, _______, _______, _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,
    _______, KC_NUBS, _______, _______, _______, _______,  _______,  KC_DEL,   KC_INS,   _______,  _______, _______,
    _______, _______, KC_RALT, _______, _______, _______,            _______,  KC_HOME,  KC_PGUP,  KC_PGDN, KC_END
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |BRGTH-|BRGTH+| BLTG | BLST |      |      |      |   -  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HUE- | HUE+ | RGB  |RGBMOD|      |      |      |   /  |   4  |   5  |   6  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SAT- | SAT+ |  SP- | SP+  |      |      |      |   =  |   1  |   2  |   3  | Tab  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DBLY | BL-  |  BL+ |      |      |             |      |   0  |   ,  |   +  |   *  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_mit(
    RGB_VAD, RGB_VAI, BL_TOGG, BL_STEP,  _______, _______, _______, KC_PMNS, KC_P7,   KC_P8,    KC_P9,    KC_BSPC,
    RGB_HUD, RGB_HUI, RGB_TOG, RGB_MOD,  _______, _______, _______, KC_PSLS, KC_P4,   KC_P5,    KC_P6,    KC_PENT,
    RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI,  _______, _______, _______, KC_EQL,  KC_P1,   KC_P2,    KC_P3,    KC_TAB,
    DBLY,    BL_DEC,  BL_INC,  _______,  _______, _______, _______, KC_P0,   KC_PDOT, KC_PPLS,  KC_PAST
),

/* Debug
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | DBLY |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DEBUG] = LAYOUT_planck_mit(
    _______, RESET, DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    DBLY,   _______,   _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)

};