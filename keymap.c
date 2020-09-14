#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

#include "shift.c"
#include "lang.c"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

// Inverted shift modifier
#define QK_INVERT_SHIFT QK_RGUI
#define INVERT_SHIFT(kc) ((kc) | QK_INVERT_SHIFT)
#define IS(kc) INVERT_SHIFT(kc)
#define HAS_INVERTED_SHIFT(kc) (((kc) & 0xFF00) == QK_INVERT_SHIFT)
#define HAS_MACRO(kc) ((((kc) & 0xF000) == QK_MACRO))
#define MY_IS_KEY(kc) (IS_KEY(kc) || IS_KEY((kc) ^ QK_LCTL) || IS_KEY((kc) ^ QK_LSFT) || IS_KEY((kc) ^ QK_LALT) || HAS_INVERTED_SHIFT(kc))

//-----------------------------------------------------------------------------
#define _______ KC_TRNS 
#define XXXXXXX KC_NO

// Shift keys
#define SH_F11 S(KC_F11)
#define SH_PSCR S(KC_PSCR)

// Ctrl+Shift keys
#define CS_TAB LCTL(S(KC_TAB))
#define CS_T LCTL(S(KC_T))
#define CS_K LCTL(S(KC_K))
#define TASK LCTL(S(KC_ESC))

// Gui keys
#define WN_E LGUI(KC_E)
#define WN_D LGUI(KC_D)
#define WN_1 LGUI(KC_1) // Telegram
#define WN_2 LGUI(KC_2) // Yabrowser
#define WN_3 LGUI(KC_3) // Console
#define WN_4 LGUI(KC_4) // Nautilus
#define WN_5 LGUI(KC_5) // CLion
#define WN_6 LGUI(KC_6) // Sublime
#define WN_7 LGUI(KC_7) // Firefox
#define WN_8 LGUI(KC_8) // Git ahead
#define WN_RGHT LGUI(KC_RGHT) // Window to right half
#define WN_LEFT LGUI(KC_LEFT) // Window to left half
#define WS_RGHT LGUI(S(KC_RGHT)) // Window to right display
#define WS_LEFT LGUI(S(KC_LEFT)) // Window to left display

// Alt keys
#define AL_TAB LALT(KC_TAB)
#define AL_TTAB M(0)
#define AL_D LALT(KC_D)
#define AL_PSCR LALT(KC_PSCR)
#define AL_F6 LALT(KC_F6) // Alt+Tab between same windows
#define AL_ESC LALT(KC_ESC) // Alt+Tab with instant preview
#define AL_F10 LALT(KC_F10) // Maximize window
#define AL_F4 LALT(KC_F4) // Close window

// Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)
#define CT_ENT LCTL(KC_ENT)
#define CT_DEL LCTL(KC_DEL)
#define CT_BSPC LCTL(KC_BSPC)
#define CT_F10 LCTL(KC_F10)
#define CT_TAB LCTL(KC_TAB)
#define CT_SLSH LCTL(KC_SLSH)
#define CT_1 LCTL(KC_1)
#define CT_2 LCTL(KC_2)
#define CT_3 LCTL(KC_3)
#define CT_4 LCTL(KC_4)
#define CT_5 LCTL(KC_5)
#define CT_Z LCTL(KC_Z)
#define CT_T LCTL(KC_T)
#define CT_W LCTL(KC_W)
#define CT_J LCTL(KC_J)
#define CT_D LCTL(KC_D)
#define CT_S LCTL(KC_S)
#define CT_F LCTL(KC_F)
#define CT_A LCTL(KC_A)
#define CT_S LCTL(KC_S)
#define CT_D LCTL(KC_D)

#define CT_X LCTL(KC_X)
#define CT_C LCTL(KC_C)
#define CT_V LCTL(KC_V)

// Real Ctrl+J for terminating programs
#define CTRL_J LCTL(KC_J)

