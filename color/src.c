extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void set_layer_color(int layer) {
  #define SET_COLOR(H, S, V) hsv.h = H; hsv.s = S; hsv.v = V;

  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t color = pgm_read_byte(&ledmap[layer][i]);
    HSV hsv;

    if (color == COLOR_TRANS) { continue; } else
    if (color == COLOR_LAYER) {
      uint8_t layer = biton32(layer_state);
      if (layer < layermap_size) {
        SET_COLOR(
          pgm_read_byte(&layermap[layer][0]),
          pgm_read_byte(&layermap[layer][1]),
          pgm_read_byte(&layermap[layer][2])
        );
      } else {
        SET_COLOR(0, 0, 0);
      }
    } else if (color < colormap_size) {
      SET_COLOR(
        pgm_read_byte(&colormap[color][0]),
        pgm_read_byte(&colormap[color][1]),
        pgm_read_byte(&colormap[color][2])
      );
    } else {
      SET_COLOR(0, 0, 0);
    }

    RGB rgb = hsv_to_rgb(hsv);
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
  }
}

uint8_t draw_layer = COLOR_PICTURE_DEFAULT;
void color_rgb_matrix_indicators(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  if (draw_layer != 0) {
  	set_layer_color(draw_layer - 1);
  }
}

void color_set_picture(uint8_t picture) {
	draw_layer = picture;
}

bool color_process_record(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case PIC_0: if (record->event.pressed) { color_set_picture(0); } return false;
		case PIC_1: if (record->event.pressed) { color_set_picture(1); } return false;
		case PIC_2: if (record->event.pressed) { color_set_picture(2); } return false;

		case RGB__0: if (record->event.pressed) { rgblight_mode(0); } return false; break;
		case RGB__1: if (record->event.pressed) { rgblight_mode(1); } return false; break;
		case RGB__2: if (record->event.pressed) { rgblight_mode(2); } return false; break;
		case RGB__3: if (record->event.pressed) { rgblight_mode(3); } return false; break;
		case RGB__4: if (record->event.pressed) { rgblight_mode(4); } return false; break;
		case RGB__5: if (record->event.pressed) { rgblight_mode(5); } return false; break;
		case RGB__6: if (record->event.pressed) { rgblight_mode(6); } return false; break;
		case RGB__7: if (record->event.pressed) { rgblight_mode(7); } return false; break;
		case RGB__8: if (record->event.pressed) { rgblight_mode(8); } return false; break;
		case RGB__9: if (record->event.pressed) { rgblight_mode(9); } return false; break;
		case RGB__10: if (record->event.pressed) { rgblight_mode(10); } return false; break;
		case RGB__11: if (record->event.pressed) { rgblight_mode(11); } return false; break;
		case RGB__12: if (record->event.pressed) { rgblight_mode(12); } return false; break;
		case RGB__13: if (record->event.pressed) { rgblight_mode(13); } return false; break;
		case RGB__14: if (record->event.pressed) { rgblight_mode(14); } return false; break;
		case RGB__15: if (record->event.pressed) { rgblight_mode(15); } return false; break;
		case RGB__16: if (record->event.pressed) { rgblight_mode(16); } return false; break;
		case RGB__17: if (record->event.pressed) { rgblight_mode(17); } return false; break;
		case RGB__18: if (record->event.pressed) { rgblight_mode(18); } return false; break;
		case RGB__19: if (record->event.pressed) { rgblight_mode(19); } return false; break;
		case RGB__20: if (record->event.pressed) { rgblight_mode(20); } return false; break;
		case RGB__21: if (record->event.pressed) { rgblight_mode(21); } return false; break;
		case RGB__22: if (record->event.pressed) { rgblight_mode(22); } return false; break;
		case RGB__23: if (record->event.pressed) { rgblight_mode(23); } return false; break;
		case RGB__24: if (record->event.pressed) { rgblight_mode(24); } return false; break;
		case RGB__25: if (record->event.pressed) { rgblight_mode(25); } return false; break;
		case RGB__26: if (record->event.pressed) { rgblight_mode(26); } return false; break;
		case RGB__27: if (record->event.pressed) { rgblight_mode(27); } return false; break;
		case RGB__28: if (record->event.pressed) { rgblight_mode(28); } return false; break;
		case RGB__29: if (record->event.pressed) { rgblight_mode(29); } return false; break;
		case RGB__30: if (record->event.pressed) { rgblight_mode(30); } return false; break;
		case RGB__31: if (record->event.pressed) { rgblight_mode(31); } return false; break;
		case RGB__32: if (record->event.pressed) { rgblight_mode(32); } return false; break;
		case RGB__33: if (record->event.pressed) { rgblight_mode(33); } return false; break;
		case RGB__34: if (record->event.pressed) { rgblight_mode(34); } return false; break;
		case RGB__35: if (record->event.pressed) { rgblight_mode(35); } return false; break;
		case RGB__36: if (record->event.pressed) { rgblight_mode(36); } return false; break;

		case RGB_PRT: 
		if (record->event.pressed) {
			uprintf(
				"enabled: %d, "
				"mode: %d, "
				"HSV: (%d, %d, %d), "
				"speed: %d, "
				"suspend state: %d\n", 
				rgb_matrix_is_enabled(),
				rgb_matrix_get_mode(),
				rgb_matrix_get_hue(),
				rgb_matrix_get_sat(),
				rgb_matrix_get_val(),
				rgb_matrix_get_speed(),
				rgb_matrix_get_suspend_state()
			);
		}
		return false;
		break;
	}

	return true;
}
