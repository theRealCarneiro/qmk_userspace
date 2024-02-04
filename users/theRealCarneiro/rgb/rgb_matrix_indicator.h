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

#pragma once
#include "quantum.h"

enum caps_indicator_modes {
    CAPS_INDICATOR_OFF,
    CAPS_INDICATOR_DEFAULT_COLOR,
    CAPS_INDICATOR_INVERT_COLOR,
    CAPS_INDICATOR_INVERT_DEFAULT_COLOR
};

enum layer_indicator_modes {
    LAYER_INDICATOR_OFF,
    LAYER_INDICATOR_DEFAULT_COLOR,
    LAYER_INDICATOR_INVERT_COLOR,
    LAYER_INDICATOR_INVERT_DEFAULT_COLOR,
    LAYER_INDICATOR_LIGHT_LAYER_ONLY
};

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
void rgb_matrix_caps_word_highlight(uint8_t led_min, uint8_t led_max);
void rgb_matrix_caps_lock_highlight(uint8_t led_min, uint8_t led_max);
void rgb_matrix_layer_highlight(uint8_t led_min, uint8_t led_max);
RGB get_layer_highlight_rgb(void);
RGB get_caps_highlight_rgb(void);
HSV hsv_step(HSV hsv);
HSV get_default_hsv(void);
