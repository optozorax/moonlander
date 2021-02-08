#include QMK_KEYBOARD_H
#include <quantum/pointing_device.h>
#include "version.h"

#include "arbitrary_keycode/include.h"

#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE
#include "lang_shift/include.h"
#include "combo/include.h"
#include "color/include.h"
#include "tt/include.h"
#include "repeat/include.h"

enum custom_keycodes {
  KEYCODES_START = CUSTOM_SAFE_RANGE,

  // Wow, such empty

  NEW_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE NEW_NEW_SAFE_RANGE
};

#define MY_layout( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

// Shift keys
#define SH_TAB S(KC_TAB)

// Ctrl+Shift keys
#define CS_T LCTL(S(KC_T))
#define CS_K LCTL(S(KC_K))
#define CS_M LCTL(S(KC_M))
#define CS_P LCTL(S(KC_P))

// Alt keys
#define AL_UP LALT(KC_UP)
#define AL_PSCR LALT(KC_PSCR)

// Gui keys
#define WN_1 LGUI(KC_1)
#define WN_2 LGUI(KC_2)
#define WN_3 LGUI(KC_3)
#define WN_4 LGUI(KC_4)
#define WN_5 LGUI(KC_5)
#define WN_6 LGUI(KC_6)
#define WN_7 LGUI(KC_7)
#define WN_8 LGUI(KC_8)
#define WN_9 LGUI(KC_9)
#define WN_F1 LGUI(KC_F1)
#define WN_F2 LGUI(KC_F2)
#define WN_F3 LGUI(KC_F3)
#define WN_Q LGUI(KC_Q)
#define WN_L LGUI(KC_L)

// Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)
#define CT_ENT LCTL(KC_ENT)
#define CT_BSPC LCTL(KC_BSPC)
#define CT_1 LCTL(KC_1)
#define CT_2 LCTL(KC_2)
#define CT_T LCTL(KC_T)
#define CT_W LCTL(KC_W)
#define CT_J LCTL(KC_J)
#define CT_G LCTL(KC_G)
#define CT_S LCTL(KC_S)
#define CT_F LCTL(KC_F)
#define CT_A LCTL(KC_A)
#define CT_S LCTL(KC_S)
#define CT_F5 LCTL(KC_F5)
#define CT_PGUP LCTL(KC_PGUP)
#define CT_PGDN LCTL(KC_PGDN)
#define CT_X LCTL(KC_X)
#define CT_C LCTL(KC_C)
#define CT_V LCTL(KC_V)
#define CT_PLUS LCTL(KC_EQL)
#define CT_MINS LCTL(KC_MINS)
#define CT_BSLS LCTL(KC_BSLS)

#define RGB_LYR TOGGLE_LAYER_COLOR

// Chords
// Left Index
#define CMB_CTC CMB_000
#define CMB_CTV CMB_001
// Left Thumb
#define CMB_SFT CMB_002
#define CMB_BSP CMB_003
#define CMB_ENT CMB_004
#define CMB_CTL CMB_005
// Left Left Thumb
#define CMB_LYV CMB_006
#define CMB_LYG CMB_007
// Right Thumb
#define CMB_LAN CMB_008
#define CMB_DOT CMB_009
#define CMB_SPC CMB_010
#define CMB_ALT CMB_011

// Shifted index keys
#define CMB_CAC CMB_012
#define CMB_CAV CMB_013

// Russian index keys on letters
#define CMS_R CMB_014
#define CMS_SH CMB_015
#define CMS_S_R CMB_016
#define CMS_SSH CMB_017

// Left number-row
#define CMB_PLS CMB_018
#define CMB_SCL CMB_019
#define CMB_GRV CMB_020
#define CMB_EXL CMB_021
#define CMB_ASR CMB_022
// Right number-row
#define CMB_EQL CMB_023
#define CMB_CLN CMB_024
#define CMB_CMM CMB_025
#define CMB_QUE CMB_026
#define CMB_SLS CMB_027

