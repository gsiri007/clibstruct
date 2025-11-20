# Makefile for Singly Linked List

# Compiler
CC = gcc

# Compiler flags
# -g: Add debug info
# -Wall: Enable all warnings
CFLAGS = -g -Wall

# Directories
SRC_DIR = singlylinkedlist
TEST_DIR = tests
BUILD_DIR = build

# Source files
LIB_SRCS = $(SRC_DIR)/singlylinkedlist.c
LIB_OBJS = $(BUILD_DIR)/singlylinkedlist.o

# Library target
LIB_TARGET = $(BUILD_DIR)/libsinglylinkedlist.a

# Test files
TEST_SRCS = $(TEST_DIR)/test_runner.c $(TEST_DIR)/test_creation.c $(TEST_DIR)/test_deletion.c $(TEST_DIR)/test_insertion.c
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Phony targets
.PHONY: all test clean test_objs

# Default target
all: $(LIB_TARGET)

# Rule to build the library object file
$(LIB_OBJS): $(LIB_SRCS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $(LIB_SRCS) -o $(LIB_OBJS)

# Rule to create the static library
$(LIB_TARGET): $(LIB_OBJS)
	ar rcs $@ $^

# Object file build for test sources
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

# Test runner build
test: $(LIB_TARGET) $(TEST_OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -o $(BUILD_DIR)/test_runner $^ $(LIB_TARGET)
	@echo "Running tests..."
	@$(BUILD_DIR)/test_runner



# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

