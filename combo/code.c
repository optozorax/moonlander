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

const ComboKey combos[COMBO_COUNT][COMBO_MAX_SIZE + 1];

const uint8_t combos_size = COMBO_COUNT;

typedef struct Combo {
  ComboKey array[COMBO_MAX_SIZE];
  uint8_t size;
  uint8_t state;
  uint32_t last_modify_time;
} Combo;


#if 0
  #define TRANSITION_DEBUG(a) uprintf("transition '" #a "' for #%d: {", combo - &combo_stack[0]); \
    for (int i = 0; i < combo->size; ++i) { \
      uprintf("%d, ", combo->array[i]); \
    } \
    uprintf("} in %d\n", combo->state);
#else
  #define TRANSITION_DEBUG(a) ;
#endif

Combo combo_stack[COMBO_STACK_MAX_SIZE] = {};
uint8_t combo_stack_size = 0;

bool combo_enabled = true;

bool combo_is_combo_key(uint16_t key) {
  return CMB_000 <= key && key < CMB_000 + COMBO_KEYS_COUNT;
}

ComboKey combo_key_to_combo_key(uint16_t key) {
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
  
  layer_on(COMBO_LAYER);
  combo_enabled = false;
  process_record(&record);
  combo_enabled = true;
  layer_off(COMBO_LAYER);
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

bool combo_process_1(Combo *combo, uint16_t key, keyrecord_t *record) {
  bool down = record->event.pressed;
  bool up = !down;
  ComboKey key_combo = combo_key_to_combo_key(key);
  ComboPos pos = combo_get_pos(combo);

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

bool combo_process_2(Combo *combo, uint16_t key, keyrecord_t *record) {
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

bool combo_process_3(Combo *combo, uint16_t key, keyrecord_t *record) {
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

bool combo_process_local_states(Combo *combo, uint16_t key, keyrecord_t *record) {
  switch (combo->state) {
    case 1: return combo_process_1(combo, key, record);
    case 2: return combo_process_2(combo, key, record);
    case 3: return combo_process_3(combo, key, record);
  }
  return false;
}

bool combo_process(uint16_t key, keyrecord_t *record) {
  for (uint8_t i = 0; i < combo_stack_size; ++i) {
    Combo *combo = &combo_stack[i];
    if (combo_process_local_states(combo, key, record))
      return true;
  }

  bool down = record->event.pressed;
  ComboKey key_combo = combo_key_to_combo_key(key);

  if (down && neq_combo_key(key_combo, NONE_COMBO_KEY)) {
    Combo* combo = &combo_stack[combo_stack_size];
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
