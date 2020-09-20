typedef uint8_t Lang;
#define NONE_LANG (uint8_t)(255)

Lang lang_should_be = 0;
Lang lang_current = 0;
uint32_t lang_timer = 0;

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
		if (new_lang != NONE_LANG) {
			lang_activate(new_lang);
		} else {
			lang_activate(lang_should_be);
		}
	}

	return lang_get_key(key);
}

void lang_user_timer(void) {
	// Нужно выключать язык после прохождения определённого времени, потому что пользователь ожидает как будто шифт на самом деле включён
  // Но это не работает для случая когда зажата клавиша, так что пока что лучше не трогать это место.
	if (lang_current != lang_should_be && timer_read() - lang_timer >= 100) {
		lang_activate(lang_should_be);
	}
}

#include "custom_lang.c"
// Следующие вещи находятся в файле `custom_lang.c`:
// #define MY_LANG_KEYS - это надо потом вставить в custom_keycodes
// Key lang_get_key(Key key) - возвращает клавишу без языка по данной клавише с языком, если это обычная клавиша, то возвращает -1
// Lang lang_get_lang(Key key) - возвращает какой язык у данной клавиши, если никакой, то -1
