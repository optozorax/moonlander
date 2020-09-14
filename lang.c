typedef uint8_t Lang;

Lang lang_should_be = 0;
Lang lang_current = 0;

Key lang_get_key(Key key);
Lang lang_get_lang(Key key);

// Public
enum LangChange {
  LANG_CHANGE_CAPS,
  LANG_CHANGE_ALT_SHIFT,
  LANG_CHANGE_CTRL_SHIFT,
  LANG_CHANGE_WIN_SPACE
};

// Public
enum LangChange lang_current_change = LANG_CHANGE_CAPS;

// Public
void lang_synchronize(void) {
  switch (lang_current_change) {
    case LANG_CHANGE_CAPS: {
      register_code(KC_CAPS);
      unregister_code(KC_CAPS);
    } break;
    case LANG_CHANGE_ALT_SHIFT: {
      register_code(KC_LALT);
      register_code(KC_LSHIFT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LALT);
    } break;
    case LANG_CHANGE_CTRL_SHIFT: {
      register_code(KC_LCTRL);
      register_code(KC_LSHIFT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTL);
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

// Public
Key lang_process(Key key, bool down) {
	Lang new_lang = lang_get_lang(key);
	if (down) {
		if (new_lang != -1) {
			lang_activate(new_lang);
		} else {
			lang_activate(lang_should_be);
		}
	}

	return lang_get_key(key);
}

#include "custom_lang.c"
// Следующие вещи находятся в файле `custom_lang.c`:
// #define MY_LANG_KEYS - это надо потом вставить в custom_keycodes
// Key lang_get_key(Key key) - возвращает клавишу без языка по данной клавише с языком, если это обычная клавиша, то возвращает -1
// Lang lang_get_lang(Key key) - возвращает какой язык у данной клавиши, если никакой, то -1
