# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
COMMAND_ENABLE = no
WEBUSB_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
AUDIO_DRIVER = dac_basic

# Automouse needs QMK's pointing-device task for timeout housekeeping. The
# Navigator itself reports through the digitizer path, so no sensor driver is
# needed here.
POINTING_DEVICE_DRIVER = custom
CONSOLE_ENABLE = yes
POINTING_DEVICE_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
