#include QMK_KEYBOARD_H
#include "version.h"

#include "keycodes_lang.h"
#include "keycodes_shift.h"
#include "keycodes_lang_shift_processing.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,

  MY_LANG_KEYS
  MY_SHIFT_KEYS
  MY_SHIFT_LANG_KEYS

  HSV_86_255_128,
};

#include "lang_shift_common.h"
#include "shift.c"
#include "lang.c"
#include "lang_shift_processing.c"

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //---------------------------------------------------------------------------
  [0] = MY_layout(
    // LEFT HALF
    KC_ESC,     EN_AMPR,  EN_LBRC,  EN_RBRC,  EN_PLUS,  EN_EQL, EN_GRV,
    KC_TAB,     EN_SCLN,  EN_LCBR,  EN_RCBR,  EN_P,     EN_Y,   EN_DLR,
    KC_A,       EN_A,     EN_O,     EN_E,     EN_U,     EN_I,   RU_NUME,
    KC_CAPS,    EN_QUOT,  EN_Q,     EN_J,     EN_K,     EN_X,
    XXXXXXX,    XXXXXXX,  XXXXXXX,  EN_SLSH,  KC_UP,
    SHF_1, // LEFT RED THUMB KEY
    SHF_1_O,    KC_BSPC,  KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    XXXXXXX,    EN_ASTR,  EN_EXCL,  EN_RPRN,  EN_LPRN,  EN_QUES,  RESET,
    XXXXXXX,    EN_F,     EN_G,     EN_C,     EN_R,     EN_L,     EN_BSLS,
    XXXXXXX,    EN_D,     EN_H,     EN_T,     EN_N,     EN_S,     EN_MINS,
                EN_B,     EN_M,     EN_W,     EN_V,     EN_Z,     EN_HASH,
                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                          XXXXXXX, // RIGHT RED THUMB KEY
                          MY_LANG, KC_DOT, KC_SPC // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [1] = MY_layout(
    // LEFT HALF
    _______,    EN_7,     EN_5,     EN_3,     EN_1,     EN_9,    _______,
    _______,    EN_COLN,  EN_LT,    EN_GT,    EN_S_P,   EN_S_Y,  EN_DLR,
    _______,    EN_S_A,   EN_S_O,   EN_S_E,   EN_S_U,   EN_S_I,  EN_TILD,
    _______,    EN_DQUO,  EN_S_Q,   EN_S_J,   EN_S_K,   EN_S_X, 
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    EN_0,     EN_2,     EN_4,     EN_6,     EN_8,     EN_PERC,
    _______,    EN_S_F,   EN_S_G,   EN_S_C,   EN_S_R,   EN_S_L,   EN_PIPE,
    _______,    EN_S_D,   EN_S_H,   EN_S_T,   EN_S_N,   EN_S_L,   EN_AT,
                EN_S_B,   EN_S_M,   EN_S_W,   EN_S_V,   EN_S_Z,   EN_CIRC,
                          EN_COMM,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______, EN_UNDS, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [2] = MY_layout(
    // LEFT HALF
    _______,    RU_PLUS,  RU_MINS,  RU_SCLN,  RU_DQUO,  RU_COLN,  EN_GRV,
    _______,    RU_J,     RU_TS,    RU_U,     RU_JE,    RU_F,     EN_DLR,
    _______,    RU_K,     RU_M,     RU_V,     RU_A,     RU_P,     RU_NUME,
    _______,    RU_JA,    RU_CH,    RU_S,     RU_I,     RU_Y,
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    SHF_3,      _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    RU_ASTR,  RU_EXCL,  RU_RPRN,  RU_LPRN,  RU_QUES,  RESET,
    _______,    RU_SC,    RU_G,     RU_T,     RU_N,     RU_Z,     RU_HD,
    _______,    RU_R,     RU_O,     RU_L,     RU_D,     RU_ZH,    RU_E,
                RU_SH,    RU_SF,    RU_B,     RU_JU,    RU_H,     RU_JO,
                          RU_COMM,  XXXXXXX,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,  RU_UNDS,   _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [3] = MY_layout(
    // LEFT HALF
    _______,    RU_7,     RU_5,     RU_3,     RU_1,     RU_9,     _______,
    _______,    _______,  _______,  _______,  _______,  _______,  EN_HASH,
    _______,    _______,  _______,  _______,  _______,  _______,  EN_EQL,
    _______,    _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______,    _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    RU_0,     RU_2,     RU_4,     RU_6,     RU_8,     KC_PERC,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______,  _______,  _______,
                          KC_QUES,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,  RU_SLSH,  _______ // RIGHT THUMB KEYS
    ),
};


bool process_record_user(uint16_t key, keyrecord_t *record) {
  if (!process_record_lang_shift(key, record))
    return false;

  switch (key) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
  }

  return true;
}