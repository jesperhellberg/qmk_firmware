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

enum layers {
    BASE, 
	NUMBER,
	SYMBOL,
	IDEA,
	LIGHTS
};

enum combos {
	JK_ESC
};

enum custom_keycodes {
	PROJFIND = SAFE_RANGE,
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[JK_ESC] = COMBO(jk_combo, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   GUI_A,   ALT_O,  CTRL_E,   SFT_U,    KC_I,                         KC_D,   SFT_H,  CTRL_T,   ALT_N,    KC_S, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, GUI_SCL,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,OSM_SHIFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_SPC,NUM_BSPC,    SYM_DEL,  KC_ENT, MO(IDEA)
                                      //`--------------------------'  `--------------------------'

  ),

  [NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    SE_A,    SE_O,   SE_AE, XXXXXXX, XXXXXXX,                       KC_EQL,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,			             KC_RBRC,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,    KC_0, MO(LIGHTS)
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR,   KC_UP, KC_LPRN, KC_RPRN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    SE_A,    SE_O,   SE_AE, XXXXXXX, XXXXXXX,                       KC_INS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_APP, XXXXXXX, XXXXXXX, XXXXXXX,    MUTE, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,_______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [IDEA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     PROJFIND,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  ICLASS, XXXXXXX, XXXXXXX,   GOSUP, IFORMAT,                      XXXXXXX, XXXXXXX, XXXXXXX,  IDEBUG,    IRUN,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,_______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'

  ),
  [LIGHTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCG_NRM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE

    #define PINK {HSV_PINK} 
    #define RED {HSV_RED}
    #define BLUE {HSV_BLUE}
    #define MAGENTA {HSV_MAGENTA}
    #define PURPLE {HSV_PURPLE}
    #define ORANGE {HSV_ORANGE}

  // Currently only the base layer is read. Change in rgb_matrix_indicators_advanced_user() to use all layers.
  const uint8_t PROGMEM ledmap[][42][3] = {
  [BASE] = {
    RED, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, RED,
    RED, BLUE, BLUE, BLUE, RED, BLUE, 				BLUE, RED, BLUE, BLUE, BLUE, RED,
    RED, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, RED,
		RED, RED, RED, 				RED, RED, RED
			},
  [NUMBER] = {
    MAGENTA, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, MAGENTA,
    MAGENTA, BLUE, BLUE, BLUE, RED, BLUE, 				BLUE, RED, BLUE, BLUE, BLUE, MAGENTA,
    MAGENTA, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, MAGENTA,
		MAGENTA, MAGENTA, MAGENTA, 				MAGENTA, MAGENTA, MAGENTA
			},
  [SYMBOL] = {
    PINK, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, PINK,
    PINK, BLUE, BLUE, BLUE, RED, BLUE, 				BLUE, RED, BLUE, BLUE, BLUE, PINK,
    PINK, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, PINK,
		PINK, PINK, PINK, 				PINK, PINK, PINK
			},
  [IDEA] = {
    PURPLE, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, PURPLE,
    PURPLE, BLUE, BLUE, BLUE, RED, BLUE, 				BLUE, RED, BLUE, BLUE, BLUE, PURPLE,
    PURPLE, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, PURPLE,
		PURPLE, PURPLE, PURPLE, 				PURPLE, PURPLE, PURPLE
			},
  [LIGHTS] = {
    ORANGE, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, ORANGE,
    ORANGE, BLUE, BLUE, BLUE, RED, BLUE, 				BLUE, RED, BLUE, BLUE, BLUE, ORANGE,
    ORANGE, BLUE, BLUE, BLUE, BLUE, BLUE, 				BLUE, BLUE, BLUE, BLUE, BLUE, ORANGE,
		ORANGE, ORANGE, ORANGE, 				ORANGE, ORANGE, ORANGE
			},
  };


// ====================================================
// RGB matrix
// ====================================================

  uint8_t ledIndexForKeymapIndex(uint8_t keyIndex) {
	// Turn keyIndex into a row and column within g_led_config.
	// Reference: https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/r2g/r2g.c
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t keysPerRow = 12; // Specific to crkdb!
	uint8_t keysPerHalf = keysPerRow / 2; // Assumes equal split!

	row = keyIndex / keysPerRow;
	col = keyIndex % keysPerRow;
	if (row == 3) { // Specific to crkbd!
		col += 3; // Compensate for leading three NO_LED entries in g_led_config.
	}

	bool mirror = (col >= keysPerHalf);
	if (mirror) {
		// Normalise row and col per g_led_config structure.
		row += 4;
		col -= keysPerHalf;
		// Mirror column position.
		col = (keysPerHalf - 1) - col;
	}

	return g_led_config.matrix_co[row][col];
  }

  bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layerNum = get_highest_layer(layer_state);
    uint8_t sLayer = 0;

    // Per-key indicators
    uint8_t ledIndex = 0;
    for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) { // 0 to 42
        ledIndex = ledIndexForKeymapIndex(keyIndex);

        if (ledIndex >= led_min && ledIndex <= led_max) {
            // Currently using same colors for all layers, 
            // replace sLayer with layerNum to set colors for each layer
	    HSV hsv = { .h = pgm_read_byte(&ledmap[sLayer][keyIndex][0]),
               .s = pgm_read_byte(&ledmap[sLayer][keyIndex][1]),
               .v = rgb_matrix_get_val() };
	    RGB rgb = hsv_to_rgb(hsv);
	    rgb_matrix_set_color(ledIndex, rgb.r, rgb.g, rgb.b);
        }
    }

    // Underglow layer indicators
    HSV bkgrd;
    switch (layerNum) {
      case BASE:
       bkgrd = (HSV){HSV_RED}; 
       break;
      case NUMBER:
       bkgrd = (HSV){HSV_PURPLE};
       break;
      case SYMBOL:
       bkgrd = (HSV){HSV_MAGENTA};
       break;
      case IDEA:
       bkgrd = (HSV){HSV_PINK};
       break;
      default:
       bkgrd = (HSV){HSV_GOLDENROD};
    }

    bkgrd.v = rgb_matrix_get_val() + 120;
    RGB rgb = hsv_to_rgb(bkgrd);
    for (uint8_t  i = 0; i < 12; i++) {
        ledIndex = (i < 6) ? i : i + 21;
        rgb_matrix_set_color(ledIndex, rgb.r, rgb.g, rgb.b);
    }
    return false;
  }
#endif //RGB_MATRIX_ENABLE


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

//#define L_BASE 0
//#define L_LOWER 2
//#define L_RAISE 4
//#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case NUMBER:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case SYMBOL:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case IDEA:
            oled_write_ln_P(PSTR("Idea"), false);
            break;
        case LIGHTS:
            oled_write_ln_P(PSTR("Lights"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
//        case L_ADJUST|L_LOWER:
//        case L_ADJUST|L_RAISE:
//        case L_ADJUST|L_LOWER|L_RAISE:
//            oled_write_ln_P(PSTR("Adjust"), false);
//            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  
  if (keycode == PROJFIND) {
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_F1)SS_UP(X_LALT));
      SEND_STRING("1");
    }
  } 
  return true;
}


