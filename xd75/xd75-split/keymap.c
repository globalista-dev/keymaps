#include QMK_KEYBOARD_H
#include <keymap_brazilian_abnt2.h>

enum layer_names {
    _QW,
    _FN,
    _RGB
};

#define FN OSL(_FN)
#define RGB OSL(_RGB)
#define PRINT SGUI(KC_S)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  BR_QUOT, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP, KC_MPLY, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BR_ACUT, BR_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN, PRINT,   KC_H,    KC_J,    KC_K,    KC_L,    BR_CCED, BR_TILD, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME, KC_INS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  BR_SCLN, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, FN,      RGB,     KC_SPC,  KC_END,  KC_DEL,  KC_SPC,  KC_LGUI, KC_RALT, BR_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    
    [_FN] = LAYOUT_ortho_5x15(
        BR_QUOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,  _______,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BR_LBRC, _______,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, BR_RBRC, _______,
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MSTP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),
    
    [_RGB] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_TOG, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______
    )
};
