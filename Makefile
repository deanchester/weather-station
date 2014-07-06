CC=avr-gcc
HEX_MAKER=avr-objcopy


MMCU=atmega16
DEV=/dev/cu.usbserial
PART=m16
PROGRAMMER=stk500

FILENAME=weather
BUILD_DIR=target
SRC_DIR=src

all: build | install

hex: elf $(BUILD_DIR)/$(FILENAME).elf
	$(HEX_MAKER) -O ihex $(BUILD_DIR)/$(FILENAME).elf $(BUILD_DIR)/$(FILENAME).hex

elf: mkTarget $(SRC_DIR)/$(FILENAME).c $(SRC_DIR)/uart.c
	$(CC)  $(SRC_DIR)/uart.c $(SRC_DIR)/$(FILENAME).c -o $(BUILD_DIR)/$(FILENAME).elf -mmcu=$(MMCU)

mkTarget:
	mkdir -p $(BUILD_DIR)

build: hex

install: 
	avrdude -p $(PART) -c $(PROGRAMMER) -P $(DEV) -e -U flash:w:$(BUILD_DIR)/$(FILENAME).hex -U lfuse:w:0xe0:m -U hfuse:w:0xd9:m

clean: 
	rm -rf target