// Inverted shift keys
#define IS_0 IS(KC_0)
#define IS_1 IS(KC_1)
#define IS_2 IS(KC_2)
#define IS_3 IS(KC_3)
#define IS_4 IS(KC_4)
#define IS_5 IS(KC_5)
#define IS_6 IS(KC_6)
#define IS_7 IS(KC_7)
#define IS_8 IS(KC_8)
#define IS_9 IS(KC_9)
#define IS_QUES IS(KC_QUES)
#define IS_EQL IS(KC_EQL)
#define IS_SLSH IS(KC_SLSH)
#define IS_COMM IS(KC_COMM)
#define IS_GRV IS(KC_GRV)

// Audio keys
#define AU_MUTE KC_AUDIO_MUTE
#define AU_VOLU KC_AUDIO_VOL_UP
#define AU_VOLD KC_AUDIO_VOL_DOWN
#define AU_NEXT KC_MEDIA_NEXT_TRACK
#define AU_PREV KC_MEDIA_PREV_TRACK
#define AU_PLAY KC_MEDIA_PLAY_PAUSE

enum custom_keycodes {
  PLACEHOLDER = ML_SAFE_RANGE,
  RGB_SLD,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,

  // Special shifts
  SHF_1,
  SHF_3,

  // Change language
  MY_LANG,
  RE_LANG,
  LANG__1,  LANG__2,  LANG__3,  LANG__4,

  // All of these modificators on 0 layer
  MY_CTRL,
  MY_ALT,
  MY_WIN,
  MY_SHAL, // Shift+Alt
  MY_CTAL, // Ctrl+Alt
  MY_CTSH, // Ctrl+Shift
  MY_MCAS, // Ctrl+Alt+Shift
  
  // Russian specific keys
  RU_3DOT, // Three dots
  RU_CMSP, // Comma Space
  RU_SDOT, // Space + Dot + AutoShift

  // English specific keys
  EN_CMSP, // Comma Space
  EN_SDOT, // Space + Dot + AutoShift

  // Mouse keys
  MS_DOWN,
  MS_UP,
  MS_LEFT,
  MS_RGHT,
  MSWH_DW,
  MSWH_UP,
  MSWH_LF,
  MSWH_RG,

  SP_LAN,

  KG_NEXT, // Klavogonki next race (Tab Tab Ctrl+Right)

  LED_DN,

  LEFT_5, // 5 x left
  UP_1C, // 10 x ctrl+up
  DOWN_1C, // 10 x ctrl+down
  RGHT_5, // 5 x right

  MY_SCRN,

  I3_CR,

  MY_SHIFT_KEYS
  MY_LANG_KEYS
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //---------------------------------------------------------------------------
  [0] = MY_layout(
    // LEFT HALF
    KC_ESC,     KC_AMPR,  KC_LBRC,  KC_RBRC,  KC_PLUS,  KC_EQL, CT_X,
    KC_TAB,     KC_SCLN,  KC_LCBR,  KC_RCBR,  KC_P,     KC_Y,   CT_C,
    MO(4),      KC_A,     KC_O,     KC_E,     KC_U,     KC_I,   CT_V,
    MO(5),      KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,
    TG(4),      TG(5),    CT_SLSH,  KC_SLSH,  MO(7),
    MY_CTRL, // LEFT RED THUMB KEY
    SHF_1, KC_BSPC, KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    CT_D,       KC_ASTR,  KC_EXLM,  KC_RPRN,  KC_LPRN,  KC_QUES,  CT_Z,
    CT_S,       KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_BSLS,
    CT_BSPC,    KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
                KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_HASH,
                          EN_CMSP,  KG_NEXT,  MY_SHAL,  TG(6),    CTRL_J,
                          MY_ALT, // RIGHT RED THUMB KEY
                          MY_LANG, KC_DOT, KC_SPC // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [1] = MY_layout(
    // LEFT HALF
    _______,    IS_7,     IS_5,     IS_3,     IS_1,     IS_9,     IS_GRV,
    _______,    KC_COLN,  KC_LT,    KC_GT,    _______,  _______,  KC_DLR,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_TILD,
    _______,    KC_DQT,   _______,  _______,  _______,  _______, 
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    IS_0,     IS_2,     IS_4,     IS_6,     IS_8,     KC_PERC,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_PIPE,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_AT,
                _______,  _______,  _______,  _______,  _______,  KC_CIRC,
                          IS_COMM,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______, KC_UNDS, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [2] = MY_layout(
    // LEFT HALF
    _______,    KC_PLUS,  KC_MINS,  KC_DLR,   KC_AT,    KC_CIRC,  CT_X,
    _______,    KC_Q,     KC_W,     KC_E,     KC_T,     KC_A,     CT_C,
    _______,    KC_R,     KC_V,     KC_D,     KC_F,     KC_G,     CT_V,
    _______,    KC_Z,     KC_X,     KC_C,     KC_B,     KC_S,
    _______,    _______,  _______,  _______,  MO(7),
    _______, // LEFT RED THUMB KEY
    SHF_3,      _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    KC_ASTR,  KC_EXLM,  KC_RPRN,  KC_LPRN,  KC_AMPR,  CT_Z,
    _______,    KC_O,     KC_U,     KC_N,     KC_Y,     KC_P,     KC_RBRC,
    _______,    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                KC_I,     KC_M,     KC_COMM,  KC_DOT,   KC_LBRC,  KC_GRV,
                          RU_CMSP,  KG_NEXT,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,   RU_SDOT,   _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [3] = MY_layout(
    // LEFT HALF
    _______,    IS_7,     IS_5,     IS_3,     IS_1,     IS_9,     _______,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_HASH,
    _______,    _______,  _______,  _______,  _______,  _______,  IS_EQL,
    _______,    _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______,    _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______,    IS_0,     IS_2,     IS_4,     IS_6,     IS_8,     KC_PERC,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,
                _______,  _______,  _______,  _______,  _______,  _______,
                          KC_QUES,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,  IS_SLSH,  _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [4] = MY_layout(
    // LEFT HALF
    TG(4),      KC_F7,    KC_F5,    KC_F3,    KC_F1,    KC_F9,    CT_X,
    AU_MUTE,    LALT(S(KC_F9)),   KC_F8,   KC_F9,    LCTL(KC_B),   WN_D,     CT_C,
    _______,    AU_VOLU,  AU_NEXT,  CS_TAB,   CT_TAB,   AL_TAB,   CT_V,
    LED_DN,     AU_VOLD,  AU_PREV,  CT_1,     CT_2,     AL_TTAB,
    RE_LANG,    _______,  _______,  WN_E,     AU_PLAY,
    TASK, // LEFT RED THUMB KEY
    _______,    _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    KC_PAUSE,   KC_F10,   KC_F2,    KC_F4,    KC_F6,    KC_F8,    KC_F11,
    KC_INSERT,  CT_DEL,   KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_F12,
    CT_BSPC,    CS_K,     KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,  KC_PSCR,
                CT_ENT,   CT_LEFT,  CT_UP,    CT_DOWN,  CT_RGHT,  AL_PSCR,
                          _______,  LANG__1,  LANG__2,  LANG__3,  LANG__4,
                          _______, // RIGHT RED THUMB KEY
                          _______,  _______,  _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [5] = MY_layout(
    // LEFT HALF
    TG(5),      CT_1,     CT_2,     CT_3,     CT_4,     CT_5,     CT_X,
    KC_F5,      KC_F6,    CS_T,     CT_T,     CT_W,     CT_J,     CT_C,
    KC_BTN2,    KC_BTN1,  KC_BTN3,  CS_TAB,   CT_TAB,   CT_D,     CT_V,
    _______,    CT_S,     KC_ENT,   KC_UP,    KC_DOWN,  CT_F,
    MY_SCRN,    _______,  HSV_0_255_255,  HSV_86_255_128,  HSV_172_255_255,  
    RGB_MOD, // LEFT RED THUMB KEY
    RGB_VAD,    RGB_VAI,  TOGGLE_LAYER_COLOR, // LEFT THUMB KEYS

    // RIGHT HALF
    AU_TOG,     RGB_SLD,  RGB_HUD,  RGB_HUI,  RGB_TOG,  _______,  RESET,
    MU_TOG,     WN_6,     WN_1,     WN_2,     WN_3,     WN_4,     WN_5,
    MU_MOD,     WN_7,     AL_ESC,   AL_F6,    AL_F10,   _______,  AL_F4,
                WN_8,     WN_LEFT,  WN_RGHT,  WS_LEFT,  WS_RGHT,  _______,
                KC_MS_LEFT,  KC_MS_UP,  KC_MS_DOWN,  KC_MS_RIGHT,  _______,
                _______, // RIGHT RED THUMB KEY
                _______,  KC_MS_BTN2,  KC_MS_BTN1 // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [6] = MY_layout(
    // LEFT HALF
    KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
    KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_7,
    KC_LSFT,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_8,
    KC_LCTL,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
    XXXXXXX,    XXXXXXX,  TG(6),    KC_PERC,  RU_CMSP,
    XXXXXXX, // LEFT RED THUMB KEY
    KC_SPC,    KC_LALT,   KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    XXXXXXX,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,
    XXXXXXX,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,
    XXXXXXX,    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UNDS,
                          KC_LEFT,  KC_UP,    KC_DOWN,  TG(6),    XXXXXXX,
                          XXXXXXX, // RIGHT RED THUMB KEY
                          XXXXXXX,   XXXXXXX,   XXXXXXX // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [7] = MY_layout(
    // LEFT HALF
    _______,  LGUI(KC_6),  LGUI(KC_5),  LGUI(KC_4),  LGUI(KC_3),  LGUI(KC_2),  LGUI(KC_1),
    LGUI(LCTL(KC_SPACE)),  LGUI(KC_F4),  LGUI(KC_F3),  LGUI(KC_F2),  LGUI(KC_F1),  LGUI(S(KC_Q)),  LGUI(KC_A),
    LGUI(LCTL(KC_LEFT)),  LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),  LGUI(KC_RIGHT),  LGUI(LCTL(KC_RIGHT)), LGUI(KC_I),
    LGUI(LALT(KC_LEFT)),  LGUI(KC_F8),  LGUI(KC_F7),  LGUI(KC_F6),  LGUI(KC_F5),  LGUI(LALT(KC_RIGHT)),
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______,  _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    LGUI(S(KC_1)),    LGUI(S(KC_2)),  LGUI(S(KC_3)),  LGUI(S(KC_4)),  LGUI(S(KC_5)),  LGUI(S(KC_6)),  _______,
    LGUI(KC_F), LGUI(KC_R),  KC_LEFT,  KC_UP,  KC_DOWN,  KC_RIGHT,  LGUI(KC_SPACE),
    I3_CR,      LGUI(KC_D),  LGUI(S(KC_LEFT)),  LGUI(S(KC_UP)),    LGUI(S(KC_DOWN)),  LGUI(S(KC_RIGHT)),  LGUI(KC_G),
                LGUI(KC_H),  LGUI(KC_V),  LGUI(KC_E),  LGUI(KC_W),  LGUI(KC_S),  LGUI(KC_N),
                          _______,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,  _______,  _______ // RIGHT THUMB KEYS
  ),
};

//-----------------------------------------------------------------------------
uint32_t layer_state_set_user(uint32_t state);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    //-------------------------------------------------------------------------
    case 0: // Alt+Tab+Tab
      if (record->event.pressed) {
        register_code(KC_LALT);
      } else {
        register_code(KC_TAB);
        wait_ms(10);
        unregister_code(KC_TAB);
        wait_ms(10);
        register_code(KC_TAB);
        wait_ms(10);
        unregister_code(KC_TAB);
        wait_ms(10);
        unregister_code(KC_LALT);
      }
      break;
  }
  return MACRO_NONE;
};

//-----------------------------------------------------------------------------
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

//-----------------------------------------------------------------------------
bool currentShift = false;
bool off_unshift = false;
uint32_t unshift_time = 0;
bool process_inverted_shift(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;
  bool isShiftPressed = keyboard_report->mods & MOD_BIT(KC_LSFT);
  if (HAS_INVERTED_SHIFT(keycode)) {
    uint16_t normalKeycode = keycode % QK_INVERT_SHIFT;
    if (pressed) {
      if (isShiftPressed) {
        unregister_code(KC_LSHIFT);
        unshift_time = timer_read();
        off_unshift = true;
      }
      register_code(normalKeycode);
    } else {
      unregister_code(normalKeycode);
    }
    return false;
  } else {
    if (pressed && currentShift && !isShiftPressed) {
      register_code(KC_LSHIFT);
      off_unshift = false;
    }
  }
  return true;
}

//-----------------------------------------------------------------------------
bool isSetLeds = false;

//-----------------------------------------------------------------------------
bool layerChange = false;
int currentLayer = 0;
bool oneShotLight = false;
uint32_t shift_time = 0;
bool one_shot_regime = false;
int layer_offset = 0;
bool process_oneshot_shift(uint16_t keycode, keyrecord_t *record) {
  static bool record_presses = false;
  static bool is_pressed = false;
  static bool off_one_shot_regime = false;
  static bool unpress_one_shot_keycode = false;

  if (record_presses && keycode != SHF_1 && keycode != SHF_3 && record->event.pressed && MY_IS_KEY(keycode)) {
    is_pressed = true;
  }

  if (off_one_shot_regime) {
    unregister_code(KC_LSHIFT);
    off_one_shot_regime = false;
    currentShift = false;
  }

  if (unpress_one_shot_keycode) {
    unregister_code(keycode);
    unpress_one_shot_keycode = false;
  }

  if (one_shot_regime && record->event.pressed && MY_IS_KEY(keycode)) {
    bool returned = false;

    currentLayer = 0 + layer_offset;
    layerChange = false;
    layer_off(1 + layer_offset);

    if (!(HAS_INVERTED_SHIFT(keycode)) && (keycode < PLACEHOLDER)) {
      register_code(KC_LSHIFT);
      off_one_shot_regime = true;
      currentShift = true;

      register_code(keycode);
      unpress_one_shot_keycode = true;

      returned = false;
    } else {
      returned = true;
    }

    one_shot_regime = false;

    oneShotLight = false;
    layer_state_set_user(0);

    return returned;
  }

  switch (keycode) {
    case SHF_1:
      if (record->event.pressed) {
        currentLayer = 1;
        register_code(KC_LSHIFT);
        layer_on(1);
        layerChange = true;
        record_presses = true;
        layer_offset = 0;

        currentShift = true;
      } else {
        currentShift = false;
        record_presses = false;
        unregister_code(KC_LSHIFT);

        if (!is_pressed) {
          one_shot_regime = true;
          shift_time = timer_read();

          oneShotLight = true;
          layer_state_set_user(0);
        } else {
          currentLayer = 0;
          layerChange = false;
          layer_off(1);
          is_pressed = false;
        }
      }
      return false;
      break;
    case SHF_3:
      if (record->event.pressed) {
        currentLayer = 3;
        register_code(KC_LSHIFT);
        layer_on(3);
        layerChange = true;
        record_presses = true;
        layer_offset = 2;

        currentShift = true;
      } else {
        currentShift = false;
        record_presses = false;
        unregister_code(KC_LSHIFT);

        if (!is_pressed) {
          one_shot_regime = true;
          shift_time = timer_read();

          oneShotLight = true;
          layer_state_set_user(0);
        } else {
          currentLayer = 2;
          layerChange = false;
          layer_off(3);
          is_pressed = false;
        }
      }
      return false;
      break;
  }

  return true;
}

//-----------------------------------------------------------------------------
#define L000 0
#define L001 1
#define L010 2
#define L011 3
#define L100 4
#define L101 5
#define L110 6
#define L111 7

bool is_led_dance = false;
uint32_t led_dance_start_time = 0;
uint8_t led_dance_animation[] = {
  #define PING_PONG \
  L001, L001, L001, \
  L010, L010,       \
  L100, L100, L100, \
  L010, L010,

  #define PING_LONG_PONG
  L001, L001, L001, \
  L011,             \
  L010, L010, L010, \
  L110,             \
  L100, L100, L100, \
  L110,             \
  L010, L010, L010, \
  L011,

  PING_PONG
  PING_PONG
  PING_PONG
  PING_LONG_PONG
  PING_LONG_PONG
  PING_LONG_PONG

  L000, L000, L000,
  L111, L111, L111,
  L000, L000,
  L111, L111,
  L000,
  L111,
  L000,
  L111,
  L000,
  L111,
};
uint8_t animation_count = sizeof(led_dance_animation)/sizeof(uint8_t);
uint8_t one_animation_time = 50;
void process_led_dance(void) {
  if (is_led_dance) {
    uint32_t temp = timer_read() - led_dance_start_time;
    temp /= one_animation_time;
    temp %= animation_count;
    temp = led_dance_animation[temp];
    if (temp % 2) ML_LED_3(true); else ML_LED_3(false); temp /= 2;
    if (temp % 2) ML_LED_2(true); else ML_LED_2(false); temp /= 2;
    if (temp % 2) ML_LED_1(true); else ML_LED_1(false); temp /= 2;
  }
}

//-----------------------------------------------------------------------------
void user_timer(void) {
  if (oneShotLight && (timer_read() - shift_time >= 1000)) {
    currentLayer = 0 + layer_offset;
    layerChange = false;
    layer_off(1 + layer_offset);

    one_shot_regime = false;

    oneShotLight = false;
    layer_state_set_user(layer_state);
  }

  process_led_dance();
}

//-----------------------------------------------------------------------------
bool process_my_mod(uint16_t keycode, keyrecord_t *record) {
  #define _PROCESS(_name, _register, _unregister) \
    case _name: { \
      static int oldLayer = 0; \
      if (record->event.pressed) { \
        _register; \
        if (currentLayer == 2) { \
          oldLayer = 2; \
          layer_off(2); \
          default_layer_set(0); \
          layerChange = true; \
        } \
      } else { \
        if (oldLayer == 2) { \
          layerChange = false; \
          layer_on(2); \
          default_layer_set(2); \
          oldLayer = 0; \
        } \
        _unregister; \
      } \
      return false; \
      } break;

  switch (keycode) {
    _PROCESS(MY_CTRL, register_code(KC_LCTRL), unregister_code(KC_LCTRL));
    _PROCESS(MY_ALT,  register_code(KC_LALT),  unregister_code(KC_LALT));
    _PROCESS(MY_WIN,  register_code(KC_LGUI),  unregister_code(KC_LGUI));

    _PROCESS(MY_CTAL, {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
    }, {
      unregister_code(KC_LALT);
      unregister_code(KC_LCTRL);
    })

    _PROCESS(MY_SHAL, {
      register_code(KC_LSHIFT);
      register_code(KC_LALT);
    }, {
      unregister_code(KC_LALT);
      unregister_code(KC_LSHIFT);
    })

    _PROCESS(MY_CTSH, {
      register_code(KC_LCTRL);
      register_code(KC_LSHIFT);
    }, {
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
    })
    
    _PROCESS(MY_MCAS, {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
    }, {
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTRL);
    })
  }

