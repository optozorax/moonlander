Key lang_get_key(Key key) {
  if (EN_GRV <= key && key <= EN_QUES) {
    return (key - EN_GRV) + KS_GRV;
  } else if (RU_JO <= key && key <= RU_COMM) {
    return (key - RU_JO) + KS_GRV;
  } else {
    return NONE_KEY;
  }
}

Lang lang_get_lang(Key key) {
  if (EN_GRV <= key && key <= EN_QUES) {
    return 0;
  } else if (RU_JO <= key && key <= RU_COMM) {
    return 1;
  } else {
    return NONE_LANG;
  }
}
