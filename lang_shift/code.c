enum lang_shift_ceycodes {
	LANG_SHIFT_START = ML_SAFE_RANGE,

	#include "keycodes/lang.h"
	#include "keycodes/shift.h"
	#include "keycodes/lang_shift_processing.h"

	LANG_SHIFT_NEW_SAFE_RANGE,
};

#undef ML_SAFE_RANGE
#define ML_SAFE_RANGE LANG_SHIFT_NEW_SAFE_RANGE

typedef uint16_t Key;
#define NONE_KEY (uint16_t)(65535)

#include "shift.c"
#include "lang.c"

#include "shift_once.c"
#include "lang_shift_processing.c"