#include "custom_shift.c"
// Следующие вещи находятся в файле `custom_shift.c`:
// #define MY_SHIFT_KEYS - это надо потом вставить в custom_keycodes
// Key shift_get_key(Key key) - возвращает клавишу без шифта по данной клавише с шифтом, если это обычная клавиша, то возвращает -1
// Shift shift_get_shift(Key key) - возвращает какой шифт у данной клавиши, если никакой, то -1

typedef bool Shift;
typedef uint16_t Key;

Shift shift_should_be = 0;
Shift shift_current = 0;
uint32_t shift_timer = 0;

void shift_activate(Shift shift) {
	if (shift_current != shift) {
		shift_timer = timer_read();
		if (shift) {
			unregister_code(KC_LSHIFT);
		} else {
			register_code(KC_LSHIFT);
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
		if (new_shift != -1) {
			shift_activate(new_shift);
		} else {
			shift_activate(shift_should_be);
		}
	}

	return shift_get_key();
}

void shift_user_timer() {
	// Нужно выключать шифт после прохождения определённого времени, потому что пользователь ожидает как будто шифт на самом деле включён
	if (shift_current != shift_should_be && timer_read() - shift_timer >= 50) {
		shift_activate(shift_should_be);
	}
}