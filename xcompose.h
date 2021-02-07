#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom .XCompose keycodes."
#endif

enum custom_xcompose_keycodes {
  CUSTOM_XCOMPOSE_START = CUSTOM_SAFE_RANGE,

  XC_NIN,  // ∉
  XC_IN,   // ∈
  XC_LCRN, // ⌜

  CUSTOM_XCOMPOSE_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_XCOMPOSE_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_xcompose(uint16_t keycode, keyrecord_t *record) {
  // English-specific codes
  switch (keycode) {
    case XC_NIN:
      if (record->event.pressed) {
        lang_activate(0);
        register_code(KC_SLCK); 
        unregister_code(KC_SLCK);
        register_code(KC_N); 
        unregister_code(KC_N);
        register_code(KC_I); 
        unregister_code(KC_I);
        register_code(KC_N); 
        unregister_code(KC_N);
      }
      return false;
      break;
    case XC_IN:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
          register_code(KC_I); 
          unregister_code(KC_I);
          register_code(KC_N); 
          unregister_code(KC_N);
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case XC_LCRN:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
          register_code(KC_SPC); 
          unregister_code(KC_SPC);
          register_code(KC_LBRC); 
          unregister_code(KC_LBRC);
        unregister_code(KC_LGUI);
      }
      return false;
      break;
  }
  return true;
}
