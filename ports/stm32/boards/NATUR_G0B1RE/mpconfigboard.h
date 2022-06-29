#define MICROPY_HW_BOARD_NAME                "NATUR-G0B1RE"
#define MICROPY_HW_MCU_NAME                   "STM32G0B1RE"

#define MICROPY_HW_HAS_FLASH                            (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE        (0)
#define MICROPY_HW_ENABLE_ADC                           (0)
#define MICROPY_HW_SDCARD_SDMMC                         (0)
#define MICROPY_EMIT_THUMB                              (0)
#define MICROPY_EMIT_INLINE_THUMB                       (0)
#define MICROPY_OPT_COMPUTED_GOTO                       (0)
#define MICROPY_PY_USOCKET                              (0)
#define MICROPY_PY_NETWORK                              (0)
#define MICROPY_PY_UPLATFORM                            (0)

// For system clock, enable one source:
//#define MICROPY_HW_CLK_USE_HSI                          (1) // internal rc 16MHz -> PLL = 64MHz.
#define MICROPY_HW_CLK_USE_HSE                          (1) // external crystal -> PLL = 64MHz.
// HSE is 8MHz.
#define MICROPY_HW_CLK_PLLM                 (RCC_PLLM_DIV1)
#define MICROPY_HW_CLK_PLLN                            (16)
#define MICROPY_HW_CLK_PLLP                 (RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ                 (RCC_PLLQ_DIV2)

#define MICROPY_HW_UART_REPL                     PYB_UART_2
#define MICROPY_HW_UART_REPL_BAUD                    115200

// UART config
#define MICROPY_HW_UART1_TX                        (pin_C4)
#define MICROPY_HW_UART1_RX                        (pin_C5)
#define MICROPY_HW_UART2_TX                        (pin_A2)
#define MICROPY_HW_UART2_RX                        (pin_A3)
#define MICROPY_HW_UART3_TX                       (pin_B10)
#define MICROPY_HW_UART3_RX                       (pin_B11)

// SPI buses
#define MICROPY_HW_SPI1_NSS                        (pin_A4)
#define MICROPY_HW_SPI1_SCK                        (pin_A5)
#define MICROPY_HW_SPI1_MISO                       (pin_A6)
#define MICROPY_HW_SPI1_MOSI                       (pin_A7)

// use external SPI flash for storage
#define MICROPY_HW_SPIFLASH_SIZE_BITS     (8 * 1024 * 1024)
#define MICROPY_HW_SPIFLASH_CS                     (pin_C1)
#define MICROPY_HW_SPIFLASH_SCK                    (pin_A0)
#define MICROPY_HW_SPIFLASH_MOSI                   (pin_C3)
#define MICROPY_HW_SPIFLASH_MISO                   (pin_C2)

#define MICROPY_BOARD_EARLY_INIT    NATUR_G0B1RE_board_early_init
void NATUR_G0B1RE_board_early_init(void);

// block device config for SPI flash
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_SPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
)
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol
