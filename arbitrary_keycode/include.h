#pragma once

void press_arbitrary_keycode(uint16_t keycode, bool down) {
	keyrecord_t record = {
	  .event = {
	    .key = {
	      .col = 255,
	      .row = 0,
	      .use_custom_keycode = true,
	      .custom_keycode = keycode,
	    },
	    .pressed = down,
	    .time = timer_read(),
	  },
	};

	process_record(&record);
}
