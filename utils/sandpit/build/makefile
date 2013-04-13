all: sandpit

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

sandpit: $(OBJ_C) 
	gcc -o $@ $(OBJ_C)

%.o: %.c
	gcc -g -c -MMD -o $@ $<

clean:
	rm -rf *.o *.d
