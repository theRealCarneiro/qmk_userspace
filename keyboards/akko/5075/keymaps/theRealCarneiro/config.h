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

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define LAYER_STATE_8BIT

// Add delay to key release so that games can register LT
#define TAP_CODE_DELAY 20

#ifdef CAPS_WORD_ENABLE
#    define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#endif // CAPS_WORD_ENABLE

#ifdef RGB_MATRIX_ENABLE

#    define CUSTOM_RGB_MATRIX
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_SOLID_OFF
#    define RGB_MATRIX_DEFAULT_HUE 6
#    define RGB_MATRIX_DEFAULT_SAT 252
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_DEFAULT_IDLE_ANIMATION RGB_MATRIX_PIXEL_FRACTAL
#    define RGB_MATRIX_IDLE_TIMEOUT 10000

#    define LEFT_CAPS_WORD_RGB_INDEX 59
#    define RIGHT_CAPS_WORD_RGB_INDEX 71
#    define CAPS_LOCK_RGB_INDEX 44

#endif
