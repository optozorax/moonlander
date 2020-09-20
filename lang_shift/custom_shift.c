Key shift_get_key(Key key) {
  switch (key) {
    case KS_GRV:  return KC_GRV;
    case KS_TILD: return KC_GRV;
    case KS_1:    return KC_1;
    case KS_EXCL: return KC_1;
    case KS_2:    return KC_2;
    case KS_AT:   return KC_2;
    case KS_3:    return KC_3;
    case KS_HASH: return KC_3;
    case KS_4:    return KC_4;
    case KS_DLR:  return KC_4;
    case KS_5:    return KC_5;
    case KS_PERC: return KC_5;
    case KS_6:    return KC_6;
    case KS_CIRC: return KC_6;
    case KS_7:    return KC_7;
    case KS_AMPR: return KC_7;
    case KS_8:    return KC_8;
    case KS_ASTR: return KC_8;
    case KS_9:    return KC_9;
    case KS_LPRN: return KC_9;
    case KS_0:    return KC_0;
    case KS_RPRN: return KC_0;
    case KS_MINS: return KC_MINS;
    case KS_UNDS: return KC_MINS;
    case KS_EQL:  return KC_EQL;
    case KS_PLUS: return KC_EQL;
    case KS_Q:    return KC_Q;
    case KS_S_Q:  return KC_Q;
    case KS_W:    return KC_W;
    case KS_S_W:  return KC_W;
    case KS_E:    return KC_E;
    case KS_S_E:  return KC_E;
    case KS_R:    return KC_R;
    case KS_S_R:  return KC_R;
    case KS_T:    return KC_T;
    case KS_S_T:  return KC_T;
    case KS_Y:    return KC_Y;
    case KS_S_Y:  return KC_Y;
    case KS_U:    return KC_U;
    case KS_S_U:  return KC_U;
    case KS_I:    return KC_I;
    case KS_S_I:  return KC_I;
    case KS_O:    return KC_O;
    case KS_S_O:  return KC_O;
    case KS_P:    return KC_P;
    case KS_S_P:  return KC_P;
    case KS_LBRC: return KC_LBRC;
    case KS_LCBR: return KC_LBRC;
    case KS_RBRC: return KC_RBRC;
    case KS_RCBR: return KC_RBRC;
    case KS_A:    return KC_A;
    case KS_S_A:  return KC_A;
    case KS_S:    return KC_S;
    case KS_S_S:  return KC_S;
    case KS_D:    return KC_D;
    case KS_S_D:  return KC_D;
    case KS_F:    return KC_F;
    case KS_S_F:  return KC_F;
    case KS_G:    return KC_G;
    case KS_S_G:  return KC_G;
    case KS_H:    return KC_H;
    case KS_S_H:  return KC_H;
    case KS_J:    return KC_J;
    case KS_S_J:  return KC_J;
    case KS_K:    return KC_K;
    case KS_S_K:  return KC_K;
    case KS_L:    return KC_L;
    case KS_S_L:  return KC_L;
    case KS_SCLN: return KC_SCLN;
    case KS_COLN: return KC_SCLN;
    case KS_QUOT: return KC_QUOT;
    case KS_DQUO: return KC_QUOT;
    case KS_BSLS: return KC_BSLS;
    case KS_PIPE: return KC_BSLS;
    case KS_Z:    return KC_Z;
    case KS_S_Z:  return KC_Z;
    case KS_X:    return KC_X;
    case KS_S_X:  return KC_X;
    case KS_C:    return KC_C;
    case KS_S_C:  return KC_C;
    case KS_V:    return KC_V;
    case KS_S_V:  return KC_V;
    case KS_B:    return KC_B;
    case KS_S_B:  return KC_B;
    case KS_N:    return KC_N;
    case KS_S_N:  return KC_N;
    case KS_M:    return KC_M;
    case KS_S_M:  return KC_M;
    case KS_COMM: return KC_COMM;
    case KS_LT:   return KC_COMM;
    case KS_DOT:  return KC_DOT;
    case KS_GT:   return KC_DOT;
    case KS_SLSH: return KC_SLSH;
    case KS_QUES: return KC_SLSH;

    default: return NONE_KEY;
  }
}

Shift shift_get_shift(Key key) {
  if (KS_GRV <= key && key <= KS_QUES) {
    return (key - KS_GRV) % 2;
  } else {
    return NONE_SHIFT;
  }
}
