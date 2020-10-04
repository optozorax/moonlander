/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"xbJpL/wy5xo"
#define RGB_MATRIX_STARTUP_SPD 60

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

#define LANG_CHANGE_DEFAULT LANG_CHANGE_CAPS

#define COMBO_KEYS_COUNT 50
#define COMBO_MAX_SIZE 3
#define COMBO_STACK_MAX_SIZE 3
#define COMBO_WAIT_TIME 100
#define COMBO_COUNT 75

#define COLOR_PICTURES_COUNT 2
#define COLOR_COLORS_COUNT 9
#define COLOR_LAYERS_COUNT 9
#define COLOR_PICTURE_DEFAULT 2

#define DISABLE_DEFAULT_ML_LEDS_LOGIC