#pragma once

#include "map.h"

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for combo extension."
#endif

enum combo_keycodes {
  COMBO_START = CUSTOM_SAFE_RANGE,

  #include "keycodes.h"

  COMBO_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE COMBO_NEW_SAFE_RANGE
};

// С помощью этого макроса задаётся аккорд
#define CHORD(KEYCODE, ...) { .to_press = { MAP(COMBO_WITH_SEP, __VA_ARGS__) NONE_COMBO_KEY }, .keycode = KEYCODE }
#define COMBO_WITH_SEP(x) COMBO_KEY(x - CMB_000), 

// Uncomment this line if you want to print debug this extension
// #define COMBO_DEBUG

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
#define COMBO_KEY(x) ((ComboKey){ .repr = (x) }) // C is weak piece of shit: it can't do #define inside #define, or it can't do const function which we can use inside initialization. So we must write this by hand.

NEWTYPE(ComboPos, combo_pos, uint8_t, 255, NONE_COMBO_POS)
#define COMBO_POS(x) ((ComboPos){ .repr = (x) })

typedef struct ComboWithKeycode {
  ComboKey to_press[COMBO_MAX_SIZE + 1];
  uint16_t keycode;
} ComboWithKeycode;

const ComboWithKeycode combos[];
const uint8_t combos_size;

bool combo_process_record(uint16_t key, keyrecord_t *record);
void combo_user_timer(void);

// Инклюжу код напрямую, потому что нельзя сделать линковку, ведь код внутри использует кейкоды отсюда, и обязательно нужно это делать через safe_range
#include "src.c"
