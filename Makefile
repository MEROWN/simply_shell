#VARS
CC := clang
CFLAGS := -Wall -Wextra -Iinclude
TARGET := shell

#File search
#Source
SRC := $(wildcard src/*.c)

#Object
OBJ := $(SRC:src/%.c=obj/%.o)

#Targets
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

#Clean
clean:
	rm -rf obj $(TARGET)

.PHONY: all clean
	
