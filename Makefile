# Makefile for clibstruct

# Compiler
CC = gcc

# Compiler flags
# -g: Add debug info
# -Wall: Enable all warnings
# -I: Add include directories
CFLAGS = -g -Wall -Isinglylinkedlist -Istack

# Directories
SLL_DIR = singlylinkedlist
STACK_DIR = stack
TEST_DIR = tests
BUILD_DIR = build

# Library source files
LIB_SRCS = $(SLL_DIR)/singlylinkedlist.c $(STACK_DIR)/stack.c
LIB_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(LIB_SRCS)))

# Library target
LIB_TARGET = $(BUILD_DIR)/libclibstruct.a

# Test source files
TEST_SRCS = $(TEST_DIR)/test_runner.c $(TEST_DIR)/test_creation.c $(TEST_DIR)/test_deletion.c $(TEST_DIR)/test_insertion.c $(TEST_DIR)/test_data_types.c $(TEST_DIR)/test_stack.c
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Phony targets
.PHONY: all test clean

# Default target
all: $(LIB_TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to build library object files
$(BUILD_DIR)/singlylinkedlist.o: $(SLL_DIR)/singlylinkedlist.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/stack.o: $(STACK_DIR)/stack.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library
$(LIB_TARGET): $(LIB_OBJS)
	ar rcs $@ $^

# Rule to build test object files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Test runner build and execution
test: $(LIB_TARGET) $(TEST_OBJS)
	$(CC) $(CFLAGS) -I. -o $(BUILD_DIR)/test_runner $(TEST_OBJS) $(LIB_TARGET)
	@echo "Running tests..."
	@$(BUILD_DIR)/test_runner

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Phony target for documentation
.PHONY: docs clean_docs

# Clean documentation artifacts
clean_docs:
	rm -rf html latex

# Generate documentation
docs: clean_docs
	doxygen Doxyfile
