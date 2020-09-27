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
    case SHF_1_O:
      shift_once_process_key(1, down);
      return false;
    case SHF_3_O:
      shift_once_process_key(3, down);
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
}