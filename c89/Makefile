# Makefile
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Werror
INCLUDES = -Iinclude
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SERVER_SRCS = $(SRCDIR)/server_main.c $(SRCDIR)/server.c $(SRCDIR)/network.c
CLIENT_SRCS = $(SRCDIR)/client_main.c $(SRCDIR)/client.c $(SRCDIR)/network.c

# Object files
SERVER_OBJS = $(SERVER_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CLIENT_OBJS = $(CLIENT_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Executables
SERVER = $(BINDIR)/server
CLIENT = $(BINDIR)/client

.PHONY: all clean directories

all: directories $(SERVER) $(CLIENT)

directories:
	@mkdir -p $(OBJDIR) $(BINDIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