  return true;
}

enum LANG_CHANGE {
  CAPS,
  ALT_SHIFT,
  CTRL_SHIFT,
  WIN_SPACE
};

int lang_current_change = ALT_SHIFT;
void change_lang(void) {
  switch (lang_current_change) {
    case CAPS: {
      register_code(KC_CAPS);
        unregister_code(KC_CAPS);
    } break;
    case ALT_SHIFT: {
      register_code(KC_LALT);
        register_code(KC_LSHIFT);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LALT);
    } break;
    case CTRL_SHIFT: {
      register_code(KC_LCTRL);
        register_code(KC_LSHIFT);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTL);
    } break;
    case WIN_SPACE: {
      register_code(KC_LGUI);
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
        unregister_code(KC_LGUI);
    } break;
  }
}

void screenshot(void) {
  // Костыль, когда я определяю кнопку для скриншота по переключению языка
  switch (lang_current_change) {
    case CAPS: {
      register_code(KC_LCTRL);
      register_code(KC_LSHIFT);
      register_code(KC_PSCR);
      unregister_code(KC_PSCR);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
    } break;
    case ALT_SHIFT:
    case CTRL_SHIFT: {
      register_code(KC_LGUI);
        register_code(KC_LSHIFT);
        register_code(KC_S);
      unregister_code(KC_S);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
    } break;
    case WIN_SPACE: {
      // No screenshot, maybe it android
    } break;
  } 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  user_timer();
  layer_state_set_user(layer_state);
  
  #ifdef CONSOLE_ENABLE
  //uprintf("KL: col=%d, row=%d, pressed=%d, layer=%d\n", 
  //  record->event.key.col, record->event.key.row, record->event.pressed, biton32(layer_state));
  #endif

  // Сначала должен идит oneshot_shift, затем inverted_shift
  if (!process_oneshot_shift(keycode, record))
    return false;

  if (!process_inverted_shift(keycode, record)) 
    return false;

  if (!process_my_mod(keycode, record))
    return false;

  switch(keycode) {
    case I3_CR:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSHIFT);

        register_code(KC_C);
        unregister_code(KC_C);

        register_code(KC_R);
        unregister_code(KC_R);

        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MY_SCRN:
      if (record->event.pressed) {
        screenshot();
      }
      return false;
      break;
    case LANG__1:
      if (record->event.pressed) {
        lang_current_change = CAPS;
      }
      return false;
      break;
    case LANG__2:
      if (record->event.pressed) {
        lang_current_change = ALT_SHIFT;
      }
      return false;
      break;
    case LANG__3:
      if (record->event.pressed) {
        lang_current_change = CTRL_SHIFT;
      }
      return false;
      break;
    case LANG__4:
      if (record->event.pressed) {
        lang_current_change = WIN_SPACE;
      }
      return false;
      break;
    case RE_LANG:
      if (record->event.pressed) {
        change_lang();
      }
      return false;
      break;
    case MY_LANG:
      if (record->event.pressed && !layerChange) {
        change_lang();
        if (currentLayer == 0) {
          currentLayer = 2;
          layer_on(2);
          default_layer_set(2);
        } else {
          currentLayer = 0;
          layer_off(2);
          default_layer_set(0);
        }
      }
      return false;
      break;
    case RU_3DOT:
      if (record->event.pressed) {
        SEND_STRING("///");
      }    
      return false;
      break;
    case KG_NEXT:
      if (record->event.pressed) {
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_LCTRL);
        register_code(KC_RGHT);
        unregister_code(KC_RGHT);
        unregister_code(KC_LCTRL);
      }    
      return false;
      break;
    case RU_CMSP:
      if (record->event.pressed) {
        SEND_STRING("? ");
      }
      return false;
      break;
    case EN_CMSP:
      if (record->event.pressed) {
        SEND_STRING(", ");
      }
      return false;
      break;
    #ifdef POINTING_DEVICE_ENABLE
    case MS_DOWN: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.y = 1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MS_UP: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.y = -1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MS_LEFT: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.x = -1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MS_RGHT: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.x = 1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MSWH_DW: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.v = -1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MSWH_UP: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.v = 1;
        pointing_device_set_report(currentReport);
      }
      return false;
      } break;
    case MSWH_LF: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.h = 1;
        pointing_device_set_report(currentReport);
        pointing_device_task();
        unregister_code(KC_LSHIFT);
      }
      return false;
      } break;
    case MSWH_RG: {
      if (record->event.pressed) {
        report_mouse_t currentReport = {};
        currentReport.h = -1;
        pointing_device_set_report(currentReport);
        pointing_device_task();
        unregister_code(KC_LSHIFT);
      }
      return false;
      } break;
    #endif
    case SP_LAN: {
      if (record->event.pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        process_record_user(MY_LANG, record);
      }
      return false;
      } break;
    case RU_SDOT: {
      if (record->event.pressed) {
        register_code(KC_SLSH);
        unregister_code(KC_SLSH);
        register_code(KC_SPC);
        unregister_code(KC_SPC);

        currentLayer = 3;
        layer_on(3);
        layerChange = true;
        layer_offset = 2;
        one_shot_regime = true;
        shift_time = timer_read();
        oneShotLight = true;
      }
      return false;
      } break;
    case LED_DN: {
      if (record->event.pressed) {
        is_led_dance = !is_led_dance;
        if (is_led_dance)
          led_dance_start_time = timer_read();
      }
      return false;
      } break;

    case LEFT_5: {
      if (record->event.pressed) {
        for (int i = 0; i < 5; ++i) {
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
        }
      }
      return false;
    } break;
    case UP_1C: {
      if (record->event.pressed) {
        for (int i = 0; i < 10; ++i) {
          register_code(KC_LCTL);
          register_code(KC_UP);
          unregister_code(KC_UP);
          unregister_code(KC_LCTL);
        }
      }
      return false;
    } break;
    case DOWN_1C: {
      if (record->event.pressed) {
        for (int i = 0; i < 10; ++i) {
          register_code(KC_LCTL);
          register_code(KC_DOWN);
          unregister_code(KC_DOWN);
          unregister_code(KC_LCTL);
        }
      }
      return false;
    } break;
    case RGHT_5: {
      if (record->event.pressed) {
        for (int i = 0; i < 5; ++i) {
          register_code(KC_RIGHT);
          unregister_code(KC_RIGHT);
        }
      }
      return false;
    } break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

