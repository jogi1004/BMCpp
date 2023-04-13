# ~/.local/bin/pymcuprog write --erase -d avr128db64 -t uart -u /dev/ttyUSB0 -f test10.hex

CPPFLAGS += -DF_CPU=4000000

targets = test00.s test00.elf 
targets += test01.s test01.elf 
targets += test10.s test10.hex test10.elf 
targets += test11.s test11.hex test11.elf 
targets += test12.s test12.hex test12.elf
targets += test13.s test13.hex test13.elf
targets += test14.s test14.hex test14.elf
targets += test20.s test20.hex test20.elf
targets += test21.s test21.hex test21.elf

all: $(targets)

#test00.elf: test00.cc

#test00.s: test00.cc

include ../make/Makefile.include

-include *.d
