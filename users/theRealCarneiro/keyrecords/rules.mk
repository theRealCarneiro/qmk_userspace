USER_KEYRECORDS_ENABLE ?= yes
ifeq ($(strip $(USER_KEYRECORDS_ENABLE)), yes)
	SRC += $(USER_PATH)/keyrecords/keyrecords.c
endif

USER_TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	ifeq ($(strip $(USER_TAP_DANCE_ENABLE)), yes)
		SRC += $(USER_PATH)/keyrecords/tap_dance.c
	endif
endif
