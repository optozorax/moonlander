#include QMK_KEYBOARD_H
#include "version.h"

#define COMBO_KEYS_COUNT 5
#define COMBO_MAX_SIZE 3
#define COMBO_STACK_MAX_SIZE 3
#define COMBO_WAIT_TIME 100

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
    { KC_DEL,  MO(2),   KC_E,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX },
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
#define NEWTYPE(name, func_name, type, max, none_name) \
  typedef struct name { \
    type repr; \
  } name; \
  \
  const name none_name = ((name){ .repr = max }); \
  \
  type get_ ## func_name(name a) { \
    return a.repr; \
  } \
  \
  bool eq_ ## func_name(name a, name b) { \
    return get_ ## func_name(a) == get_ ## func_name(b); \
  } \
  \
  bool neq_ ## func_name(name a, name b) { \
    return get_ ## func_name(a) != get_ ## func_name(b); \
  }

NEWTYPE(ComboKey, combo_key, uint8_t, 255, NONE_COMBO_KEY)
#define COMBO_KEY(x) ((ComboKey){ .repr = (x) })
// ^ C is weak piece of shit: it can't do #define inside #define, or it can't do const function which we can use inside initialization. So we must write this by hand.

NEWTYPE(ComboPos, combo_pos, uint8_t, 255, NONE_COMBO_POS)
#define COMBO_POS(x) ((ComboPos){ .repr = (x) })

const ComboKey combos[][COMBO_MAX_SIZE + 1] = {
  { COMBO_KEY(0), NONE_COMBO_KEY },
  { COMBO_KEY(1), NONE_COMBO_KEY },
  { COMBO_KEY(2), NONE_COMBO_KEY },
  { COMBO_KEY(3), NONE_COMBO_KEY },
  { COMBO_KEY(4), NONE_COMBO_KEY },
  { COMBO_KEY(0), COMBO_KEY(1), NONE_COMBO_KEY },
  { COMBO_KEY(0), COMBO_KEY(2), NONE_COMBO_KEY },
  { COMBO_KEY(1), COMBO_KEY(2), NONE_COMBO_KEY },
  { COMBO_KEY(3), COMBO_KEY(4), NONE_COMBO_KEY },
  { COMBO_KEY(0), COMBO_KEY(1), COMBO_KEY(2), NONE_COMBO_KEY },
};

const uint8_t combos_size = sizeof(combos)/(sizeof(ComboKey) * (COMBO_MAX_SIZE + 1));

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

ComboKey combo_key_to_combo_key(Key key) {
  if (combo_is_combo_key(key)) {
    return COMBO_KEY(key - CMB_000);
  } else {
    return NONE_COMBO_KEY;
  }
}

bool combo_has_key(Combo *combo, ComboKey key) {
  for (uint8_t i = 0; i < combo->size; ++i) {
    if (eq_combo_key(combo->array[i], key)) {
      return true;
    }
  }

  return false;
}

uint8_t combo_get_len(uint8_t elem_index) {
  for (uint8_t i = 0; i < COMBO_MAX_SIZE + 1; ++i) {
    if (eq_combo_key(combos[elem_index][i], NONE_COMBO_KEY)) {
      return i;
    }
  }
  return 0;
}

bool combo_elem_has_key(uint8_t elem_index, ComboKey key) {
  uint8_t len = combo_get_len(elem_index);
  for (uint8_t i = 0; i < len; ++i) {
    if (eq_combo_key(combos[elem_index][i], key)) {
      return true;
    }
  }

  return false;
}

ComboPos combo_get_pos(Combo *combo) {
  for (uint8_t i = 0; i < combos_size; ++i) {
    if (combo_get_len(i) == combo->size) {
      bool found = true;
      for (uint8_t j = 0; j < combo->size; ++j) {
        found &= combo_has_key(combo, combos[i][j]);
      }
      if (found) {
        return COMBO_POS(i);
      }
    }
  }
  return NONE_COMBO_POS;
}

bool combo_has_prefix(Combo *combo, ComboKey another_key) {
  for (uint8_t i = 0; i < combos_size; ++i) {
    if (combo_get_len(i) > combo->size) {
      bool found = combo_elem_has_key(i, another_key);
      for (uint8_t j = 0; j < combo->size; ++j) {
        found &= combo_elem_has_key(i, combo->array[j]);
      }
      if (found) {
        return true;
      }
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
      .time = timer_read(),
    },
  };
  
  uprintf("KC_DEL: %d, KC_BSPC: %d\n", KC_DEL, KC_BSPC);
  #define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
  #define BYTE_TO_BINARY(byte)  \
    (byte & 0x80 ? '1' : '0'), \
    (byte & 0x40 ? '1' : '0'), \
    (byte & 0x20 ? '1' : '0'), \
    (byte & 0x10 ? '1' : '0'), \
    (byte & 0x08 ? '1' : '0'), \
    (byte & 0x04 ? '1' : '0'), \
    (byte & 0x02 ? '1' : '0'), \
    (byte & 0x01 ? '1' : '0') 
  uprintf("layer state BEFORE: " BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(layer_state));
  layer_on(COMBO_LAYER);
  combo_enabled = false;
  process_record(&record);
  combo_enabled = true;
  layer_off(COMBO_LAYER);
  uprintf("layer state AFTER: " BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(layer_state));
}

void process_as_usual(keyrecord_t* record) {
  combo_enabled = false;
  process_record(record);
  combo_enabled = true;
}

void combo_onenter_1(Combo *combo) {
  combo->state = 1;
}

void combo_onenter_2(Combo *combo, ComboPos pos, keyrecord_t* record) {
  combo_press(pos, true);
  process_as_usual(record);
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
  ComboPos pos = combo_get_pos(combo);

  uprintf("1. down: %d, neq_combo_key: %d, has_prefix: %d\n", down, neq_combo_key(key_combo, NONE_COMBO_KEY), combo_has_prefix(combo, key_combo));
  if (down && neq_combo_key(key_combo, NONE_COMBO_KEY)) {
    if (combo_has_prefix(combo, key_combo)) {
      TRANSITION_DEBUG(e);
      combo->array[combo->size] = key_combo;
      combo->size++;
      combo->last_modify_time = timer_read();
      return true;
    } else {
      if (neq_combo_pos(pos, NONE_COMBO_POS)) {
        TRANSITION_DEBUG(k);
        combo_press(pos, true);
        combo->state = 3;
        return false;
      }
    }
  }

  if (neq_combo_pos(pos, NONE_COMBO_POS)) {
    if (neq_combo_key(key_combo, NONE_COMBO_KEY)) {
      if (up && combo_has_key(combo, key_combo)) {
        TRANSITION_DEBUG(g);
        combo_press(pos, true);
        combo_press(pos, false);

        combo_onenter_3(combo, key_combo);
        return true;  
      }
    } else {
      if (down) {
        TRANSITION_DEBUG(b);
        combo_onenter_2(combo, pos, record);
        return true;
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

  if (up && neq_combo_key(key_combo, NONE_COMBO_KEY) && combo_has_key(combo, key_combo)) {
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

  if (up && neq_combo_key(key_combo, NONE_COMBO_KEY) && combo_has_key(combo, key_combo)) {
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

void combo_user_timer(void) {
  for (int i = 0; i < combo_stack_size; ++i) {
    Combo* combo = &combo_stack[i];
    if (combo->state == 1) {
      uprintf("timer: %d\n", timer_read() - combo_stack[i].last_modify_time);
      if (timer_read() - combo->last_modify_time > COMBO_WAIT_TIME) {
        ComboPos pos = combo_get_pos(combo);
        if (neq_combo_pos(pos, NONE_COMBO_POS)) {
          TRANSITION_DEBUG(d);
          combo_press(pos, true);
          combo->state = 2;
        }
      }
    }
  }
}

void user_timer(void) {
  combo_user_timer();
  // lang_user_timer();
  // shift_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}

bool process_record_user(uint16_t key, keyrecord_t *record) {
  if (combo_enabled) {
    uprintf("\n\n");
    uprintf("%s %d\n", record->event.pressed ? "down" : "  up", combo_key_to_combo_key(key));
    if (combo_process(key, record))
      return false;
    uprintf("processed as usual\n");
  } else {
    uprintf("inside combo: %s, %d\n", record->event.pressed ? "down" : "  up", key);
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