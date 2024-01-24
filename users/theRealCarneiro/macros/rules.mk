USER_MACROS_ENABLE ?= yes
ifeq ($(strip $(USER_MACROS_ENABLE)), yes)
	SRC += $(USER_PATH)/macros/macros.c
endif
