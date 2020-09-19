#include QMK_KEYBOARD_H
#include "version.h"

#define COMBO_KEYS_COUNT 5
#define COMBO_MAX_SIZE 4
#define COMBO_STACK_MAX_SIZE 5

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_86_255_128,

#if COMBO_KEYS_COUNT > 0
  CMB_000,
#endif
#if COMBO_KEYS_COUNT > 1
  CMB_001,
#endif
#if COMBO_KEYS_COUNT > 2
  CMB_002,
#endif
#if COMBO_KEYS_COUNT > 3
  CMB_003,
#endif
#if COMBO_KEYS_COUNT > 4
  CMB_004,
#endif

  #include "lang_shift/keycodes.h"
};

#define LANG_CHANGE_DEFAULT LANG_CHANGE_CAPS
#include "lang_shift/code.c"

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
    XXXXXXX,    XXXXXXX,  XXXXXXX,  CMB_003,  CMB_004,
    CMB_002, // LEFT RED THUMB KEY
    CMB_000,    CMB_001,  KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    XXXXXXX,    EN_ASTR,  EN_EXCL,  EN_RPRN,  EN_LPRN,  EN_QUES,  RESET,
    XXXXXXX,    EN_F,     EN_G,     EN_C,     EN_R,     EN_L,     EN_BSLS,
    XXXXXXX,    EN_D,     EN_H,     EN_T,     EN_N,     EN_S,     EN_MINS,
                EN_B,     EN_M,     EN_W,     EN_V,     EN_Z,     EN_HASH,
                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                          XXXXXXX, // RIGHT RED THUMB KEY
                          LA_CHNG, KC_DOT, KC_SPC // RIGHT THUMB KEYS
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

  #define COMBO_LAYER 4
  [4] = {
    { SHF_1_O, KC_BSPC, KC_LCTL, KC_SLSH, KC_UP,   SHF_1,   XXXXXXX },
    { KC_DEL,  MO(3),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }
  },
};

// Newtype pattern allows us wrap some type in that type and use static type-checking
#define NEWTYPE(name, new_name, get_name, eq_name, neq_name, type, max, none_name) \
  typedef struct name { \
    type repr; \
  } name; \
  \
  const name none_name = ((name){ .repr = max }); \
  \
  type get_name(name a) { \
    return a.repr; \
  } \
  \
  bool eq_name(name a, name b) { \
    return get_name(a) == get_name(b); \
  } \
  \
  bool neq_name(name a, name b) { \
    return get_name(a) != get_name(b); \
  }

NEWTYPE(ComboKey, new_combo_key, get_combo_key, eq_combo_key, neq_combo_key, uint8_t, 255, NONE_COMBO_KEY)
#define COMBO_KEY(x) ((ComboKey){ .repr = (x) })
// ^ C is weak piece of shit: it can't do #define inside #define, or it can't do const function which we can use inside initialization. So we must write this by hand.

NEWTYPE(ComboPos, new_combo_pos, get_combo_pos, eq_combo_pos, neq_combo_pos, uint8_t, 255, NONE_COMBO_POS)
#define COMBO_POS(x) ((ComboPos){ .repr = (x) })

const ComboKey combos_two_keys[][2] = {
  { COMBO_KEY(0), COMBO_KEY(1) },
  { COMBO_KEY(0), COMBO_KEY(2) },
  { COMBO_KEY(1), COMBO_KEY(2) },
  { COMBO_KEY(3), COMBO_KEY(4) },
};

const uint8_t combo_two_keys_size = sizeof(combos_two_keys)/(sizeof(uint16_t) * 2) + 1;

typedef struct Combo {
  ComboKey array[COMBO_MAX_SIZE];
  uint8_t size;
  uint8_t state;
  uint32_t last_modify_time;
} Combo;

