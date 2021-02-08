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
  EN_CLTG, // </
  AG2COLN, // ::
  AG2SLSH, // //⎵
  EN2QUOT, // ''◀️
  AG2DQUO, // ""◀️
  EN2AMPR, // &&
  EN2PIPE, // ||
  EN_HOME, // ~/
  AG_2B1,  // ()◀️
  EN_2B2,  // []◀️
  EN_2B3,  // {}◀️
  EN_2B4,  // <>◀️
  AG_CMNT, // /* ⎵ ⎵ */◀️◀️◀️

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
    case EN_CLTG:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(AG_SLSH);
      }
      return false;
      break;
    case AG2COLN:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_COLN);
        lang_shift_tap_key(AG_COLN);
      }
      return false;
      break;
    case AG2SLSH:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_SLSH);
        lang_shift_tap_key(AG_SLSH);
        register_code(KC_SPC); unregister_code(KC_SPC);
      }
      return false;
      break;
    case EN2QUOT:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_QUOT);
        lang_shift_tap_key(EN_QUOT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case AG2DQUO:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_DQUO);
        lang_shift_tap_key(AG_DQUO);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN2AMPR:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_AMPR);
        lang_shift_tap_key(EN_AMPR);
      }
      return false;
      break;
    case EN2PIPE:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_PIPE);
        lang_shift_tap_key(EN_PIPE);
      }
      return false;
      break;
    case EN_HOME:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_TILD);
        lang_shift_tap_key(AG_SLSH);
      }
      return false;
      break;
    case AG_2B1:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_LPRN);
        lang_shift_tap_key(AG_RPRN);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B2:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LBRC);
        lang_shift_tap_key(EN_RBRC);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B3:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LCBR);
        lang_shift_tap_key(EN_RCBR);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case EN_2B4:
      if (record->event.pressed) {
        lang_shift_tap_key(EN_LT);
        lang_shift_tap_key(EN_GT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
    case AG_CMNT:
      if (record->event.pressed) {
        lang_shift_tap_key(AG_SLSH);
        lang_shift_tap_key(AG_ASTR);
        register_code(KC_SPC); unregister_code(KC_SPC);
        register_code(KC_SPC); unregister_code(KC_SPC);
        lang_shift_tap_key(AG_ASTR);
        lang_shift_tap_key(AG_SLSH);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
        register_code(KC_LEFT); unregister_code(KC_LEFT);
      }
      return false;
      break;
  }
  return true;
}
