#pragma once

void press_arbitrary_keycode(uint16_t keycode, bool down, uint8_t col, uint8_t row) {
	keyrecord_t record = {
	  .event = {
	    .key = {
	      .col = col,
	      .row = row,
	      .use_custom_keycode = true,
	      .custom_keycode = keycode,
	    },
	    .pressed = down,
	    .time = timer_read(),
	  },
	};

	process_record(&record);
}
