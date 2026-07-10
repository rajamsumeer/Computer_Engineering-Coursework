all:
	arm-none-eabi-gcc systick2.c usart.c startup-systick.c vendor/CMSIS/Device/ST/STM32F3/Source/Templates/system_stm32f3xx.c -T linker_script.ld -o blink.elf -Ivendor/CMSIS/CMSIS/Core/Include -Ivendor/CMSIS/Device/ST/STM32F3/Include -mcpu=cortex-m4 -mthumb -nostdlib -DSTM32F303x8
	arm-none-eabi-objcopy -S -O binary blink.elf blink.bin

flash:
	st-flash write blink.bin 0x08000000

term:
	gtkterm
