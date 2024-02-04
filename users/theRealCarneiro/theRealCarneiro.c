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
#include <stdint.h>
#include "color.h"
#include "eeconfig.h"
#include "keyboard.h"
#include "rgb_matrix.h"

user_config_t user_config;
uint32_t      idle_time;

/*void keyboard_pre_init_user(void) {*/

/*}*/

void eeconfig_init_user(void) { // EEPROM is getting reset!
    user_config.raw                         = 0;
    user_config.rgb_matrix_custom_indicator = true;
    user_config.layer_indicator_mode        = 1;
    user_config.caps_indicator_mode         = 1;
    user_config.rgb_matrix_idle             = true;
    user_config.rgb_matrix_idle_animation   = RGB_MATRIX_DEFAULT_IDLE_ANIMATION;
    eeconfig_update_user(user_config.raw);
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
__attribute__((weak)) void keyboard_post_init_rgb_matrix(void) {}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();

    user_config.raw = eeconfig_read_user();

#ifdef CUSTOM_RGB_MATRIX
    keyboard_post_init_rgb_matrix();
#endif
}

__attribute__((weak)) void housekeeping_task_keymap(void) {}
__attribute__((weak)) void housekeeping_task_rgb_matrix(void) {}

void housekeeping_task_user() {
    housekeeping_task_keymap();

#ifdef CUSTOM_RGB_MATRIX
    housekeeping_task_rgb_matrix();
#endif
}

__attribute__((weak)) bool shutdown_keymap(bool jump_to_bootloader) {
    return true;
}

__attribute__((weak)) void shutdown_rgb_matrix(bool jump_to_bootloader) {}

bool shutdown_user(bool jump_to_bootloader) {
#ifdef CUSTOM_RGB_MATRIX
    shutdown_rgb_matrix(jump_to_bootloader);
#endif

    if (!shutdown_keymap(jump_to_bootloader)) {
        return false;
    }
    return true;
}
