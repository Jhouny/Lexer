CXX = g++
CFLAGS = -g -Wall -I../
BUILD_DIR = ../build
TEST_SRCS = test_lexer.cpp ../analyseur.cpp ../lexer.cpp ../symbole.cpp ../automate.cpp ../etat.cpp
TEST_EXEC = $(BUILD_DIR)/test_lexer

all: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_SRCS) | $(BUILD_DIR)
	$(CXX) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: $(TEST_EXEC)
	$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean test