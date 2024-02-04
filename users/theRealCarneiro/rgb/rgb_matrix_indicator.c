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

#include "theRealCarneiro.h"
#include "action_layer.h"
#include "rgb_matrix_indicator.h"
#include "rgb_matrix.h"

#define RGB_MATRIX_INDICATOR_SET_RGB(index, rgb) RGB_MATRIX_INDICATOR_SET_COLOR(index, rgb.r, rgb.g, rgb.b)

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max) || !user_config.rgb_matrix_custom_indicator) {
        return false;
    }

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_LAYER_DISABLE
    rgb_matrix_layer_highlight(led_min, led_max);
#endif // CUSTOM_RGB_MATRIX_INDICATOR_LAYER_DISABLE

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_CAPS_DISABLE
    rgb_matrix_caps_word_highlight(led_min, led_max);
    rgb_matrix_caps_lock_highlight(led_min, led_max);
#endif // CUSTOM_RGB_MATRIX_INDICATOR_CAPS_DISABLE

    return false;
}

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_CAPS_DISABLE
/* Highlight both caps word keys when caps word is on */
void rgb_matrix_caps_word_highlight(uint8_t led_min, uint8_t led_max) {
    if (is_caps_word_on()) {
        if (user_config.caps_indicator_mode == CAPS_INDICATOR_OFF) {
            return;
        }
        RGB rgb = get_caps_highlight_rgb();
        RGB_MATRIX_INDICATOR_SET_RGB(LEFT_CAPS_WORD_RGB_INDEX, rgb);
        RGB_MATRIX_INDICATOR_SET_RGB(RIGHT_CAPS_WORD_RGB_INDEX, rgb);
    }
}

/* Highlight capslock rgb when caps lock is on */
void rgb_matrix_caps_lock_highlight(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        if (user_config.caps_indicator_mode == CAPS_INDICATOR_OFF) {
            return;
        }
        RGB rgb = get_caps_highlight_rgb();
        RGB_MATRIX_INDICATOR_SET_RGB(CAPS_LOCK_RGB_INDEX, rgb);
    }
}

RGB get_caps_highlight_rgb(void) {
    RGB rgb = {0, 0, 0};
    switch (user_config.caps_indicator_mode) {
        case CAPS_INDICATOR_DEFAULT_COLOR:
            rgb = hsv_to_rgb(get_default_hsv());
            break;

        case CAPS_INDICATOR_INVERT_COLOR:
            rgb = hsv_to_rgb(hsv_step(rgb_matrix_get_hsv()));
            break;

        case CAPS_INDICATOR_INVERT_DEFAULT_COLOR:
            rgb = hsv_to_rgb(hsv_step(get_default_hsv()));
            break;
    }
    return rgb;
}
#endif // CUSTOM_RGB_MATRIX_INDICATOR_CAPS_DISABLE

#ifndef CUSTOM_RGB_MATRIX_INDICATOR_LAYER_DISABLE
/* Highlight highest active layer */
void rgb_matrix_layer_highlight(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) <= 1 || !user_config.layer_indicator_mode) {
        return;
    }

    uint8_t layer = get_highest_layer(layer_state);
    RGB     rgb   = get_layer_highlight_rgb();
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index   = g_led_config.matrix_co[row][col];
            int     keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

            switch (user_config.layer_indicator_mode) {
                case LAYER_INDICATOR_DEFAULT_COLOR:
                case LAYER_INDICATOR_INVERT_COLOR:
                case LAYER_INDICATOR_INVERT_DEFAULT_COLOR:
                    // clang-format off
                    if (keycode > KC_TRNS) { RGB_MATRIX_INDICATOR_SET_RGB(index, rgb); }
                    break;

                case LAYER_INDICATOR_LIGHT_LAYER_ONLY:
                    if (keycode == KC_TRNS) { RGB_MATRIX_INDICATOR_SET_RGB(index, rgb); }
                    // clang-format on
                    break;
            }
        }
    }
}

RGB get_layer_highlight_rgb(void) {
    RGB rgb;
    switch (user_config.layer_indicator_mode) {
        case LAYER_INDICATOR_DEFAULT_COLOR:
            rgb = hsv_to_rgb(get_default_hsv());
            break;

        case LAYER_INDICATOR_INVERT_COLOR:
            rgb = hsv_to_rgb(hsv_step(rgb_matrix_get_hsv()));
            break;

        case LAYER_INDICATOR_INVERT_DEFAULT_COLOR:
            rgb = hsv_to_rgb(hsv_step(get_default_hsv()));
            break;

        case LAYER_INDICATOR_LIGHT_LAYER_ONLY:
            rgb = (RGB){0, 0, 0};
            break;
    }
    return rgb;
}
#endif // CUSTOM_RGB_MATRIX_INDICATOR_LAYER_DISABLE

HSV hsv_step(HSV hsv) {
    hsv.h = (hsv.h + 125) % 255;
    hsv.v = RGB_MATRIX_DEFAULT_VAL;
    return hsv;
}

HSV get_default_hsv(void) {
    return (HSV){RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL};
}
