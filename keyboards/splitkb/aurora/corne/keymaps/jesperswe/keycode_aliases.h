#pragma once

#include "quantum.h"
#include "keymap_swedish.h"

#define OSM_SHIFT OSM(MOD_RSFT)
#define GUI_ENT GUI_T(KC_ENT)
#define OSM_ALT OSM(MOD_LALT)

// ***** base layer modifiers
#define NUM_DEL LT(NUMBER,KC_DEL)
#define NUM_BSPC LT(NUMBER,KC_BSPC)
#define SYM_DEL LT(SYMBOL,KC_DEL)
#define SYM_BSPC LT(SYMBOL,KC_BSPC)

// ***** home row mod *****
#define GUI_A LGUI_T(KC_A)
#define ALT_O LALT_T(KC_O)
#define CTRL_E LCTL_T(KC_E)
#define SFT_U LSFT_T(KC_U)
#define SFT_H LSFT_T(KC_H)
#define CTRL_T RCTL_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)


// ***** IDEA
#define IDEBUG A(S(KC_F9))
#define IRUN A(S(KC_F10))
#define IFORMAT A(C(S(KC_L)))
#define GOSUP C(S(A(KC_U)))

#define MUTE C(S(KC_M))


// Normal shift
#define SHIFT_NORM(kc1, kc2) \
if (record->event.pressed) { \
  if (get_mods() & MOD_MASK_SHIFT) { \
    register_code(KC_LSFT); \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    unregister_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
} \
return false;

// Never shifted
#define SHIFT_NO(kc1, kc2) \
if (record->event.pressed) { \
  if (get_mods() & MOD_MASK_SHIFT) { \
    unregister_code(KC_LSFT); \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    unregister_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  if (get_mods() & MOD_MASK_SHIFT) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

// Always shifted
#define SHIFT_ALL(kc1, kc2) \
if (record->event.pressed) { \
  if (get_mods() & MOD_MASK_SHIFT) { \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    register_code(KC_LSFT); \
    unregister_code(kc1); \
    register_code(kc1); \
    unregister_code(KC_LSFT); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  if (get_mods() & MOD_MASK_SHIFT) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

#define BACKTICK() \
if (record->event.pressed) { \
    register_code(KC_LSFT); \
    register_code(SE_ACUT); \
    register_code(KC_SPC); \
} else { \
    clear_mods(); \
    unregister_code(KC_SPC); \
} \
return false;

#define TILDE() \
if (record->event.pressed) { \
    register_code(KC_RALT); \
    register_code(SE_DIAE); \
    register_code(KC_SPC); \
} else { \
    clear_mods(); \
    unregister_code(KC_SPC); \
} \
return false;
