/* Define the end of RAM and limit of stack memory */
/* (4KB SRAM on the STM32F303k8 line, 4096 = 0x1000) */
/* (RAM starts at address 0x20000000) */
_estack = 0x20003000;

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 64K
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 12K
}