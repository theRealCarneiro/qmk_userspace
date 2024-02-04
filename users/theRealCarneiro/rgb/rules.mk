CUSTOM_RGB_MATRIX ?= yes
CUSTOM_RGB_MATRIX_INDICATOR ?= yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	ifeq ($(strip $(CUSTOM_RGB_MATRIX)), yes)
		SRC += $(USER_PATH)/rgb/rgb_matrix_stuff.c
	endif

	ifeq ($(strip $(CUSTOM_RGB_MATRIX_INDICATOR)), yes)
		SRC += $(USER_PATH)/rgb/rgb_matrix_indicator.c
	endif
endif
