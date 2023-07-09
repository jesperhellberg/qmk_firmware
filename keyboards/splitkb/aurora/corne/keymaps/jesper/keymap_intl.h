#pragma once

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
#define SE_A ALGR(KC_A)
#define SE_AE ALGR(KC_D)
#define SE_O ALGR(KC_S)

// ***** IDEA
#define IDEBUG A(S(KC_F9))
#define IRUN A(S(KC_F10))
#define IFORMAT A(C(S(KC_L)))
//#define ICLASS C(S(KC_N))
#define ICLASS C(KC_N)
#define GOSUP C(S(A(KC_U)))

#define MUTE C(S(KC_M))
