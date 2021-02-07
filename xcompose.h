#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom .XCompose keycodes."
#endif

enum custom_xcompose_keycodes {
  CUSTOM_XCOMPOSE_START = CUSTOM_SAFE_RANGE,

  // Letter modifiers
  AC_GRV,  // `
  AC_ACT,  // '
  AC_CIRC, // ^
  AC_TILD, // ~

  // Number modifiers
  AC_SUB,  // _
  AC_SUP,  // ^
  AC_CRCL, // (

  // Greek symbols
  XC_MU,   // µ
  XC_LMBD, // λ
  XC_PI,   // π

  // Math
  XC_NIN,  // ∉
  XC_IN,   // ∈
  XC_SBST, // ⊂
  XC_ANGL, // ∠
  XC_IFAI, // ⇔
  XC_EXST, // ∃
  XC_ALL,  // ∀
  XC_THEN, // ⇒
  XC_PLMN, // ±
  XC_DEGR, // °
  XC_APRX, // ≈
  XC_EMPT, // ∅
  XC_TIMS, // ×
  XC_NEQ,  // ≠
  XC_INF,  // ∞

  // Arrows
  XC_LEFT, // ←
  XC_DOWN, // ↓
  XC_UP,   // ↑
  XC_RGHT, // →

  // Other symbols
  XC_LTRE, // «
  XC_RTRE, // »
  XC_BTRE, // «»◀️
  XC_DASH, // —
  XC_BULL, // •
  XC_LCRN, // ⌜
  XC_RCRN, // ⌟
  XC_BCRN, // ⌜⌟◀️
  XC_MUSC, // ♪
  XC_TM,   // ™
  XC_COPY, // ©

  // Emojis
  XC_CRSS, // ❌
  XC_DONE, // ✅
  XC_SPRK, // ✨
  XC_TMBU, // 👍
  XC_TMBD, // 👎

  CUSTOM_XCOMPOSE_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_XCOMPOSE_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_xcompose(uint16_t keycode, keyrecord_t *record) {
  #define PRESS(X) tap_code16(X);
  #define COMPOSE PRESS(KC_SLCK)
  #define CASE_PROCESS(WHAT, DO) case WHAT: if (record->event.pressed) { COMPOSE DO } return false; break;
  #define XC_PROCESS(WHAT, ...) CASE_PROCESS(WHAT, MAP(TO_NUM, __VA_ARGS__) PRESS(KC_9))
  #define TO_NUM(x) PRESS(KC_ ## x)

  // English-specific codes
  switch (keycode) {
    // Letter modifiers
    CASE_PROCESS(AC_GRV, PRESS(KC_GRV))  // `
    CASE_PROCESS(AC_ACT, PRESS(KC_QUOT))  // '
    CASE_PROCESS(AC_CIRC, PRESS(KC_CIRC)) // ^
    CASE_PROCESS(AC_TILD, PRESS(KC_TILD)) // ~

    // Number modifiers
    CASE_PROCESS(AC_SUB, PRESS(KC_UNDS))  // _
    CASE_PROCESS(AC_SUP, PRESS(KC_CIRC))  // ^
    CASE_PROCESS(AC_CRCL, PRESS(KC_LPRN)) // (

    // Greek symbols
    XC_PROCESS(XC_MU, 0, 1)   // µ
    XC_PROCESS(XC_LMBD, 0, 2) // λ
    XC_PROCESS(XC_PI, 0, 3)   // π

    // Math
    XC_PROCESS(XC_NIN, 0, 4)  // ∉
    XC_PROCESS(XC_IN, 0, 5)   // ∈
    XC_PROCESS(XC_SBST, 0, 6) // ⊂
    XC_PROCESS(XC_ANGL, 0, 7) // ∠
    XC_PROCESS(XC_IFAI, 0, 8) // ⇔
    XC_PROCESS(XC_EXST, 0, 9) // ∃
    XC_PROCESS(XC_ALL, 1, 0)  // ∀
    XC_PROCESS(XC_THEN, 1, 1) // ⇒
    XC_PROCESS(XC_PLMN, 1, 2) // ±
    XC_PROCESS(XC_DEGR, 1, 3) // °
    XC_PROCESS(XC_APRX, 1, 4) // ≈
    XC_PROCESS(XC_EMPT, 1, 5) // ∅
    XC_PROCESS(XC_TIMS, 1, 6) // ×
    XC_PROCESS(XC_NEQ, 1, 7)  // ≠
    XC_PROCESS(XC_INF, 1, 8)  // ∞

    // Arrows
    XC_PROCESS(XC_LEFT, 1, 9) // ←
    XC_PROCESS(XC_DOWN, 2, 0) // ↓
    XC_PROCESS(XC_UP, 2, 1)   // ↑
    XC_PROCESS(XC_RGHT, 2, 2) // →

    // Other symbols
    XC_PROCESS(XC_LTRE, 2, 3) // «
    XC_PROCESS(XC_RTRE, 2, 4) // »
    CASE_PROCESS(XC_BTRE, PRESS(KC_2) PRESS(KC_3) PRESS(KC_9) COMPOSE PRESS(KC_2) PRESS(KC_4) PRESS(KC_9)  PRESS(KC_LEFT)) // «»◀️
    XC_PROCESS(XC_DASH, 2, 5) // —
    XC_PROCESS(XC_BULL, 2, 6) // •
    XC_PROCESS(XC_LCRN, 2, 7) // ⌜
    XC_PROCESS(XC_RCRN, 2, 8) // ⌟
    CASE_PROCESS(XC_BCRN, PRESS(KC_2) PRESS(KC_7) PRESS(KC_9) COMPOSE PRESS(KC_2) PRESS(KC_8) PRESS(KC_9) PRESS(KC_LEFT)) // ⌜⌟◀️
    XC_PROCESS(XC_MUSC, 2, 9) // ♪
    XC_PROCESS(XC_TM, 3, 0)   // ™
    XC_PROCESS(XC_COPY, 3, 1) // ©

    // Emojis
    XC_PROCESS(XC_CRSS, 3, 2) // ❌
    XC_PROCESS(XC_DONE, 3, 3) // ✅
    XC_PROCESS(XC_SPRK, 3, 4) // ✨
    XC_PROCESS(XC_TMBU, 3, 5) // 👍
    XC_PROCESS(XC_TMBD, 3, 6) // 👎
  }
  return true;
}
