SRC_DIR = src
OBJ_DIR = object
LIB_DIR = lib
INC_DIR = include
ISL_DIR = /usr/local

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -I$(INC_DIR)

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

LIB_NAME = libmin_hint.a

.PHONY: all clean install uninstall

all: $(LIB_DIR)/$(LIB_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

install: $(LIB_DIR)/$(LIB_NAME)
	cp $(LIB_DIR)/$(LIB_NAME) $(ISL_DIR)/lib/$(LIB_NAME)
	cp -r $(INC_DIR)/* $(ISL_DIR)/include/

uninstall:
	rm -f $(ISL_DIR)/lib/$(LIB_NAME)
	rm -rf $(ISL_DIR)/include/min/hint

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)
