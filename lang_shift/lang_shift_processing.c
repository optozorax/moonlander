void lang_press_key(Key key, bool down);
void lang_tap_key(Key key);

uint8_t lang_shift_current_shift_layer = 0;
bool process_record_lang_shift(Key key, keyrecord_t* record) {
  bool down = record->event.pressed;

  // Обрабатываем Once Shift
  shift_once_process(key, record);

  // Разбираемся, имеет ли эта клавиша какой-то язык, заданный в ней
  Key key1 = lang_process(key, down);
  Key key_to_shift = key;
  if (key1 != NONE_KEY) {
    key_to_shift = key1;
  }

  // Разбираемся, имеет ли эта клавиша шифт, засунутый в неё
  // Это нужно отдельно от обработки языка, чтобы шифт мог выключаться для обычных клавиш
  Key key2 = shift_process(key_to_shift, down);
  if (key2 != NONE_KEY) {
    if (down) {
      register_code(key2);
    } else {
      unregister_code(key2);
    }
    return false;
  }

  // Обрабатываем клавиши, связанные с кастомным шифтом и кастомным переключением языка
  switch (key) {
    case SHF_N_O:
      shift_once_process_key(lang_get_shift_layer_number(), down);
      return false;
    case SHF_1_O:
      shift_once_process_key(1, down);
      return false;
    case SHF_3_O:
      shift_once_process_key(3, down);
      return false;
    case SHF_N:
      if (down) {
        shift_activate_from_user(true);
        lang_shift_current_shift_layer = lang_get_shift_layer_number();
        layer_on(lang_shift_current_shift_layer);
      } else {
        shift_activate_from_user(false);
        layer_off(lang_shift_current_shift_layer);
      }
      return false;
    case SHF_1:
      if (down) {
        shift_activate_from_user(true);
        layer_on(1);
      } else {
        shift_activate_from_user(false);
        layer_off(1);
      }
      return false;
    case SHF_3:
      if (down) {
        shift_activate_from_user(true);
        layer_on(3);
      } else {
        shift_activate_from_user(false);
        layer_off(3);
      }
      return false;
    case LA_CHNG:
      if (down) {
        if (lang_should_be == 0) {
          lang_activate_from_user(1);
          layer_on(2);  
        } else {
          lang_activate_from_user(0);
          layer_off(2);
        }
      }
      return false;
    case LA_SYNC:
      if (down) {
        lang_synchronize();
      }
      return false;
    case LA_CAPS:
      if (down) {
        lang_current_change = LANG_CHANGE_CAPS;
      }
      return false;
    case LA_ALSH:
      if (down) {
        lang_current_change = LANG_CHANGE_ALT_SHIFT;
      }
      return false;
    case LA_CTSH:
      if (down) {
        lang_current_change = LANG_CHANGE_CTRL_SHIFT;
      }
      return false;
    case LA_WISP:
      if (down) {
        lang_current_change = LANG_CHANGE_WIN_SPACE;
      }
      return false;
    case AG_3DOT:
      if (record->event.pressed) {
        lang_tap_key(AG_DOT);
        lang_tap_key(AG_DOT);
        lang_tap_key(AG_DOT);
      }    
      return false;
      break;
    case AG_CMSP:
      if (record->event.pressed) {
        lang_tap_key(AG_COMM);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      return false;
      break;
    case AG_SDOT:
      if (record->event.pressed) {
        lang_tap_key(AG_DOT);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        shift_once_use_to_next_key(lang_get_shift_layer_number());
      }
      return false;
      break;
  }

  static Lang lang_stack[3] = {};
  static uint8_t modifiers_count = 0;
  #define PROCESS(NAME, REGISTER, UNREGISTER) \
    case NAME: { \
      if (record->event.pressed) { \
        lang_stack[modifiers_count] = lang_should_be; \
        modifiers_count += 1; \
        if (lang_should_be == 1) { \
          layer_off(2); \
        } \
        lang_activate_from_user(0); \
        REGISTER; \
      } else { \
        UNREGISTER; \
        modifiers_count -= 1; \
        lang_activate_from_user(lang_stack[modifiers_count]); \
        if (lang_should_be == 1) { \
          layer_on(2); \
        } \
      } \
      return false; \
    } break;

  #define Rg(x) register_code(KC_L ## x)
  #define Un(x) unregister_code(KC_L ## x)

  switch (key) {
    PROCESS(CTRL_0, Rg(CTRL), Un(CTRL));
    PROCESS(ALT_0,  Rg(ALT),  Un(ALT));
    PROCESS(WIN_0,  Rg(GUI),  Un(GUI));
    PROCESS(CTAL_0, { Rg(CTRL);  Rg(ALT);   }, { Un(ALT);   Un(CTRL);  })
    PROCESS(SHAL_0, { Rg(SHIFT); Rg(ALT);   }, { Un(ALT);   Un(SHIFT); })
    PROCESS(CTSH_0, { Rg(CTRL);  Rg(SHIFT); }, { Un(SHIFT); Un(CTRL);  })
    PROCESS(MCAS_0, { Rg(CTRL);  Rg(ALT); Rg(SHIFT); }, { Un(SHIFT); Un(ALT); Un(CTRL); })
  }

  return true;
}

void lang_press_key(Key key, bool down) {
  keyrecord_t record = {
    .event = {
      .key = {
        .col = 0,
        .row = 0,
      },
      .pressed = down,
      .time = timer_read(),
    },
  };
  
  process_record_lang_shift(key, &record);
}

void lang_tap_key(Key key) {
  lang_press_key(key, true);
  lang_press_key(key, false);
  shift_activate(shift_should_be);
  lang_activate(lang_should_be);
}
