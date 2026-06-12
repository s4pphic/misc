# MISC - Minimal Instruction Set for Computing
#
# Makefile! Only tested on Linux, may not work on macOS or Windows!
# (c) s4pphic 2026
# SPDX-License-Identifier: APACHE-2.0

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

CC      = clang
CFLAGS  = -std=c11 -Wall -Wextra -I$(INC_DIR)
LDFLAGS =

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)
TARGET  = $(BIN_DIR)/misc

.PHONY: all clean debug

all: $(BIN_DIR) $(TARGET)

debug: CFLAGS += -g -DDEBUG
debug: all

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)