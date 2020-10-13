typedef uint8_t Lang;
#define NONE_LANG (uint8_t)(255)

Lang lang_should_be = 0;
Lang lang_current = 0;
uint32_t lang_timer = 0;

Lang lang_get_shift_layer_number(void) {
  return lang_should_be * 2 + 1;
}

Key lang_get_key(Key key);
Lang lang_get_lang(Key key);
Key lang_calc_agnostic(Key key);

// Public
enum LangChange {
  LANG_CHANGE_CAPS,
  LANG_CHANGE_ALT_SHIFT,
  LANG_CHANGE_CTRL_SHIFT,
  LANG_CHANGE_WIN_SPACE
};

// Public
enum LangChange lang_current_change = 
#ifdef LANG_CHANGE_DEFAULT
  LANG_CHANGE_DEFAULT;
#else
  #error "You must specify default language change method by defining variable LANG_CHANGE_DEFAULT."
#endif

// Public
void lang_synchronize(void) {
  lang_timer = timer_read();
  switch (lang_current_change) {
    case LANG_CHANGE_CAPS: {
      // Костыль, потому что при нажатии Shift+Caps включается режим Caps, а не переключение языка :facepalm:
      if (shift_current == 1) {
      	unregister_code(KC_LSHIFT);
      	register_code(KC_CAPS);
      	unregister_code(KC_CAPS);
      	register_code(KC_LSHIFT);
      } else {
      	register_code(KC_CAPS);
      	unregister_code(KC_CAPS);
      }
    } break;
    case LANG_CHANGE_ALT_SHIFT: {
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LALT);

      // Костыль, потому что при зажатом шифте если хочется нажать клавишу, которая переключает язык, то шифт слетает... 
      if (shift_current == 1) {
        register_code(KC_LSHIFT);
      }
    } break;
    case LANG_CHANGE_CTRL_SHIFT: {
      register_code(KC_LCTRL);
      register_code(KC_LSHIFT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTL);

      // Костыль, потому что при зажатом шифте если хочется нажать клавишу, которая переключает язык, то шифт слетает...
      if (shift_current == 1) {
        register_code(KC_LSHIFT);
      }
    } break;
    case LANG_CHANGE_WIN_SPACE: {
      register_code(KC_LGUI);
      register_code(KC_SPACE);
      unregister_code(KC_SPACE);
      unregister_code(KC_LGUI);
    } break;
  }
}

void lang_activate(Lang lang) {
	// Нужно дополнять этот код, если нужно три языка и более
	if (lang_current != lang) {
		lang_synchronize();
	}
	lang_current = lang;
}

// Public
void lang_activate_from_user(Lang lang) {
	lang_should_be = lang;
	lang_activate(lang);
}

uint8_t lang_pressed_count = 0;

// Public
Key lang_process(Key key, bool down) {
  Key after_agnostic = lang_calc_agnostic(key);
  if (after_agnostic != NONE_KEY) {
    key = after_agnostic;
  }

	Lang new_lang = lang_get_lang(key);
	if (down) {
		if (new_lang != NONE_LANG) {
			lang_activate(new_lang);
		} else {
			lang_activate(lang_should_be);
		}
	}

  if (new_lang != NONE_LANG) {
    if (down) {
      lang_pressed_count++;
    } else {
      lang_pressed_count--;
    }
  }

	return lang_get_key(key);
}

void lang_user_timer(void) {
	// Нужно выключать язык после прохождения определённого времени, потому что пользователь ожидает как будто шифт на самом деле включён
	if (lang_pressed_count == 0 && lang_current != lang_should_be && timer_read() - lang_timer >= 100) {
		lang_activate(lang_should_be);
	}
}

Key lang_get_key(Key key) {
  if (EN_GRV <= key && key <= EN_QUES) {
    return (key - EN_GRV) + KS_GRV;
  } else if (RU_JO <= key && key <= RU_COMM) {
    return (key - RU_JO) + KS_GRV;
  } else {
    return NONE_KEY;
  }
}

Lang lang_get_lang(Key key) {
  if (EN_GRV <= key && key <= EN_QUES) {
    return 0;
  } else if (RU_JO <= key && key <= RU_COMM) {
    return 1;
  } else {
    return NONE_LANG;
  }
}

Key lang_calc_agnostic(Key key) {
  if (lang_current == 0) {
    switch (key) {
      case AG_1:    return EN_1;
      case AG_2:    return EN_2;
      case AG_3:    return EN_3;
      case AG_4:    return EN_4;
      case AG_5:    return EN_5;
      case AG_6:    return EN_6;
      case AG_7:    return EN_7;
      case AG_8:    return EN_8;
      case AG_9:    return EN_9;
      case AG_0:    return EN_0;
      case AG_EXCL: return EN_EXCL;
      case AG_PERC: return EN_PERC;
      case AG_ASTR: return EN_ASTR;
      case AG_LPRN: return EN_LPRN;
      case AG_RPRN: return EN_RPRN;
      case AG_MINS: return EN_MINS;
      case AG_UNDS: return EN_UNDS;
      case AG_EQL:  return EN_EQL;
      case AG_PLUS: return EN_PLUS;
      case AG_SCLN: return EN_SCLN;
      case AG_COLN: return EN_COLN;
      case AG_DQUO: return EN_DQUO;
      case AG_BSLS: return EN_BSLS;
      case AG_COMM: return EN_COMM;
      case AG_DOT:  return EN_DOT;
      case AG_SLSH: return EN_SLSH;
      case AG_QUES: return EN_QUES;
      default:      return NONE_KEY;
    }
  } else {
    switch (key) {
      case AG_1:    return RU_1;
      case AG_2:    return RU_2;
      case AG_3:    return RU_3;
      case AG_4:    return RU_4;
      case AG_5:    return RU_5;
      case AG_6:    return RU_6;
      case AG_7:    return RU_7;
      case AG_8:    return RU_8;
      case AG_9:    return RU_9;
      case AG_0:    return RU_0;
      case AG_EXCL: return RU_EXCL;
      case AG_PERC: return RU_PERC;
      case AG_ASTR: return RU_ASTR;
      case AG_LPRN: return RU_LPRN;
      case AG_RPRN: return RU_RPRN;
      case AG_MINS: return RU_MINS;
      case AG_UNDS: return RU_UNDS;
      case AG_EQL:  return RU_EQL;
      case AG_PLUS: return RU_PLUS;
      case AG_SCLN: return RU_SCLN;
      case AG_COLN: return RU_COLN;
      case AG_DQUO: return RU_DQUO;
      case AG_BSLS: return RU_BSLS;
      case AG_COMM: return RU_COMM;
      case AG_DOT:  return RU_DOT;
      case AG_SLSH: return RU_SLSH;
      case AG_QUES: return RU_QUES;
      default:      return NONE_KEY;
    }
  }
}