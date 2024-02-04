/* Copyright 2024 Gabriel Carneiro @theRealCarneiro
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

#include "keycodes.h"
#include "theRealCarneiro.h"
#include QMK_KEYBOARD_H

#define VI_ADJ MO(_VI_ADJ)
#define VI_ESC LT(_VI, KC_ESC)
#define RGB_ESC LT(_RGB, KC_ESC)
#define SBL_GRV LT(_SYMBOL, KC_GRV)
#define SBL_QTO LT(_SYMBOL, KC_QUOT)

// clang-format off
enum layers {
    _BASE,
    _STOCK,
    _VI,
    _VI_ADJ,
    _SYMBOL,
    _FN,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        RGB_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        SBL_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        VI_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SBL_QTO, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

    [_STOCK] = LAYOUT(
        RGB_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

    [_VI] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, WORDFOR, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,QK_LEAD, _______, _______, _______,          _______,
        VI_ADJ,  _______, _______, KC_DEL,  _______, SELWORD, WORDBAC, _______, _______, _______, _______, _______,          VI_ADJ,  _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [_VI_ADJ] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, KC_BSPC, _______, SELLINE, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [_SYMBOL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [_FN] = LAYOUT(
        QT_DNCE, _______, _______, _______, _______, KC_MPLY, KC_MSTP, KC_MNXT, KC_MPRV, _______, _______, _______, KC_F14,  KC_SLEP,          KC_F15,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______,          _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MAIL, _______, _______, _______,          _______, _______, _______,
        _______, GU_TOGG, _______,                   _______,                            _______, _______, _______,          _______, _______, _______),

    [_RGB] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           RGB_TOG,
        _______, RGB_M_P, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_ITG, _______, _______, _______, _______, RGB_SAI,           RGB_SPI,
        RGB_CIN, _______, RGB_ISA, _______, _______, _______, _______, _______, _______, RGB_LIN, _______, _______, _______, RGB_SAD,           RGB_SPD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______,          _______,  RGB_VAI, _______,
        _______, _______, _______,                   RGB_IDT,                            _______, _______, _______,          RGB_RMOD, RGB_VAD, RGB_MOD),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]     =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_STOCK]    =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_VI]       =   { ENCODER_CCW_CW(KC_BRIU, KC_BRID) },
    [_VI_ADJ]   =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_SYMBOL]   =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_FN]       =   { ENCODER_CCW_CW(KC_BRIU, KC_BRID) },
    [_RGB]      =   { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

#ifdef COMBO_ENABLE
const uint16_t PROGMEM bootloader_combo[]   = {KC_F1, KC_F9, KC_F12, COMBO_END};
const uint16_t PROGMEM reset_eeprom_combo[] = {KC_F2, KC_F9, KC_F12, COMBO_END};
const uint16_t PROGMEM reset_keyboard_combo[] = {KC_F3, KC_F9, KC_F12, COMBO_END};
const uint16_t PROGMEM make_flash_combo[] = {KC_F4, KC_F9, KC_F12, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootloader_combo, QK_BOOTLOADER),
    COMBO(reset_eeprom_combo, QK_CLEAR_EEPROM),
    COMBO(reset_keyboard_combo, QK_REBOOT),
    COMBO(make_flash_combo, QK_MAKE)
};
#endif // COMBO_ENABLE

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index != 0) {
        return true;
    }

    layer_move(active * _STOCK);
    set_single_persistent_default_layer(active * _STOCK);
    return false;
}
#endif // DIP_SWITCH_ENABLE

bool shutdown_keymap(bool jump_to_bootloader) {
    if(jump_to_bootloader) {
        writePin(LED_MAC_OS_PIN, 1);
    }
    return true;
}
