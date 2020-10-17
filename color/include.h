#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for color extension."
#endif

enum color_keycodes {
	COLOR_START = CUSTOM_SAFE_RANGE,

	// Все известные режимы подсветки
	RGB__0,
	RGB__1,
	RGB__2,
	RGB__3,
	RGB__4,
	RGB__5,
	RGB__6,
	RGB__7,
	RGB__8,
	RGB__9,
	RGB__10,
	RGB__11,
	RGB__12,
	RGB__13,
	RGB__14,
	RGB__15,
	RGB__16,
	RGB__17,
	RGB__18,
	RGB__19,
	RGB__20,
	RGB__21,
	RGB__22,
	RGB__23,
	RGB__24,
	RGB__25,
	RGB__26,
	RGB__27,
	RGB__28,
	RGB__29,
	RGB__30,
	RGB__31,
	RGB__32,
	RGB__33,
	RGB__34,
	RGB__35,
	RGB__36,

	// Дебаг текущего состояния подсветки
	RGB_PRT,

	// Покажать картинку под определённым номером
	PIC_0, // Отсутствие картинки

	// Картинки пользователя
	PIC_1,
	PIC_2,
	// TODO сделать чтобы было больше картинок

	COLOR_NEW_SAFE_RANGE,
	#undef CUSTOM_SAFE_RANGE
	#define CUSTOM_SAFE_RANGE COLOR_NEW_SAFE_RANGE
};

// Для рисования картинок
enum custom_ledmap_colors {
  COLOR_TRANS, // Прозрачный, пропускает обычную подсветку
  COLOR_LAYER, // Цвет текущего слоя
  COLOR_SAFE_RANGE, // Далее для создания своего цвета нужно начинать с этого промежутка
};

#define ___________ COLOR_TRANS

// Для рисования картинок
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL];
const uint8_t ledmap_size;

// Использованные цвета в картинках
const uint8_t PROGMEM colormap[][3];
const uint8_t colormap_size;

// Цвета для каждого слоя
const uint8_t PROGMEM layermap[][3];
const uint8_t layermap_size;

void color_rgb_matrix_indicators(void);
bool color_process_record(uint16_t keycode, keyrecord_t *record);

// Инклюжу код напрямую, потому что нельзя сделать линковку, ведь код внутри использует кейкоды отсюда, и обязательно нужно это делать через safe_range
#include "src.c"
