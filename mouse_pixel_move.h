#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for mouse pixel move keycodes."
#endif

enum mouse_pixel_move_keycodes {
  MOUSE_PIXEL_MOVE_START = CUSTOM_SAFE_RANGE,

  MS_DN_1,
  MS_UP_1,
  MS_LF_1,
  MS_RG_1,

  MS_DN10,
  MS_UP10,
  MS_LF10,
  MS_RG10,

  MOUSE_PIXEL_MOVE_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE MOUSE_PIXEL_MOVE_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_mouse_pixel_move(uint16_t keycode, keyrecord_t *record) {
  if (!(MOUSE_PIXEL_MOVE_START < keycode && keycode < MOUSE_PIXEL_MOVE_NEW_SAFE_RANGE)) {
    return true;
  }

  if (!record->event.pressed)
    return false;

  report_mouse_t currentReport = {};
  switch (keycode) {
    case MS_DN_1: currentReport.y = 1; break;
    case MS_UP_1: currentReport.y = -1; break;
    case MS_LF_1: currentReport.x = -1; break;
    case MS_RG_1: currentReport.x = 1; break;

    case MS_DN10: currentReport.y = 10; break;
    case MS_UP10: currentReport.y = -10; break;
    case MS_LF10: currentReport.x = -10; break;
    case MS_RG10: currentReport.x = 10; break;
  }
  host_mouse_send(&currentReport);
  return false;
}
