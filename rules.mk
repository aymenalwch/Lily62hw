BOARD = GENERIC_RP_RP2040
# LTO_ENABLE = yes            # Link Time Optimization enabled
SERIAL_DRIVER = vendor
SPLIT_KEYBOARD = yes

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
AUDIO_ENABLE = no           # Audio output
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
NKRO_ENABLE = yes           # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
WS2812_DRIVER = vendor
VELOCIKEY_ENABLE = yes


OLED_ENABLE = yes           # OLED display
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c
OLED_DISPLAY_128X64 = true


# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./lib/host_led_state_reader.c \
        ./lib/timelogger.c \
		./lib/mode_icon_reader.c \
