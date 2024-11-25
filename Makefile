#	Makefile for ft_printf project

# Name of the library
NAME = libftprintf.a

# Test runner
TEST_RUNNER = test_runner

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
TEST_FLAGS = -lcriterion

# Directories
SRC_DIR = .
OBJ_DIR = obj
TEST_DIR = tests

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
clean:
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

test-tap: tclean $(TEST_RUNNER)
	@echo "Running tests..."
	./$(TEST_RUNNER) --tap

# Test clean rule
tclean:
	rm -f $(TEST_RUNNER)

# Build test runner
$(TEST_RUNNER): $(NAME)
	$(CC) $(CFLAGS) $(COVERAGE_FLAGS) $(TEST_FLAGS) -o $(TEST_RUNNER) $(TESTS) $(NAME)

# Coverage rule
coverage: test
	gcovr -r . --branches --exclude-directories=obj --xml -o coverage.xml --gcov-ignore-parse-errors
	gcovr -r . --branches --exclude-directories=obj --html -o coverage.html --gcov-ignore-parse-errors

.PHONY: all clean fclean re test
