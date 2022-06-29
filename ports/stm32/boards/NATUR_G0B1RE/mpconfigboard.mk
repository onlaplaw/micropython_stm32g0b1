MCU_SERIES = g0
CMSIS_MCU = STM32G0B1xx
AF_FILE = boards/stm32g0b1_af.csv
ifeq ($(USE_MBOOT),1)
# When using Mboot all the text goes together after the filesystem
TEXT0_ADDR = 0x08020000
LD_FILES = boards/stm32g0b1xe.ld boards/common_blifs.ld
else
# When not using Mboot the ISR text goes first, then the rest after the filesystem
LD_FILES = boards/stm32g0b1xe.ld boards/common_basic.ld
TEXT0_ADDR = 0x08000000
TEXT1_ADDR = 0x08020000
endif

# MicroPython settings
MICROPY_VFS_FAT ?= 1

# Don't include default frozen modules because MCU is tight on flash space
FROZEN_MANIFEST ?=
