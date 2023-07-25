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
TARGET ?= c1final
VERBOSE ?=
COURSE1 ?=

# Compiler Flags and Defines
OUTPUT = c1m2
GFLAGS = -Wall -Werror -g -O0 -std=c99
ifeq ($(PLATFORM), MSP432)
	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	FLOAT-ABI = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs

	# Compile Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	SIZE-UTL = arm-none-eabi-size
      	CPPFLAGS = -D$(PLATFORM) $(INCLUDES)
	CFLAGS = $(GLAGS) -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=$(FLOAT-ABI) -mfpu=$(FPU) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(OUTPUT).map -T $(LINKER_FILE)
	
else ifeq ($(PLATFORM), HOST)

        # Compile Defines
	CC = gcc
	LD = ld
	OBJDUMP = x86_64-linux-gnu-objdump
	SIZE-UTL = size
	CPPFLAGS = -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(INCLUDES)
	CFLAGS = $(GFLAGS)
	LDFLAGS = -Wl,-Map=$(OUTPUT).map
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

$(OUTPUT).asm: $(OUTPUT).out
	$(OBJDUMP) -S $< > $@

.PHONY: compile-all
compile-all: $(OBJS) 	


.PHONY: build
build:$(OUTPUT).out

$(OUTPUT).out:$(OBJS)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE-UTL) *.o *.out


.PHONY: clean
clean:
	rm -f *.d *.i *.s *.asm *.o $(OUTPUT).out $(OUTPUT).map
