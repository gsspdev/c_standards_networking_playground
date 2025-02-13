# Compiler and flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall
INCLUDES = -Iinclude

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)/obj

# Source files
SERVER_SRCS = $(wildcard $(SRC_DIR)/server/*.c)
CLIENT_SRCS = $(wildcard $(SRC_DIR)/client/*.c)

# Object files
SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executables
SERVER = $(BIN_DIR)/server
CLIENT = $(BIN_DIR)/client

.PHONY: all clean

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*
