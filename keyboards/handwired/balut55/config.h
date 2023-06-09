/*
Copyright 2021 Queen Dela Cruz

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1234
#define PRODUCT_ID      0x5678
#define MANUFACTURER    cubeydice
#define PRODUCT         balut55
#define DEVICE_VER 0

/* Key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 15

/* Key matrix pins */
#define MATRIX_ROW_PINS { B0, D3, D2, B7 }
#define MATRIX_COL_PINS { D0, D4, C6, D7, E6, B4, B5, F4, F5, F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS { B0, C7, D5 }

/* Encoder pins */
#define ENCODERS_PAD_A { F1 }
#define ENCODERS_PAD_B { F0 }

/* Encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1
