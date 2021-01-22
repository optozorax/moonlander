#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for lang_shift extension."
#endif

#define RP_TO_REPEAT_TIME 300
#define RP_REPEAT_PERIOD 5
#define RP_MAX_KEYS_SIZE 4

enum rp_keycodes {
	RP_START = CUSTOM_SAFE_RANGE,

	RP_000,
	RP_001,
	RP_002,
	RP_003,
	RP_004,
	RP_005,
	RP_006,
	RP_007,
	RP_008,
	RP_009,
	RP_010,
	RP_011,

	RP_NEW_SAFE_RANGE,
	#undef CUSTOM_SAFE_RANGE
	#define CUSTOM_SAFE_RANGE RP_NEW_SAFE_RANGE
};

const uint16_t repeat_keys[][2];
const uint8_t repeat_size;
void repeated_key_error(void);

uint8_t rp_get_pos(uint16_t key) {
	for (int i = 0; i < repeat_size; ++i) {
		if (repeat_keys[i][0] == key) {
			return i;
		}
	}
	return 255;
}

typedef struct RepeatedKey {
	uint16_t key;
	uint16_t to_repeat;
	uint32_t start_time;
	bool is_wait;
} RepeatedKey;

RepeatedKey repeated_keys_stack[RP_MAX_KEYS_SIZE] = {};
uint8_t repeated_keys_size = 0;

uint8_t rp_get_pos_in_stack(uint16_t key) {
	for (int i = 0; i < repeated_keys_size; ++i) {
		if (repeated_keys_stack[i].key == key) {
			return i;
		}
	}
	return 255;
}

bool rp_process_record(uint16_t key, keyrecord_t *record) {
	if (RP_000 <= key && key < RP_NEW_SAFE_RANGE) {
		uint8_t pos = rp_get_pos(key);
		if (pos != 255) {
			if (record->event.pressed) {
				if (repeated_keys_size != RP_MAX_KEYS_SIZE) {
					RepeatedKey* repeated_key = &repeated_keys_stack[repeated_keys_size];
					repeated_keys_size++;
					repeated_key->key = key;
					repeated_key->to_repeat = repeat_keys[pos][1];
					repeated_key->start_time = timer_read();
					repeated_key->is_wait = true;
					press_arbitrary_keycode(repeated_key->to_repeat, true);
					press_arbitrary_keycode(repeated_key->to_repeat, false);
				} else {
					repeated_key_error();
				}
			} else {
				uint8_t pos_in_stack = rp_get_pos_in_stack(key);
				if (pos_in_stack != 255) {
					repeated_keys_size--;
					
					for (uint8_t i = pos_in_stack; i < repeated_keys_size; ++i) {
						repeated_keys_stack[i] = repeated_keys_stack[i+1];
					}
				} else {
					repeated_key_error();
				}
			}
			return false;
		}
	}
	return true;
}

void rp_timer(void) {
	for (int i = 0; i < repeated_keys_size; ++i) {
		RepeatedKey* repeated_key = &repeated_keys_stack[i];
		uint32_t current_time = timer_read();
		bool press = false;
		if (repeated_key->is_wait) {
			if (current_time - repeated_key->start_time >= RP_TO_REPEAT_TIME) {
				press = true;
				repeated_key->is_wait = false;
			}
		} else {
			if (current_time - repeated_key->start_time >= RP_REPEAT_PERIOD) {
				press = true;
			}
		}
		if (press) {
			repeated_key->start_time = current_time;
			press_arbitrary_keycode(repeated_key->to_repeat, true);
			press_arbitrary_keycode(repeated_key->to_repeat, false);
		}
	}
}