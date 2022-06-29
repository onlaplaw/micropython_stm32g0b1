/*
    GNU linker script for STM32G0B1xE
*/

/* Specify the memory areas */
MEMORY
{
    FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K /* entire flash */
    FLASH_ISR (rx)  : ORIGIN = 0x08000000, LENGTH = 16K  /* sector 0~7 */
    FLASH_FS (rx)   : ORIGIN = 0x08004000, LENGTH = 112K /* sectors 8~63 are for filesystem */
    FLASH_TEXT (rx) : ORIGIN = 0x08020000, LENGTH = 384K /* sectors 64~255 */
    RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 144K
}

/* produce a link error if there is not this amount of RAM for these sections */
_minimum_stack_size = 2K;
_minimum_heap_size = 16K;

/* Define the stack.  The stack is full descending so begins just above last byte above last byte
   of RAM.  Note that EABI requires the stack to be 8-byte aligned for a call. */
/* RAM extents for the garbage collector */
_ram_start = ORIGIN(RAM);
_ram_end = ORIGIN(RAM) + LENGTH(RAM);

_ram_fs_cache_end = _ram_end;
_ram_fs_cache_start = _ram_fs_cache_end - 10K; /* fs cache = 10K */

_estack = _ram_fs_cache_start - _estack_reserve;
_sstack = _estack - 10K; /* stack = 10K */

_heap_start = _ebss; /* heap starts just after statically allocated memory */
_heap_end = _sstack; /* bss + heap = 52K, tunable by adjusting stack size */

_flash_fs_start = ORIGIN(FLASH_FS);
_flash_fs_end   = ORIGIN(FLASH_FS) + LENGTH(FLASH_FS);
