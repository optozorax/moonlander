#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom lang keycodes."
#endif

enum custom_lang_keycodes {
  CUSTOM_LANG_START = CUSTOM_SAFE_RANGE,

  EN_LTEQ, // <=
  EN_GTEQ, // >=
  EN_ARR1, // ->
  EN_ARR2, // =>
  EN_FISH, // ::<>()◀️◀️◀️
  EN_MACR, // #[]◀️

  CUSTOM_LANG_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_LANG_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_lang_keys(uint16_t keycode, keyrecord_t *record) {
  // English-specific codes
  switch (keycode) {
    case EN_LTEQ:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case EN_GTEQ:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_GT);
        lang_shift_tap_key(AG_EQL);
      }
      return false;
      break;
    case EN_ARR1:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_MINS);
        lang_shift_tap_key(EN_GT);
      }
      return false;
      break;
    case EN_ARR2:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_EQL);
        lang_shift_tap_key(EN_GT);
      }
      return false;
      break;
    case EN_FISH:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(EN_GT);
        lang_shift_tap_key(EN_LPRN);
        lang_shift_tap_key(EN_RPRN);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_MACR:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_HASH);
        lang_shift_tap_key(EN_LBRC);
        lang_shift_tap_key(EN_RBRC);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
  }
  return true;
}
