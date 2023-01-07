#pragma once

enum System {
  SYSTEM_LINUX,
  SYSTEM_WINDOWS,
  SYSTEM_MACOS,
};

enum system_keycodes {
  SYSTEM_START = CUSTOM_SAFE_RANGE,

  // Кейкоды, которые включают определённую систему
  SYS_LIN,
  SYS_WIN,
  SYS_MAC,

  // Напечатать текущую систему
  SYS_PRT,

  CUSTOM_SYSTEM_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_SYSTEM_NEW_SAFE_RANGE
};

// Если вы хотите делать ОС-зависимое поведение, то смотрите на эту переменную
enum System system_current = 
#ifdef SYSTEM_CURRENT_DEFAULT
  SYSTEM_CURRENT_DEFAULT;
#else
  #error "You must specify default system by defining variable SYSTEM_CURRENT_DEFAULT."
#endif

bool process_system_keys(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYS_LIN: {system_current = SYSTEM_LINUX; return false; }
    case SYS_WIN: {system_current = SYSTEM_WINDOWS; return false; }
    case SYS_MAC: {system_current = SYSTEM_MACOS; return false; }
    case SYS_PRT: {
      if (record->event.pressed) {
        #define PRESS(x) { register_code(KC_ ## x); unregister_code(KC_ ## x); }
        PRESS(S);
        PRESS(Y);
        PRESS(S);
        PRESS(T);
        PRESS(E);
        PRESS(M);
        register_code(KC_LSHIFT);
        register_code(KC_SCLN);
        unregister_code(KC_SCLN);
        unregister_code(KC_LSHIFT);
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
        switch (system_current) {
          case SYSTEM_LINUX: {
            PRESS(L);
            PRESS(I);
            PRESS(N);
            PRESS(U);
            PRESS(X);
            break;
          }
          case SYSTEM_WINDOWS: {
            PRESS(W);
            PRESS(I);
            PRESS(N);
            PRESS(D);
            PRESS(O);
            PRESS(W);
            PRESS(S);
            break;
          }
          case SYSTEM_MACOS: {
            PRESS(M);
            PRESS(A);
            PRESS(C);
            PRESS(O);
            PRESS(S);
            break;
          }
        }
        register_code(KC_ENTER);
        unregister_code(KC_ENTER);
        #undef PRESS
      }
      return false;
    }
  }
  return true;
}
