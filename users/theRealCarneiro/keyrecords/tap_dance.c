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

#include "tap_dance.h"
#include "custom_keycodes.h"

tap_dance_action_t tap_dance_actions[] = {
    [CT_QTM] = ACTION_TAP_DANCE_FN(dance_clear_reset),
};

void dance_clear_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 3: // Enter Bootloader
            eeconfig_init();
            reset_keyboard();
            break;
        case 4: // Clear EEPROM
            eeconfig_init();
            break;
        case 5: // Reset
            soft_reset_keyboard();
            break;
    }
}
