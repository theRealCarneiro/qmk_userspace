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

/*#include "rgb_matrix.h"*/
#include "rgb_matrix_indicator.h"

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_LAYER_DISABLE
    rgb_matrix_layer_highlight(led_min, led_max);
#endif

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_CAPS_DISABLE
    rgb_matrix_caps_word_highlight();
    rgb_matrix_caps_lock_highlight();
#endif

    return false;
}

/* Highlight both caps word keys when caps word is on */
void rgb_matrix_caps_word_highlight(void) {
    if (is_caps_word_on()) {
        rgb_matrix_set_color(LEFT_CAPS_WORD_RGB_INDEX, RGB_INDICATOR_COLOR); /* Left shift */
        rgb_matrix_set_color(RIGHT_CAPS_WORD_RGB_INDEX, RGB_INDICATOR_COLOR); /* Right shift */
    }
}

/* Highlight capslock rgb when caps lock is on */
void rgb_matrix_caps_lock_highlight(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_RGB_INDEX, RGB_INDICATOR_COLOR); /* Left shift */
    }
}

/* Highlight highest layer */
void rgb_matrix_layer_highlight(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 1) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_INDICATOR_COLOR);
                }
            }
        }
    }
}
