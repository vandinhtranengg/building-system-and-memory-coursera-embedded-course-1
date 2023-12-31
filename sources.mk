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

#Platform Override:


#Source and Include file's Selection based on the Target Platfrom
SOURCES :=	src/main.c		\
			src/memory.c	\
			src/stats.c		\
			src/data.c

INCLUDES :=	-I include/common

ifneq ($(COURSE1),)
	SOURCES +=	\
		src/course1.c

endif

ifeq ($(PLATFORM),MSP432)
	SOURCES +=	\
				src/interrupts_msp432p401r_gcc.c\
				src/startup_msp432p401r_gcc.c	\
				src/system_msp432p401r.c

	INCLUDES +=	\
				-I include/CMSIS	\
				-I include/msp432
endif
