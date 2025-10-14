# === Makefile ===

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -O2 -std=c++17

# Folders
SRC_DIR := src
BUILD_DIR := build

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
TARGET := search

# Default target
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	@echo "Linking $@..."
	$(CXX) $(OBJS) -o $@

# Compile step
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build
clean:
	rm -rf $(BUILD_DIR)

# Run program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
