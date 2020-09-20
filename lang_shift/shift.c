typedef uint8_t Shift;
#define NONE_SHIFT (uint8_t)(255)

Shift shift_should_be = 0;
Shift shift_current = 0;
uint32_t shift_timer = 0;

Key shift_get_key(Key key);
Shift shift_get_shift(Key key);

void shift_activate(Shift shift) {
	if (shift_current != shift) {
		shift_timer = timer_read();
		if (shift) {
			register_code(KC_LSHIFT);
		} else {
			unregister_code(KC_LSHIFT);
		}
	}
	shift_current = shift;
}

// Public
void shift_activate_from_user(Shift shift) {
  shift_should_be = shift;
  shift_activate(shift);
}

// Public
Key shift_process(Key key, bool down) {
	Shift new_shift = shift_get_shift(key);
	if (down) {
		if (new_shift != NONE_SHIFT) {
			shift_activate(new_shift);
		} else {
			shift_activate(shift_should_be);
		}
	}

	return shift_get_key(key);
}

void shift_user_timer(void) {
	// Нужно выключать шифт после прохождения определённого времени, потому что пользователь ожидает как будто шифт на самом деле включён
	// Но это не работает для случая когда зажата клавиша, так что пока что лучше не трогать это место.
	if (shift_current != shift_should_be && timer_read() - shift_timer >= 100) {
		shift_activate(shift_should_be);
	}
}

#include "custom_shift.c"
// Следующие вещи находятся в файле `custom_shift.c`:
// #define MY_SHIFT_KEYS - это надо потом вставить в custom_keycodes
// Key shift_get_key(Key key) - возвращает клавишу без шифта по данной клавише с шифтом, если это обычная клавиша, то возвращает -1
// Shift shift_get_shift(Key key) - возвращает какой шифт у данной клавиши, если никакой, то -1
