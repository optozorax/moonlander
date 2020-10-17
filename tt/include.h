#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for lang_shift extension."
#endif

#define TT_KEYS_COUNT 10

enum tt_keycodes {
	TT_START = CUSTOM_SAFE_RANGE,

	#include "keycodes.h"

	TT_NEW_SAFE_RANGE,
	#undef CUSTOM_SAFE_RANGE
	#define CUSTOM_SAFE_RANGE TT_NEW_SAFE_RANGE
};

const uint16_t tt_keys[][3];
const uint8_t tt_size;

uint8_t tt_get_pos(uint16_t key) {
	for (int i = 0; i < tt_size; ++i) {
		if (tt_keys[i][0] == key) {
			return i;
		}
	}
	return 255;
}

uint16_t tt_previous_key = 0;
uint8_t tt_count = 0;
bool tt_now_press = false;
bool tt_process_record(uint16_t key, keyrecord_t *record) {
	if (TT_000 <= key && key < TT_NEW_SAFE_RANGE) {
		uint8_t pos = tt_get_pos(key);
		if (pos != 255) {
			if (key == tt_previous_key) {
				if (record->event.pressed) {
					tt_count += 1;
				}
			} else {
				tt_previous_key = key;
				tt_count = 1;
			}

			tt_now_press = true;
			if (tt_count == 3) {
				if (!record->event.pressed) {
					press_arbitrary_keycode(tt_keys[pos][2], true);
					press_arbitrary_keycode(tt_keys[pos][2], false);
					tt_previous_key = 0;
					tt_count = 0;
				}
			} else {
				press_arbitrary_keycode(tt_keys[pos][1], record->event.pressed);
			}
			tt_now_press = false;

			return false;
		}
	} else {
		if (!tt_now_press) {
			tt_previous_key = 0;
			tt_count = 0;
		}
	}

	return true;
}
