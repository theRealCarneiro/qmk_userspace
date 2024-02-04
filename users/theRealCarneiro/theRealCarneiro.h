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
#include <stdint.h>
#include <stdbool.h>
#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
#    include "rgb/rgb_matrix_indicator.h"
#    include "rgb/rgb_matrix_stuff.h"
#endif // RGB_MATRIX_ENABLE

#include "keyrecords/custom_keycodes.h"

#ifdef TAP_DANCE_ENABLE
#    include "keyrecords/tap_dance.h"
#endif // TAP_DANCE_ENABLE

typedef union {
    uint16_t raw;
    struct {
        bool rgb_matrix_custom_indicator  : 1;
        uint8_t layer_indicator_mode      : 2;
        uint8_t caps_indicator_mode       : 2;
        bool rgb_matrix_idle              : 1;
        uint8_t rgb_matrix_idle_animation : 8;
    };
} user_config_t;

_Static_assert(sizeof(user_config_t) == sizeof(uint16_t), "User EECONFIG out of spec.");

extern user_config_t user_config;
extern uint32_t idle_time;
