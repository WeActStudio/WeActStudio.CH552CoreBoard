TARGET = 01-Blink

FREQ_SYS = 24000000

EXTERNAL_CRYSTAL = 1

XRAM_SIZE = 0x0400
XRAM_LOC = 0x0400

C_FILES = \
	App/main.c \
	App/time.c \
	include/debug.c

INCLUDE_DIR = \
	include/ 

ASM_FILES = 

BUILD_DIR = build

EXTRA_FLAGS = 

pre-flash:

#######################################################

# toolchain
CC = sdcc
OBJCOPY = objcopy
PACK_HEX = packihx
WCHISP ?= wchisptool -g -f

ifeq ($(OS),Windows_NT)
RM = del /F /Q
else
RM = rm -fR
endif

#######################################################

EXTERNAL_CRYSTAL ?= 0

FREQ_SYS ?= 24000000

XRAM_SIZE ?= 0x0400

XRAM_LOC ?= 0x0000

CODE_SIZE ?= 0x4000

ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CFLAGS := -V -mmcs51 --model-small \
	--xram-size $(XRAM_SIZE) --xram-loc $(XRAM_LOC) \
	--code-size $(CODE_SIZE) \
	-I$(ROOT_DIR)$(INCLUDE_DIR) -DFREQ_SYS=$(FREQ_SYS) -DEXTERNAL_CRYSTAL=$(EXTERNAL_CRYSTAL) \
	$(EXTRA_FLAGS)

LFLAGS := $(CFLAGS)

RELS := $(C_FILES:.c=.rel)

print-%  : ; @echo $* = $($*)

ifeq ($(BUILD_DIR),) 
BUILD_FLAG = 
BUILDDIR=
else
BUILDDIR=$(BUILD_DIR)/
BUILD_FLAG = -o $(BUILDDIR)
$(BUILD_DIR):
	mkdir $@
endif

%.rel : %.c
	$(CC) -c $(CFLAGS) $(BUILD_FLAG) $<

# Note: SDCC will dump all of the temporary files into this one, so strip the paths from RELS
# For now, get around this by stripping the paths off of the RELS list.

$(TARGET).ihx: $(RELS)
	$(CC) $(patsubst %,$(BUILDDIR)%,$(notdir $(RELS))) $(LFLAGS) -o $(BUILD_DIR)/$(TARGET).ihx

$(TARGET).hex: $(TARGET).ihx
	$(PACK_HEX) $(BUILD_DIR)/$(TARGET).ihx > $(TARGET).hex

$(TARGET).bin: $(TARGET).ihx
	$(OBJCOPY) -I ihex -O binary $(BUILD_DIR)/$(TARGET).ihx $(TARGET).bin
	
flash: $(TARGET).bin pre-flash
	$(WCHISP) $(TARGET).bin

.DEFAULT_GOAL := all
all: $(BUILD_DIR) $(TARGET).bin $(TARGET).hex



clean:
	$(RM) \
	$(BUILD_DIR) \
	$(notdir $(RELS:.rel=.asm)) \
	$(notdir $(RELS:.rel=.lst)) \
	$(notdir $(RELS:.rel=.mem)) \
	$(notdir $(RELS:.rel=.rel)) \
	$(notdir $(RELS:.rel=.rst)) \
	$(notdir $(RELS:.rel=.sym)) \
	$(notdir $(RELS:.rel=.adb)) \
	$(TARGET).lk \
	$(TARGET).map \
	$(TARGET).mem \
	$(TARGET).ihx \
	$(TARGET).hex \
	$(TARGET).bin