// Brackets on red layer, order: 1 - (), 2 - [], 3 - {}, 4 - <>
#define CMB_LB1 CMB_028
#define CMB_RB1 CMB_029
#define CMB_LB2 CMB_030
#define CMB_RB2 CMB_031
#define CMB_LB3 CMB_032
#define CMB_RB3 CMB_033
#define CMB_LB4 CMB_034
#define CMB_RB4 CMB_035

// Brackets on XCompose layer
#define CMB_LTR CMB_036
#define CMB_RTR CMB_037
#define CMB_LCR CMB_038
#define CMB_RCR CMB_039

#define TT_CTJ TT_000

// Подключаем обработку кастомных кейкодов
#include "xcompose.h"
#include "custom_lang.h"
#include "custom_hotkeys.h"
#include "moonlander_leds.h"
#include "mouse_pixel_move.h"
#include "song_keys.h"

enum Layers {
  L_EN = 0,
  L_EN_S,

  L_RU,
  L_RU_S,

  L_RED,
  L_GREN,
  L_VIOL,
  L_GRAY,
  L_CYAN,
  L_YELW,

  L_GAME,
  L_NUCL,
};

#define TG_RED TG(L_RED)
#define TG_GREN TG(L_GREN)
#define TG_VIOL TG(L_VIOL)
#define TG_GRAY TG(L_GRAY)
#define TG_CYAN TG(L_CYAN)
#define TG_YELW TG(L_YELW)
#define TG_GAME TG(L_GAME)
#define TG_NUCL TG(L_NUCL)

#define MO_RED MO(L_RED)
#define MO_GREN MO(L_GREN)
#define MO_VIOL MO(L_VIOL)
#define MO_GRAY MO(L_GRAY)
#define MO_CYAN MO(L_CYAN)
#define MO_YELW MO(L_YELW)
#define MO_GAME MO(L_GAME)
#define MO_NUCL MO(L_NUCL)

#define TT_RED (TT_000 + L_RED)
#define TT_GREN (TT_000 + L_GREN)
#define TT_VIOL (TT_000 + L_VIOL)
#define TT_GRAY (TT_000 + L_GRAY)
#define TT_CYAN (TT_000 + L_CYAN)
#define TT_YELW (TT_000 + L_YELW)
#define TT_GAME (TT_000 + L_GAME)
#define TT_NUCL (TT_000 + L_NUCL)

