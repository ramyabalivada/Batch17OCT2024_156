# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I../inc  # Includes the header files from the 'inc' directory
LDFLAGS = -lpthread  # Link the pthread library for threading
 
# Directories
SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin
INC_DIR = ../inc
 
# Source and object files
SRC_SERVER = $(SRC_DIR)/server.c \
             $(SRC_DIR)/log.c \
             $(SRC_DIR)/menu.c \
             $(SRC_DIR)/netcmd.c \
             $(SRC_DIR)/clientHandle.c
SRC_CLIENT = $(SRC_DIR)/client.c \
             $(SRC_DIR)/log.c \
             $(SRC_DIR)/menu.c \
             $(SRC_DIR)/netcmd.c
 
OBJ_SERVER = $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
 
# Output targets
TARGET_SERVER = $(BIN_DIR)/server
TARGET_CLIENT = $(BIN_DIR)/client
 
# Default target (Build everything)
all: $(TARGET_SERVER) $(TARGET_CLIENT)
 
# Rule to link the server executable
$(TARGET_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $^ $(LDFLAGS)
 
# Rule to link the client executable
$(TARGET_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT) $^ $(LDFLAGS)
 
# Rule to compile C files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
 
# Clean the build (removes object files and executables)
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*
 
# Phony targets (not files)
.PHONY: all clean

