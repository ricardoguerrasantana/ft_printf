#	Makefile for ft_printf project

# Name of the library
NAME = libftprintf.a

# Test runner
TEST_RUNNER = test_runner

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
COVERAGE_FLAGS = -coverage -g -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcriterion

# Directories
SRC_DIR = .
OBJ_DIR = obj
TEST_DIR = tests
COV_DIR = coverage

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
TESTS = $(wildcard $(TEST_DIR)/*.c)

# Default target
all: $(NAME)

# Build default target
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean: tclean covclean
	rm -rf $(OBJ) $(OBJ_DIR)

# Full clean rule
fclean: clean
	rm -f $(NAME) $(TEST_RUNNER)

# Remake rule
re: fclean all

# Test rule
test: tclean $(TEST_RUNNER)
	@echo "Running tests..."
	./$(TEST_RUNNER)

# Test rule with TAP output format
test-tap: tclean $(TEST_RUNNER)
	@echo "Running tests..."
	./$(TEST_RUNNER) --tap

# Test clean rule
tclean:
	rm -f $(TEST_RUNNER)

# Build test runner
$(TEST_RUNNER): $(NAME)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) $(TEST_FLAGS) -o $(TEST_RUNNER) $(TESTS) $(NAME)

# Test with valgrind
valgrind: $(TEST_RUNNER)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_RUNNER)

# Create coverage directory
$(COV_DIR):
	mkdir -p $(COV_DIR)

# Coverage rule
cov: covclean test $(COV_DIR)
	gcovr -r . --branches --exclude-directories=obj-tests --xml -o $(COV_DIR)/coverage.xml --gcov-ignore-parse-errors
	gcovr -r . --branches --exclude-directories=obj-tests --html -o $(COV_DIR)/coverage.html --gcov-ignore-parse-errors

covclean:
	rm -rf $(COV_DIR) coverage.xml coverage.html *.gcov *.gcda *.gcno

.PHONY: all clean fclean re test test-tap tclean valgrind coverage
