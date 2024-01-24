#include "macros.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

    return process_record_keymap(keycode, record);
}
