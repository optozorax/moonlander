/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"xbJpL/wy5xo"
#define RGB_MATRIX_STARTUP_SPD 60

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

#define LANG_CHANGE_DEFAULT LANG_CHANGE_WIN_SPACE
#define SYSTEM_CURRENT_DEFAULT SYSTEM_MACOS

#define COMBO_KEYS_COUNT 50
#define COMBO_MAX_SIZE 4
#define COMBO_STACK_MAX_SIZE 5
#define COMBO_WAIT_TIME 100

#define COLOR_PICTURE_DEFAULT 2

#define DISABLE_DEFAULT_ML_LEDS_LOGIC
