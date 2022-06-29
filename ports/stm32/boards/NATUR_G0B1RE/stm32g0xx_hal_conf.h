/* This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2019 Damien P. George
 */
#ifndef MICROPY_INCLUDED_STM32G0XX_HAL_CONF_H
#define MICROPY_INCLUDED_STM32G0XX_HAL_CONF_H

#define HSE_VALUE                     (8000000)      /*!< Value of the External oscillator in Hz */
#define HSE_STARTUP_TIMEOUT               (100)      /*!< Time out for HSE start up, in ms */
#define HSI_VALUE                    (16000000)      /*!< Value of the Internal oscillator in Hz*/
#define HSI48_VALUE                  (48000000)      /*!< Value of the Internal High Speed oscillator for USB FS/SDMMC/RNG in Hz.
                                                       The real value my vary depending on manufacturing process variations.*/
#define LSI_VALUE                       (32000)      /*!< LSI Typical Value in Hz*/
#define LSE_VALUE                       (32768)      /*!< Value of the External oscillator in Hz*/
#define LSE_STARTUP_TIMEOUT              (5000)      /*!< Time out for LSE start up, in ms */

#include "boards/stm32g0xx_hal_conf_base.h"

#endif // MICROPY_INCLUDED_STM32G0XX_HAL_CONF_H
