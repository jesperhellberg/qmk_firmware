#pragma once

// ***** home row mod *****
#define GUI_A LGUI_T(KC_A)
#define ALT_O LALT_T(KC_O)
#define CTRL_E LCTL_T(KC_E)
#define SFT_U LSFT_T(KC_U)
#define SFT_H RSFT_T(KC_H)
#define CTRL_T RCTL_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define GUI_S RGUI_T(KC_S)



#define OSM_SHIFT OSM(MOD_RSFT)
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
#define ICLASS C(KC_N)
#define GOSUP C(S(A(KC_U)))

#define MUTE C(S(KC_M))
