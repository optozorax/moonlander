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
// firmware20's Moonlander DAC driver played every declared frequency one octave
// lower. Keep that sound while using firmware25's corrected audio driver.
float my_song1[][2] = SONG(E__NOTE(_GS5), E__NOTE(_A5), S__NOTE(_REST), Q__NOTE(_E6));
float my_song2[][2] = SONG(ED_NOTE(_E6), E__NOTE(_CS6), E__NOTE(_E5), E__NOTE(_A5), M__NOTE(_CS6, 20));
float my_song3[][2] = SONG(SD_NOTE(_B4), SD_NOTE(_A4), SD_NOTE(_B4), SD_NOTE(_A4));
float my_song4[][2] = SONG(Q__NOTE(_G4), Q__NOTE(_D5), Q__NOTE(_A5), Q__NOTE(_E6));
float my_song5[][2] = SONG(Q__NOTE(_E4), Q__NOTE(_A4), Q__NOTE(_D5), Q__NOTE(_G5));
float my_song6[][2] = SONG(Q__NOTE(_A4), Q__NOTE(_AS4), Q__NOTE(_B4), Q__NOTE(_C5), Q__NOTE(_CS5));

// Эта функция должна обрабатываться первой в process_record_user: клавиши MU_*
// нужно перехватить раньше combo/lang_shift, иначе те могут их проглотить.
bool process_my_music_keys(uint16_t keycode, keyrecord_t *record) {
  // https://github.com/qmk/qmk_firmware/blob/master/quantum/audio/song_list.h
  // https://docs.qmk.fm/#/feature_audio

  // Счётчик, а не bool: press_arbitrary_keycode переоткрывает весь
  // process_record, и цель (TO) сама может оказаться музыкальной клавишей,
  // поэтому защита от повторного входа должна выдерживать вложенность.
  static uint8_t music_depth = 0;

  if (music_depth > 0)
    return true;

  #define MUSIC_KEYCODE(FROM, TO, SONG) \
    case FROM: \
      if (record->event.pressed) { \
        PLAY_SONG(SONG); \
        music_depth++; \
        press_arbitrary_keycode(TO, true); \
        music_depth--; \
      } else { \
        music_depth++; \
        press_arbitrary_keycode(TO, false); \
        music_depth--; \
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
