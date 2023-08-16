/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keycode_aliases.h"
#include "/home/jesper/qmk_firmware/jesperKeymap/generalSwedish.h"

enum combos {
	JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[JK_ESC] = COMBO(jk_combo, KC_ESC)
};

// turn off leds
void keyboard_pre_init_user(void) {
    setPinOutput(24);
    writePinHigh(24);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PROJFIND:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F1)SS_UP(X_LALT));
            SEND_STRING("1");
        }
        return false;
    case JH_DOT:
        SHIFT_NORM(KC_DOT,SE_LABK);
    case JH_COMM:
        SHIFT_NO(KC_COMM,SE_LABK);
    case JH_QUOT:
        SHIFT_NORM(KC_NUHS,SE_2);
    case JH_SLSH:
        SHIFT_ALL(SE_7,SE_PLUS);
    case JH_GRV:
        SHIFT_ALGR(SE_ACUT,SE_DIAE);
    case JH_SCLN:
        SHIFT_ALL(SE_COMM,SE_DOT);
    default:
        return true;
  }
}
