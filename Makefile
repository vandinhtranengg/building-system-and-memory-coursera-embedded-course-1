#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST
TARGET ?= C1Final
COURSE1 ?=
VERBOSE ?=

# Compiler Flags and Defines
GFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)

ifneq ($(VERBOSE),)
	CPPFLAGS += -D$(VERBOSE)
endif

ifneq ($(COURSE1),)
	CPPFLAGS += -D$(COURSE1)
endif


ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ISA = thumb
	ARCH = armv7e-m
	FLOAT-ABI = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs

	# Compile Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	SIZE-UTL = arm-none-eabi-size
	CFLAGS = $(GFLAGS) -mcpu=$(CPU) -m$(ISA) -march=$(ARCH) -mfloat-abi=$(FLOAT-ABI) -mfpu=$(FPU) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
else ifeq ($(PLATFORM), HOST)

        # Compile Defines
	CC = gcc
	LD = ld
	#OBJDUMP = x86_64-linux-gnu-objdump
	OBJDUMP = $(shell which objdump)
	SIZE-UTL = size
	CFLAGS = $(GFLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif	

#Dependency Files Generation
DEPS = $(SOURCES:.c=.d)

#Object Files Generation
OBJS = $(SOURCES:.c=.o)

%.d : %.c
	$(CC)  -MM $< $(CPPFLAGS) -o $@

%.i : %.c
	$(CC)  -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.s : %.c
	$(CC)  -S $< $(CPPFLAGS) $(CFLAGS) -o $@

%.o : %.c
	$(CC)  -c $< $(CPPFLAGS) $(CFLAGS) -o $@

%.asm : %.o
	$(OBJDUMP) -S $< > $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -S $< > $@

.PHONY: compile-all
compile-all: $(OBJS) 	


.PHONY: build
build:$(TARGET).out

$(TARGET).out:$(OBJS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE-UTL) src/*.o *.out


.PHONY: clean
clean:
	rm -f src/*.d src/*.i src/*.s src/*.asm src/*.o $(TARGET).out $(TARGET).map $(TARGET).asm
