BOOTMAGIC_ENABLE=no
COMMAND_ENABLE=no
SLEEP_LED_ENABLE=no
DEBUG_ENABLE = no
CONSOLE_ENABLE = no
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
