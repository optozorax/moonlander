#pragma once

// Extend the Moonlander board configuration from the keymap.  The legacy-style
// differential DAC driver uses TIM6 and TIM7 for its two audio channels and
// TIM8 to update playback state.
#include_next <mcuconf.h>

#undef STM32_GPT_USE_TIM7
#define STM32_GPT_USE_TIM7 TRUE

#undef STM32_GPT_USE_TIM8
#define STM32_GPT_USE_TIM8 TRUE
