#include "custom_lang.c"
// Следующие вещи находятся в файле `custom_lang.c`:
// #define MY_LANG_KEYS - это надо потом вставить в custom_keycodes
// Key lang_get_key(Key key) - возвращает клавишу без языка по данной клавише с языком, если это обычная клавиша, то возвращает -1
// Lang lang_get_lang(Key key) - возвращает какой язык у данной клавиши, если никакой, то -1

typedef uint8_t Lang;
typedef uint16_t Key;

Lang lang_should_be = 0;
Lang lang_current = 0;

// Public
enum LANG_CHANGE {
  CAPS,
  ALT_SHIFT,
  CTRL_SHIFT,
  WIN_SPACE
};

// Public
int lang_current_change = ALT_SHIFT;

// Public
void lang_synchronize() {
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

void lang_activate(Lang lang) {
	// Нужно дополнять этот код, если нужно три языка и более
	if (lang_current != lang) {
		lang_synchronize();
	}
	lung_current = lang;
}

// Public
void lang_activate_from_user(Lang lang) {
	lang_should_be = lang;
	lang_activate(lang);
}

// Public
Key lang_process(Key key, bool pressed) {
	Lang new_lang = lang_get_lang(key);
	if (down) {
		if (new_lang != -1) {
			lang_activate(new_lang);
		} else {
			lang_activate(lang_should_be);
		}
	}

	return lang_get_key();
}