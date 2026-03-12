CXX = g++

# Compile using debugger flags
CFLAGS = -g -Wall

# Build directory
BUILD_DIR = build

# List of source files
SRCS = main.cpp automate.cpp etat.cpp lexer.cpp symbole.cpp analyseur.cpp

# List of object files (in build directory)
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Name of the executable (in build directory)
EXEC = $(BUILD_DIR)/lexer

# Default target
all: $(EXEC)

# Rule to link object files into the executable
$(EXEC): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files in build directory
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Clean target to remove object files and executable
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean