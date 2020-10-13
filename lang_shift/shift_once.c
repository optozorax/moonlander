uint8_t shift_once_disable_stage = 2;
uint8_t shift_once_layer_off = 0;
uint8_t shift_once_layer_current = 0;
uint32_t shift_once_enabled_time = 0;
bool shift_once_can_disable = true;

bool shift_once_is_enabled(void) {
  return shift_once_disable_stage == 2;
}

void shift_once_use_to_next_key(uint8_t layer) {
  if (shift_current == 0) {
    shift_activate_from_user(true);
    layer_on(layer);
    shift_once_disable_stage = 2;
    shift_once_layer_off = layer;
    shift_once_enabled_time = timer_read();
  }
}

void shift_once_process_key(uint8_t layer, bool down) {
  if (down) {
    shift_once_use_to_next_key(layer);
    shift_once_can_disable = false;
  } else {
    shift_once_can_disable = true;
    shift_once_enabled_time = timer_read();
  }
}

void shift_once_disable(void) {
  if (shift_once_disable_stage == 2) {
    layer_off(shift_once_layer_off);
    shift_activate_from_user(false);
    shift_once_disable_stage = 0;
  }
}

void shift_once_process(Key key, keyrecord_t* record) {
  bool down = record->event.pressed;
  
  if (shift_once_disable_stage == 1) {
    shift_once_disable_stage = 0;
    shift_activate_from_user(false);
  }
  if (down && key != SHF_1_O && key != SHF_3_O && shift_once_disable_stage == 2) {
    shift_once_disable_stage = 1;
    layer_off(shift_once_layer_off);
  }
}

void shift_once_user_timer(void) {
  if (shift_once_can_disable && shift_once_is_enabled() && timer_read() - shift_once_enabled_time >= 1000) {
    shift_once_disable();
  }
}