#define TRANSITION_DEBUG(a) uprintf("transition '" #a "' for #%d: {", combo - &combo_stack[0]); \
  for (int i = 0; i < combo->size; ++i) { \
    uprintf("%d, ", combo->array[i]); \
  } \
  uprintf("} in %d\n", combo->state);

Combo combo_stack[COMBO_STACK_MAX_SIZE] = {};
uint8_t combo_stack_size = 0;

bool combo_enabled = true;

bool combo_is_combo_key(Key key) {
  return CMB_000 <= key && key < CMB_000 + COMBO_KEYS_COUNT;
}

ComboPos combo_get_combo_pos_two(ComboKey a, ComboKey b) {
  for (uint8_t i = 0; i < combo_two_keys_size; ++i) {
    if ((eq_combo_key(combos_two_keys[i][0], a) && eq_combo_key(combos_two_keys[i][1], b)) || 
        (eq_combo_key(combos_two_keys[i][0], b) && eq_combo_key(combos_two_keys[i][1], a))) {
      return COMBO_POS(i + COMBO_KEYS_COUNT);
    }
  }

  return NONE_COMBO_POS;
}

ComboKey combo_key_to_combo_key(Key key) {
  if (combo_is_combo_key(key)) {
    return COMBO_KEY(key - CMB_000);
  } else {
    return NONE_COMBO_KEY;
  }
}

ComboPos combo_get_pos(Combo *combo) {
  // TODO MAKE FOR ANY LENGTH OF COMBOS
  if (combo->size == 1) {
    return COMBO_POS(get_combo_key(combo->array[0]));
  } else {
    return combo_get_combo_pos_two(combo->array[0], combo->array[1]);
  }
}

bool combo_has_prefix(Combo *combo, ComboKey another_key) {
  // TODO MAKE FOR ANY LENGTH OF COMBOS
  for (uint8_t i = 0; i < combo_two_keys_size; ++i) {
    if (eq_combo_key(combos_two_keys[i][0], another_key) || eq_combo_key(combos_two_keys[i][1], another_key)) {
      return true;
    }
  }

  return false;
}

bool combo_is_current_key(Combo *combo, ComboKey key) {
  for (uint8_t i = 0; i < combo->size; ++i) {
    if (eq_combo_key(combo->array[i], key)) {
      return true;
    }
  }

  return false;
}

void combo_press(ComboPos pos, bool down) {
  keyrecord_t record = {
    .event = {
      .key = {
        .col = get_combo_pos(pos) % MATRIX_COLS,
        .row = get_combo_pos(pos) / MATRIX_COLS
      },
      .pressed = down,
      .time = timer_read()
    },
  };
  combo_enabled = false;
  layer_on(COMBO_LAYER);
  process_record(&record);
  layer_off(COMBO_LAYER);
  combo_enabled = true;
}

void combo_onenter_1(Combo *combo) {
  combo->state = 1;
}

void combo_onenter_2(Combo *combo, ComboPos pos) {
  combo_press(pos, true);
  combo->state = 2;
}

void combo_onenter_end(Combo *combo) {
  uint8_t pos = 0;
  for (uint8_t i = 0; i < combo_stack_size; ++i) {
    if (&combo_stack[i] == combo) {
      pos = i;
    }
  }

  combo_stack_size--;

  for (uint8_t i = pos; i < combo_stack_size; ++i) {
    combo_stack[i] = combo_stack[i+1];
  }
}

void combo_onenter_3(Combo *combo, ComboKey key) {
  uint8_t pos = 0;
  for (uint8_t i = 0; i < combo->size; ++i) {
    if (eq_combo_key(combo->array[i], key)) {
      pos = i;
    }
  }

  combo->size--;

  for (uint8_t i = pos; i < combo->size; ++i) {
    combo->array[i] = combo->array[i+1];
  }

  combo->state = 3;

  if (combo->size == 0) {
    TRANSITION_DEBUG(i);
    combo_onenter_end(combo);
  }
}

