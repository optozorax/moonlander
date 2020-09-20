// Newtype pattern allows us wrap some type in that type and use static type-checking
#define NEWTYPE(name, func_name, type, max, none_name) \
  typedef struct name { \
    type repr; \
  } name; \
  \
  const name none_name = ((name){ .repr = max }); \
  \
  type get_ ## func_name(name a) { \
    return a.repr; \
  } \
  \
  bool eq_ ## func_name(name a, name b) { \
    return get_ ## func_name(a) == get_ ## func_name(b); \
  } \
  \
  bool neq_ ## func_name(name a, name b) { \
    return get_ ## func_name(a) != get_ ## func_name(b); \
  }

NEWTYPE(ComboKey, combo_key, uint8_t, 255, NONE_COMBO_KEY)
#define COMBO_KEY(x) ((ComboKey){ .repr = (x) })
// ^ C is weak piece of shit: it can't do #define inside #define, or it can't do const function which we can use inside initialization. So we must write this by hand.

NEWTYPE(ComboPos, combo_pos, uint8_t, 255, NONE_COMBO_POS)
#define COMBO_POS(x) ((ComboPos){ .repr = (x) })