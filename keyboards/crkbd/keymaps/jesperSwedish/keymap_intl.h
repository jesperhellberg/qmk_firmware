#pragma once

#include "quantum.h"
#include "keymap_swedish.h"

#define OSM_SHIFT OSM(MOD_RSFT)
//#define OSM_CTRL OSM(MOD_LCTL)
#define GUI_ENT GUI_T(KC_ENT)
#define OSM_ALT OSM(MOD_LALT)
#define GUI_SCL GUI_T(KC_SCLN)

// ***** base layer modifiers
#define NUM_DEL LT(NUMBER,KC_DEL)
#define NUM_BSPC LT(NUMBER,KC_BSPC)
#define SYM_DEL LT(SYMBOL,KC_DEL)
#define SYM_BSPC LT(SYMBOL,KC_BSPC)

// ***** swedish chars
//#define SE_A ALGR(KC_A)
//#define SE_AE ALGR(KC_D)
//#define SE_O ALGR(KC_S)


// ***** IDEA
#define IDEBUG A(S(KC_F9))
#define IRUN A(S(KC_F10))
#define IFORMAT A(C(S(KC_L)))
//#define ICLASS C(S(KC_N))
#define ICLASS C(KC_N)
#define GOSUP C(S(A(KC_U)))

#define MUTE C(S(KC_M))


extern bool lshift;
extern bool rshift;

// Normal shift
#define SHIFT_NORM(kc1, kc2) \
if (record->event.pressed) { \
  if (lshift || rshift) { \
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
  unregister_code(KC_LSFT); \
  if (lshift || rshift) { \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;

// Always shifted
#define SHIFT_ALL(kc1, kc2) \
if (record->event.pressed) { \
  register_code(KC_LSFT); \
  if (lshift || rshift) { \
    unregister_code(kc2); \
    register_code(kc2); \
  } else { \
    unregister_code(kc1); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  if (lshift || rshift) \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;


// Shift on kc1, AltGr on kc2
// this needs to unregister it's pressed button
#define SHIFT_ALGR(kc1, kc2) \
if (record->event.pressed) { \
  if (lshift || rshift) { \
    unregister_code(KC_LSFT); \
    register_code(KC_RALT); \
    register_code(kc2); \
  } else { \
    clear_mods(); \
    register_code(KC_LSFT); \
    register_code(kc1); \
  } \
} else { \
  unregister_code(kc1); \
  unregister_code(kc2); \
  if (get_mods() & MOD_BIT(KC_RALT)) { \
    unregister_code(KC_RALT); \
  } \
  if (lshift || rshift)  \
    register_code(KC_LSFT); \
  else \
    unregister_code(KC_LSFT); \
} \
return false;