// Этот макрос нужен, чтобы задавать одинаковые слои (в том числе и шифтовый слой) для английского и русского языка. В итоге их отличия будут только в буквах.
#define LANG_TWO_LAYERS(\
  L_DEFAULT, L_SHIFT,\
  \
  /* Left hand */ \
       LU1, LU2, LU3, LU4, LU5, \
       LH1, LH2, LH3, LH4, LH5, \
  LD0, LD1, LD2, LD3, LD4, LD5, \
  /* Right hand */ \
  RU1, RU2, RU3, RU4, RU5, \
  RH1, RH2, RH3, RH4, RH5, RH6, \
  RD1, RD2, RD3, RD4, RD5, RD6, \
  \
  /* ---------------------------- Shift layer ---------------------------- */ \
  /* Left hand */ \
        SLU1, SLU2, SLU3, SLU4, SLU5, \
        SLH1, SLH2, SLH3, SLH4, SLH5, \
  SLD0, SLD1, SLD2, SLD3, SLD4, SLD5, \
  /* Right hand */ \
  SRU1, SRU2, SRU3, SRU4, SRU5, \
  SRH1, SRH2, SRH3, SRH4, SRH5, SRH6, \
  SRD1, SRD2, SRD3, SRD4, SRD5, SRD6 \
) \
  /*-------------------------------------------------------------------------*/ \
  [L_DEFAULT] = MY_layout( \
    /* LEFT HALF */ \
    KC_ESC,  CMB_PLS, CMB_SCL, CMB_GRV, CMB_EXL, CMB_ASR, EN_AT, \
    AG_UNDS, LU1,     LU2,     LU3,     LU4,     LU5,     CMB_CTC, \
    SFT_N_O, LH1,     LH2,     LH3,     LH4,     LH5,     CMB_CTV, \
    LD0,     LD1,     LD2,     LD3,     LD4,     LD5, \
    MU_CTJ,  TT_YELW, CT_SLSH, CMB_LYG, CMB_LYV, \
    CMB_CTL, /* LEFT RED THUMB KEY */ \
    CMB_SFT, CMB_BSP, CMB_ENT, /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    EN_CIRC, CMB_EQL, CMB_CLN, CMB_CMM, CMB_QUE, CMB_SLS, CT_Z, \
    CT_S,    RU1,     RU2,     RU3,     RU4,     RU5,     AG_MINS, \
    CT_D,    RH1,     RH2,     RH3,     RH4,     RH5,     RH6, \
             RD1,     RD2,     RD3,     RD4,     RD5,     RD6, \
                      TT_RED,  AG_3DOT, KG_NEXT, TT_GAME, TT_NUCL, \
                      CMB_ALT, /* RIGHT RED THUMB KEY */ \
                      CMB_LAN, CMB_DOT, CMB_SPC /* RIGHT THUMB KEYS */ \
  ), \
  \
  /*-------------------------------------------------------------------------*/ \
  [L_SHIFT] = MY_layout( \
    /* LEFT HALF */ \
    _______, _______, _______, _______, _______, AG_CMNT, _______, \
    _______, SLU1,    SLU2,    SLU3,    SLU4,    SLU5,    CMB_CAC, \
    _______, SLH1,    SLH2,    SLH3,    SLH4,    SLH5,    CMB_CAV, \
    SLD0,    SLD1,    SLD2,    SLD3,    SLD4,    SLD5, \
    _______, _______, _______, _______, _______, \
    _______, /* LEFT RED THUMB KEY */ \
    _______, _______, _______, /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    _______, _______, AG2COLN, AG_COMM, _______, AG2SLSH, CT_Y, \
    _______, SRU1,    SRU2,    SRU3,    SRU4,    SRU5,    _______, \
    _______, SRH1,    SRH2,    SRH3,    SRH4,    SRH5,    SRH6, \
             SRD1,    SRD2,    SRD3,    SRD4,    SRD5,    SRD6, \
                      _______, _______, _______, _______, _______, \
                      _______, /* RIGHT RED THUMB KEY */ \
                      _______, _______, _______ /* RIGHT THUMB KEYS */ \
  ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //---------------------------------------------------------------------------
  LANG_TWO_LAYERS(
    L_EN, L_EN_S,

    /* Left hand */
             AC_GRV,  EN_X,    EN_Y,    EN_P,    EN_S_I,
             EN_A,    EN_O,    EN_E,    EN_U,    EN_I,
    XXXXXXX, AC_ACT,  EN_Q,    EN_J,    EN_K,    AC_CIRC,

    /* Right hand */
    EN_F,    EN_G,    EN_C,    EN_R,    EN_L,
    EN_D,    EN_H,    EN_T,    EN_N,    EN_S,    XXXXXXX,
    EN_B,    EN_M,    EN_W,    EN_V,    EN_Z,    AC_TILD,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             AC_GRV,  EN_S_X,  EN_S_Y,  EN_S_P,  EN_S_I,
             EN_S_A,  EN_S_O,  EN_S_E,  EN_S_U,  EN_S_I,
    _______, AC_ACT,  EN_S_Q,  EN_S_J,  EN_S_K,  AC_CIRC, 

    /* Right hand */
    EN_S_F,  EN_S_G,  EN_S_C,  EN_S_R,  EN_S_L,
    EN_S_D,  EN_S_H,  EN_S_T,  EN_S_N,  EN_S_S,  _______,
    EN_S_B,  EN_S_M,  EN_S_W,  EN_S_V,  EN_S_Z,  _______
  )

  //---------------------------------------------------------------------------
  LANG_TWO_LAYERS(
    L_RU, L_RU_S,

    /* Left hand */
             RU_J,    RU_TS,   RU_U,    RU_JE,   RU_F,
             RU_K,    RU_M,    RU_V,    RU_A,    RU_P,
    XXXXXXX, RU_JA,   RU_CH,   RU_S,    RU_I,    RU_Y,

    /* Right hand */
    RU_SC,   RU_Z,    RU_T,    RU_N,    RU_G,
    CMS_R,   RU_O,    RU_L,    RU_D,    RU_ZH,   RU_E,
    CMS_SH,  RU_SF,   RU_B,    RU_JU,   RU_H,    RU_JO,

    /* ---------------------------- Shift layer ---------------------------- */
    /* Left hand */
             RU_S_J,  RU_S_TS, RU_S_U,  RU_S_JE, RU_S_F,
             RU_S_K,  RU_S_M,  RU_S_V,  RU_S_A,  RU_S_P,
    _______, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_I,  RU_S_Y,

    /* Right hand */
    RU_S_SC, RU_S_Z,  RU_S_T,  RU_S_N,  RU_S_G,
    CMS_S_R, RU_S_O,  RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E,
    CMS_SSH, RU_S_SF, RU_S_B,  RU_S_JU, RU_S_H,  RU_S_JO
  )

  //---------------------------------------------------------------------------
  [L_RED] = MY_layout(
    // LEFT HALF
    TG_RED,  _______, _______, _______, _______, _______, _______,
    CT_G,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  CT_J,    _______,
    CS_M,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CS_K,    _______,
    _______, CT_LEFT, CT_DOWN, CT_UP,   CT_RGHT, CT_F,
    _______, _______, _______, _______, TT_CYAN,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    CT_PLUS, EN_MACR, CMB_LB2, CMB_RB2, EN_ARR2, EN_ARR1, CT_ENT,
    CT_MINS, KC_TAB,  CMB_LB1, CMB_RB1, CMB_LB4, CMB_RB4, SH_TAB,
             EN_FISH, CMB_LB3, CMB_RB3, EN_LTEQ, EN_GTEQ, EN_CLTG,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [L_GREN] = MY_layout(
    // LEFT HALF
    TG_GREN, _______, _______, _______, _______,  _______,  _______,
    KC_MUTE, KC_F5,   CS_T,    CT_T,    CT_W,     F6_CT_C,  _______,
    KC_VOLU, KC_MPRV, KC_MNXT, CT_PGUP, CT_PGDN,  KC_MPLY,  _______,
    KC_VOLD, CT_F5,   CS_P,    CT_1,    CT_2,     AL_PSCR,
    _______, _______, _______, _______, _______,  
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
    _______, _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,
             _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,  _______,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_VIOL] = MY_layout(
    // LEFT HALF
    TG_VIOL, _______, _______, _______, _______, _______, _______,
    AL_UP,   WN_8,    WN_7,    WN_6,    WN_5,    _______, _______,
    WN_Q,    WN_4,    WN_3,    WN_2,    WN_1,    _______, _______,
    KC_F2,   KC_LGUI, _______, WN_5,    WN_9,    _______,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, AC_SUB,  AG_4,    AG_5,    AG_6,    _______, _______,
    _______, AC_SUP,  AG_0,    AG_1,    AG_2,    AG_3,    _______,
             AC_CRCL, AG_9,    AG_8,    AG_7,    _______, _______,
                      TT_CYAN, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_GRAY] = MY_layout(
    // LEFT HALF
    TG_GRAY, _______, _______, _______, _______, _______,  _______,
    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,  _______,
    KC_BTN1, RP_001,  RP_003,  RP_002,  RP_004,  KC_BTN2,  _______,
    _______, RP_005,  RP_007,  RP_006,  RP_008,  KC_BTN3,
    _______, _______, _______, _______, _______,  
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [L_CYAN] = MY_layout(
    // LEFT HALF
    TG_CYAN, _______, _______, _______, _______, _______,  _______,
    XC_NIN,  XC_IN,   XC_SBST, XC_DEGR, XC_PLMN, XC_MU,    _______,
    XC_MUSC, XC_LEFT, XC_DOWN, XC_UP,   XC_RGHT, XC_LMBD,  _______,
    XC_ANGL, XC_IFAI, XC_EXST, XC_ALL,  XC_THEN, XC_PI,
    _______, _______, _______, _______, _______,  
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, XC_CRSS, CMB_LCR, CMB_RCR, XC_APRX, XC_EMPT, XC_TM,
    _______, XC_DONE, CMB_LTR, CMB_RTR, XC_DASH, XC_TIMS, XC_NEQ,
             XC_SPRK, XC_TMBU, XC_TMBD, XC_BULL, XC_INF, XC_COPY,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),
  
  //---------------------------------------------------------------------------
  [L_YELW] = MY_layout(
    // LEFT HALF
    TG_YELW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, RGB_TOG,
    RGB_PRT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,RGB_LYR,
    RGB__0,  RGB__1,  RGB__2,  RGB__25, RGB__28, RGB__36, RGB__27,
    RGB__7,  RGB__13, RGB__15, RGB__16, RGB__17, _______,
    _______, _______, AU_TOG,  MU_TOG,  MU_MOD,
    RGB_PRT, // LEFT RED THUMB KEY
    PIC_0,   PIC_1,   PIC_2, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, LED_1,   LED_2,   LED_3,   LED_4,   LED_5,   LED_6,
             _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),


  //---------------------------------------------------------------------------
  [L_GAME] = MY_layout(
    // LEFT HALF
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_8,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CS_M,
    KC_LGUI, // LEFT RED THUMB KEY
    KC_SPC,  KC_LALT, KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG_GAME,
    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, // RIGHT RED THUMB KEY
                      XXXXXXX, XXXXXXX, XXXXXXX // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [L_NUCL] = MY_layout(
    // LEFT HALF
    TG_NUCL, KC_SLCK, KC_CAPS, KC_INS,  KC_PAUS, KC_PSCR, KC_APP,
    _______, _______, _______, _______, _______, _______, _______,
    _______, MU_LAN1, MU_LAN2, MU_LAN3, MU_LAN4, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_RGUI,
    _______, // LEFT RED THUMB KEY
    KC_RCTL, KC_RSFT, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, RESET,
    _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PENT, _______,
             _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
                      KC_P0,   KC_PDOT, KC_PCMM, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),
};

const ComboWithKeycode combos[] PROGMEM = {
  // Left Index
  CHORD(CT_C,    /* <- */ CMB_CTC),
  CHORD(CT_V,    /* <- */ CMB_CTV),
  CHORD(CT_X,    /* <- */ CMB_CTC, CMB_CTV),

  // Left Thumb
  IMMEDIATE_CHORD(SFT_N, SFT_N,     /* <-! */ CMB_SFT),
  CHORD(KC_BSPC, /* <- */ CMB_BSP),
  CHORD(KC_ENT,  /* <- */ CMB_ENT),
  IMMEDIATE_CHORD(CTRL_EN, CTRL_EN, /* <-! */ CMB_CTL),
  CHORD(CT_A,    /* <- */ CMB_SFT, CMB_CTL),
  IMMEDIATE_CHORD(TT_GRAY, TT_UNDO, /* <-! */ CMB_SFT, CMB_BSP),
  CHORD(KC_DEL,  /* <- */ CMB_BSP, CMB_CTL),
  CHORD(CT_BSPC, /* <- */ CMB_BSP, CMB_ENT),
  CHORD(CTSH_EN, /* <- */ CMB_SFT, CMB_BSP, CMB_CTL),
  CHORD(MU_SCR,  /* <- */ CMB_BSP, CMB_ENT, CMB_CTL),

  // Left Left Thumb
  IMMEDIATE_CHORD(TT_VIOL, TT_UNDO, /* <-! */ CMB_LYV),
  IMMEDIATE_CHORD(TT_GREN, TT_UNDO, /* <-! */ CMB_LYG),
  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_LYV, CMB_LYG),

  // Right Thumb
  CHORD(MU_LANG, /* <- */ CMB_LAN),
  CHORD(AG_DOT,  /* <- */ CMB_DOT),
  CHORD(KC_SPC,  /* <- */ CMB_SPC),
  CHORD(ALT_EN,  /* <- */ CMB_ALT),
  CHORD(AG_SDOT, /* <- */ CMB_DOT, CMB_SPC),
  CHORD(LA_SYNC, /* <- */ CMB_LAN, CMB_DOT),
  CHORD(CTAL_EN, /* <- */ CMB_SPC, CMB_ALT),
  CHORD(SHAL_EN, /* <- */ CMB_DOT, CMB_ALT),
  CHORD(WIN_EN,  /* <- */ CMB_SPC, CMB_DOT, CMB_ALT),
  CHORD(MU_WNL,  /* <- */ CMB_LAN, CMB_DOT, CMB_ALT),

  // -------------------------------------------------------------------------
  // Shifted index keys

  // Left Index
  CHORD(CT_A_C,  /* <- */ CMB_CAC),
  CHORD(CT_A_V,  /* <- */ CMB_CAV),
  CHORD(CT_A_X,  /* <- */ CMB_CAC, CMB_CAV),

  // -------------------------------------------------------------------------
  // Russian combos on letters
  CHORD(RU_R,    /* <- */ CMS_R),
  CHORD(RU_SH,   /* <- */ CMS_SH),
  CHORD(RU_HD,   /* <- */ CMS_R, CMS_SH),
  CHORD(RU_S_R,  /* <- */ CMS_S_R),
  CHORD(RU_S_SH, /* <- */ CMS_SSH),
  CHORD(RU_S_HD, /* <- */ CMS_S_R, CMS_SSH),

  // -------------------------------------------------------------------------
  // Number row

  // Left hand
  CHORD(AG_PLUS, /* <- */ CMB_PLS),
  CHORD(AG_SCLN, /* <- */ CMB_SCL),
  CHORD(EN_GRV,  /* <- */ CMB_GRV),
  CHORD(AG_EXCL, /* <- */ CMB_EXL),
  CHORD(AG_ASTR, /* <- */ CMB_ASR),
  CHORD(EN_TILD, /* <- */ CMB_PLS, CMB_EXL),
  CHORD(RU_NUME, /* <- */ CMB_PLS, CMB_ASR),
  CHORD(EN_QUOT, /* <- */ CMB_GRV, CMB_EXL),
  CHORD(AG_DQUO, /* <- */ CMB_SCL, CMB_GRV),
  CHORD(AG_PERC, /* <- */ CMB_SCL, CMB_EXL),
  CHORD(EN2QUOT, /* <- */ CMB_SCL, CMB_ASR),
  CHORD(AG2DQUO, /* <- */ CMB_SCL, CMB_GRV, CMB_EXL),

  // Right hand
  CHORD(AG_SLSH, /* <- */ CMB_SLS),
  CHORD(AG_QUES, /* <- */ CMB_QUE),
  CHORD(AG_CMSP, /* <- */ CMB_CMM),
  CHORD(AG_COLN, /* <- */ CMB_CLN),
  CHORD(AG_EQL,  /* <- */ CMB_EQL),
  CHORD(EN_DLR,  /* <- */ CMB_SLS, CMB_CLN),
  CHORD(EN_HASH, /* <- */ CMB_SLS, CMB_EQL),
  CHORD(EN_PIPE, /* <- */ CMB_CMM, CMB_CLN),
  CHORD(EN_AMPR, /* <- */ CMB_QUE, CMB_CMM),
  CHORD(AG_BSLS, /* <- */ CMB_QUE, CMB_CLN),
  CHORD(EN2PIPE, /* <- */ CMB_QUE, CMB_EQL),
  CHORD(EN2AMPR, /* <- */ CMB_QUE, CMB_CMM, CMB_CLN),

  // -------------------------------------------------------------------------
  // Brackets on red layer
  CHORD(AG_LPRN, /* <- */ CMB_LB1),
  CHORD(AG_RPRN, /* <- */ CMB_RB1),
  CHORD(EN_LBRC, /* <- */ CMB_LB2),
  CHORD(EN_RBRC, /* <- */ CMB_RB2),
  CHORD(EN_LCBR, /* <- */ CMB_LB3),
  CHORD(EN_RCBR, /* <- */ CMB_RB3),
  CHORD(EN_LT,   /* <- */ CMB_LB4),
  CHORD(EN_GT,   /* <- */ CMB_RB4),
  CHORD(AG_2B1,  /* <- */ CMB_LB1, CMB_RB1),
  CHORD(EN_2B2,  /* <- */ CMB_LB2, CMB_RB2),
  CHORD(EN_2B3,  /* <- */ CMB_LB3, CMB_RB3),
  CHORD(EN_2B4,  /* <- */ CMB_LB4, CMB_RB4),

  // -------------------------------------------------------------------------
  // Brackets on XCompose layer

  CHORD(XC_LTRE, /* <- */ CMB_LTR),
  CHORD(XC_RTRE, /* <- */ CMB_RTR),
  CHORD(XC_BTRE, /* <- */ CMB_LTR, CMB_RTR),

  CHORD(XC_LCRN, /* <- */ CMB_LCR),
  CHORD(XC_RCRN, /* <- */ CMB_RCR),
  CHORD(XC_BCRN, /* <- */ CMB_LCR, CMB_RCR),
};
const uint8_t combos_size = sizeof(combos)/sizeof(ComboWithKeycode);

const uint16_t tt_keys[][3] = {
  { TT_CTJ, CT_J,  CT_BSLS }, // Убийство программы, если нажать три раза, то выдаёт Ctrl+\, что убивает безоговорочно.
  { TT_RED,  MO_RED,  TG_RED },
  { TT_GREN, MO_GREN, TG_GREN },
  { TT_VIOL, MO_VIOL, TG_VIOL },
  { TT_GRAY, MO_GRAY, TG_GRAY },
  { TT_CYAN, MO_CYAN, TG_CYAN },
  { TT_YELW, MO_YELW, TG_YELW },
  { TT_GAME, MO_GAME, TG_GAME },
  { TT_NUCL, MO_NUCL, TG_NUCL },
};
const uint8_t tt_size = sizeof(tt_keys)/(sizeof(uint16_t) * 3);

const uint16_t repeat_keys[][2] = {
  { RP_000, AR_L5 },
  { RP_001, MS_LF_1 },
  { RP_002, MS_UP_1 },
  { RP_003, MS_DN_1 },
  { RP_004, MS_RG_1 },
  { RP_005, MS_LF10 },
  { RP_006, MS_UP10 },
  { RP_007, MS_DN10 },
  { RP_008, MS_RG10 },
};
const uint8_t repeat_size = sizeof(repeat_keys)/(sizeof(uint16_t) * 2);

enum ledmap_colors {
  COLOR_BLACK = COLOR_SAFE_RANGE, // Чёрный цвет
  COLOR_ANYFN, // Цвет для кнопки, нажимаемой любым пальцем
  COLOR_PINKY, // Для кнопки нажимаемой мизинцем
  COLOR_ANNUL, // Безымянным
  COLOR_MIDDL, // Средним
  COLOR_INDEX, // Указательным
  COLOR_THUMB, // Большим пальцем
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL] = {
    [0] = {
      COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
      COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_THUMB,
      COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, 

      COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
      COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
      COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, 
      COLOR_THUMB,
      COLOR_THUMB, COLOR_THUMB, COLOR_THUMB
    },

    [1] = {
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, 
      ___________, ___________, ___________, 
      COLOR_LAYER,
      COLOR_LAYER, COLOR_LAYER, COLOR_LAYER, 

      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, ___________,
      ___________, ___________, ___________, ___________, 
      ___________, ___________, ___________, 
      COLOR_LAYER,
      COLOR_LAYER, COLOR_LAYER, COLOR_LAYER
    },
};
const uint8_t ledmap_size = sizeof(ledmap)/(sizeof(uint8_t) * DRIVER_LED_TOTAL);

const uint8_t PROGMEM colormap[][3] = {
  [COLOR_BLACK] = { 0, 0, 0 },
  [COLOR_ANYFN] = { 0, 0, 255 },
  [COLOR_PINKY] = { 31, 255, 255 },
  [COLOR_ANNUL] = { 164, 255, 255 },
  [COLOR_MIDDL] = { 76, 255, 255 },
  [COLOR_INDEX] = { 224, 255, 255 },
  [COLOR_THUMB] = { 8, 255, 255 },
};
const uint8_t colormap_size = sizeof(colormap)/(sizeof(uint8_t) * 3);

const uint8_t PROGMEM layermap[][3] = {
  [L_EN] = { 0, 0, 255 },
  [L_EN_S] = { 0, 0, 192 },

  [L_RU] = { 164, 255, 255 },
  [L_RU_S] = { 164, 255, 192 },

  [L_RED] = { 0, 255, 210 },
  [L_GREN] = { 76, 255, 255 },
  [L_VIOL] = { 188, 255, 255 },
  [L_GRAY] = { 0, 0, 128 },
  [L_CYAN] = { 128, 255, 255 },

  [L_YELW] = { 35, 255, 255 },
  [L_GAME] = { 228, 255, 255 },

  [L_NUCL] = { 8, 255, 255 },
};
const uint8_t layermap_size = sizeof(layermap)/(sizeof(uint8_t) * 3);

bool initted_for_layer_state = false;
layer_state_t layer_state_set_user(layer_state_t state) {
  if (initted_for_layer_state) {
    // Выключаем все леды, потому что они только просвечивают своим некрасивым цветом через прозрачные кейкапы, а для чего их использовать можно я не придумал
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    uint8_t layer = get_highest_layer(state);

    // Устанавливаем текущий цвет клавиатуры таким же какой сейчас цвет у слоя. Это создаёт красивый эффект для подсветок, которые используют текущий цвет.
    rgb_matrix_sethsv_noeeprom(
      pgm_read_byte(&layermap[layer][0]),
      pgm_read_byte(&layermap[layer][1]),
      pgm_read_byte(&layermap[layer][2])
    );
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  initted_for_layer_state = true;

  if (!process_my_music_keys(keycode, record)) {
    return false;
  }

  if (!combo_process_record(keycode, record)) {
    return false;
  }

  if (!tt_process_record(keycode, record)) {
    return false;
  }

  if (!rp_process_record(keycode, record)) {
    return false;
  }

  if (!process_my_lang_keys(keycode, record)) {
    return false;
  }

  if (!process_my_xcompose(keycode, record)) {
    return false;
  }

  if (!lang_shift_process_record(keycode, record)) {
    return false;
  }

  if (!color_process_record(keycode, record)) {
    return false;
  }

  if (!process_my_hotkeys(keycode, record)) {
    return false;
  }

  if (!process_moonlander_leds(keycode, record)) {
    return false;
  }

  if (!process_mouse_pixel_move(keycode, record)) {
    return false;
  }

  return true;
}

float error_song1[][2] = SONG(MUSIC_OFF_SOUND);
void combo_max_count_error(void) {
  PLAY_SONG(error_song1);
  uprintf("COMBO ERROR: MAX COMBOS COUNT HAS REACHED\n");
}

float error_song2[][2] = SONG(VOICE_CHANGE_SOUND);
void combo_max_size_error(void) {
  PLAY_SONG(error_song2); 
  uprintf("COMBO ERROR: MAX COMBO SIZE HAS REACHED\n");
}

void repeated_key_error(void) {
  PLAY_SONG(error_song2); 
  uprintf("REPEATED KEY ERROR\n"); 
}

void user_timer(void) {
  combo_user_timer();
  lang_shift_user_timer();
  rp_timer();
}

void matrix_scan_user(void) {
  user_timer();
}

// Нужно для color.h
void rgb_matrix_indicators_user(void) {
  color_rgb_matrix_indicators();
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}
