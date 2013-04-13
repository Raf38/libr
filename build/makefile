all: libr.a

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

libr.a: $(OBJ_C) $(OBJ_S)
	libr-ar rcs $@ $(OBJ_S) $(OBJ_C)

%.o: %.c
	libr-gcc -g -c -MMD -I../include -o $@ $<

%.o: %.s
	libr-gcc -g -c -o $@ $<

clean:
	rm -rf *.o *.d libr.a
