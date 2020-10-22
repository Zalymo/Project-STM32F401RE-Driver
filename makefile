LIB = ./lib

LIBH = \
	$(LIB)/addrmanip.h \
	$(LIB)/GPIO_MODE_OD.h \
	$(LIB)/STM32F4XX-Local-2.h

LIBC = \
	$(LIB)/addrmanip.c \
	$(LIB)/GPIO_MODE_OD.c

# Let's abstract the compiler to it's own variable so we can swap it out if/when needed
GXX = arm-none-eabi-gcc

# Flags on their own for modularity
CFLAGS = -mcpu=cortex-m4 -g -T stm32_flash.ld -nostdlib -O0

#.PHONY: all
#all: program.o program.elf program.bin

# Create bin file for flashing
program.bin: program.elf
	arm-none-eabi-objcopy -O binary program.elf program.bin

# The final product will depend on all previous compilation steps
program.elf: program.o
	$(GXX) $(CFLAGS) program.o -o program.elf

# The -c flag in gcc means create an object file
program.o: program.s program.c $(LIBH)
	$(GXX) $(CFLAGS) program.s program.c $(LIBC) -o program.o

#.PHONY: clean
clean:
	del /f *.o
	del /f *.elf
	del /f *.bin