//-----------------------------------------------------------------------------
// Set led by value of layer
// uint32_t layer_state_set_user(uint32_t state) {
//     uint8_t layer = biton32(state);

//     if (is_led_dance) return state;

//     if (oneShotLight) {
//       ML_LED_1(false);
//       ML_LED_2(false);
//       ML_LED_3(false);

//       ML_LED_2(true);
//       ML_LED_3(true);
//     } else {
//       if (!isSetLeds) {
//         ML_LED_1(false);
//         ML_LED_2(false);
//         ML_LED_3(false);
//       }

//       switch (layer) {
//         case 0:
//           break;
//         case 1:
//           break;
//         case 2:
//           ML_LED_3(true);
//           break;
//         case 3:
//           ML_LED_3(true);
//           break;
//         case 4:
//           ML_LED_1(true);
//           break;
//         case 5:
//           ML_LED_2(true);
//           break;
//         case 6:
//           ML_LED_1(true);
//           // Shold be 2
//           ML_LED_3(true);
//           break;
//         case 7:
//           ML_LED_1(true);
//           ML_LED_2(true);
//           break;
//         case 8:
//           ML_LED_1(true);
//           ML_LED_2(true);
//           ML_LED_3(true);
//           break;
//         case 9:
//           ML_LED_1(true);
//           ML_LED_2(true);
//           ML_LED_3(true);
//           break;
//         default:
//           break;
//       }
//     }
//     return state;
// };
