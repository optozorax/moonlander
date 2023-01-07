#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom hotkeys keycodes."
#endif

enum custom_hotkeys_keycodes {
  CUSTOM_HOTKEYS_START = CUSTOM_SAFE_RANGE,

  // really custom
  KG_NEXT,
  F6_CT_C, // copy current url in browser
  MY_SCRN,
  CT_A_C,
  CT_A_V,
  CT_A_X,
  AR_L5,
  CS_T,
  CS_K,
  WN_L, // lock computer
  CT_PGUP, // prev tab
  CT_PGDN, // next tab
  MY_HOME,
  MY_END,
  CT_UP,
  CT_DOWN,
  MY_APPS,

  APP_1,
  APP_2,
  APP_3,
  APP_4,
  APP_5,
  APP_6,
  APP_7,
  APP_8,
  APP_9,
  APP_0,


  // for macos: ctrl -> option
  CT_SLSH,
  CT_D,
  CT_Y, // redo
  CT_Z,
  CT_LEFT,
  CT_RGHT,
  CT_BSPC,

  // for macos: ctrl -> cmd
  CT_ENT,
  CT_T,
  CT_W,
  CT_F,
  CT_A,
  CT_S,
  CT_X,
  CT_C,
  CT_V,
  CT_PLUS,
  CT_MINS,

