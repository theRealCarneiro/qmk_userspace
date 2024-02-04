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
#include "custom_keycodes.h"
#include "theRealCarneiro.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool process_record_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        idle_time = timer_read32();
    }

    if (!(process_record_keymap(keycode, record)
#ifdef CUSTOM_RGB_MATRIX
          && process_record_rgb_matrix(keycode, record)
#endif
              )) {
        return false;
    }

    switch (keycode) {
        case SELWORD: /* Select word */
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
            }
            break;

        case SELLINE: /* Select line */
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            break;

        case WORDFOR: /* Next word */
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)));
            }
            break;

        case WORDBAC: /* Previous word */
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
            }
            break;
    }
    return true;
}
