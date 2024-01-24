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

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define TAP_CODE_DELAY 20

#ifdef RGB_MATRIX_ENABLE

#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_TRIGGER_ON_KEYDOWN
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_KEYRELEASES

#    define RGB_INDICATOR_COLOR 0, 236, 253

#    define LEFT_CAPS_WORD_RGB_INDEX 59
#    define RIGHT_CAPS_WORD_RGB_INDEX 71
#    define CAPS_LOCK_RGB_INDEX 44

#endif
