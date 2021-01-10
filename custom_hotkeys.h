#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom hotkeys keycodes."
#endif

enum custom_hotkeys_keycodes {
  CUSTOM_HOTKEYS_START = CUSTOM_SAFE_RANGE,

  KG_NEXT,
  F6_CT_C,
  MY_SCRN,
  CT_A_C,
  CT_A_V,
  CT_A_X,
  CT_D,
  CT_SLSH,
  CT_Y,
  KC_LF5,
  KC_RG5,

  CUSTOM_HOTKEYS_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_HOTKEYS_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_hotkeys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KG_NEXT:
      if (record->event.pressed) {
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_LCTRL);
        register_code(KC_RGHT);
        unregister_code(KC_RGHT);
        unregister_code(KC_LCTRL);
      }    
      return false;
      break;
    case F6_CT_C:
      if (record->event.pressed) {
        register_code(KC_F6);
        unregister_code(KC_F6);

        register_code(KC_LCTL);
          register_code(KC_C);
          unregister_code(KC_C);
        unregister_code(KC_LCTL);
      }
      return false;
      break;
    case MY_SCRN:
      if (record->event.pressed) {
        switch (lang_current_change) {
          case LANG_CHANGE_CAPS: {
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_PSCR);
            unregister_code(KC_PSCR);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
          } break;
          case LANG_CHANGE_ALT_SHIFT:
          case LANG_CHANGE_CTRL_SHIFT: {
            register_code(KC_LGUI);
              register_code(KC_LSHIFT);
              register_code(KC_S);
            unregister_code(KC_S);
              unregister_code(KC_LSHIFT);
              unregister_code(KC_LGUI);
          } break;
          case LANG_CHANGE_WIN_SPACE: {
            // No screenshot, maybe it android
          } break;
        } 
      }
      return false;
      break;
    case CT_A_C:
      if (record->event.pressed) {
        shift_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_C);
        unregister_code(KC_C);
        unregister_code(KC_LCTRL);
      }
      return false;
    case CT_A_V:
      if (record->event.pressed) {
        shift_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_V);
        unregister_code(KC_V);
        unregister_code(KC_LCTRL);
      }
      return false;
    case CT_A_X:
      if (record->event.pressed) {
        shift_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_X);
        unregister_code(KC_X);
        unregister_code(KC_LCTRL);
      }
      return false;
    case CT_D:
      if (record->event.pressed) {
        lang_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_D);
        unregister_code(KC_D);
        unregister_code(KC_LCTRL);
      }
      return false;
    case CT_Y:
      if (record->event.pressed) {
        shift_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_Y);
        unregister_code(KC_Y);
        unregister_code(KC_LCTRL);
      }
      return false;
    case CT_SLSH:
      if (record->event.pressed) {
        lang_activate(0);
        register_code(KC_LCTRL);
        register_code(KC_SLSH);
        unregister_code(KC_SLSH);
        unregister_code(KC_LCTRL);
      }
      return false;
  }

  return true;
}