CUSTOM_RGB_MATRIX_INDICATOR ?= yes
ifeq ($(strip $(CUSTOM_RGB_MATRIX_INDICATOR)), yes)
	SRC += $(USER_PATH)/rgb/rgb_matrix_indicator.c
endif
