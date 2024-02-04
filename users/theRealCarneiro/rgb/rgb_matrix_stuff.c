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

#include <stdint.h>
#include "config.h"
#include "theRealCarneiro.h"
#include "rgb_matrix_stuff.h"
#include "keyrecords/custom_keycodes.h"
#include "rgb_matrix.h"

#define IS_IDLE_TIMEOUT(idle_time) (timer_elapsed32(idle_time) >= RGB_MATRIX_IDLE_TIMEOUT)

void keyboard_post_init_rgb_matrix(void) {}

void shutdown_rgb_matrix(bool jump_to_bootloader) {
    if (jump_to_bootloader) {
        void rgb_matrix_update_pwm_buffers(void);
        rgb_matrix_set_color_all(0, 0, 0);
        rgb_matrix_update_pwm_buffers();
    }
}

void housekeeping_task_rgb_matrix(void) {
    static uint32_t last_time = 0;

    // only check idle hint once every 100ms
    if (timer_elapsed32(last_time) > 100 && user_config.rgb_matrix_idle) {
        handle_idle_anim();
    }
}

bool process_record_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_ITG: // Toggle custom indicators
            if (record->event.pressed) {
                user_config.rgb_matrix_custom_indicator = !user_config.rgb_matrix_custom_indicator;
            }
            break;
        case RGB_LIN: // RGB layer indicator mode next
            if (record->event.pressed) {
                user_config.layer_indicator_mode += 1;
                if (user_config.layer_indicator_mode > 4) {
                    user_config.layer_indicator_mode = 0;
                }
            }

            break;
        case RGB_LIP: // RGB layer indicator mode previous
            break;

        case RGB_CIN: // RGB caps indicator mode next
            if (record->event.pressed) {
                user_config.caps_indicator_mode += 1;
                if (user_config.caps_indicator_mode > 3) {
                    user_config.caps_indicator_mode = 0;
                }
            }
            break;

        case RGB_CIP: // RGB caps indicator mode mode previous
            break;

        case RGB_IDT: // Toggle idle
            if (record->event.pressed) {
                user_config.rgb_matrix_idle = !user_config.rgb_matrix_idle;
            }
            break;

        case RGB_ISA: // Sets the current animation as the new idle animation
            if (record->event.pressed) {
                user_config.rgb_matrix_idle_animation = rgb_matrix_get_mode();
            }
            break;


        default:
            return true;
    }

    eeconfig_update_user(user_config.raw);
    return true;
}

void handle_idle_anim(void) {
    static uint32_t last_anim;
    static bool     idle_anim_active = false;

    if (IS_IDLE_TIMEOUT(idle_time)) {
        if (!idle_anim_active) {
            idle_anim_active = true;
            last_anim        = rgb_matrix_get_mode();
            rgb_matrix_mode_noeeprom(user_config.rgb_matrix_idle_animation);
        }
    } else if (idle_anim_active) {
        idle_anim_active = false;
        rgb_matrix_mode_noeeprom(last_anim);
    }
}
