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
#include "action.h"
#include "version.h"

enum userspace_custom_keycodes {

    // macros
    SELWORD = SAFE_RANGE,
    SELLINE,
    WORDFOR,
    WORDBAC,

    // RGB
    RGB_IDT, // RGB toggle idle config status
    RGB_ISA, // RGB idle set animation
    RGB_ITG, // RGB toggle indicator config status
             //
    RGB_LIN, // RGB layer indicator mode next
    RGB_LIP, // RGB layer indicator mode previous

    RGB_CIN, // RGB caps indicator mode next
    RGB_CIP, // RGB caps indicator mode previous
};

#ifdef TAP_DANCE_ENABLE
#    define QT_DNCE TD(CT_QTM)

enum tap_dance_index {
    CT_QTM, // Quantum tap dance
};

#endif // TAP_DANCE_ENABLE
