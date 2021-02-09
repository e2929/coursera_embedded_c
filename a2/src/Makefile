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


# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = gcc
LD = 
LDFLAGS = 
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGs = -E
TARGET = c1m2

# Here, we are defining a variable OBJS. 
# This will go through every word in the sources list, and replace any .c ending with a .o ending.
OBJS = $($(PLATFORM)_SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
	
.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(TARGET).asm

