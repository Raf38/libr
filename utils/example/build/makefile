all: example

LD=ld
CC=gcc
CC_FLAGS=-O0 -MMD -I../../../include

SRC_DIR=../src/
OBJ_DIR=./objs/

SRC_C:=$(shell find $(SRC_DIR) -type f -name '*.c')
SRC_S:=$(shell find $(SRC_DIR) -type f -name '*.s')

OBJ_C:=$(subst .c,.o,$(notdir $(SRC_C)))
OBJ_S=$(subst .s,.o,$(notdir $(SRC_S))) 

DEPS=$(shell find ./ -type f -name '*.d')
-include $(DEPS)
VPATH=$(dir $(SRC_S))
VPATH+=$(dir $(SRC_C))

example: $(OBJ_C) $(OBJ_S) libr
	$(LD) -o $@ $(OBJ_S) $(OBJ_C) ../../../build/libr.a

%.o: %.c
	$(CC) $(CC_FLAGS) -g -c -o $@ $<

%.o: %.s
	$(CC) $(CC_FLAGS) -g -c -o $@ $<

libr:
	make -C ../../../build/ --no-print-directory

clean:
	make clean -C ../../../build/ --no-print-directory
	rm -rf *.o *.d libr.a
