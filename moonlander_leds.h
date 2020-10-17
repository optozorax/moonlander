#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for moonlander leds keycodes."
#endif

enum moonlander_leds_keycodes {
  MOONLANDER_LEDS_START = CUSTOM_SAFE_RANGE,

  LED_1,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,

  MOONLANDER_LEDS_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE MOONLANDER_LEDS_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_moonlander_leds(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LED_1: if (record->event.pressed) { ML_LED_1(true); } else { ML_LED_1(false); } return false; break;
    case LED_2: if (record->event.pressed) { ML_LED_2(true); } else { ML_LED_2(false); } return false; break;
    case LED_3: if (record->event.pressed) { ML_LED_3(true); } else { ML_LED_3(false); } return false; break;
    case LED_4: if (record->event.pressed) { ML_LED_4(true); } else { ML_LED_4(false); } return false; break;
    case LED_5: if (record->event.pressed) { ML_LED_5(true); } else { ML_LED_5(false); } return false; break;
    case LED_6: if (record->event.pressed) { ML_LED_6(true); } else { ML_LED_6(false); } return false; break;
  }

  return true;
}