bool combo_process_1(Combo *combo, Key key, keyrecord_t *record) {
  bool down = record->event.pressed;
  bool up = !down;
  ComboKey key_combo = combo_key_to_combo_key(key);

  if (down && neq_combo_key(key_combo, NONE_COMBO_KEY) && combo_has_prefix(combo, key_combo)) {
    uprintf("combo size: %d\n", combo->size);
    TRANSITION_DEBUG(e);
    combo->array[combo->size] = key_combo;
    combo->size++;
    combo->last_modify_time = timer_read();
    return true;
  }

  ComboPos pos = combo_get_pos(combo);
  if (neq_combo_pos(pos, NONE_COMBO_POS)) {
    if (neq_combo_key(key_combo, NONE_COMBO_KEY)) {
      if (up && combo_is_current_key(combo, key_combo)) {
        TRANSITION_DEBUG(g);
        combo_press(pos, true);
        combo_press(pos, false);

        combo_onenter_3(combo, key_combo);
        return true;  
      }
    } else {
      if (down) {
        TRANSITION_DEBUG(b);
        combo_onenter_2(combo, pos);
        return false; // for processing as usual
      }
    }
  } else {
    if (up && neq_combo_key(key_combo, NONE_COMBO_KEY)) {
      TRANSITION_DEBUG(f);
      combo_onenter_3(combo, key_combo);
      return true;
    }
  }

  return false;
}

bool combo_process_2(Combo *combo, Key key, keyrecord_t *record) {
  bool down = record->event.pressed;
  bool up = !down;
  ComboKey key_combo = combo_key_to_combo_key(key);

  if (up && neq_combo_key(key_combo, NONE_COMBO_KEY) && combo_is_current_key(combo, key_combo)) {
    TRANSITION_DEBUG(c);

    ComboPos pos = combo_get_pos(combo);
    combo_press(pos, false);

    combo_onenter_3(combo, key_combo);
    return true;
  }

  return false;
}

bool combo_process_3(Combo *combo, Key key, keyrecord_t *record) {
  bool down = record->event.pressed;
  bool up = !down;
  ComboKey key_combo = combo_key_to_combo_key(key);

  if (up && neq_combo_key(key_combo, NONE_COMBO_KEY) && combo_is_current_key(combo, key_combo)) {
    TRANSITION_DEBUG(h);

    combo_onenter_3(combo, key_combo);

    return true;
  }

  return false;
}

bool combo_process_local_states(Combo *combo, Key key, keyrecord_t *record) {
  switch (combo->state) {
    case 1: return combo_process_1(combo, key, record);
    case 2: return combo_process_2(combo, key, record);
    case 3: return combo_process_3(combo, key, record);
  }
  return false;
}

bool combo_process(Key key, keyrecord_t *record) {
  for (uint8_t i = 0; i < combo_stack_size; ++i) {
    Combo *combo = &combo_stack[i];
    if (combo_process_local_states(combo, key, record))
      return true;
  }

  bool down = record->event.pressed;
  ComboKey key_combo = combo_key_to_combo_key(key);

  if (down && neq_combo_key(key_combo, NONE_COMBO_KEY)) {
    Combo* combo = &combo_stack[combo_stack_size];
    uprintf("stack size: %d\n", combo_stack_size);
    TRANSITION_DEBUG(a);
    combo_stack_size++;
    combo->array[0] = key_combo;
    combo->size = 1;
    combo->state = 1;
    combo->last_modify_time = timer_read();
    return true;
  }

  return false;
}

// TOOD user timer process 1 only with timer

bool process_record_user(uint16_t key, keyrecord_t *record) {
  if (combo_enabled) {
    uprintf("\n\n");
    uprintf("%s %d\n", record->event.pressed ? "down" : "  up", combo_key_to_combo_key(key));
    if (combo_process(key, record))
      return false;
    uprintf("processed as usual\n");
  } else {
    uprintf("inside combo: %s\n", record->event.pressed ? "down" : "  up");
  }

  #include "lang_shift/process_record_user.c"

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