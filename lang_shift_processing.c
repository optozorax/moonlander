uint8_t shift_once_disable_stage = 2;
uint8_t shift_once_layer_off = 0;
uint8_t shift_once_layer_current = 0;

bool process_record_lang_shift(Key key, keyrecord_t* record) {
  bool down = record->event.pressed;

  if (down) {
    uprintf("\n\n\n----------------------------------------------\n");
    uprintf("      lang current: %d\n", lang_current);
    uprintf("    lang should be: %d\n", shift_should_be);
    uprintf("      lang has key: %d\n", lang_get_key(key) != NONE_KEY);
    uprintf("     lang has lang: %d\n", lang_get_lang(key) != NONE_LANG);
    uprintf("     shift current: %d\n", shift_current);
    uprintf("   shift should be: %d\n", shift_should_be);
    if (lang_get_key(key) != NONE_KEY) {
      uprintf("     shift has key: %d\n", shift_get_key(lang_get_key(key)) != NONE_KEY);
      uprintf("   shift has shift: %d\n", shift_get_shift(lang_get_key(key)) != NONE_SHIFT);
    } else {
      uprintf("     shift has key: %d\n", shift_get_key(key) != NONE_KEY);
      uprintf("   shift has shift: %d\n", shift_get_shift(key) != NONE_SHIFT);
    }
  }

  if (shift_once_disable_stage == 1) {
    uprintf("shf1_o stage 1\n");
    shift_once_disable_stage = 0;
    shift_activate_from_user(false);
  }
  if (key != SHF_1_O && key != SHF_3_O && shift_once_disable_stage == 2) {
    uprintf("shf1_o stage 2\n");
    shift_once_disable_stage = 1;
    layer_off(shift_once_layer_off);
  }

  Key key1 = lang_process(key, down);
  Key key_to_shift = key;
  if (key1 != NONE_KEY) {
    key_to_shift = key1;
  }

  Key key2 = shift_process(key_to_shift, down);
  if (key2 != NONE_KEY) {
    if (down) {
      uprintf("  register!!! %d\n", key2);
      register_code(key2);
    } else {
      uprintf("unregister!!! %d\n", key2);
      unregister_code(key2);
    }
    return false;
  }

  uprintf("this is normal key\n");

  switch (key) {
    case SHF_1_O:
      if (down) {
        uprintf("shf1_o down\n");
        shift_activate_from_user(true);
        layer_on(1);
        shift_once_disable_stage = 2;
        shift_once_layer_off = 1;
      }
      return false;
    case SHF_3_O:
      if (down) {
        uprintf("shf3_o down\n");
        shift_activate_from_user(true);
        layer_on(3);
        shift_once_disable_stage = 2;
        shift_once_layer_off = 3;
      }
      return false;
    case SHF_1:
      if (down) {
        uprintf("shf1 down\n");
        shift_activate_from_user(true);
        layer_on(1);
      } else {
        uprintf("shf2 down\n");
        shift_activate_from_user(false);
        layer_off(1);
      }
      return false;
    case SHF_3:
      if (down) {
        shift_activate_from_user(true);
        layer_on(3);
      } else {
        shift_activate_from_user(false);
        layer_off(3);
      }
      return false;
    case MY_LANG:
      if (down) {
        if (lang_should_be == 0) {
          uprintf("my_lang to 2\n");
          lang_activate_from_user(1);
          layer_on(2);  
        } else {
          uprintf("my_lang to 0\n");
          lang_activate_from_user(0);
          layer_off(2);
        }
      }
      return false;
    case SYNC_LA:
      if (down) {
        lang_synchronize();
      }
      return false;
  }

  return true;
}