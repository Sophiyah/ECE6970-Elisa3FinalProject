###############################################################################
# Makefile for the project Elisa3ECE6970
###############################################################################

## General Flags
PROJECT = Elisa3ECE6970
MCU = atmega2560
TARGET = Elisa3ECE6970.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=Elisa3ECE6970.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Libraries
LIBS = -l\avr6\libm 

## Objects that must be built in order to link
OBJECTS = adc.o behaviors.o eepromIO.o Elisa3ECE6970.o ir_remote_control.o irCommunication.o leds.o mirf.o motors.o ports_io.o sensors.o speed_control.o spi.o twimaster.o usart.o utility.o variables.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) Elisa3ECE6970.hex Elisa3ECE6970.eep Elisa3ECE6970.lss## Compile
adc.o: ../adc.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

behaviors.o: ../behaviors.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

eepromIO.o: ../eepromIO.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Elisa3ECE6970.o: ../Elisa3ECE6970.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ir_remote_control.o: ../ir_remote_control.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

irCommunication.o: ../irCommunication.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

leds.o: ../leds.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

mirf.o: ../mirf.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

motors.o: ../motors.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ports_io.o: ../ports_io.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

sensors.o: ../sensors.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

speed_control.o: ../speed_control.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

spi.o: ../spi.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

twimaster.o: ../twimaster.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

usart.o: ../usart.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

utility.o: ../utility.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

variables.o: ../variables.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) Elisa3ECE6970.elf dep/* Elisa3ECE6970.hex Elisa3ECE6970.eep Elisa3ECE6970.lss Elisa3ECE6970.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

