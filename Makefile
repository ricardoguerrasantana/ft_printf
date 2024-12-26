#	Makefile for ft_printf project

# Name of the library
NAME = libftprintf.a

# Test runner
TEST_RUNNER = test_runner

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
TEST_FLAGS = -lcriterion

# Directories
SRC_DIR = src/
INCLUDE = include/
OBJ_DIR = obj/
TEST_DIR = tests/

# Files
SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
TESTS = $(wildcard $(TEST_DIR)*.c)

# Default target
all: $(NAME)

# Build default target
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean: tclean
	rm -rf $(OBJ) $(OBJ_DIR)

# Full clean rule
fclean: clean
	rm -f $(NAME) $(TEST_RUNNER)

# Remake rule
re: fclean all

# Norminette rule
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INCLUDE)

# Test rule
test: tclean $(TEST_RUNNER)
	@echo "Running tests..."
	./$(TEST_RUNNER)
	$(MAKE) tclean

# Test rule with TAP output format
test-tap: tclean $(TEST_RUNNER)
	@echo "Running tests with TAP format..."
	./$(TEST_RUNNER) --tap
	$(MAKE) tclean

# Test clean rule
tclean:
	rm -f $(TEST_RUNNER)

# Link the test runner with the compiled library and test files
$(TEST_RUNNER): $(NAME) $(TESTS)
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o $(TEST_RUNNER) $(TESTS) $(NAME)

# Test with valgrind
valgrind: $(TEST_RUNNER)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_RUNNER)
	$(MAKE) tclean

.PHONY: all clean fclean re norm test test-tap tclean valgrind
