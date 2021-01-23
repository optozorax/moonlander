#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for songs keycodes."
#endif

enum songs_keycodes {
  SONGS_START = CUSTOM_SAFE_RANGE,

  MU_LANG,
  MU_LAN1,
  MU_LAN2,
  MU_LAN3,
  MU_LAN4,
  MU_CTJ,
  MU_SCR,
  MU_WNL,

  SONGS_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE SONGS_NEW_SAFE_RANGE
};

// Музыка обязательно должна находиться вне функции, потому что она проигрывается асинхронно...
float my_song1[][2] = SONG(QWERTY_SOUND);
float my_song2[][2] = SONG(PLANCK_SOUND);
float my_song3[][2] = SONG(AG_SWAP_SOUND);
float my_song4[][2] = SONG(VIOLIN_SOUND);
float my_song5[][2] = SONG(GUITAR_SOUND);
float my_song6[][2] = SONG(CHROMATIC_SOUND);

// Эта функция должна находиться самой последней по приоритету
bool process_my_music_keys(uint16_t keycode, keyrecord_t *record) {
  // https://github.com/qmk/qmk_firmware/blob/master/quantum/audio/song_list.h
  // https://docs.qmk.fm/#/feature_audio

  static bool disable_music = false;

  if (disable_music)
    return true;

  #define MUSIC_KEYCODE(FROM, TO, SONG) \
    case FROM: \
      if (record->event.pressed) { \
        PLAY_SONG(SONG); \
        disable_music = true; \
        press_arbitrary_keycode(TO, true); \
        disable_music = false; \
      } else { \
        disable_music = true; \
        press_arbitrary_keycode(TO, false); \
        disable_music = false; \
      } \
      return false; \
      break;

  switch (keycode) {
    MUSIC_KEYCODE(MU_LANG, LA_CHNG, my_song1)
    MUSIC_KEYCODE(MU_LAN1, LA_CAPS, my_song2)
    MUSIC_KEYCODE(MU_LAN2, LA_ALSH, my_song4)
    MUSIC_KEYCODE(MU_LAN3, LA_CTSH, my_song5)
    MUSIC_KEYCODE(MU_LAN4, LA_WISP, my_song6)
    MUSIC_KEYCODE(MU_CTJ, TT_CTJ, my_song3)
    MUSIC_KEYCODE(MU_SCR, MY_SCRN, my_song3)
    MUSIC_KEYCODE(MU_WNL, WN_L, my_song3)

    case TG(4):
    case TG(5):
    case TG(6):
    case TG(7):
    case TG(8):
    MUSIC_KEYCODE(TG(9), keycode, my_song6)
  }

  return true;
}
