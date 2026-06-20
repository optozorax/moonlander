/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"xbJpL/wy5xo"
#define RGB_MATRIX_STARTUP_SPD 60

// Match the timing used by QMK's pre-audio-overhaul implementation.
#define TEMPO_DEFAULT 200

// dac_basic advances playback every two timer ticks. 1000 Hz gives songs a
// 2 ms scheduling resolution instead of firmware25's unusable 200 ms default.
#define AUDIO_STATE_TIMER_FREQUENCY 1000

// firmware20's DAC timer made these sound one octave below their definitions.
#define STARTUP_SONG SONG(E__NOTE(_E5), E__NOTE(_A5), ED_NOTE(_E6))
#define AUDIO_ON_SONG SONG(E__NOTE(_A4), E__NOTE(_A5))
#define AUDIO_OFF_SONG SONG(E__NOTE(_A5), E__NOTE(_A4))

#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

#define LANG_CHANGE_DEFAULT LANG_CHANGE_WIN_SPACE
#define SYSTEM_CURRENT_DEFAULT SYSTEM_WINDOWS

#define COMBO_KEYS_COUNT 50
#define COMBO_MAX_SIZE 4
#define COMBO_STACK_MAX_SIZE 5
#define COMBO_WAIT_TIME 100

#define COLOR_PICTURE_DEFAULT 2

#define DISABLE_DEFAULT_ML_LEDS_LOGIC
#define MOONLANDER_USER_LEDS