  CUSTOM_HOTKEYS_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_HOTKEYS_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_hotkeys(uint16_t keycode, keyrecord_t *record) {
  #define REG(X) register_code(X);
  #define UNREG(X) unregister_code(X);
  #define PRESS(X) REG(X); UNREG(X);
  #define WITH(X, Y) REG(X); Y; UNREG(X);
  #define CTRL KC_LCTRL
  #define ALT KC_LALT
  #define WIN KC_LGUI
  #define SHIFT KC_LSHIFT
  #define OPTION KC_LOPT
  #define COMMAND KC_LCMD

  uint16_t CTRL_OR_COMMAND = system_current == SYSTEM_MACOS ? COMMAND : CTRL;
  uint16_t CTRL_OR_OPTION = system_current == SYSTEM_MACOS ? OPTION : CTRL;

  switch (keycode) {
    case KG_NEXT:
      if (record->event.pressed) {
        PRESS(KC_TAB);
        PRESS(KC_TAB);
        switch (system_current) {
          case SYSTEM_LINUX:
          case SYSTEM_WINDOWS: {
            WITH(CTRL, { PRESS(KC_RGHT); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(SHIFT, { WITH(CTRL, { PRESS(KC_RGHT); }); });
            break;
          }
        }
      }    
      return false;
      break;
    case F6_CT_C:
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_LINUX:
          case SYSTEM_WINDOWS: {
            PRESS(KC_F6);
            WITH(CTRL, { PRESS(KC_C); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(COMMAND, { PRESS(KC_L); PRESS(KC_C); });
            break;
          }
        }
      }
      return false;
      break;
    case MY_SCRN:
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_LINUX: {
            WITH(CTRL, { WITH(SHIFT, { PRESS(KC_PSCR); }); });
            break;
          }
          case SYSTEM_WINDOWS: {
            WITH(WIN, { WITH(SHIFT, { PRESS(KC_S); }); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(CTRL, { WITH(SHIFT, { WITH(COMMAND, { PRESS(KC_4); }); }); });
            break;
          }
        }
      }
      return false;
      break;
    case CT_A_C:
      if (record->event.pressed) {
        shift_activate(0);
        WITH(CTRL_OR_COMMAND, { PRESS(KC_A); PRESS(KC_C); });
      }
      return false;
    case CT_A_V:
      if (record->event.pressed) {
        shift_activate(0);
        WITH(CTRL_OR_COMMAND, { PRESS(KC_A); PRESS(KC_V); });
      }
      return false;
    case CT_A_X:
      if (record->event.pressed) {
        shift_activate(0);
        WITH(CTRL_OR_COMMAND, { PRESS(KC_A); PRESS(KC_X); });
      }
      return false;
    case AR_L5:
      if (record->event.pressed) {
        PRESS(KC_LEFT);
        PRESS(KC_LEFT);
        PRESS(KC_LEFT);
        PRESS(KC_LEFT);
        PRESS(KC_LEFT);
      }
      return false;
    case CS_T: {
      if (record->event.pressed) {
        WITH(CTRL_OR_COMMAND, { WITH(SHIFT, { PRESS(KC_T); }); });
      }
      return false;
    }
    case CS_K: {
      if (record->event.pressed) {
        WITH(CTRL_OR_COMMAND, { WITH(SHIFT, { PRESS(KC_K); }); });
      }
      return false;
    }
    case WN_L: {
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_WINDOWS:
          case SYSTEM_LINUX: {
            WITH(WIN, { PRESS(KC_L); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(COMMAND, { WITH(CTRL, { PRESS(KC_Q); }); });
            break;
          }
        }
      }
      return false;
    }
    case MY_APPS: {
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_WINDOWS:
          case SYSTEM_LINUX: {
            PRESS(WIN);
            break;
          }
          case SYSTEM_MACOS: {
            WITH(CTRL, { PRESS(KC_UP); });
            break;
          }
        }
      }
      return false;
    }
    case CT_PGUP: {
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_WINDOWS:
          case SYSTEM_LINUX: {
            WITH(CTRL, { PRESS(KC_PGUP); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(SHIFT, { WITH(CTRL, { PRESS(KC_TAB); }); });
            break;
          }
        }
      }
      return false;
    }
    case CT_PGDN: {
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_WINDOWS:
          case SYSTEM_LINUX: {
            WITH(CTRL, { PRESS(KC_PGDN); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(CTRL, { PRESS(KC_TAB); });
            break;
          }
        }
      }
      return false;
    }
    case CT_UP: {
     if (record->event.pressed) {
        REG(CTRL);
        if (system_current == SYSTEM_MACOS) { REG(COMMAND); }
        REG(KC_UP);
      } else {
        UNREG(KC_UP);
        if (system_current == SYSTEM_MACOS) { UNREG(COMMAND); }
        UNREG(CTRL);
      }
      return false;
    }
    case CT_DOWN: {
     if (record->event.pressed) {
        REG(CTRL);
        if (system_current == SYSTEM_MACOS) { REG(COMMAND); }
        REG(KC_DOWN);
      } else {
        UNREG(KC_DOWN);
        if (system_current == SYSTEM_MACOS) { UNREG(COMMAND); }
        UNREG(CTRL);
      }
      return false;
    }
    case MY_HOME: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
          REG(KC_LEFT);
        } else {
          UNREG(KC_LEFT);
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_HOME);
        } else {
          UNREG(KC_HOME);
        }
      }
      return false;
    }
    case MY_END: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
          REG(KC_RGHT);
        } else {
          UNREG(KC_RGHT);
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_END);
        } else {
          UNREG(KC_END);
        }
      }
      return false;
    }
  }

  #define CASE_CTRL_OR_COMMAND_LANG0(CASE, TO_PRESS) \
    case CASE: {\
      if (record->event.pressed) { \
        lang_activate(0); \
        REG(CTRL_OR_COMMAND); \
        REG(TO_PRESS); \
      } else { \
        UNREG(TO_PRESS); \
        UNREG(CTRL_OR_COMMAND); \
      } \
      return false; \
    }

  #define CASE_CTRL_OR_COMMAND(CASE, TO_PRESS) \
    case CASE: {\
      if (record->event.pressed) { \
        REG(CTRL_OR_COMMAND); \
        REG(TO_PRESS); \
      } else { \
        UNREG(TO_PRESS); \
        UNREG(CTRL_OR_COMMAND); \
      } \
      return false; \
    }

  #define CASE_CTRL_OR_OPTION(CASE, TO_PRESS) \
    case CASE: {\
      if (record->event.pressed) { \
        REG(CTRL_OR_OPTION); \
        REG(TO_PRESS); \
      } else { \
        UNREG(TO_PRESS); \
        UNREG(CTRL_OR_OPTION); \
      } \
      return false; \
    }

  #define CASE_APP(CASE, PRESS_LINUX, PRESS_MACOS) \
    case CASE: {\
      if (record->event.pressed) { \
        if (system_current == SYSTEM_MACOS) { \
          PRESS(PRESS_MACOS); \
        } else { \
          WITH(WIN, { PRESS(PRESS_LINUX) }); \
        } \
      } \
      return false; \
    }

  switch (keycode) {
    CASE_CTRL_OR_COMMAND_LANG0(CT_D, KC_D);
    CASE_CTRL_OR_COMMAND_LANG0(CT_Y, KC_Y);
    CASE_CTRL_OR_COMMAND_LANG0(CT_Z, KC_Z);
    CASE_CTRL_OR_COMMAND_LANG0(CT_SLSH, KC_SLSH);
    CASE_CTRL_OR_COMMAND(CT_ENT, KC_ENT)
    CASE_CTRL_OR_COMMAND(CT_T, KC_T)
    CASE_CTRL_OR_COMMAND(CT_W, KC_W)
    CASE_CTRL_OR_COMMAND(CT_S, KC_S)
    CASE_CTRL_OR_COMMAND(CT_F, KC_F)
    CASE_CTRL_OR_COMMAND(CT_A, KC_A)
    CASE_CTRL_OR_COMMAND(CT_X, KC_X)
    CASE_CTRL_OR_COMMAND(CT_C, KC_C)
    CASE_CTRL_OR_COMMAND(CT_V, KC_V)
    CASE_CTRL_OR_COMMAND(CT_PLUS, KC_EQL)
    CASE_CTRL_OR_COMMAND(CT_MINS, KC_MINS)
    CASE_CTRL_OR_OPTION(CT_LEFT, KC_LEFT)
    CASE_CTRL_OR_OPTION(CT_RGHT, KC_RGHT)
    CASE_CTRL_OR_OPTION(CT_BSPC, KC_BSPC)
    CASE_APP(APP_1, KC_1, KC_F13)
    CASE_APP(APP_2, KC_2, KC_F23)
    CASE_APP(APP_3, KC_3, KC_F24)
    CASE_APP(APP_4, KC_4, KC_F16)
    CASE_APP(APP_5, KC_5, KC_F17)
    CASE_APP(APP_6, KC_6, KC_F18)
    CASE_APP(APP_7, KC_7, KC_F19)
    CASE_APP(APP_8, KC_8, KC_F20)
    CASE_APP(APP_9, KC_9, KC_F22)
    CASE_APP(APP_0, KC_0, KC_F21)
  }

  #undef REG
  #undef UNREG
  #undef PRESS
  #undef WITH
  #undef CTRL
  #undef ALT
  #undef WIN
  #undef SHIFT
  #undef OPTION
  #undef COMMAND

  return true;
}